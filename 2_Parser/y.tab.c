/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "cminus.y" /* yacc.c:339  */

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


#line 84 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 201 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    37,    37,    42,    55,    60,    64,    69,    75,    81,
      90,    99,   112,   127,   126,   141,   140,   155,   159,   167,
     180,   185,   192,   199,   206,   214,   221,   235,   239,   253,
     257,   261,   265,   269,   273,   278,   282,   287,   295,   303,
     310,   315,   321,   327,   333,   332,   342,   348,   355,   362,
     369,   376,   383,   390,   396,   403,   410,   412,   418,   424,
     426,   430,   434,   439,   445,   444,   455,   460,   464,   477
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "INT", "RETURN", "VOID", "WHILE",
  "PLUS", "MINUS", "TIMES", "OVER", "LT", "LE", "GT", "GE", "EQ", "NE",
  "ASSIGN", "SEMI", "COMMA", "LPAREN", "RPAREN", "LCURLY", "RCURLY",
  "LBRACE", "RBRACE", "ID", "NUM", "LETTER", "DIGIT", "ERROR", "NO_ELSE",
  "ELSE", "$accept", "program", "declaration_list", "declaration",
  "identifier", "number", "var_declaration", "fun_declaration", "@1", "@2",
  "params", "param_list", "param", "compound_stmt", "local_declarations",
  "stmt_list", "stmt", "expression_stmt", "if_stmt", "iteration_stmt",
  "return_stmt", "expression", "variable", "@3", "simple_expression",
  "add_expression", "term", "factor", "call", "@4", "args", "arg_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF -113

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-113)))

#define YYTABLE_NINF -65

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      45,   -18,   -18,    21,  -113,    45,  -113,  -113,  -113,   -12,
     -11,  -113,  -113,  -113,    10,     6,  -113,    10,    24,  -113,
      26,    57,    39,    57,    13,   -18,   -18,    76,    79,  -113,
      81,    80,  -113,    78,    82,    83,    88,  -113,    83,    75,
      84,  -113,  -113,   -18,  -113,  -113,  -113,  -113,    89,   -18,
     -18,  -113,    12,   -12,   -11,    87,    -3,    90,  -113,   -17,
    -113,  -113,     1,  -113,  -113,  -113,  -113,  -113,  -113,    85,
      91,  -113,    74,    31,  -113,  -113,   -17,  -113,    86,   -17,
      92,    93,    94,  -113,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,    95,  -113,    97,  -113,   -17,
     -17,  -113,  -113,    31,    31,    60,    60,    60,    60,    60,
      60,  -113,  -113,    43,    43,    96,  -113,    98,   101,    99,
    -113,  -113,  -113,   -17,    43,  -113,  -113
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     5,     6,     7,    13,
      15,     1,     3,    10,     0,     0,     9,     0,     0,     8,
       0,     0,     0,     0,     0,     0,    18,     0,    17,    20,
       0,     0,    12,    21,    23,     0,     0,    11,     0,     0,
       0,    27,    14,     0,    19,    16,    22,    24,    29,     0,
       0,    26,     0,     0,     0,     0,     0,     0,    36,     0,
      25,    62,    46,    31,    28,    30,    32,    33,    34,     0,
      61,    43,    53,    56,    59,    63,     0,    40,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,    60,     0,
      67,    42,    61,    54,    55,    51,    52,    49,    50,    47,
      48,    57,    58,     0,     0,     0,    69,     0,    66,    37,
      39,    45,    65,     0,     0,    68,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -113,  -113,   107,  -113,     4,   106,    65,  -113,  -113,  -113,
     102,  -113,   100,    -1,  -113,  -113,  -112,  -113,  -113,  -113,
    -113,   -56,   -13,  -113,  -113,   -32,    11,    -9,  -113,  -113,
    -113,  -113
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    62,    20,     6,     7,    15,    18,
      27,    28,    29,    63,    48,    52,    64,    65,    66,    67,
      68,    69,    70,    81,    71,    72,    73,    74,    75,    82,
     117,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      78,   119,   120,    80,    59,     9,    10,    13,    16,     8,
       8,    61,   126,    14,    17,    55,    77,    56,    59,    57,
      95,    11,   -64,    97,     8,    61,   -44,    21,   101,    33,
      34,    58,    32,    59,    42,    41,    60,    45,    19,     8,
      61,    93,    94,   115,   116,    23,    55,    34,    56,     1,
      57,     2,    24,    53,    54,   105,   106,   107,   108,   109,
     110,    25,    58,    26,    59,    30,    41,   125,    85,    86,
       8,    61,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,    85,    86,   111,   112,    87,    88,    89,    90,
      91,    92,    25,    49,    43,    50,   103,   104,    35,    36,
      37,    46,    38,    39,    83,    96,    41,    40,    76,    84,
      47,    79,    12,    51,    98,   100,     0,   113,    99,   114,
     122,   123,   121,    22,     0,    31,     0,     0,     0,     0,
       0,     0,   124,     0,     0,     0,    44
};

