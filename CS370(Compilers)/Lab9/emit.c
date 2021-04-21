/* Lab9 emit.c file
 * FILE: emit.c
 * 
 * This file prints out MIPS assembly code into a specified file using
 * a pointer to the AST and a pointer to the file
 * similar to AST.c it finds searches through the AST until it finds a specific type, 
 * then calls a function to print out the correct MIPS code outside of functions emit_AST
 * it also generates labels and prints finds global variables along with strings and prints out
 * the corresponding MIPS code
 * 
 * Santiago Flores
 * 5/8/2020
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "AST.h"
#include "emit.h"

char * CURR_FUNCTION;


/* emit_expr
 * PRE: takes a file pointer to the file you will write to(.asm) and three char pointers 
 * POST: Writes specified MIPS code to the file using a Labe, the command, and a comment
 */
void emit(FILE *fp, char *Label, char *command, char *comment) {
    
    if (strcmp("",Label) == 0)
        fprintf(fp,"\t\t%s\t\t%s\n",command, comment);
    else
        fprintf(fp,"%s:\t\t%s\t\t%s\n", Label, command, comment);
}//end emit

/*  emit_read
 *  PRE: pointer to a read statement and a file
 *  POST: Calls emit to print MIPS code to read input from user
 */

void emit_read(ASTNode *p, FILE *fp) {
    
    emit_identifier(p->s1,fp); //store into $a0
    emit(fp,"","li $v0, 5"," #  read the num");
    emit(fp,"","syscall","#system call for reading the num");
    emit(fp,"","sw $v0, ($a0)", " # store the read into a mem location");
    emit(fp,"","",""); //$v0 has the value read in
    
}//end emit_write


/* emit_write
 * PRE: a pointer to a write statement found in emit_AST
 * POST: MIPS code that will write the given expr or string
 */
void emit_write(ASTNode *p, FILE *fp) {
    char s[100];
    //print expr after storing in a0 using emit_expr
    if(p->s1 != NULL) {
        emit_expr(p->s1, fp);
        emit(fp,"","li $v0 1"," #  Print the num");
        emit(fp,"","syscall","#  system call for printing num");
        emit(fp,"","","");
    }
    //print a string using the label
    else if(p->label != NULL) {
        sprintf(s,"la $a0, %s", p->label);
        emit(fp,"","li $v0, 4", "# Printing string");
        emit(fp,"",s, "# use the label to print string");
        emit(fp,"","syscall","# print the string ");
        emit(fp,"","","");
    }
    
}//end emit_write


/* emit_if
 * PRE: a pointer to an if statement found in emit_AST 
 * POST: MIPS code that compares values to see if it should branch or not 
 */
void emit_if(ASTNode *p, FILE *fp) {
    char s[100];
    char *L1, *L2;
    L1 = genlabel();
    L2 = genlabel();
    
    emit(fp,L1,"","");
    emit(fp,"","li $t0 0","# load t0 with 0 to compare with a0");
    emit_expr(p->s1,fp);
    sprintf(s,"beq $a0 $t0 %s",L2);
    emit(fp,"",s,"# branch if the expr is 0");
    emit_AST(p->s2,fp);
    if(p->type == whilestmt) { //if node is a while statement then jump back
        sprintf(s,"j %s",L1);
        emit(fp,"",s,"# jump back to start of while ");
    }
    emit(fp,L2,"","");
    
}//end emit_while

/* emit_ifelse
 * PRE: Takes a ASTNode of an ifelse statment and pointer to the file
 * POST: Writes MIPS code for an if else stmt using labels jumps and beq
 */
void emit_ifelse(ASTNode *p, FILE *fp) {
    char s[100];
    char *L1, *L2; //labels
    L1 = genlabel();
    L2 = genlabel();
    
    emit_expr(p->s1, fp);
    emit(fp,"","li $t0 0","# store t0 with 0 to compare");
    sprintf(s,"beq $a0 $t0 %s",L1);
    emit(fp,"",s," # branch to L1 if a0 == 0");
    emit_AST(p->s2->s1, fp);
    sprintf(s,"j %s",L2);
    emit(fp,"",s,"# jump to L2");
    
    emit(fp,L1,"","# else part of if");
    emit_AST(p->s2->s2, fp);
    
    emit(fp,L2,"","#end of if");
}//end emit_ifelse


/* emit_identifier
 * PRE: takes a pointer to an identifier node and a file
 * POST: MIPS code that adds the stack pointer(sp) with the symbols offset * word size(4) and stores that value in a0
 */
