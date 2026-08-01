/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "src/parser/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "symtab.h"

extern int yylex();
extern int line_num;
extern char* yytext;
void yyerror(const char *s);

ASTNode* ast_root = NULL;

/* Line 371 of yacc.c  */
#line 83 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 387 of yacc.c  */
#line 16 "src/parser/parser.y"

    #include <stdbool.h>
    #include "ast.h"


/* Line 387 of yacc.c  */
#line 121 "parser.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_VAL = 258,
     FLOAT_VAL = 259,
     TRUE_CONST = 260,
     FALSE_CONST = 261,
     IDENTIFIER = 262,
     INT = 263,
     FLOAT = 264,
     BOOL = 265,
     IF = 266,
     ELSE = 267,
     WHILE = 268,
     FOR = 269,
     DO = 270,
     SWITCH = 271,
     CASE = 272,
     DEFAULT = 273,
     RETURN = 274,
     PRINT = 275,
     INC = 276,
     DEC = 277,
     EQ = 278,
     NEQ = 279,
     LE = 280,
     GE = 281,
     AND = 282,
     OR = 283,
     PLUS = 284,
     MINUS = 285,
     MULT = 286,
     DIV = 287,
     MOD = 288,
     ASSIGN = 289,
     LT = 290,
     GT = 291,
     NOT = 292,
     LBRACE = 293,
     RBRACE = 294,
     LPAREN = 295,
     RPAREN = 296,
     LBRACKET = 297,
     RBRACKET = 298,
     SEMI = 299,
     COMMA = 300,
     COLON = 301,
     LOWER_THAN_ELSE = 302
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 21 "src/parser/parser.y"

    int int_val;
    float float_val;
    bool bool_val;
    char* str_val;
    ASTNode* node;


