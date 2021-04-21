.data
_L0:		.asciiz	"\n"		# string
_L1:		.asciiz	"\n"		# string
_L2:		.asciiz	"\n"		# string
_L3:		.asciiz	"\n"		# string
_L21:		.asciiz	"8 good statements 8 wrong"		# string
_L20:		.asciiz	"!(a==48)\n"		# string
_L19:		.asciiz	"a>51 wrong(8)\n"		# string
_L18:		.asciiz	"a>12 wrong(7)\n"		# string
_L17:		.asciiz	"a>2 good(8)\n"		# string
_L16:		.asciiz	"a<48 good(7)\n"		# string
_L15:		.asciiz	"a<12 wrong(6)\n"		# string
_L14:		.asciiz	"a<2 wrong(5)\n"		# string
_L13:		.asciiz	"a!=12 wrong(4)\n"		# string
_L12:		.asciiz	"a!=89 good(6)\n"		# string
_L11:		.asciiz	"a>=32 wrong(3)\n"		# string
_L10:		.asciiz	"a>=12 good(5)\n"		# string
_L9:		.asciiz	"a>=5 good(4)\n"		# string
_L8:		.asciiz	"a==1 good(3)\n"		# string
_L7:		.asciiz	"a==-1 wrong(2)\n"		# string
_L6:		.asciiz	"a<=24 good(2)\n"		# string
_L5:		.asciiz	"a<=1 good(1)\n"		# string
_L4:		.asciiz	"a<=4 wrong(1)\n"		# string

.align 2

x:		.space 4		# global variable
				

.text

main:					# start of Function
		subu $a0, $sp, 124		# adjust the stack for function setup
		sw $sp, ($a0)		
		sw $ra, 4($a0)		
		move $sp, $a0		
				
		li $a0, 3		# expression is a NUM
		sw $a0, 20($sp)		 # store in a0 sp + offset
		li $a0, 1		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 20($sp)		# load a0 with the symbols offset + stack pointer
		add $a0, $a0, $a1		# add the two values together into a0
		move $a1 $a0		# move the value of the right hand side to use a for the variable
		la $a0 x		# load global variable from data into a0
				
		sw $a1 ($a0)		# store value into var 
		la $a0 x		# load global variable from data into a0
				
		lw $a0, ($a0)		#  fetch value for identifier
		li $v0 1		 #  Print the num
		syscall		#  system call for printing num
				
		li $v0, 4		# Printing string
		la $a0, _L0		# use the label to print string
		syscall		# print the string 
				
		la $a0 x		# load global variable from data into a0
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 28($sp)		 # store in a0 sp + offset
		li $a0, 6		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 28($sp)		# load a0 with the symbols offset + stack pointer
		sub $a0, $a0, $a1		# subtract the two values into a0
		move $a1 $a0		# move the value of the right hand side to use a for the variable
		add $a0, $sp, 16		 # identifier is a scalar
				
		sw $a1 ($a0)		# store value into var 
		add $a0, $sp, 16		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		li $v0 1		 #  Print the num
		syscall		#  system call for printing num
				
		li $v0, 4		# Printing string
		la $a0, _L1		# use the label to print string
		syscall		# print the string 
				
		add $a0, $sp, 16		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 36($sp)		 # store in a0 sp + offset
		li $a0, 2		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 36($sp)		# load a0 with the symbols offset + stack pointer
		div $a0 $a1		# divide the two values
		mflo $a0		# hold the lower value in a0
		move $a1 $a0		# move the value of the right hand side to use a for the variable
		add $a0, $sp, 12		 # identifier is a scalar
				
		sw $a1 ($a0)		# store value into var 
		add $a0, $sp, 12		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		li $v0 1		 #  Print the num
		syscall		#  system call for printing num
				
		li $v0, 4		# Printing string
		la $a0, _L2		# use the label to print string
		syscall		# print the string 
				
		add $a0, $sp, 12		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 44($sp)		 # store in a0 sp + offset
		li $a0, 13		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 44($sp)		# load a0 with the symbols offset + stack pointer
		mult $a0 $a1		# multiply the two values
		mflo $a0		# hold the lower value in a0
		move $a1 $a0		# move the value of the right hand side to use a for the variable
		la $a0 x		# load global variable from data into a0
				
		sw $a1 ($a0)		# store value into var 
		la $a0 x		# load global variable from data into a0
				
		lw $a0, ($a0)		#  fetch value for identifier
		li $v0 1		 #  Print the num
		syscall		#  system call for printing num
				
		li $v0, 4		# Printing string
		la $a0, _L3		# use the label to print string
		syscall		# print the string 
				
		li $a0, 12		# expression is a NUM
		move $a1 $a0		# move the value of the right hand side to use a for the variable
		add $a0, $sp, 8		 # identifier is a scalar
				
		sw $a1 ($a0)		# store value into var 
