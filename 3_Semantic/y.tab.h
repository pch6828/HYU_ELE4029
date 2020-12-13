/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    INT = 259,
    RETURN = 260,
    VOID = 261,
    WHILE = 262,
    PLUS = 263,
    MINUS = 264,
    TIMES = 265,
    OVER = 266,
    LT = 267,
    LE = 268,
    GT = 269,
    GE = 270,
    EQ = 271,
    NE = 272,
    ASSIGN = 273,
    SEMI = 274,
    COMMA = 275,
    LPAREN = 276,
    RPAREN = 277,
    LCURLY = 278,
    RCURLY = 279,
    LBRACE = 280,
    RBRACE = 281,
    ID = 282,
    NUM = 283,
    LETTER = 284,
    DIGIT = 285,
    ERROR = 286,
    NO_ELSE = 287,
    ELSE = 288
  };
#endif
/* Tokens.  */
#define IF 258
#define INT 259
#define RETURN 260
#define VOID 261
#define WHILE 262
#define PLUS 263
#define MINUS 264
#define TIMES 265
#define OVER 266
#define LT 267
#define LE 268
#define GT 269
#define GE 270
#define EQ 271
#define NE 272
#define ASSIGN 273
#define SEMI 274
#define COMMA 275
#define LPAREN 276
#define RPAREN 277
#define LCURLY 278
#define RCURLY 279
#define LBRACE 280
#define RBRACE 281
#define ID 282
#define NUM 283
#define LETTER 284
#define DIGIT 285
#define ERROR 286
#define NO_ELSE 287
#define ELSE 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
