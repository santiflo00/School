#Santiago Flores
#March 28, 2020
#Makefile for Lab6
all:
	yacc -d lab6.y
	lex lab6.l
	gcc lex.yy.c y.tab.c AST.c -o lab6
	#./lab6 < lab6test.al  #run test file after compilation
