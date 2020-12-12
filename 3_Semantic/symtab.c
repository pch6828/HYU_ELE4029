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

typedef struct ScopeStack{
    Scope scope;
    int cnt;
    struct ScopeStack* next;
}* Stack;

Scope scopelist = NULL;
Stack stack = NULL;

Stack top(){
  if(stack==NULL){
    stack = (Stack)malloc(sizeof(struct ScopeStack));
    memset(stack, 0, sizeof(struct ScopeStack));
  }
  return stack->next;
}

Scope pushstack(){
  if(stack==NULL){
    stack = (Stack)malloc(sizeof(struct ScopeStack));
    memset(stack, 0, sizeof(struct ScopeStack));
  }
  Stack temp = (Stack)malloc(sizeof(struct ScopeStack));
  temp->cnt = 0;
  Scope scope = (Scope)malloc(sizeof(struct ScopeListRec));
  memset(scope, 0, sizeof(struct ScopeListRec));
  
  if(scopelist){
    Scope iter = scopelist;
    while(iter->next){
      iter = iter->next;
    }
    iter->next = scope;
  }else{
    scopelist = scope;
  }
  Stack tos = top();
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
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->lines->next = NULL;
    l->next = scope->bucket[h];
    scope->bucket[h] = l; 
  }
  else /* found in table, so just add line number */
  { 
    LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
  }
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( Scope scope, char * name )
{ 
  if(scope==NULL){
    return -1;
  }
  int h = hash(name);
  BucketList l = scope->bucket[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) return st_lookup(scope->parent, name);
  else return l->memloc;
}

/* Function st_lookup_excluding_parent returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( Scope scope, char * name )
{ 
  int h = hash(name);
  BucketList l = scope->bucket[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) return -1;
  else return l->memloc;
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
          fprintf(listing,"%-10d  ",iter->name);
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
