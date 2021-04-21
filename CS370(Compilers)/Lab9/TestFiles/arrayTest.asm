.data
_L2:		.asciiz	"A["		# string
_L3:		.asciiz	"] = "		# string
_L4:		.asciiz	"\n"		# string
_L1:		.asciiz	"\n"		# string
_L0:		.asciiz	"enter X: "		# string

.align 2

A:		.space 400		# global variable
				

.text

main:					# start of Function
		subu $a0, $sp, 72		# adjust the stack for function setup
		sw $sp, ($a0)		
		sw $ra, 4($a0)		
		move $sp, $a0		
				
		li $a0, 0		# expression is a NUM
		move $a1 $a0		# move the value of the right hand side to use a for the variable
		add $a0, $sp, 28		 # identifier is a scalar
				
		sw $a1 ($a0)		# store value into var 
_L5:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 28		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 40($sp)		 # store in a0 sp + offset
		li $a0, 5		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 40($sp)		# load a0 with the symbols offset + stack pointer
		slt $a0, $a0, $a1		# set a0 with 1 if a0 < a1 else set to 0
		beq $a0 $t0 _L6		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L0		# use the label to print string
		syscall		# print the string 
				
		add $a0, $sp, 28		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sll $t3 $a0 2		# shift logical left twice to mulitply by 4
		li $a0 8		# load offset
		add $a0 $a0 $sp		# add stack pointer puls offset
		add $a0 $a0 $t3		# add the index with the sp + offset
				
		li $v0, 5		 #  read the num
		syscall		#system call for reading the num
		sw $v0, ($a0)		 # store the read into a mem location
				
		add $a0, $sp, 28		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 44($sp)		 # store in a0 sp + offset
		li $a0, 1		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 44($sp)		# load a0 with the symbols offset + stack pointer
		add $a0, $a0, $a1		# add the two values together into a0
		move $a1 $a0		# move the value of the right hand side to use a for the variable
		add $a0, $sp, 28		 # identifier is a scalar
				
		sw $a1 ($a0)		# store value into var 
		j _L5		# jump back to start of while 
_L6:				
		li $a0, 0		# expression is a NUM
		move $a1 $a0		# move the value of the right hand side to use a for the variable
		add $a0, $sp, 28		 # identifier is a scalar
				
		sw $a1 ($a0)		# store value into var 
_L7:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 28		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 48($sp)		 # store in a0 sp + offset
		li $a0, 5		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 48($sp)		# load a0 with the symbols offset + stack pointer
		slt $a0, $a0, $a1		# set a0 with 1 if a0 < a1 else set to 0
		beq $a0 $t0 _L8		# branch if the expr is 0
		add $a0, $sp, 28		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sll $t3 $a0 2		# shift logical left twice to mulitply by 4
		li $a0 8		# load offset
		add $a0 $a0 $sp		# add stack pointer puls offset
		add $a0 $a0 $t3		# add the index with the sp + offset
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 52($sp)		 # store in a0 sp + offset
		add $a0, $sp, 28		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sll $t3 $a0 2		# shift logical left twice to mulitply by 4
		li $a0 8		# load offset
		add $a0 $a0 $sp		# add stack pointer puls offset
		add $a0 $a0 $t3		# add the index with the sp + offset
				
		lw $a0, ($a0)		#  fetch value for identifier
		move $a1 $a0		# move a0 into a1
		lw $a0 52($sp)		# load a0 with the symbols offset + stack pointer
		mult $a0 $a1		# multiply the two values
		mflo $a0		# hold the lower value in a0
		li $v0 1		 #  Print the num
		syscall		#  system call for printing num
				
		li $v0, 4		# Printing string
		la $a0, _L1		# use the label to print string
		syscall		# print the string 
				
		add $a0, $sp, 28		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 56($sp)		 # store in a0 sp + offset
		li $a0, 1		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 56($sp)		# load a0 with the symbols offset + stack pointer
		add $a0, $a0, $a1		# add the two values together into a0
		move $a1 $a0		# move the value of the right hand side to use a for the variable
		add $a0, $sp, 28		 # identifier is a scalar
				
		sw $a1 ($a0)		# store value into var 
		j _L7		# jump back to start of while 
_L8:				
		li $a0, 10		# expression is a NUM
		move $a1 $a0		# move the value of the right hand side to use a for the variable
		add $a0, $sp, 32		 # identifier is a scalar
				
		sw $a1 ($a0)		# store value into var 
_L9:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 32		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 56($sp)		 # store in a0 sp + offset
		li $a0, 0		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 56($sp)		# load a0 with the symbols offset + stack pointer
		sge $a0, $a0, $a1		# set a0 with 1 if a0 >= a1 else set to 0
		beq $a0 $t0 _L10		# branch if the expr is 0
		add $a0, $sp, 32		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		move $a1 $a0		# move the value of the right hand side to use a for the variable
		add $a0, $sp, 32		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sll $t3 $a0 2		# shift logical left twice to multiply by 4
		la $a0 A		# load a0 with address
		add $a0 $a0 $t3		# array mem address plus index
		sw $a1 ($a0)		# store value into var 
		li $v0, 4		# Printing string
		la $a0, _L2		# use the label to print string
		syscall		# print the string 
				
		add $a0, $sp, 32		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		li $v0 1		 #  Print the num
		syscall		#  system call for printing num
				
		li $v0, 4		# Printing string
		la $a0, _L3		# use the label to print string
		syscall		# print the string 
				
		add $a0, $sp, 32		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sll $t3 $a0 2		# shift logical left twice to multiply by 4
		la $a0 A		# load a0 with address
		add $a0 $a0 $t3		# array mem address plus index
		lw $a0, ($a0)		#  fetch value for identifier
		li $v0 1		 #  Print the num
		syscall		#  system call for printing num
				
		li $v0, 4		# Printing string
		la $a0, _L4		# use the label to print string
		syscall		# print the string 
				
		add $a0, $sp, 32		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 64($sp)		 # store in a0 sp + offset
		li $a0, 1		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 64($sp)		# load a0 with the symbols offset + stack pointer
		sub $a0, $a0, $a1		# subtract the two values into a0
		move $a1 $a0		# move the value of the right hand side to use a for the variable
		add $a0, $sp, 32		 # identifier is a scalar
				
		sw $a1 ($a0)		# store value into var 
		j _L9		# jump back to start of while 
_L10:				
				
		lw $ra, 4($sp)		# restore RA
		lw $sp, ($sp)		# restore SP
				
		li $v0, 10		  # Leave Main program
		syscall		# 