static const yytype_int8 yycheck[] =
{
      56,   113,   114,    59,    21,     1,     2,    19,    19,    27,
      27,    28,   124,    25,    25,     3,    19,     5,    21,     7,
      76,     0,    21,    79,    27,    28,    25,    21,    84,    25,
      26,    19,    19,    21,    35,    23,    24,    38,    28,    27,
      28,    10,    11,    99,   100,    21,     3,    43,     5,     4,
       7,     6,    26,    49,    50,    87,    88,    89,    90,    91,
      92,     4,    19,     6,    21,    26,    23,   123,     8,     9,
      27,    28,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     8,     9,    93,    94,    12,    13,    14,    15,
      16,    17,     4,     4,     6,     6,    85,    86,    22,    20,
      19,    26,    22,    25,    19,    19,    23,    25,    21,    18,
      26,    21,     5,    48,    22,    21,    -1,    22,    25,    22,
      22,    20,    26,    17,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     6,    35,    36,    37,    40,    41,    27,    38,
      38,     0,    36,    19,    25,    42,    19,    25,    43,    28,
      39,    21,    39,    21,    26,     4,     6,    44,    45,    46,
      26,    44,    19,    38,    38,    22,    20,    19,    22,    25,
      25,    23,    47,     6,    46,    47,    26,    26,    48,     4,
       6,    40,    49,    38,    38,     3,     5,     7,    19,    21,
      24,    28,    38,    47,    50,    51,    52,    53,    54,    55,
      56,    58,    59,    60,    61,    62,    21,    19,    55,    21,
      55,    57,    63,    19,    18,     8,     9,    12,    13,    14,
      15,    16,    17,    10,    11,    55,    19,    55,    22,    25,
      21,    55,    56,    60,    60,    59,    59,    59,    59,    59,
      59,    61,    61,    22,    22,    55,    55,    64,    65,    50,
      50,    26,    22,    20,    33,    55,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    39,    40,
      40,    40,    40,    42,    41,    43,    41,    44,    44,    45,
      45,    46,    46,    46,    46,    47,    48,    48,    49,    49,
      50,    50,    50,    50,    50,    51,    51,    52,    52,    53,
      54,    54,    55,    55,    57,    56,    56,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    60,    60,    60,
      61,    61,    61,    61,    63,    62,    64,    64,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       3,     6,     6,     0,     7,     0,     7,     1,     1,     3,
       1,     2,     4,     2,     4,     4,     2,     0,     2,     0,
       1,     1,     1,     1,     1,     2,     1,     5,     7,     5,
       2,     3,     3,     1,     0,     5,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     1,     0,     5,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 38 "cminus.y" /* yacc.c:1646  */
    { 
                            savedTree = (yyvsp[0]);
                          }
#line 1368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 43 "cminus.y" /* yacc.c:1646  */
    { 
                            YYSTYPE now = (yyvsp[-1]);
                            if (now != NULL) {
                              while(now->sibling != NULL){
                                now = now->sibling;
                              }
                              now->sibling = (yyvsp[0]);
                              (yyval) = (yyvsp[-1]);
                            }else{
                              (yyval) = (yyvsp[0]);
                            }
                          }
#line 1385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 56 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 61 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 65 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 70 "cminus.y" /* yacc.c:1646  */
    { 
                            savedName = copyString(tokenString);
                            savedLineNo = lineno; 
                          }
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 76 "cminus.y" /* yacc.c:1646  */
    {
                            savedNum = atoi(tokenString);
                            savedLineNo = lineno;
                          }
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newDeclNode(VarK);
                            //save line #
                            (yyval)->lineno = lineno;
                            //save name
                            (yyval)->attr.decl.name = savedName;
                            (yyval)->attr.decl.type = VOID;
                          }
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 91 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newDeclNode(VarK);
                            //save line #
                            (yyval)->lineno = lineno;
                            //save name
                            (yyval)->attr.decl.name = savedName;
                            (yyval)->attr.decl.type = INT;
                          }
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 100 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newDeclNode(ArrVarK);
                            //save line #
                            (yyval)->lineno = lineno;
                            //save name and size
                            (yyval)->attr.decl.name = savedName;
                            (yyval)->attr.decl.type = VOID;

                            YYSTYPE size = newExpNode(ConstK);
                            size->attr.val = savedNum;
                            (yyval)->child[0] = size;
                          }
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 113 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newDeclNode(ArrVarK);
                            //save line #
                            (yyval)->lineno = lineno;
                            //save name and size
                            (yyval)->attr.decl.name = savedName;
                            (yyval)->attr.decl.type = INT;

                            YYSTYPE size = newExpNode(ConstK);
                            size->attr.val = savedNum;
                            (yyval)->child[0] = size;
                          }
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newDeclNode(FunK);
                            (yyval)->lineno = savedLineNo;
                            (yyval)->attr.decl.name = savedName;
                            (yyval)->attr.decl.type = INT;
                          }
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 134 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[-4]);
                            //save type, parameters, body
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                          }
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 141 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newDeclNode(FunK);
                            (yyval)->lineno = savedLineNo;
                            (yyval)->attr.decl.name = savedName;
                            (yyval)->attr.decl.type = VOID;
                          }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 148 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[-4]);
                            //save type, parameters, body
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                          }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 156 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 160 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newParamNode(NonArrParamK);
                            //save type and name
                            (yyval)->attr.decl.type = VOID;
                            (yyval)->attr.decl.name = NULL;
                          }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 168 "cminus.y" /* yacc.c:1646  */
    {
                            YYSTYPE now = (yyvsp[-2]);
                            if (now != NULL) {
                              while(now->sibling != NULL){
                                now = now->sibling;
                              }
                              now->sibling = (yyvsp[0]);
                              (yyval) = (yyvsp[-2]);
                            }else{
                              (yyval) = (yyvsp[0]);
                            }                        
                          }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 181 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 186 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newParamNode(NonArrParamK);
                            //save type and name
                            (yyval)->attr.decl.type = INT;
                            (yyval)->attr.decl.name = savedName;
                          }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 193 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newParamNode(ArrParamK);
                            //save type and name
                            (yyval)->attr.decl.type = INT;
                            (yyval)->attr.decl.name = savedName;
                          }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 200 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newParamNode(NonArrParamK);
                            //save type and name
                            (yyval)->attr.decl.type = VOID;
                            (yyval)->attr.decl.name = savedName;
                          }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 207 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newParamNode(ArrParamK);
                            //save type and name
                            (yyval)->attr.decl.type = VOID;
                            (yyval)->attr.decl.name = savedName;
                          }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 215 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newStmtNode(CompK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[-1]);
                          }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 222 "cminus.y" /* yacc.c:1646  */
    {
                            YYSTYPE now = (yyvsp[-1]);
                            if (now != NULL) {
                              while(now->sibling != NULL){
                                now = now->sibling;
                              }
                              now->sibling = (yyvsp[0]);
                              (yyval) = (yyvsp[-1]);
                            }else{
                              (yyval) = (yyvsp[0]);
                            }                            
                          }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 235 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = NULL;
                          }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 240 "cminus.y" /* yacc.c:1646  */
    {
                            YYSTYPE now = (yyvsp[-1]);
                            if (now != NULL) {
                              while(now->sibling != NULL){
                                now = now->sibling;
                              }
                              now->sibling = (yyvsp[0]);
                              (yyval) = (yyvsp[-1]);
                            }else{
                              (yyval) = (yyvsp[0]);
                            }
                          }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 253 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = NULL;
                          }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 258 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 262 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 266 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 270 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 274 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 279 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[-1]);
                          }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 283 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = NULL;
                          }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 288 "cminus.y" /* yacc.c:1646  */
    { 
                            (yyval) = newStmtNode(IfK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                            // mark child #2 because of "if-else" statement
                            (yyval)->child[2] = NULL;
                          }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 296 "cminus.y" /* yacc.c:1646  */
    { 
                            (yyval) = newStmtNode(IfK);
                            (yyval)->child[0] = (yyvsp[-4]);
                            (yyval)->child[1] = (yyvsp[-2]);
                            (yyval)->child[2] = (yyvsp[0]);
                          }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 304 "cminus.y" /* yacc.c:1646  */
    { 
                            (yyval) = newStmtNode(IterK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                          }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 311 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newStmtNode(ReturnK);
                            (yyval)->child[0] = NULL;
                          }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 316 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newStmtNode(ReturnK);
                            (yyval)->child[0] = (yyvsp[-1]);
                          }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 322 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newExpNode(AssignK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                          }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 328 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 333 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newExpNode(ArrIdK);
                            (yyval)->attr.name = savedName;
                          }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 338 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[-3]);
                            (yyval)->child[0] = (yyvsp[-1]);
                          }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 343 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newExpNode(IdK);
                            (yyval)->attr.name = savedName;
                          }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 349 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newExpNode(OpK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                            (yyval)->attr.op = EQ;
                          }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 356 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newExpNode(OpK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                            (yyval)->attr.op = NE;
                          }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 363 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newExpNode(OpK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                            (yyval)->attr.op = GT;
                          }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 370 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newExpNode(OpK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                            (yyval)->attr.op = GE;
                          }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 377 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newExpNode(OpK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                            (yyval)->attr.op = LT;
                          }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 384 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newExpNode(OpK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                            (yyval)->attr.op = LE;
                          }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 391 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 397 "cminus.y" /* yacc.c:1646  */
    { 
                            (yyval) = newExpNode(OpK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                            (yyval)->attr.op = PLUS;
                          }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 404 "cminus.y" /* yacc.c:1646  */
    { 
                            (yyval) = newExpNode(OpK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                            (yyval)->attr.op = MINUS;
                          }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 410 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 413 "cminus.y" /* yacc.c:1646  */
    { (yyval) = newExpNode(OpK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                            (yyval)->attr.op = TIMES;
                          }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 419 "cminus.y" /* yacc.c:1646  */
    { (yyval) = newExpNode(OpK);
                            (yyval)->child[0] = (yyvsp[-2]);
                            (yyval)->child[1] = (yyvsp[0]);
                            (yyval)->attr.op = OVER;
                          }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 424 "cminus.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 427 "cminus.y" /* yacc.c:1646  */
    { 
                            (yyval) = (yyvsp[-1]); 
                          }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 431 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 435 "cminus.y" /* yacc.c:1646  */
    { 
                            (yyval) = newExpNode(ConstK);
                            (yyval)->attr.val = atoi(tokenString);
                          }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 440 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 445 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = newExpNode(CallK);
                            (yyval)->attr.name = savedName;
                          }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 450 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[-3]);
                            (yyval)->child[0] = (yyvsp[-1]);
                          }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 456 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 460 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = NULL;
                          }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 465 "cminus.y" /* yacc.c:1646  */
    {
                            YYSTYPE now = (yyvsp[-2]);
                            if (now != NULL) {
                              while(now->sibling != NULL){
                                now = now->sibling;
                              }
                              now->sibling = (yyvsp[0]);
                              (yyval) = (yyvsp[-2]);
                            }else{
                              (yyval) = (yyvsp[0]);
                            }  
                          }
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 478 "cminus.y" /* yacc.c:1646  */
    {
                            (yyval) = (yyvsp[0]);
                          }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2055 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 483 "cminus.y" /* yacc.c:1906  */


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

