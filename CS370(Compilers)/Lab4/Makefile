#Santiago Flores
#Feb 14, 2020
#Makefile for Lab4
all:
	yacc -d lab4.y
	lex lab4.l
	gcc lex.yy.c y.tab.c symtable.c -o lab4
