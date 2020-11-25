/****************************************************/
/* File: cminus.y                                   */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedNum;
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void); // added 11/2/11 to ensure no conflict with lex
int yyerror(char * message);

%}

%token IF INT RETURN VOID WHILE
%left PLUS MINUS TIMES OVER 
%token LT LE GT GE EQ NE ASSIGN SEMI COMMA 
%token LPAREN RPAREN LCURLY RCURLY LBRACE RBRACE 
%token ID NUM LETTER DIGIT
%token ERROR 

%nonassoc NO_ELSE
%nonassoc ELSE

%% /* Grammar for CMINUS */

program               : declaration_list
                          { 
                            savedTree = $1;
                          } 
                      ;
declaration_list      : declaration declaration_list
                          { 
                            YYSTYPE now = $1;
                            if (now != NULL) {
                              while(now->sibling != NULL){
                                now = now->sibling;
                              }
                              now->sibling = $2;
                              $$ = $1;
                            }else{
                              $$ = $2;
                            }
                          }
                      | declaration
                          {
                            $$ = $1;
                          }
                      ;
declaration           : var_declaration
                          {
                            $$ = $1;
                          }
                      | fun_declaration
                          {
                            $$ = $1;
                          }
                      ;
identifier            : ID 
                          { 
                            savedName = copyString(tokenString);
                            savedLineNo = lineno; 
                          }
                      ;
number                : NUM
                          {
                            savedNum = atoi(tokenString);
                            savedLineNo = lineno;
                          }
                      ;
var_declaration       : VOID identifier SEMI
                          {
                            $$ = newDeclNode(VarK);
                            //save line #
                            $$->lineno = lineno;
                            //save name
                            $$->attr.decl.name = savedName;
                            $$->attr.decl.type = VOID;
                          }
                      | INT identifier SEMI
                          {
                            $$ = newDeclNode(VarK);
                            //save line #
                            $$->lineno = lineno;
                            //save name
                            $$->attr.decl.name = savedName;
                            $$->attr.decl.type = INT;
                          }
                      | VOID identifier LBRACE number RBRACE SEMI  
                          {
                            $$ = newDeclNode(ArrVarK);
                            //save line #
                            $$->lineno = lineno;
                            //save name and size
                            $$->attr.decl.name = savedName;
                            $$->attr.decl.type = VOID;

                            YYSTYPE size = newExpNode(ConstK);
                            size->attr.val = savedNum;
                            $$->child[0] = size;
                          }                      
                          | INT identifier LBRACE number RBRACE SEMI  
                          {
                            $$ = newDeclNode(ArrVarK);
                            //save line #
                            $$->lineno = lineno;
                            //save name and size
                            $$->attr.decl.name = savedName;
                            $$->attr.decl.type = INT;

                            YYSTYPE size = newExpNode(ConstK);
                            size->attr.val = savedNum;
                            $$->child[0] = size;
                          }
                      ;
fun_declaration       : INT identifier 
                          {
                            $$ = newDeclNode(FunK);
                            $$->lineno = savedLineNo;
                            $$->attr.decl.name = savedName;
                            $$->attr.decl.type = INT;
                          }
                        LPAREN params RPAREN compound_stmt  
                          {
                            $$ = $3;
                            //save type, parameters, body
                            $$->child[0] = $5;
                            $$->child[1] = $7;
                          } 
                      | VOID identifier 
                          {
                            $$ = newDeclNode(FunK);
                            $$->lineno = savedLineNo;
                            $$->attr.decl.name = savedName;
                            $$->attr.decl.type = VOID;
                          }
                        LPAREN params RPAREN compound_stmt  
                          {
                            $$ = $3;
                            //save type, parameters, body
                            $$->child[0] = $5;
                            $$->child[1] = $7;
                          } 
                      ;
params                : param_list 
                          {
                            $$ = $1;
                          }
                      | VOID
                          {
                            $$ = newParamNode(NonArrParamK);
                            //save type and name
                            $$->attr.decl.type = VOID;
                            $$->attr.decl.name = NULL;
                          }                  
                      ;    
param_list            : param_list COMMA param 
                          {
                            YYSTYPE now = $1;
                            if (now != NULL) {
                              while(now->sibling != NULL){
                                now = now->sibling;
                              }
                              now->sibling = $3;
                              $$ = $1;
                            }else{
                              $$ = $3;
                            }                        
                          }
                      | param   
                          {
                            $$ = $1;
                          }         
                      ;
param                 : INT identifier
                          {
                            $$ = newParamNode(NonArrParamK);
                            //save type and name
                            $$->attr.decl.type = INT;
                            $$->attr.decl.name = savedName;
                          }
                      | INT identifier LBRACE RBRACE
                          {
                            $$ = newParamNode(ArrParamK);
                            //save type and name
                            $$->attr.decl.type = INT;
                            $$->attr.decl.name = savedName;
                          }
                      | VOID identifier
                          {
                            $$ = newParamNode(NonArrParamK);
                            //save type and name
                            $$->attr.decl.type = VOID;
                            $$->attr.decl.name = savedName;
                          }
                      | VOID identifier LBRACE RBRACE
                          {
                            $$ = newParamNode(ArrParamK);
                            //save type and name
                            $$->attr.decl.type = VOID;
                            $$->attr.decl.name = savedName;
                          }
                      ; 
compound_stmt         : LCURLY local_declarations stmt_list RCURLY
                          {
                            $$ = newStmtNode(CompK);
                            $$->child[0] = $2;
                            $$->child[1] = $3;
                          }
                      ;
