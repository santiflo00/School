/*  
 * Symbol Table using linked list
 * FILE: symtable.c
 * Store symbols from yacc to check semantic action
 * Uses Insert function to store a new entry
 * Search looks for an entry with the given name and level
 * Display shows the symbols in the table with their appropriate level and offset
 * Delete removes all entries at a given level and returns the amount removed based on symbols sized. Used to reset offset
 * 
 * Santiago Flores
 * 4/17/2020
 *
 */

    
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "symtable.h"
#include "AST.h"

struct SymbTab *first = NULL;
int GTEMP = 0;

// Insert a symbol into the table returning the pointer of the symbol just entered
// Insert giving name, type, if its a function, level, size, offset, ASTNode pointer
// returns a SymbTab pointer of the entry

struct SymbTab * Insert(char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset , ASTNode * fparms) {
  
    struct SymbTab * n;
    n=Search(name,level, 0);
    
    if(n != NULL) {
      //Here if the symbol already exits
      printf("\n %s at level %d already exists in the symbol table\n",name, level);
      return (NULL);
    }//end if
    
    else {//enter the new symbol into the table and set all values given in the parmeters
        struct SymbTab *p;
        p=malloc(sizeof(struct SymbTab));
        p->name=name;
        p->offset=offset;  
        p->level=level;  
        p->mysize=mysize;  
        p->Type=Type;  
        p->IsAFunc=isafunc;  
        p->fparms=fparms;  
        p->next=NULL;
        
      //check to see if there are other entries in the table if not then set the new symbol to first
        if(first == NULL) {
            first = p;
        }
        else {
            p->next = first;
            first = p;
        }
        return (p);
    }//end outer else
     
}//end Insert

//Create Temp
char * CreateTemp() {
    
    char hold[100];
    char *s;
    
    sprintf(hold, "_t%d",GTEMP++);
    s = strdup(hold);
    return s;
    
}//end CreateTemp


//Used to print an entry int the symbol table given a pointer. Only called in Display to help debug
void PrintSym(struct SymbTab *s) {
    printf("\t%s\t\t%d\t\t%d\n",s->name,s->offset, s->level);
}//end PrintSym


//Display the Symbol with its corresponding offset and level
//Call to print SYMBOL  OFFSET  LEVEL uses PrintSym to print values

void Display() {
    
    int i;
    struct SymbTab *p;
    p = first;
   
    printf("\n\tSYMBOL\t\tOFFSET\t\tLEVEL\n");
    while (p!=NULL) {
        PrintSym(p);
        p=p->next;
    }
}//end Display

 
/* Search for symbol with the given parameters - name, level, recur
   Returns the pointer to that symbol if found else it returns null
   If recur is non-zero then look through all levels for the symbol
*/ 

struct SymbTab * Search(char name[], int level, int recur) {
    int i,flag=0;
    struct SymbTab *p;

    while (level >= 0) {
        p=first;
        while (p != NULL){
            if((strcmp(p->name,name)==0) && (p->level == level))
                return p; //the symbol WAS found 
            p = p->next;
        }
        if (recur == 0) return (NULL);   //check the next level
        level--;
    }//end while
    //the symbol was NOT found return NULL
    return  NULL; 
}//end Search

// Remove all symbol table entries within the given level
// Return the number of entries that have been removed based on their size. Used to set the offset back to before entering a comp statment

int Delete(int level) {
    struct SymbTab *p,*f = NULL;  /* we follow with pointer f */
    int SIZE = 0;
    p = first;

    while (p != NULL) {
        if (p->level >= level) { /* if it is the first in the list we have to update first, we know this by f being NULL */
            SIZE += p->mysize;
            if (f == NULL) 
                first=p->next;
            else {
                f->next=p->next;
            }
            p=p->next;
        }//end if
        
        else {
            f=p;
            p=p->next;
        }
      }//end while
      
    return(SIZE);
    
}//end delete

