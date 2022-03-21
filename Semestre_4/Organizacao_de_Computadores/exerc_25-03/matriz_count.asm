	.data
matriz:	.word	5,-1,6,-1,7,65,2,-9,36,-1
string_answer:	.string	"O número de -1 encontrados na matriz eh: \n"

	.text
main:
	la	a0, matriz
	li	a1, 5
	li	a2, 2
	
	jal	f_conta_matriz
	mv	s0,a0
	
	la	a0,string_answer
	li	a7, 4
	ecall

	li	a7, 1
	mv	a0, s0
	ecall
	
	j	end

f_conta_matriz: # a0 - endereço inicial da matriz, a1 - quantidade de colunas na matriz, a2 - quantidade de linhas da matriz
	li	t0, -1 # i -> linhas
	mv	t1, zero # j -> colunas
	mv	t2, zero # count -> contador de -1
	li	t4, 4
	li	t6, -1
	
loop_i:
	addi	t0, t0, 1
	beq	t0, a2, endloop_i
	mv	t1, zero

loop_j:
	beq	t1, a1, loop_i
	mv	t3, a1
	mul	t3, t3, t0
	add	t3, t3, t1
	mul	t3, t3, t4
	add	t3, t3, a0
	lw	t5, 0(t3)
	
	addi	t1, t1, 1
	
	beq	t5, t6, true
	j	loop_j
	
true:
	addi	t2, t2, 1
	j	loop_j

endloop_i:
	mv	a0, t2
	ret
	
end:
	nop

	