_L22:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 56($sp)		 # store in a0 sp + offset
		li $a0, 4		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 56($sp)		# load a0 with the symbols offset + stack pointer
		sle $a0, $a0, $a1		# set a0 with 1 if a0 <= a1 else set to 0
		beq $a0 $t0 _L23		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L4		# use the label to print string
		syscall		# print the string 
				
_L23:				
_L24:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 60($sp)		 # store in a0 sp + offset
		li $a0, 12		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 60($sp)		# load a0 with the symbols offset + stack pointer
		sle $a0, $a0, $a1		# set a0 with 1 if a0 <= a1 else set to 0
		beq $a0 $t0 _L25		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L5		# use the label to print string
		syscall		# print the string 
				
_L25:				
_L26:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 64($sp)		 # store in a0 sp + offset
		li $a0, 24		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 64($sp)		# load a0 with the symbols offset + stack pointer
		sle $a0, $a0, $a1		# set a0 with 1 if a0 <= a1 else set to 0
		beq $a0 $t0 _L27		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L6		# use the label to print string
		syscall		# print the string 
				
_L27:				
_L28:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 68($sp)		 # store in a0 sp + offset
		li $a0, 1		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 68($sp)		# load a0 with the symbols offset + stack pointer
		seq $a0, $a0, $a1		# set a0 with 1 if a0 == a1 else set to 0
		beq $a0 $t0 _L29		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L7		# use the label to print string
		syscall		# print the string 
				
_L29:				
_L30:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 72($sp)		 # store in a0 sp + offset
		li $a0, 12		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 72($sp)		# load a0 with the symbols offset + stack pointer
		seq $a0, $a0, $a1		# set a0 with 1 if a0 == a1 else set to 0
		beq $a0 $t0 _L31		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L8		# use the label to print string
		syscall		# print the string 
				
_L31:				
_L32:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 76($sp)		 # store in a0 sp + offset
		li $a0, 5		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 76($sp)		# load a0 with the symbols offset + stack pointer
		sge $a0, $a0, $a1		# set a0 with 1 if a0 >= a1 else set to 0
		beq $a0 $t0 _L33		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L9		# use the label to print string
		syscall		# print the string 
				
_L33:				
_L34:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 80($sp)		 # store in a0 sp + offset
		li $a0, 12		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 80($sp)		# load a0 with the symbols offset + stack pointer
		sge $a0, $a0, $a1		# set a0 with 1 if a0 >= a1 else set to 0
		beq $a0 $t0 _L35		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L10		# use the label to print string
		syscall		# print the string 
				
_L35:				
_L36:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 84($sp)		 # store in a0 sp + offset
		li $a0, 32		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 84($sp)		# load a0 with the symbols offset + stack pointer
		sge $a0, $a0, $a1		# set a0 with 1 if a0 >= a1 else set to 0
		beq $a0 $t0 _L37		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L11		# use the label to print string
		syscall		# print the string 
				
