//emit.h 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef EMIT_H
#define EMIT_H

#include "AST.h"
#include "symtable.h"
#define WSIZE 4
#define LOGWSIZE 2

static int GLABEL=0;

char * genlabel();
void emit_strings(ASTNode *p, FILE *fp);
void emit_AST(ASTNode *p, FILE *fp);
void emit_expr(ASTNode *p, FILE *fp);
void emit_identifier(ASTNode *p, FILE *fp);
void emit_globals(ASTNode *p, FILE *fp);

#endif
