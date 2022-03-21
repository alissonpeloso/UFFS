	.data

printA: .string	"Digite o valor de A: " 
printB: .string	"Digite o valor de B: " 
printC: .string	"Digite o valor de C: " 
printIsTriangle: .string	"Pode ser um Triângulo! " 
printIsNotTriangle: .string	"Não pode ser um Triângulo!" 

	.text 
main:
	li 	a7, 4
	la	a0, printA
	ecall
	
	li	a7, 5
	ecall
	mv	a2, a0
	
	li 	a7, 4
	la	a0, printB
	ecall
	
	li	a7, 5
	ecall
	mv	a1, a0
	
	li 	a7, 4
	la	a0, printC
	ecall
	
	li	a7, 5
	ecall
	
	jal	func_bigger
	
	jal	func_isTriangle
	
	jal	func_printIsTriangle
	
	j	end	
	
func_bigger:
	bgt 	a2,a1,A_biggerthan_B # verifica se A > B
	bgt	a1,a0,B_biggest # se não, verifica se B > C	

A_biggerthan_B:
	bgt	a0,a2,C_biggest # verifica se C > A
	mv	t0, a2
	mv	t1, a1
	mv	t2, a0
	ret
	
B_biggest:
	mv	t1, a2
	mv	t0, a1
	mv	t2, a0 
	ret
	
C_biggest:
	mv	t2, a2
	mv	t1, a1
	mv	t0, a0
	ret
	
func_isTriangle:
	add 	t1, t1, t2
	bgt 	t0,t1,true
	li	a0,0
	ret
true:
	li 	a0, 1
	ret
	
func_printIsTriangle:
	li 	a7, 4
	beqz	a0, isNot
	
	la	a0, printIsTriangle
	ecall
	ret
isNot:
	la	a0, printIsNotTriangle
	ecall
	ret
	
end:	nop