local_declarations    : local_declarations var_declaration
                          {
                            YYSTYPE now = $1;
                            if (now != NULL) {
                              while(now->sibling != NULL){
                                now = now->sibling;
                              }
                              now->sibling = $2;
                              $$ = $1;
                            }else{
                              $$ = $2;
                            }                            
                          }
                      | /*null*/
                          {
                            $$ = NULL;
                          }           
                      ;
stmt_list             : stmt_list stmt
                          {
                            YYSTYPE now = $1;
                            if (now != NULL) {
                              while(now->sibling != NULL){
                                now = now->sibling;
                              }
                              now->sibling = $2;
                              $$ = $1;
                            }else{
                              $$ = $2;
                            }
                          }
                      | /*null*/
                          {
                            $$ = NULL;
                          }  
                      ;
stmt                  : expression_stmt
                          {
                            $$ = $1;
                          }   
                      | compound_stmt
                          {
                            $$ = $1;
                          }   
                      | if_stmt
                          {
                            $$ = $1;
                          }                         
                      | iteration_stmt
                          {
                            $$ = $1;
                          }                         
                      | return_stmt
                          {
                            $$ = $1;
                          }  
                      ;     
expression_stmt       : expression SEMI
                          {
                            $$ = $1;
                          }
                      | SEMI        
                          {
                            $$ = NULL;
                          }         
                      ;
if_stmt               : IF LPAREN expression RPAREN stmt %prec NO_ELSE
                          { 
                            $$ = newStmtNode(IfK);
                            $$->child[0] = $3;
                            $$->child[1] = $5;
                            // mark child #2 because of "if-else" statement
                            $$->child[2] = NULL;
                          }
                      | IF LPAREN expression RPAREN stmt ELSE stmt
                          { 
                            $$ = newStmtNode(IfK);
                            $$->child[0] = $3;
                            $$->child[1] = $5;
                            $$->child[2] = $7;
                          }
                      ;
iteration_stmt        : WHILE LPAREN expression RPAREN stmt 
                          { 
                            $$ = newStmtNode(IterK);
                            $$->child[0] = $3;
                            $$->child[1] = $5;
                          }
                      ;
return_stmt           : RETURN SEMI
                          {
                            $$ = newStmtNode(ReturnK);
                            $$->child[0] = NULL;
                          }
                      | RETURN expression SEMI
                          {
                            $$ = newStmtNode(ReturnK);
                            $$->child[0] = $2;
                          }
                      ;
expression            : variable ASSIGN expression
                          {
                            $$ = newExpNode(AssignK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                          }
                      | simple_expression
                          {
                            $$ = $1;
                          }
                      ;
variable              : identifier
                          {
                            $$ = newExpNode(ArrIdK);
                            $$->attr.name = savedName;
                          }       
                        LBRACE expression RBRACE
                          {
                            $$ = $2;
                            $$->child[0] = $4;
                          }
                      | identifier
                          {
                            $$ = newExpNode(IdK);
                            $$->attr.name = savedName;
                          }
                      ;
simple_expression     : add_expression EQ add_expression
                          {
                            $$ = newExpNode(OpK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                            $$->attr.op = EQ;
                          }
                      | add_expression NE add_expression
                          {
                            $$ = newExpNode(OpK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                            $$->attr.op = NE;
                          }
                      | add_expression GT add_expression
                          {
                            $$ = newExpNode(OpK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                            $$->attr.op = GT;
                          }
                      | add_expression GE add_expression
                          {
                            $$ = newExpNode(OpK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                            $$->attr.op = GE;
                          }
                      | add_expression LT add_expression
                          {
                            $$ = newExpNode(OpK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                            $$->attr.op = LT;
                          }
                      | add_expression LE add_expression
                          {
                            $$ = newExpNode(OpK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                            $$->attr.op = LE;
                          }
                      | add_expression
                          {
                            $$ = $1;
                          }
                      ;

add_expression        : add_expression PLUS term 
                          { 
                            $$ = newExpNode(OpK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                            $$->attr.op = PLUS;
                          }
                      | add_expression MINUS term
                          { 
                            $$ = newExpNode(OpK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                            $$->attr.op = MINUS;
                          } 
                      | term { $$ = $1; }
                      ;
term                  : term TIMES factor 
                          { $$ = newExpNode(OpK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                            $$->attr.op = TIMES;
                          }
                      | term OVER factor
                          { $$ = newExpNode(OpK);
                            $$->child[0] = $1;
                            $$->child[1] = $3;
                            $$->attr.op = OVER;
                          }
                      | factor { $$ = $1; }
                      ;
factor                : LPAREN expression RPAREN
                          { 
                            $$ = $2; 
                          }
                      | variable
                          {
                            $$ = $1;
                          }
                      | NUM
                          { 
                            $$ = newExpNode(ConstK);
                            $$->attr.val = atoi(tokenString);
                          }
                      | call 
                          {
                            $$ = $1;
                          }
                      ;
call                  : identifier
                          {
                            $$ = newExpNode(CallK);
                            $$->attr.name = savedName;
                          }
                        LPAREN args RPAREN
                          {
                            $$ = $2;
                            $$->child[0] = $4;
                          }
                      ;
args                  : arg_list
                          {
                            $$ = $1;
                          }
                      | /*null*/
                          {
                            $$ = NULL;
                          }           
                      ;
arg_list              : arg_list COMMA expression
                          {
                            YYSTYPE now = $1;
                            if (now != NULL) {
                              while(now->sibling != NULL){
                                now = now->sibling;
                              }
                              now->sibling = $3;
                              $$ = $1;
                            }else{
                              $$ = $3;
                            }  
                          }
                      | expression
                          {
                            $$ = $1;
                          }
                      ;

%%

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