_L37:				
_L38:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 88($sp)		 # store in a0 sp + offset
		li $a0, 89		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 88($sp)		# load a0 with the symbols offset + stack pointer
		sne $a0, $a0, $a1		# set a0 with 1 if a0 != a1 else set to 0
		beq $a0 $t0 _L39		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L12		# use the label to print string
		syscall		# print the string 
				
_L39:				
_L40:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 92($sp)		 # store in a0 sp + offset
		li $a0, 12		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 92($sp)		# load a0 with the symbols offset + stack pointer
		sne $a0, $a0, $a1		# set a0 with 1 if a0 != a1 else set to 0
		beq $a0 $t0 _L41		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L13		# use the label to print string
		syscall		# print the string 
				
_L41:				
_L42:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 96($sp)		 # store in a0 sp + offset
		li $a0, 2		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 96($sp)		# load a0 with the symbols offset + stack pointer
		slt $a0, $a0, $a1		# set a0 with 1 if a0 < a1 else set to 0
		beq $a0 $t0 _L43		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L14		# use the label to print string
		syscall		# print the string 
				
_L43:				
_L44:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 100($sp)		 # store in a0 sp + offset
		li $a0, 12		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 100($sp)		# load a0 with the symbols offset + stack pointer
		slt $a0, $a0, $a1		# set a0 with 1 if a0 < a1 else set to 0
		beq $a0 $t0 _L45		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L15		# use the label to print string
		syscall		# print the string 
				
_L45:				
_L46:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 104($sp)		 # store in a0 sp + offset
		li $a0, 48		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 104($sp)		# load a0 with the symbols offset + stack pointer
		slt $a0, $a0, $a1		# set a0 with 1 if a0 < a1 else set to 0
		beq $a0 $t0 _L47		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L16		# use the label to print string
		syscall		# print the string 
				
_L47:				
_L48:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 108($sp)		 # store in a0 sp + offset
		li $a0, 2		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 108($sp)		# load a0 with the symbols offset + stack pointer
		sgt $a0, $a0, $a1		# set a0 with 1 if a0 < a1 else set to 0
		beq $a0 $t0 _L49		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L17		# use the label to print string
		syscall		# print the string 
				
_L49:				
_L50:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 112($sp)		 # store in a0 sp + offset
		li $a0, 12		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 112($sp)		# load a0 with the symbols offset + stack pointer
		sgt $a0, $a0, $a1		# set a0 with 1 if a0 < a1 else set to 0
		beq $a0 $t0 _L51		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L18		# use the label to print string
		syscall		# print the string 
				
_L51:				
_L52:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 116($sp)		 # store in a0 sp + offset
		li $a0, 51		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 116($sp)		# load a0 with the symbols offset + stack pointer
		sgt $a0, $a0, $a1		# set a0 with 1 if a0 < a1 else set to 0
		beq $a0 $t0 _L53		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L19		# use the label to print string
		syscall		# print the string 
				
_L53:				
_L54:				
		li $t0 0		# load t0 with 0 to compare with a0
		add $a0, $sp, 8		 # identifier is a scalar
				
		lw $a0, ($a0)		#  fetch value for identifier
		sw $a0, 120($sp)		 # store in a0 sp + offset
		li $a0, 48		# expression is a NUM
		move $a1 $a0		# move a0 into a1
		lw $a0 120($sp)		# load a0 with the symbols offset + stack pointer
		seq $a0, $a0, $a1		# set a0 with 1 if a0 == a1 else set to 0
		beq $a0 $t0 _L55		# branch if the expr is 0
		li $v0, 4		# Printing string
		la $a0, _L20		# use the label to print string
		syscall		# print the string 
				
_L55:				
		li $v0, 4		# Printing string
		la $a0, _L21		# use the label to print string
		syscall		# print the string 
				
				
		lw $ra, 4($sp)		# restore RA
		lw $sp, ($sp)		# restore SP
				
		li $v0, 10		  # Leave Main program
		syscall		# 