/* Line 387 of yacc.c  */
#line 192 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 220 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   542

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    15,    18,    20,
      22,    24,    26,    28,    30,    33,    37,    41,    43,    46,
      47,    52,    54,    56,    58,    61,    67,    71,    78,    84,
      92,    98,   106,   116,   126,   134,   137,   139,   140,   145,
     149,   150,   158,   162,   164,   165,   168,   173,   177,   179,
     180,   184,   188,   192,   196,   200,   204,   208,   212,   216,
     220,   224,   228,   232,   235,   238,   241,   244,   248,   250,
     255,   257,   259,   261,   263
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    -1,    51,    50,    -1,    -1,    55,
      44,    -1,    56,    44,    -1,    57,    44,    -1,    58,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,    66,    -1,
      70,    44,    -1,    19,    72,    44,    -1,    20,    72,    44,
      -1,    52,    -1,    72,    44,    -1,    -1,    38,    53,    50,
      39,    -1,     8,    -1,     9,    -1,    10,    -1,    54,     7,
      -1,    54,     7,    42,     3,    43,    -1,     7,    34,    72,
      -1,     7,    42,    72,    43,    34,    72,    -1,    11,    40,
      72,    41,    52,    -1,    11,    40,    72,    41,    52,    12,
      52,    -1,    13,    40,    72,    41,    52,    -1,    15,    52,
      13,    40,    72,    41,    44,    -1,    14,    40,    57,    44,
      72,    44,    57,    41,    52,    -1,    14,    40,    57,    44,
      72,    44,    72,    41,    52,    -1,    16,    40,    72,    41,
      38,    63,    39,    -1,    64,    63,    -1,    65,    -1,    -1,
      17,     3,    46,    50,    -1,    18,    46,    50,    -1,    -1,
      54,     7,    40,    67,    68,    41,    52,    -1,    69,    45,
      68,    -1,    69,    -1,    -1,    54,     7,    -1,     7,    40,
      71,    41,    -1,    72,    45,    71,    -1,    72,    -1,    -1,
      72,    29,    72,    -1,    72,    30,    72,    -1,    72,    31,
      72,    -1,    72,    32,    72,    -1,    72,    33,    72,    -1,
      72,    23,    72,    -1,    72,    24,    72,    -1,    72,    35,
      72,    -1,    72,    36,    72,    -1,    72,    25,    72,    -1,
      72,    26,    72,    -1,    72,    27,    72,    -1,    72,    28,
      72,    -1,    37,    72,    -1,    30,    72,    -1,    72,    21,
      -1,    72,    22,    -1,    40,    72,    41,    -1,     7,    -1,
       7,    42,    72,    43,    -1,     3,    -1,     4,    -1,     5,
      -1,     6,    -1,    70,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    68,    69,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    90,
      90,    94,    95,    96,   100,   112,   124,   134,   147,   148,
     152,   156,   160,   161,   165,   169,   170,   171,   175,   179,
     183,   183,   199,   200,   201,   205,   217,   228,   229,   230,
     234,   235,   236,   237,   238,   240,   241,   242,   243,   244,
     245,   247,   248,   250,   251,   253,   254,   256,   258,   265,
     273,   274,   275,   276,   277
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_VAL", "FLOAT_VAL", "TRUE_CONST",
  "FALSE_CONST", "IDENTIFIER", "INT", "FLOAT", "BOOL", "IF", "ELSE",
  "WHILE", "FOR", "DO", "SWITCH", "CASE", "DEFAULT", "RETURN", "PRINT",
  "INC", "DEC", "EQ", "NEQ", "LE", "GE", "AND", "OR", "PLUS", "MINUS",
  "MULT", "DIV", "MOD", "ASSIGN", "LT", "GT", "NOT", "LBRACE", "RBRACE",
  "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "SEMI", "COMMA", "COLON",
  "LOWER_THAN_ELSE", "$accept", "program", "stmt_list", "stmt", "block",
  "$@1", "type", "var_decl", "array_decl", "assign_stmt", "if_stmt",
  "while_stmt", "do_while_stmt", "for_stmt", "switch_stmt", "case_list",
  "case_stmt", "default_stmt", "func_decl", "$@2", "param_list", "param",
  "func_call", "arg_list", "expr", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    53,
      52,    54,    54,    54,    55,    56,    57,    57,    58,    58,
      59,    60,    61,    61,    62,    63,    63,    63,    64,    65,
      67,    66,    68,    68,    68,    69,    70,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     1,     2,     0,
       4,     1,     1,     1,     2,     5,     3,     6,     5,     7,
       5,     7,     9,     9,     7,     2,     1,     0,     4,     3,
       0,     7,     3,     1,     0,     2,     4,     3,     1,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     3,     1,     4,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    70,    71,    72,    73,    68,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
       0,     2,     4,    17,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    74,     0,     0,    49,     0,     0,
       0,     0,     0,     0,    68,    74,     0,     0,    64,    63,
       4,     0,     1,     3,    24,     5,     6,     7,    14,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    26,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,     0,    67,
      40,     0,    55,    56,    59,    60,    61,    62,    50,    51,
      52,    53,    54,    57,    58,    46,    49,    69,     0,     0,
       0,     0,     0,     0,     0,    20,    44,     0,    47,     0,
      28,    30,     0,     0,     0,    37,    69,     0,     0,    43,
      25,    27,     0,     0,     0,     0,     0,     0,     0,    37,
      36,    45,     0,    44,    29,     0,     0,    31,     0,     4,
      34,    35,    41,    42,     0,     0,     4,    39,    32,    33,
      38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    50,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   138,   139,   140,    33,   116,
     128,   129,    45,    76,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
     154,  -101,  -101,  -101,  -101,     6,  -101,  -101,  -101,   -31,
     -26,   -13,     4,     9,     1,     1,     1,     1,  -101,     1,
      70,  -101,   154,  -101,    64,    28,    29,    43,  -101,  -101,
    -101,  -101,  -101,  -101,    46,   199,     1,     1,     1,     1,
       1,    84,    79,     1,   -14,  -101,   223,   247,    31,    31,
     154,   364,  -101,  -101,     5,  -101,  -101,  -101,  -101,  -101,
    -101,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,  -101,   490,    54,   174,   295,   385,
     406,    -5,    55,    60,   427,     1,  -101,  -101,    62,  -101,
    -101,   106,   150,   150,    95,    95,   506,    53,    72,    72,
      31,    31,    31,    95,    95,  -101,     1,    76,     4,     4,
       1,     1,     1,    73,   318,  -101,    15,    69,  -101,     1,
     101,  -101,   341,   271,   448,    38,  -101,   107,    77,    74,
    -101,   490,     4,    76,    14,    78,   117,    86,    94,    38,
    -101,  -101,     4,    15,  -101,    82,   469,  -101,    88,   154,
    -101,  -101,  -101,  -101,     4,     4,   154,  -101,  -101,  -101,
    -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -101,  -101,   -20,  -101,   -11,  -101,  -100,  -101,  -101,   -38,
    -101,  -101,  -101,  -101,  -101,    -2,  -101,  -101,  -101,  -101,
      -8,  -101,     0,    32,    -4
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      34,    42,    53,    82,     1,     2,     3,     4,    44,    39,
      46,    47,    48,    49,    40,    51,   127,     1,     2,     3,
       4,     5,    34,     6,     7,     8,    37,    41,    85,    36,
      88,    16,    75,    77,    78,    79,    80,   110,    17,    84,
      36,    19,    18,   127,    16,    90,    37,    91,    38,    43,
      34,    17,    59,    60,    19,   136,   137,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      52,    54,    55,    56,    59,    60,    61,    62,    63,    64,
      65,   114,    67,    68,    69,    70,    71,    57,    72,    73,
      58,    81,    83,    59,    60,   105,   145,   120,   121,   111,
     112,   115,    77,    69,    70,    71,   122,   123,   124,   117,
     119,   125,   130,   132,   141,   131,    59,    60,   142,   143,
     148,   144,   147,   154,    67,    68,    69,    70,    71,   157,
     146,   152,   149,   150,   156,   153,   160,   151,   118,     0,
       0,     0,     0,   158,   159,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,    34,     1,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
      13,    59,    60,    14,    15,    63,    64,     0,     0,    67,
      68,    69,    70,    71,    16,    72,    73,     0,     0,     0,
       0,    17,    18,     0,    19,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,   106,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,     0,     0,     0,     0,
       0,     0,     0,    74,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
       0,     0,     0,     0,     0,     0,     0,    86,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,     0,     0,     0,     0,     0,     0,
       0,    87,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,     0,     0,
       0,     0,     0,     0,     0,   134,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,     0,     0,     0,     0,     0,     0,   107,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,     0,     0,     0,     0,     0,
       0,   126,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,     0,     0,
       0,     0,     0,     0,   133,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,     0,     0,     0,     0,    89,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,     0,     0,     0,     0,   108,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,     0,     0,     0,     0,   109,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,     0,     0,     0,     0,   113,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,     0,     0,     0,     0,   135,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,     0,     0,     0,     0,
     155,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    59,    60,    61,
      62,    63,    64,     0,     0,    67,    68,    69,    70,    71,
       0,    72,    73
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-101)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    12,    22,    41,     3,     4,     5,     6,     7,    40,
      14,    15,    16,    17,    40,    19,   116,     3,     4,     5,
       6,     7,    22,     8,     9,    10,    40,    40,    42,    34,
      50,    30,    36,    37,    38,    39,    40,    42,    37,    43,
      34,    40,    38,   143,    30,    40,    40,    42,    42,    40,
      50,    37,    21,    22,    40,    17,    18,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     7,    44,    44,    21,    22,    23,    24,    25,    26,
      27,    85,    29,    30,    31,    32,    33,    44,    35,    36,
      44,     7,    13,    21,    22,    41,   134,   108,   109,    44,
      40,    39,   106,    31,    32,    33,   110,   111,   112,     3,
      34,    38,    43,    12,     7,   119,    21,    22,    41,    45,
       3,   132,    44,    41,    29,    30,    31,    32,    33,   149,
     134,   142,    46,    39,    46,   143,   156,   139,   106,    -1,
      -1,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    21,    22,    19,    20,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    30,    35,    36,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    -1,    -1,    -1,    -1,    41,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    -1,    -1,    -1,    -1,    41,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    -1,    -1,    -1,    -1,    41,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    -1,    -1,    -1,    -1,    41,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,    41,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,
      41,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    30,    31,    32,    33,
      -1,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      13,    14,    15,    16,    19,    20,    30,    37,    38,    40,
      49,    50,    51,    52,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    66,    70,    72,    34,    40,    42,    40,
      40,    40,    52,    40,     7,    70,    72,    72,    72,    72,
      53,    72,     0,    50,     7,    44,    44,    44,    44,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    35,    36,    44,    72,    71,    72,    72,    72,
      72,     7,    57,    13,    72,    42,    44,    44,    50,    41,
      40,    42,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    41,    45,    43,    41,    41,
      42,    44,    40,    41,    72,    39,    67,     3,    71,    34,
      52,    52,    72,    72,    72,    38,    43,    54,    68,    69,
      43,    72,    12,    43,    44,    41,    17,    18,    63,    64,
      65,     7,    41,    45,    52,    57,    72,    44,     3,    46,
      39,    63,    52,    68,    41,    41,    46,    50,    52,    52,
      50
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 64 "src/parser/parser.y"
    { ast_root = (yyvsp[(1) - (1)].node); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 68 "src/parser/parser.y"
    { (yyval.node) = create_seq((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 69 "src/parser/parser.y"
    { (yyval.node) = NULL; }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 73 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 74 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 75 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 76 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 77 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 78 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 79 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 80 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 81 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 82 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 83 "src/parser/parser.y"
    { (yyval.node) = create_return((yyvsp[(2) - (3)].node)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 84 "src/parser/parser.y"
    { (yyval.node) = create_print((yyvsp[(2) - (3)].node)); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 85 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 86 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 90 "src/parser/parser.y"
    { enter_scope(); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 90 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(3) - (4)].node); exit_scope(); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 94 "src/parser/parser.y"
    { (yyval.str_val) = "int"; }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 95 "src/parser/parser.y"
    { (yyval.str_val) = "float"; }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 96 "src/parser/parser.y"
    { (yyval.str_val) = "bool"; }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 100 "src/parser/parser.y"
    { 
        DataType t = TYPE_UNKNOWN;
        if(strcmp((yyvsp[(1) - (2)].str_val), "int")==0) t = TYPE_INT;
        else if(strcmp((yyvsp[(1) - (2)].str_val), "float")==0) t = TYPE_FLOAT;
        else if(strcmp((yyvsp[(1) - (2)].str_val), "bool")==0) t = TYPE_BOOL;
        insert_symbol((yyvsp[(2) - (2)].str_val), t, line_num);
        (yyval.node) = create_var_decl((yyvsp[(1) - (2)].str_val), (yyvsp[(2) - (2)].str_val)); 
        free((yyvsp[(2) - (2)].str_val)); 
    }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 112 "src/parser/parser.y"
    { 
        DataType t = TYPE_UNKNOWN;
        if(strcmp((yyvsp[(1) - (5)].str_val), "int")==0) t = TYPE_INT;
        else if(strcmp((yyvsp[(1) - (5)].str_val), "float")==0) t = TYPE_FLOAT;
        else if(strcmp((yyvsp[(1) - (5)].str_val), "bool")==0) t = TYPE_BOOL;
        insert_symbol((yyvsp[(2) - (5)].str_val), t, line_num);
        (yyval.node) = create_array_decl((yyvsp[(1) - (5)].str_val), (yyvsp[(2) - (5)].str_val), create_int_const((yyvsp[(4) - (5)].int_val))); 
        free((yyvsp[(2) - (5)].str_val)); 
    }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 124 "src/parser/parser.y"
    { 
        Symbol* sym = lookup_symbol((yyvsp[(1) - (3)].str_val));
        if (!sym) {
            fprintf(stderr, "Semantic Error at line %d: Variable '%s' not declared or out of scope\n", line_num, (yyvsp[(1) - (3)].str_val));
        } else {
            check_type(sym->type, get_type((yyvsp[(3) - (3)].node)), line_num);
        }
        (yyval.node) = create_assign(create_identifier((yyvsp[(1) - (3)].str_val)), (yyvsp[(3) - (3)].node)); 
        free((yyvsp[(1) - (3)].str_val)); 
    }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 134 "src/parser/parser.y"
    { 
        Symbol* sym = lookup_symbol((yyvsp[(1) - (6)].str_val));
        if (!sym) {
            fprintf(stderr, "Semantic Error at line %d: Array '%s' not declared or out of scope\n", line_num, (yyvsp[(1) - (6)].str_val));
        } else {
            check_type(sym->type, get_type((yyvsp[(6) - (6)].node)), line_num);
        }
        (yyval.node) = create_assign(create_array_access((yyvsp[(1) - (6)].str_val), (yyvsp[(3) - (6)].node)), (yyvsp[(6) - (6)].node)); 
        free((yyvsp[(1) - (6)].str_val)); 
    }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 147 "src/parser/parser.y"
    { (yyval.node) = create_if((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 148 "src/parser/parser.y"
    { (yyval.node) = create_if_else((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 152 "src/parser/parser.y"
    { (yyval.node) = create_while((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 156 "src/parser/parser.y"
    { (yyval.node) = create_do_while((yyvsp[(5) - (7)].node), (yyvsp[(2) - (7)].node)); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 160 "src/parser/parser.y"
    { (yyval.node) = create_for((yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node)); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 161 "src/parser/parser.y"
    { (yyval.node) = create_for((yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node)); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 165 "src/parser/parser.y"
    { (yyval.node) = create_switch((yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node)); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 169 "src/parser/parser.y"
    { (yyval.node) = create_seq((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 170 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 171 "src/parser/parser.y"
    { (yyval.node) = NULL; }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 175 "src/parser/parser.y"
    { (yyval.node) = create_case(create_int_const((yyvsp[(2) - (4)].int_val)), (yyvsp[(4) - (4)].node)); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 179 "src/parser/parser.y"
    { (yyval.node) = create_default((yyvsp[(3) - (3)].node)); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 183 "src/parser/parser.y"
    { 
        DataType t = TYPE_UNKNOWN;
        if(strcmp((yyvsp[(1) - (3)].str_val), "int")==0) t = TYPE_INT;
        else if(strcmp((yyvsp[(1) - (3)].str_val), "float")==0) t = TYPE_FLOAT;
        else if(strcmp((yyvsp[(1) - (3)].str_val), "bool")==0) t = TYPE_BOOL;
        insert_symbol((yyvsp[(2) - (3)].str_val), t, line_num);
        enter_scope(); 
    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 190 "src/parser/parser.y"
    { 
        // Note: param_list shifted to $5 and block to $7 due to mid-rule action
        (yyval.node) = create_function((yyvsp[(1) - (7)].str_val), (yyvsp[(2) - (7)].str_val), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)); 
        free((yyvsp[(2) - (7)].str_val)); 
        exit_scope();
    }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 199 "src/parser/parser.y"
    { (yyval.node) = create_seq((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 200 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 201 "src/parser/parser.y"
    { (yyval.node) = NULL; }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 205 "src/parser/parser.y"
    { 
        DataType t = TYPE_UNKNOWN;
        if(strcmp((yyvsp[(1) - (2)].str_val), "int")==0) t = TYPE_INT;
        else if(strcmp((yyvsp[(1) - (2)].str_val), "float")==0) t = TYPE_FLOAT;
        else if(strcmp((yyvsp[(1) - (2)].str_val), "bool")==0) t = TYPE_BOOL;
        insert_symbol((yyvsp[(2) - (2)].str_val), t, line_num);
        (yyval.node) = create_var_decl((yyvsp[(1) - (2)].str_val), (yyvsp[(2) - (2)].str_val)); 
        free((yyvsp[(2) - (2)].str_val)); 
    }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 217 "src/parser/parser.y"
    { 
        Symbol* sym = lookup_symbol((yyvsp[(1) - (4)].str_val));
        if (!sym) {
            fprintf(stderr, "Semantic Error at line %d: Function '%s' not declared\n", line_num, (yyvsp[(1) - (4)].str_val));
        }
        (yyval.node) = create_function_call((yyvsp[(1) - (4)].str_val), (yyvsp[(3) - (4)].node)); 
        free((yyvsp[(1) - (4)].str_val)); 
    }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 228 "src/parser/parser.y"
    { (yyval.node) = create_seq((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 229 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 230 "src/parser/parser.y"
    { (yyval.node) = NULL; }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 234 "src/parser/parser.y"
    { (yyval.node) = create_binop("+", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 235 "src/parser/parser.y"
    { (yyval.node) = create_binop("-", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 236 "src/parser/parser.y"
    { (yyval.node) = create_binop("*", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 237 "src/parser/parser.y"
    { (yyval.node) = create_binop("/", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 238 "src/parser/parser.y"
    { (yyval.node) = create_binop("%", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 240 "src/parser/parser.y"
    { (yyval.node) = create_binop("==", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 241 "src/parser/parser.y"
    { (yyval.node) = create_binop("!=", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 242 "src/parser/parser.y"
    { (yyval.node) = create_binop("<", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 243 "src/parser/parser.y"
    { (yyval.node) = create_binop(">", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 244 "src/parser/parser.y"
    { (yyval.node) = create_binop("<=", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 245 "src/parser/parser.y"
    { (yyval.node) = create_binop(">=", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 247 "src/parser/parser.y"
    { (yyval.node) = create_binop("&&", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 248 "src/parser/parser.y"
    { (yyval.node) = create_binop("||", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 250 "src/parser/parser.y"
    { (yyval.node) = create_unary("!", (yyvsp[(2) - (2)].node)); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 251 "src/parser/parser.y"
    { (yyval.node) = create_unary("-", (yyvsp[(2) - (2)].node)); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 253 "src/parser/parser.y"
    { (yyval.node) = create_unary("++", (yyvsp[(1) - (2)].node)); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 254 "src/parser/parser.y"
    { (yyval.node) = create_unary("--", (yyvsp[(1) - (2)].node)); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 256 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 258 "src/parser/parser.y"
    { 
        Symbol* sym = lookup_symbol((yyvsp[(1) - (1)].str_val));
        if (!sym) {
            fprintf(stderr, "Semantic Error at line %d: Variable '%s' not declared or out of scope\n", line_num, (yyvsp[(1) - (1)].str_val));
        }
        (yyval.node) = create_identifier((yyvsp[(1) - (1)].str_val)); free((yyvsp[(1) - (1)].str_val)); 
    }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 265 "src/parser/parser.y"
    { 
        Symbol* sym = lookup_symbol((yyvsp[(1) - (4)].str_val));
        if (!sym) {
            fprintf(stderr, "Semantic Error at line %d: Array '%s' not declared or out of scope\n", line_num, (yyvsp[(1) - (4)].str_val));
        }
        (yyval.node) = create_array_access((yyvsp[(1) - (4)].str_val), (yyvsp[(3) - (4)].node)); free((yyvsp[(1) - (4)].str_val)); 
    }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 273 "src/parser/parser.y"
    { (yyval.node) = create_int_const((yyvsp[(1) - (1)].int_val)); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 274 "src/parser/parser.y"
    { (yyval.node) = create_float_const((yyvsp[(1) - (1)].float_val)); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 275 "src/parser/parser.y"
    { (yyval.node) = create_bool_const(1); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 276 "src/parser/parser.y"
    { (yyval.node) = create_bool_const(0); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 277 "src/parser/parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;


/* Line 1792 of yacc.c  */
#line 2138 "parser.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 280 "src/parser/parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s (near '%s')\n", line_num, s, yytext);
}