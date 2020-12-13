/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

Scope scopelist = NULL;
ScopeStack stack = NULL;

Scope getglobal(){
  ScopeStack iter = stack;
  while(iter->next){
    iter = iter->next;
  }
  return iter->scope;
}

void addparam(BucketList func, ExpType type){
  ParamList temp = (ParamList)malloc(sizeof(struct ParamListRec));
  temp->next = NULL;
  temp->type = type;
  ParamList iter = func->params;
  if(iter == NULL){
    func->params = temp;
    return;
  }
  while(iter->next){
    iter = iter->next;
  }
  iter->next = temp;
}

ScopeStack top(){
  if(stack==NULL){
    stack = (ScopeStack)malloc(sizeof(struct ScopeStackRec));
    memset(stack, 0, sizeof(struct ScopeStackRec));
  }
  return stack->next;
}

Scope pushstack(char* name){
  if(stack==NULL){
    stack = (ScopeStack)malloc(sizeof(struct ScopeStackRec));
    memset(stack, 0, sizeof(struct ScopeStackRec));
  }
  ScopeStack temp = (ScopeStack)malloc(sizeof(struct ScopeStackRec));
  temp->cnt = 0;
  Scope scope = (Scope)malloc(sizeof(struct ScopeListRec));
  memset(scope, 0, sizeof(struct ScopeListRec));
  scope->name = name;
  if(scopelist){
    Scope iter = scopelist;
    while(iter->next){
      iter = iter->next;
    }
    iter->next = scope;
  }else{
    scopelist = scope;
  }
  ScopeStack tos = top();
  if(tos){
    scope->parent = tos->scope;
  }
  temp->scope = scope;
  temp->next = stack->next;
  stack->next = temp;
  
  return scope;
}

void popstack(){
  if(stack && stack->next){
    stack->next = stack->next->next;
  }
}

void addlineno(BucketList l, int lineno){
  LineList t = l->lines;
  while (t->next != NULL) t = t->next;
  t->next = (LineList) malloc(sizeof(struct LineListRec));
  t->next->lineno = lineno;
  t->next->next = NULL;  
}

/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* the hash table */
static BucketList hashTable[SIZE];

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( Scope scope, char * name, ExpType type, int lineno, int loc )
{ int h = hash(name);
  BucketList l =  scope->bucket[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) /* variable not yet in table */
  { 
    l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->type = type;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->params = NULL;
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->lines->next = NULL;
    l->next = scope->bucket[h];
    scope->bucket[h] = l; 
  }
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
BucketList st_lookup ( Scope scope, char * name )
{ 
  if(scope==NULL){
    return (BucketList)(-1);
  }
  int h = hash(name);
  BucketList l = scope->bucket[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) return st_lookup(scope->parent, name);
  else return l;
}

/* Function st_lookup_excluding_parent returns the memory 
 * location of a variable or -1 if not found
 */
BucketList st_lookup_excluding_parent ( Scope scope, char * name )
{ 
  int h = hash(name);
  BucketList l = scope->bucket[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) return (BucketList)(-1);
  else return l;
}

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing)
{ int i;
  fprintf(listing,"Variable Name  Variable Type  Scope Name  Location   Line Numbers\n");
  fprintf(listing,"-------------  -------------  ----------  --------   ------------\n");
  Scope iter = scopelist;
  while(iter){
    for (i=0;i<SIZE;++i)
    { 
      if (iter->bucket[i] != NULL)
      { BucketList l = iter->bucket[i];
        while (l != NULL)
        { LineList t = l->lines;
          fprintf(listing,"%-13s  ",l->name);
          fprintf(listing,"%-13s  ",(l->type==Integer?"Integer":(l->type==IntegerArray?"Integer array":"Function")));
          fprintf(listing,"%-10s  ",iter->name);
          fprintf(listing,"%-8d  ",l->memloc);
          while (t != NULL)
          { fprintf(listing,"%4d ",t->lineno);
            t = t->next;
          }
          fprintf(listing,"\n");
          l = l->next;
        }
      }
    }
    iter = iter->next;
  }
} /* printSymTab */
