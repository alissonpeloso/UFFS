	.data
A: 	.word	13 
B:	.word	5000
C:	.word	5000

	.text 
main:
	lw	s0, A #A = s0
	lw	s1, B #B = s1
	lw	s2, C #C = s2
	
	bgt 	s0,s1,A_biggerthan_B # verifica se A > B
	bgt	s1,s2,B_biggest # se não, verifica se B > C

A_biggerthan_B:
	bgt	s2,s0,C_biggest # verifica se C > A
	lw	a0, A # se não, guarda A em a0
	j	fim
	
B_biggest:
	lw	a0, B # guarda B em a0
	j	fim
	
C_biggest:
	lw	a0,C # guarda C em a0
	j	fim
	
fim:	nop