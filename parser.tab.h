/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

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
     PLUS = 276,
     MINUS = 277,
     MULT = 278,
     DIV = 279,
     MOD = 280,
     ASSIGN = 281,
     LT = 282,
     GT = 283,
     LE = 284,
     GE = 285,
     EQ = 286,
     NEQ = 287,
     AND = 288,
     OR = 289,
     NOT = 290,
     INC = 291,
     DEC = 292,
     LBRACE = 293,
     RBRACE = 294,
     LPAREN = 295,
     RPAREN = 296,
     LBRACKET = 297,
     RBRACKET = 298,
     SEMI = 299,
     COMMA = 300,
     COLON = 301,
     UMINUS = 302
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 26 "src/parser/parser.y"


    int int_val;

    float float_val;

    int bool_val;

    char *str_val;


    ASTNode *node;



/* Line 2058 of yacc.c  */
#line 120 "parser.tab.h"
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