void emit_identifier(ASTNode *p, FILE *fp){
    char s[100];
    if(p->s1 == NULL && p->symbol->level != 0) { // the variable is scalar
        sprintf(s, "add $a0, $sp, %d", p->symbol->offset * WSIZE);
        emit(fp,"",s," # identifier is a scalar");
        emit(fp,"","","");
    }
    else if(p->s1 != NULL && p->symbol->level != 0){ //the variable is an array
        emit_expr(p->s1,fp);
        emit(fp,"","sll $t3 $a0 2","# shift logical left twice to mulitply by 4");
        sprintf(s,"li $a0 %d",p->symbol->offset * WSIZE);
        emit(fp,"",s,"# load offset");
        emit(fp,"","add $a0 $a0 $sp","# add stack pointer puls offset");
        emit(fp,"","add $a0 $a0 $t3","# add the index with the sp + offset");
        emit(fp,"","","");
    }
    else if(p->s1 == NULL && p->symbol->level == 0) { //global scalar
        sprintf(s,"la $a0 %s",p->name);
        emit(fp,"",s,"# load global variable from data into a0");
        emit(fp,"","","");
    }
    else { //global array 
        emit_expr(p->s1,fp);
        emit(fp,"","sll $t3 $a0 2","# shift logical left twice to multiply by 4");
        sprintf(s,"la $a0 %s",p->name);
        emit(fp,"",s,"# load a0 with address");
        emit(fp,"","add $a0 $a0 $t3","# array mem address plus index");
    }
    
    
}//end emit_identifier

/* emit_expr
 * PRE: a pointer to an expression to an expression as defined in the YACC language
 * POST: MIPS code that sets $a0 to the value of pointer
 */
void emit_expr(ASTNode *p, FILE *fp) {
    char s[100];
    //base cases
    if(p == NULL)
        return;
    switch(p->type) {
        
        case myNum:
            sprintf(s,"li $a0, %d", p->size);
            emit(fp, "",s, "# expression is a NUM");
            return;
            break;
            
        case mybool:
            sprintf(s,"li $a0, %d", p->size);
            emit(fp, "",s, "# expression is a BOOLEAN");
            return;
            break;
            
        case identifier:
            emit_identifier(p,fp); //$a0 is the address 
            emit(fp,"","lw $a0, ($a0)", "#  fetch value for identifier");
            return;
            break;
            
        case call:
            //emit_call(p,fp);
            return;
            break;
                    
    }//end switch
    emit_expr(p->s1, fp);
    //in s1
    sprintf(s,"sw $a0, %d($sp)",p->symbol->offset*WSIZE);
    emit(fp,"",s," # store in a0 sp + offset");
    
    emit_expr(p->s2,fp);
    //in s2
    emit(fp,"","move $a1 $a0","# move a0 into a1");
    sprintf(s,"lw $a0 %d($sp)", p->symbol->offset*WSIZE);
    emit(fp,"",s,"# load a0 with the symbols offset + stack pointer");
    
 	//   perform  calculation   ADD A0 A0 A1
    switch(p->operator) {
        case plus: 
            emit(fp,"","add $a0, $a0, $a1","# add the two values together into a0");
            break;
            
        case minus:
            emit(fp,"","sub $a0, $a0, $a1","# subtract the two values into a0");
            break;
            
        case times:
            emit(fp,"","mult $a0 $a1","# multiply the two values");
            emit(fp,"","mflo $a0","# hold the lower value in a0");
            break;
            
        case divide:
            emit(fp,"","div $a0 $a1","# divide the two values");
            emit(fp,"","mflo $a0","# hold the lower value in a0");
            break;
            
        case greaterEqual:
            emit(fp,"","sge $a0, $a0, $a1","# set a0 with 1 if a0 >= a1 else set to 0");
            break;
            
        case lessEqual:
            emit(fp,"","sle $a0, $a0, $a1","# set a0 with 1 if a0 <= a1 else set to 0");
            break;
            
        case equal:
            emit(fp,"","seq $a0, $a0, $a1","# set a0 with 1 if a0 == a1 else set to 0");
            break;
            
        case notEqual:
            emit(fp,"","sne $a0, $a0, $a1","# set a0 with 1 if a0 != a1 else set to 0");
            break;
            
        case less:
            emit(fp,"","slt $a0, $a0, $a1","# set a0 with 1 if a0 < a1 else set to 0");
            break;
            
        case greater:
            emit(fp,"","sgt $a0, $a0, $a1","# set a0 with 1 if a0 < a1 else set to 0");
            break;

        case myAnd:
            emit(fp,"","and $a0 $a0 $a1","# and");
            break;
            
        case myOr:
            emit(fp,"","or $a0 $a0 $a1","# or");
            break;
            
        case myNot:
            emit(fp,"","stlui $a0 $a0 1", "# ");
            break;

    }//end switch
}//end emit_expr


