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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CHAR_ERR = 258,
    KEY = 259,
    NUMCONST = 260,
    CHARCONST = 261,
    CHARCONST_ESC = 262,
    RANGE = 263,
    STRINGCONST = 264,
    QMARK = 265,
    MULTIPLY = 266,
    MINUS = 267,
    PERCENT = 268,
    DIV = 269,
    PLUS = 270,
    LESS = 271,
    GRET = 272,
    EQ = 273,
    SEMI = 274,
    LIndex = 275,
    RIndex = 276,
    LB = 277,
    RB = 278,
    LP = 279,
    RP = 280,
    COM = 281,
    COL = 282,
    EQEQ = 283,
    IF = 284,
    ELSE = 285,
    ELSIF = 286,
    THEN = 287,
    WHILE = 288,
    DO = 289,
    LOOP = 290,
    FOREVER = 291,
    BREAK = 292,
    AND = 293,
    OR = 294,
    NOT = 295,
    RETURN = 296,
    TRUE = 297,
    FALSE = 298,
    ADDASS = 299,
    SUBASS = 300,
    MULASS = 301,
    DIVASS = 302,
    DEC = 303,
    INC = 304,
    NOTEQ = 305,
    LESSEQ = 306,
    GRETEQ = 307,
    ID = 308,
    INT = 309,
    BOOL = 310,
    CHAR = 311,
    STATIC = 312
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "parser.y" /* yacc.c:1909  */

    TokenData *Token_Data;
    TreeNode *Tree;
    ExpType type;

#line 118 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
