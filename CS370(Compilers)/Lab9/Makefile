#Makefile for Lab9
#FILE: Makefile 
#Santiago Flores
#5/8/2020
#
all:
	yacc -d lab9.y
	lex lab9.l
	gcc lex.yy.c y.tab.c emit.c AST.c symtable.c -o lab9

clean:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c
	rm lab9
