	.data
vetor:	.word	5,20,6,0,7,65,2,-9,36,84
str_initialVetor: .string "Vetor Inicial: \n"
str_orderVetor: .string "Vetor Ordenado: \n"
str_space: .string ", "
str_breakLine: .string "\n"


	.text
main:
	la	s11, vetor
	li	s10,10
	li 	a7, 4	
	la 	a0, str_initialVetor
	ecall
	
	mv	a1,s10
	mv	a0, s11
	jal funct_printV
	
	mv	a1,s10
	mv	a0, s11
	
	jal funct_bubble
	
	li 	a7, 4	
	la 	a0, str_orderVetor
	ecall
	
	mv	a1,s10
	mv	a0, s11
	jal funct_printV
	
	j	end
	
funct_swap: # a0) primeiro indice, a1) segundo indice, a2) endereço do vetor
	li 	t4, 4	
	mul 	t0, a0, t4  
	add 	t0, t0, a2  
	mul 	t1, a1, t4  
	add 	t1, t1, a2  
	
	lw 	t2, 0(t0)	
	lw 	t3, 0(t1)	
	
	sw 	t3, 0(t0)	
	sw 	t2, 0(t1)	
	ret
	
funct_bubble: # a0) endereço do vetor, a1) tamanho do vetor
	mv	a7, a0
	mv	a6, a1
	addi	a6,a6,-1

loop1:
	beq	t6, a6, endloop1
	addi	t6, t6, 1
	mv	t5, zero

loop2:
	beq 	t5, a6, loop1 
	li 	t4, 4
	mul 	s0, t5, t4	
	add 	s0, s0, a7 #s0 tem o endereço do indice
	lw	s1, 0(s0)
	lw	s2, 4(s0)
	
	blt	s1,s2, noSwap
	mv	a0, t5
	mv	a1, t5
	addi	a1, a1, 1
	mv	a2, a7
	mv	s3, ra
	jal	funct_swap
	mv	ra,s3
	
noSwap:	
	addi 	t5, t5, 1	
	j 	loop2
	
endloop1:
	ret
		
	
	
funct_printV: # a0) endereço do vetor, a1) tamanho do vetor
	mv	a2,a0		
	mv	t5, zero	
	
loop:
	beq 	t5, a1, endloop 
	li 	t4, 4	
	mul 	t4, t5, t4	
	add 	t4, t4, a2	
	lw 	a0, 0(t4)	
	li 	a7, 1	
	ecall		
	
	li 	a7, 4	
	la 	a0, str_space 
	ecall		
	
	addi 	t5, t5, 1	
	j 	loop
endloop:
	li 	a7, 4	
	la 	a0, str_breakLine
	ecall
	ret
	
end: 	
	nop