void emit_function_return(ASTNode *p, FILE *fp) {
    
    if(p != NULL) {
       //evaluate the expr
        emit_expr(p,fp); //this leaves $a0 with the result
    }
    
    //if it is NULL do nothing with $a0
    
    emit(fp,"","","");
    emit(fp,"","lw $ra, 4($sp)", "# restore RA");
    emit(fp,"","lw $sp, ($sp)", "# restore SP");
    emit(fp,"","","");
    
    if(strcmp(CURR_FUNCTION,"main") == 0) {
        emit(fp, "", "li $v0, 10", "  # Leave Main program");
        emit(fp,"","syscall", "# ");
    }
    else {
        //use JUMP to go back to where $ra references
        emit(fp,"","jr $ra","#jumb back to where $ra references");
    }
    
}//end emit_function_return

void emit_function_head(ASTNode *p, FILE *fp) {
    
    char s[100];
    emit(fp,p->name,"","\t# start of Function");
    CURR_FUNCTION = p->name;
    //build stack pointer movement
    sprintf(s,"subu $a0, $sp, %d", p->size*WSIZE);
    emit(fp, "", s, "# adjust the stack for function setup");
    emit(fp, "", "sw $sp, ($a0)","");
    emit(fp, "", "sw $ra, 4($a0)","");
    emit(fp, "", "move $sp, $a0","");
    emit(fp,"","","");
    
}// end emit_function_head


/* emit_AST
 * PRE: a pointer to the AST
 * POST: Calls functions to write MIPS code for the give node type
 */
void emit_AST(ASTNode *p, FILE *fp) {
    if (p == NULL) return;
    char s[100];
    switch (p->type) {
        
        case vardec:
            break;
        
        case fundec: 
            emit_function_head(p, fp);
            emit_AST(p->s2,fp);
            emit_function_return(NULL, fp);
            break;
                     
        case param:
            break;
            
        case block:   
            emit_AST(p->s2,fp);
            break;
            
        case expr:
            emit_expr(p, fp);
            break;
                      
        case myWrite:
            emit_write(p, fp);
            break;
                      
        case myRead:  
            emit_read(p, fp);
            break;
                      
        case assignstmt:
            emit_expr(p->s2, fp); // find the value on the rhs and it will be stored in a0
            emit(fp,"","move $a1 $a0", "# move the value of the right hand side to use a for the variable"); // store number into a1 to use a0 for the id
            emit_identifier(p->s1, fp); //stores location of var in a0
            emit(fp,"","sw $a1 ($a0)","# store value into var "); //store the number from a1 into mem location of a0(ID)
            break;
            
        case selecstmt:
            emit_if(p,fp);
            break;
            
        case ifelse:
            emit_ifelse(p,fp);
            break;
        
        case ifelse1:
            break;
            
        case whilestmt:
            emit_if(p,fp);
            break;
            
        case exprstmt:
            emit_expr(p->s1,fp);
            break;
            
            
        default: printf("EMIT AST Type not implemented\n");
        
        
        
    }//end switch
    emit_AST(p->next,fp);
}//end EMITAST


/* emit_strings
 * PRE: takes a pointer to the AST and a file
 * POST: MIPS code that creates any strings found in source code
 */
void emit_strings(ASTNode *p, FILE *fp) {
    if(p == NULL)
        return;
    
    char s[100];
    if((p->type == myWrite) && (p->name != NULL)){
        sprintf(s, ".asciiz\t%s",p->name);
        emit(fp,p->label,s,"# string");
    }
    
    emit_strings(p->next, fp);
    emit_strings(p->s1, fp);
    emit_strings(p->s2, fp);

}//end emit_strings


/* emit_globals
 * PRE: a pointer to the AST
 * POST: MIPS code that sets any global variables 
 */
void emit_globals(ASTNode *p, FILE *fp) {
    char s[100];
    
    if(p == NULL)
        return;
    //only find vardecs with level 0(global)
    if( (p->type == vardec) && (p->symbol->level == 0) ) {
        sprintf(s,".space %d",p->size *WSIZE);
        emit(fp,p->symbol->name, s, "# global variable");
        emit(fp,"","","");
        
    }
    emit_globals(p->next,fp);
    emit_globals(p->s1,fp);
    
}//end find_globals


/* genlabel
 * PRE: 
 * POST: Creates and returns a char used as a label in other functions
 */
char * genlabel() {
    char s[100];
    char *s1;
    sprintf(s,"_L%d",GLABEL++);
    s1 = strdup(s);
    return s1;
}//end genlabel
