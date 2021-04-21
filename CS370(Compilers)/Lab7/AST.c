/* Santiago Flores
 * FILE: AST.c
 * 
 * This c file uses three functions:
 *  ASTCreateNode - To create a new node inside of the yacc file with the given nodetype
 *  ASTprint - Prints out the entire tree created in yacc using a switch to find the correct node and neatly print it out to see if the tree is correct
 *  printSpaces - Helps ASTprint by printing spaces to make the tree print out more readable and understandable
 * 
 * NEW
 * ASTprint now prints the offset of variable declarations through struct SymbTab
 * check_params used to check if the given parameters of a called function match the actual declared parameters of a fucntion
 */

#include <stdio.h>
#include "symtable.h"
#include <malloc.h>
#include "AST.h"


//function to create node setting everything to NULL by default
ASTNode * ASTCreateNode(enum NODETYPE DesiredType){
    ASTNode *p;
    p = (ASTNode *)(malloc(sizeof (struct ASTNodeType) ) );
    p->type = DesiredType;
    p->next = NULL;
    p->s1 = NULL;
    p->s2 = NULL;
    p->symbol = NULL;
    p->size = 0;
    return p;
}//end ASTCreateNode
//check params 
//1 if good
//0 if bad
//check to see if the paramters of a called function match the parameters of the actual function
int check_params(ASTNode *f, ASTNode *a) {
    if(f == NULL && a == NULL)
        return 1;
    if(f == NULL || a == NULL)
        return 0;
    if(f->sem_type != a->sem_type)
        return 0;
    return check_params(f->next, a->next);
}//end check_params

//function to print spacing to make the output more readable
void printSpaces(int num){
    for(int i = 0; i < num; i++)
        printf("  ");
}//end printSpaces

//function to print out the tree using a switch to print when the node is found
void ASTprint(ASTNode *p, int level){
    if(p == NULL)return;
    
    printSpaces(level);
    switch(p->type){
        case vardec:        printf("VARIABLE ");        //prints VARIABLE TYPE ID'[]'
                            if(p->operator == intType)
                                printf("INT ");
                            if(p->operator == boolType)
                                printf("BOOLEAN ");
                            if(p->operator == voidType)
                                printf("VOID ");
                            printf("%s", p->name);
                            //if the size is bigger than 1 it is an array so print brackets
                            if(p->size > 1)
                                printf("[%d] ",p->size);
                            printf(" with offset %d\n",p->symbol->offset);
                            printf("\n");
                            ASTprint(p->s1,level); //print out the list of variables in declaration wasnt a list, p will be null and return
                            break;
                     
        case fundec:        if(p->operator == intType)
                                printf("INT ");
                            if(p->operator == boolType)
                                printf("BOOLEAN ");
                            if(p->operator == voidType)
                                printf("VOID ");
                            printf("FUNCTION %s with max offset %d\n", p->name, p->symbol->mysize);
                            if(p->s1 == NULL)
                                printf(" (VOID) \n");
                            else{
                                printf("( \n");
                                ASTprint(p->s1, level+1);
                                printf(")\n");
                            }//end else
                            
                            ASTprint(p->s2, level+1);
                            printf("\n");
                            break;
                     
        case param:         printf("PARAMETER ");
                            if(p->operator == intType)
                                printf("INT ");
                            if(p->operator == boolType)
                                printf("BOOLEAN ");
                            if(p->operator == voidType)
                                printf("VOID ");
                            printf("%s",p->name);
                            if(p->size == -1)
                                printf("[]");
                            printf("\n");
                            break;
                    
        case block:         printf("BLOCK STATMENT\n");
                            ASTprint(p->s1, level+1);
                            ASTprint(p->s2, level+1);
                            break;
                            
        case selecstmt:     printf("IF STATMENT\n");
                            ASTprint(p->s1, level+1);
                            printSpaces(level);
                            printf("THEN \n");
                            ASTprint(p->s2, level+1);
                            break;
            
        case ifelse:        printf("IF \n");
                            ASTprint(p->s1, level+1);
                            ASTprint(p->s2, level+1);
                            break;
                            
        case ifelse1:       printf("THEN \n");
                            ASTprint(p->s1, level+1);
                            printSpaces(level);
                            printf("ELSE \n");
                            ASTprint(p->s2, level+1);
                            break;
                            
        case myWrite:       printf("WRITE STATMENT \n");
                            ASTprint(p->s1, level+1);
                            break;
                            
        case myRead:        printf("READ STATMENT \n");
                            ASTprint(p->s1, level+1);
                            break;
                            
        case myNum:         printf("NUMBER WITH VALUE %d\n", p->size);
                            break;
                            
        case expr:          printf("EXPR ");
                            switch(p->operator) {
                                case plus:          printf(" + ");
                                                    break;
                                case minus:         printf(" - ");
                                                    break;
                                case times:         printf(" * ");
                                                    break;
                                case divide:        printf(" / ");
                                                    break;
                                case greaterEqual:  printf(" >= ");
                                                    break;
                                case lessEqual:     printf(" <= ");
                                                    break;
                                case equal:         printf(" == ");
                                                    break;
                                case notEqual:      printf(" != ");
                                                    break;
                                case less:          printf(" < ");
                                                    break;
                                case greater:       printf(" > ");
                                                    break;
                                case myAnd:         printf(" AND ");
                                                    break;
                                case myOr:          printf(" OR ");
                                                    break;
                                case myNot:         printf(" NOT ");
                                                    break;
                            }//end case operator
                            printf("\n");
                            ASTprint(p->s1, level+1);
                            if(p->operator != myNot)
                                ASTprint(p->s2, level+1);
                            break;
                    
        case whilestmt:     printf("WHILE ( \n");
                            ASTprint(p->s1, level+1);
                            printSpaces(level);
                            printf(")END WHILE \n");
                            printSpaces(level);
                            printf("DO (\n");
                            ASTprint(p->s2, level+1);
                            printSpaces(level);
                            printf(")END DO \n");
                            break;
            
        case myReturn:      printf("RETURN \n");
                            ASTprint(p->s1, level+1);
                            break;
                            
        case assignstmt:    printf("ASSIGNMENT STATMENT\n");
                            ASTprint(p->s1, level+1);
                            ASTprint(p->s2, level+1);
                            break;
        
        case identifier:    printf("IDENTIFIER %s\n", p->name);
                            if(p->s1 != NULL){
                                printSpaces(level);
                                printf("ARRAY REFERENCE [\n");
                                ASTprint(p->s1, level+1);
                                printSpaces(level);
                                printf("] END ARRAY\n");
                            }//end if
                            break;
                    
        case call:          printf("CALL %s (\n",p->name);
                            ASTprint(p->s1, level+1);
                            printSpaces(level);
                            printf(")END CALL\n");
                            break;
                            
        case mybool:        if(p->size)         //if 1 print true else print false
                                printf("TRUE\n");
                            else
                                printf("FALSE\n");
                            break;
        case arg:           printf("ARG \n");
                            ASTprint(p->s1, level+1);
                            break;
                            
        case exprstmt:      printf("EXPRESSION STMT\n");
                            ASTprint(p->s1, level+1);
                            break;
                    
        default:            printf("Unknown type in ASTprint \n");
        
    }//end switch
    
    ASTprint(p->next, level);

}//end ASTprint
