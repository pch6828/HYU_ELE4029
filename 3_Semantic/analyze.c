/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "util.h"
#include "symtab.h"
#include "analyze.h"

/* counter for variable memory locations */
static int location = 0;
char* scopename = "global";
/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (t != NULL)
  { preProc(t);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t)
{ if (t==NULL) return;
  else return;
}

static void popProc(TreeNode * t)
{
  if (t->nodekind==StmtK&&t->kind.stmt==CompK){
    popstack();
  }else if(t->nodekind==DeclK&&t->kind.decl==FunK){
    scopename = "global";
  }
}

static void declError(TreeNode * t, char * message)
{ fprintf(listing,"Declaration error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}

static void scopeError(TreeNode * t, char * name)
{ fprintf(listing,"Undeclared symbol \"%s\" at line %d\n",name, t->lineno);
  Error = TRUE;
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */

int function_body = 0;

static void insertIO()
{
  Scope global = pushstack(scopename);
  ScopeStack tos = top();
  st_insert(global, "input", IntFunction, 0, tos->cnt++);
  st_insert(global, "output", VoidFunction, 0, tos->cnt++);
  BucketList output = st_lookup(global, "output");
  addparam(output, Integer);
}

static void insertNode( TreeNode * t)
{ 
  ScopeStack tos = top();
  Scope scope = tos->scope;
  BucketList l, func;
  char message[100];
  switch (t->nodekind)
  { 
    case StmtK:
      switch (t->kind.stmt)
      { 
        case CompK:
          if(function_body == 0){
            t->scope = pushstack(scopename);
          }
          function_body = 0;
          break;
        default:
          t->scope = scope;
          break;
      }
      break;
    case DeclK:
      switch (t->kind.decl)
      {
        case VarK:
          if ((long long int)(st_lookup_excluding_parent(scope, t->attr.decl.name)) == -1){
            if(t->attr.decl.type!=VOID){
              st_insert(scope, t->attr.decl.name, Integer, t->lineno, tos->cnt++);
            }else{
              sprintf(message, "variable type cannot be void (name : %s)", t->attr.decl.name);
              declError(t, message);
            }
          }else{
            sprintf(message, "re-declaration of symbol (name : %s)", t->attr.decl.name);
            declError(t, message);
          }
          t->scope = scope;
          break;
        case FunK:
          if ((long long int)(st_lookup_excluding_parent(scope, t->attr.decl.name)) == -1){
            if(t->attr.decl.type==VOID){
              st_insert(scope, t->attr.decl.name, VoidFunction, t->lineno, tos->cnt++);
            }else{
              st_insert(scope, t->attr.decl.name, IntFunction, t->lineno, tos->cnt++);
            }
          }else{
            sprintf(message, "re-declaration of symbol (name : %s)", t->attr.decl.name);
            declError(t, message);
          }
          scopename = t->attr.decl.name;
          t->scope = pushstack(scopename);
          function_body = 1;
          break;
        case ArrVarK:
          if ((long long int)(st_lookup_excluding_parent(scope, t->attr.decl.name)) == -1){
            if(t->attr.decl.type!=VOID){
              st_insert(scope, t->attr.decl.name, IntegerArray, t->lineno, tos->cnt++);
            }else{
              sprintf(message, "variable type cannot be void (name : %s)", t->attr.decl.name);
              declError(t, message);
            }
          }else{
            sprintf(message, "re-declaration of symbol (name : %s)", t->attr.decl.name);
            declError(t, message);
          }
          t->scope = scope;
          break;
        default:
          t->scope = scope;
          break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { 
        case IdK:
          if ((long long int)((l = st_lookup(scope, t->attr.name))) == -1)
            ;
          else
          /* already in table, so ignore location, 
             add line number of use only */ 
            addlineno(l, t->lineno);
          t->scope = scope;
          break;
        case ArrIdK:
          if ((long long int)((l = st_lookup(scope, t->attr.name))) == -1)
            ;
          else
          /* already in table, so ignore location, 
             add line number of use only */ 
            addlineno(l, t->lineno);
          t->scope = scope;
          break;
        case CallK:
          if ((long long int)((l = st_lookup(scope, t->attr.name))) == -1)
            ;
          else
          /* already in table, so ignore location, 
             add line number of use only */ 
            addlineno(l, t->lineno);
          t->scope = scope;
          break;
        default:
          t->scope = scope;
          break;
      }
      break;
    case ParamK:
      func = st_lookup(getglobal(), scopename);
      switch (t->kind.param)
      {
        case ArrParamK:
          if ((long long int)(st_lookup_excluding_parent(scope, t->attr.decl.name)) == -1){
            if(t->attr.decl.type!=VOID){
              st_insert(scope, t->attr.decl.name, IntegerArray, t->lineno, tos->cnt++);
            }else{
              sprintf(message, "parameter type cannot be void (name : %s)", t->attr.decl.name);
              declError(t, message);
            }
          }else{
            sprintf(message, "re-declaration of symbol (name : %s)", t->attr.decl.name);
            declError(t, message);
          }
          addparam(func, IntegerArray);
          t->scope = scope;
          break;
        case NonArrParamK:
          if(t->attr.decl.name==NULL){
            break;
          }
          if ((long long int)(st_lookup_excluding_parent(scope, t->attr.decl.name)) == -1){
            if(t->attr.decl.type!=VOID){
              st_insert(scope, t->attr.decl.name, Integer, t->lineno, tos->cnt++);
            }else{
              sprintf(message, "parameter type cannot be void (name : %s)", t->attr.decl.name);
              declError(t, message);
            }
          }else{
            sprintf(message, "re-declaration of symbol (name : %s)", t->attr.decl.name);
            declError(t, message);
          }
          addparam(func, Integer);
          t->scope = scope;
          break;
        default:
          t->scope = scope;
          break;
      }
      break;
    default:
      break;
  }
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ 
  insertIO();
  traverse(syntaxTree,insertNode,popProc);
  if (TraceAnalyze)
  { fprintf(listing,"\nSymbol table:\n\n");
    printSymTab(listing);
  }
}

static void typeError(TreeNode * t, char * message)
{ fprintf(listing,"Type error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode * t)
{ 
  BucketList l;
  char* name;
  switch (t->nodekind)
  { 
    case ExpK:
      switch (t->kind.exp)
      { 
        case OpK:
          if ((t->child[0]->type != Integer) || (t->child[1]->type != Integer)){
            typeError(t,"invalid expression");
          }
          t->type = Integer;
          break;
        case ConstK:
          t->type = Integer;
          break;
        case IdK:
          if ((long long int)((l = st_lookup(t->scope, t->attr.name)))==-1 || l->lines->lineno > t->lineno){
            scopeError(t, t->attr.name);
            t->type = Invalid;
          }else{
            t->type = l->type;
          }
          break;
        case ArrIdK:
          if ((long long int)((l = st_lookup(t->scope, t->attr.name)))==-1 || l->lines->lineno > t->lineno){
            scopeError(t, t->attr.name);
            t->type = Invalid;
          }else if(t->child[0]->type != Integer){
            typeError(t, "invalid array index");
          }else{
            t->type = Integer;
          }
          break;
        case AssignK:
          if ((t->child[0]->type != Integer) || (t->child[1]->type != Integer)){
            typeError(t,"invalid expression");
            t->type = Invalid;
          }else{
            t->type = Integer;
          }
          break;
        case CallK:
          if ((long long int)((l = st_lookup(t->scope, t->attr.name))) == -1 || l->lines->lineno > t->lineno){
            scopeError(t, t->attr.name);
          }else{
            TreeNode* args = t->child[0];
            ParamList params = l->params;
            while(args && params){
              if(args->type!=params->type){
                typeError(t, "wrong parameter type");
              }
              args = args->sibling;
              params = params->next;
            }
            if(args!=NULL || params!=NULL){
              typeError(t, "invalid function call");
            }
            t->type = (l->type==IntFunction?Integer:Void);
          }
          break;
        default:
          break;
      }
      break;
    case StmtK:
      switch (t->kind.stmt)
      { 
        case IfK:
          if (t->child[0]->type != Integer)
            typeError(t->child[0],"if test is not Boolean");
          break;
        case IterK:
          if (t->child[0]->type != Integer)
            typeError(t->child[0],"while test is not Boolean");
          break;
        case ReturnK:
          name = t->scope->name;
          l = st_lookup(t->scope, name);
          if (l->type==VoidFunction && t->child[0]!=NULL){
            typeError(t,"invalid return type");
          }else if(l->type==IntFunction && (t->child[0]==NULL || t->child[0]->type!=Integer)){
            typeError(t,"invalid return type");
          }
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)
{ traverse(syntaxTree,nullProc,checkNode);
}
