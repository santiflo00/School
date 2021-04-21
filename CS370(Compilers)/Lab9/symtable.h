/*  
 * Symbol Table header file using linked list
 * FILE: symtable.h
 * 
 * Santiago Flores
 * 5/8/2020
 * Holds the definition for struct symbTab
 * 
 */

#include "AST.h"


#ifndef _SYMTAB 
#define _SYMTAB



void Display(); //display the id with its coresponding level and offset
int Delete();// delete all symbols at that level

struct SymbTab {
     char *name;  //the name of the symbol/ID
     int offset; /* from activation record boundary */
     int mysize;  // the size or number of words of this symbol
     int level;  // the level that the variable is at 
     enum OPERATORS Type;  // The type of the symbol(int, boolean , void) using the enum operators from ASTNode
     int IsAFunc;  //determine what the symbol is. Scalar = 1, array = 2, fucntion = 0
     ASTNode * fparms; //ASTNode pointer used to find the parameter of a function, null for non functions
     struct SymbTab *next;  //pointer to next pointer in linked list
};

struct SymbTab * Insert(char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset, ASTNode * fparms ); //insert the symbol to the table
struct SymbTab * Search(char name[], int level, int recur); //search for a symbol in the table
char * CreateTemp();

#endif
