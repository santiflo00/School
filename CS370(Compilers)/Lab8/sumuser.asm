#Santiago Flores
#4/19/2020
#This code calculates the sum of squares of a number read in by the user
#The code will ask for a number then calculate the sum of squares from 0 to that number
#Example exe:
#	Please enter a value: 5
#	The sum from 0 to 5 is
#	55
.data
L1: .asciiz "Please enter a value: "
L2: .asciiz "The number read was "
L3:  .asciiz "The sum from 0 to "
NL:  .asciiz " is\n"   

 .text  # directive that we are in the code segment

main:
        subu $a0, $sp, 20 # We want 5 mem locations for main SP, RA, i , s, x(user input)
        sw $ra, 4($a0)  # we need to store the RA in the Activation record
        sw $sp, ($a0) # store SP
        move $sp, $a0  # adjust SP

        sw $0, 8($sp)  # store 0 into memory -- counting variable  i
        sw $0, 12($sp) # store 0 into memory -- variable s
        
        #Prompts the user to enter a value
        li $v0, 4
	la $a0, L1
	syscall 

	#stores the varible into memory
	li $v0, 5
	syscall
	sw $v0 16($sp)
 	
 	#prints the range that is being sumed
 	li $v0, 4
	la $a0, L3
	syscall
	
	li $v0, 1 
	lw $a0,16($sp)     # value entered from user
 	syscall
       
loop:
	lw $t5, 16($sp) #load the users value
        lw $t6, 8($sp)  #   
        mul $t7, $t6, $t6  #  i * i
        lw $t8, 12($sp)   #  s
        addu $t9, $t8, $t7  #  s + i*i
        sw $t9, 12($sp)  #   s= s + i*i 
        lw $t6, 8($sp)   # i 
        addu $t0, $t6, 1  # i+1
        sw $t0, 8($sp)  #  i = i + 1
        ble $t0, $t5, loop  #   loop until the value of users input
        nop   # 
        
        la $a0, NL
        li $v0 4  #   print the string
        syscall # 
        nop   # 
        
        lw $a0, 12($sp)
        li $v0 1 #   Print the number
        syscall
        
       
        lw $ra, 4($sp)
        lw $sp , ($sp)  # put backl Ra and SP
        
        li $v0, 10 
        syscall     #  exit for MAIN only
        
  .data
        .align 0

        
