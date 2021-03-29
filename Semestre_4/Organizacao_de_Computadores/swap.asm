	.data
	
vetor_V: .word 3,-5,7,11,9,16
str_vetor: .string "Vetor: "
str_space: .string ", "

	.text
main:
	la a2, vetor_V 	# Registra endereço do vetor no a2
	li a7, 5 	# a7 = 7 entrada de inteiro
	ecall 		# a0 = input
	
	mv a1, a0 	# a1 = a0
	ecall 		# a0 = input
	
	jal funct_swap 	#chama a função swap entre os índices a0 e a1
	
	li a1, 6	# a1 recebe o tamanho do vetor
	jal funct_printV #chama a função para printar o vetor
	j end		#jump para final do programa

funct_swap: 		# a0 -> primeiro índice, a1 -> segundo índice, a2 -> endereço do início do vetor
	li t4, 4	# t4 = 4 -> tamanho de bytes de uma word
	mul t0, a0, t4  # índice * 4 para pegar endereço específico do índice no vetor
	add t0, t0, a2  # endereço do primeiro índice
	mul t1, a1, t4  # índice * 4 para pegar endereço específico do índice no vetor
	add t1, t1, a2  # endereço do segundo índice
	
	lw t2, 0(t0)	# t2 recebe o valor do endereço de t0
	lw t3, 0(t1)	# t3 recebe o valor do endereço de t1
	
	sw t3, 0(t0)	# salva o valor de t3 na memória com endereço t0
	sw t2, 0(t1)	# salva o valor de t2 na memória com endereço t1
	ret
	
funct_printV: 		# a1 -> size do vetor e a2 -> endereço do início do vetor
	li a7, 4	# a7 = 4 para printar string
	la a0, str_vetor # a0 recebe a string "Vetor: "
	ecall		# printa o conteúdo de a0
	
loop:
	beq t5, a1, endloop # for( int i = 0; i < vectorSize; i++)
	li t4, 4	# t4 recebe tamanho da word
	mul t4, t5, t4	# multiplica sizeof(word) pelo índice
	add t4, t4, a2	# soma o valor do índice*4 com o endereço inicial do vetor para conseguir o endereço do índice específico
	lw a0, 0(t4)	# carrega o valor do endereço registrado em t4 no registrador a0
	li a7, 1	# a7 = 1 para print de int
	ecall		# print valor do índice do vetor
	
	li a7, 4	# a7 = 4 para printar string
	la a0, str_space # carrega ", " em a0 para realizar o print
	ecall		# print do conteúdo de a0
	
	addi t5, t5, 1	# equivalente ao i++
	j loop
endloop:
	ret
	
end: 	
	nop
	
	
