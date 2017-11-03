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

#ifndef YY_YY_PROGRAM4_TAB_H_INCLUDED
# define YY_YY_PROGRAM4_TAB_H_INCLUDED
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
    DOT = 258,
    THIS = 259,
    LBRACK = 260,
    RBRACK = 261,
    DOUBBRACK = 262,
    LBRACE = 263,
    RBRACE = 264,
    INT = 265,
    IDEN = 266,
    NUM = 267,
    NLL = 268,
    READ = 269,
    NEW = 270,
    LPAREN = 271,
    RPAREN = 272,
    IF = 273,
    ELSE = 274,
    DEQ = 275,
    NEQ = 276,
    LEQ = 277,
    GEQ = 278,
    GT = 279,
    LT = 280,
    PLUS = 281,
    MINUS = 282,
    OR = 283,
    MULT = 284,
    DIVD = 285,
    MOD = 286,
    AND = 287,
    BANG = 288,
    SEMI = 289,
    EQ = 290,
    COMMA = 291,
    RETURN = 292,
    WHILE = 293,
    PRINT = 294,
    RO = 295,
    SO = 296,
    PO = 297,
    UO = 298,
    DE = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "program4.y" /* yacc.c:1909  */

  Node *ttype;
  struct attributes* atts;

#line 104 "program4.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROGRAM4_TAB_H_INCLUDED  */
