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
#line 5 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
//#include "ScanType.h"
#include "tree.h"
#define YYERROR_VERBOSE
int yylex();
extern int yylineno;
extern FILE *yyin;
static char *savedName;
static int savedLinenno;
static TreeNode *syntaxTree;
void yyerror(const char *msg)
{
      printf("ERROR(PARSER): %s\n LINE %d\nToken ", msg, yylineno );
}


#line 87 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
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
#line 27 "parser.y" /* yacc.c:355  */

    TokenData *Token_Data;
    TreeNode *Tree;
    ExpType type;

#line 191 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   333

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    66,    72,    79,    85,    92,   100,   108,
     114,   121,   127,   135,   142,   156,   162,   169,   175,   180,
     188,   198,   208,   214,   221,   227,   234,   242,   248,   255,
     262,   272,   273,   274,   275,   276,   277,   278,   283,   289,
     297,   307,   312,   319,   324,   331,   332,   333,   334,   350,
     355,   360,   367,   372,   379,   390,   398,   404,   411,   418,
     428,   435,   443,   450,   458,   468,   479,   487,   494,   506,
     514,   521,   534,   544,   552,   565,   572,   582,   591,   600,
     610,   620,   630,   640,   649,   658,   665,   675,   682,   692,
     701,   710,   717,   725,   732,   740,   748,   756,   764,   772,
     781,   789,   796,   804,   813,   821,   828,   836,   844,   853,
     860,   867,   875,   883,   892,   898,   905,   912,   925,   931,
     936,   943,   953,   959,   966,   972,   979,   987,   997,  1005,
    1014
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR_ERR", "KEY", "NUMCONST",
  "CHARCONST", "CHARCONST_ESC", "RANGE", "STRINGCONST", "QMARK",
  "MULTIPLY", "MINUS", "PERCENT", "DIV", "PLUS", "LESS", "GRET", "EQ",
  "SEMI", "LIndex", "RIndex", "LB", "RB", "LP", "RP", "COM", "COL", "EQEQ",
  "IF", "ELSE", "ELSIF", "THEN", "WHILE", "DO", "LOOP", "FOREVER", "BREAK",
  "AND", "OR", "NOT", "RETURN", "TRUE", "FALSE", "ADDASS", "SUBASS",
  "MULASS", "DIVASS", "DEC", "INC", "NOTEQ", "LESSEQ", "GRETEQ", "ID",
  "INT", "BOOL", "CHAR", "STATIC", "$accept", "program", "declarationList",
  "declaration", "varDeclaration", "scopedVarDeclaration", "varDeclList",
  "varDeclInitialize", "varDeclId", "scopedTypeSpecifier", "typeSpecifier",
  "funDeclaration", "params", "paramList", "paramTypeList", "paramIdList",
  "paramId", "statement", "expressionStmt", "compoundStmt",
  "localDeclarations", "statementList", "partialStmt", "matched",
  "unmatched", "matchedIf", "matchedElse", "unmatchedIf", "unmatchedElse",
  "iterationRange", "matchedWhile", "unmatchedWhile", "iterationStmt",
  "returnStmt", "breakStmt", "expression", "simpleExpression",
  "andExpression", "unaryRelExpression", "relExpression", "relop",
  "sumExpression", "sumop", "mulExpression", "mulop", "unaryExpression",
  "unaryop", "factor", "mutable", "immutable", "call", "args", "argList",
  "constant", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

#define YYPACT_NINF -152

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-152)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     138,   -12,  -152,  -152,  -152,    25,   138,  -152,  -152,    -8,
    -152,     3,  -152,  -152,     7,    68,  -152,    10,    15,    49,
      82,  -152,   104,     3,  -152,    60,     9,    96,   100,  -152,
     176,     3,   110,   108,   115,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,     9,     9,  -152,  -152,   112,   101,   103,  -152,
    -152,   275,   109,  -152,   271,  -152,   119,  -152,  -152,  -152,
     123,    15,  -152,  -152,     9,     9,   -23,   126,   254,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,   131,   101,   284,
    -152,  -152,   176,   128,  -152,     9,     9,     9,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,   271,   271,  -152,  -152,
    -152,   271,  -152,     9,  -152,  -152,   147,   -16,   -30,   176,
     133,  -152,  -152,   139,  -152,     9,     9,     9,     9,     9,
    -152,  -152,  -152,  -152,  -152,   143,   136,   103,  -152,    81,
     109,  -152,   142,     3,  -152,    60,  -152,   137,   215,   176,
    -152,     9,   130,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
       9,  -152,  -152,    69,  -152,  -152,     9,    19,  -152,  -152,
    -152,    74,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
      -3,   176,  -152,  -152,    51,   215,   133,   215,     9,  -152,
    -152,     9,  -152,   215,  -152,  -152,   141,  -152,  -152,    59,
      -5,  -152,  -152,   215,   215,     9,  -152,  -152,    74,  -152,
     101,  -152,  -152
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    17,    18,    19,     0,     2,     4,     5,     0,
       6,    23,     1,     3,    13,     0,    10,    11,     0,     0,
      22,    25,     0,    23,     7,     0,     0,    29,    26,    28,
       0,     0,     0,     0,    13,     9,   126,   127,   128,   113,
     112,   111,     0,     0,   130,   129,   116,    12,    87,    89,
      91,    93,   101,   105,     0,   110,   115,   114,   119,   120,
       0,     0,    39,    42,     0,     0,     0,     0,     0,    21,
      31,    32,    33,    34,    35,    36,    37,     0,    85,   115,
      24,    14,     0,     0,    90,   123,     0,     0,   103,   102,
      95,    96,    94,    99,    98,    97,     0,     0,   106,   108,
     107,     0,   109,     0,    30,    27,    44,     0,     0,     0,
       0,    77,    75,     0,    38,     0,     0,     0,     0,     0,
      84,    83,    20,   118,   125,     0,   122,    86,    88,    92,
     100,   104,     0,     0,    41,     0,    16,     0,     0,     0,
      73,     0,     0,    76,    78,    79,    80,    81,    82,   121,
       0,   117,    15,     0,    40,    43,     0,     0,    45,    46,
      51,    57,    58,    49,    52,    50,    53,    47,    48,    72,
       0,     0,   124,     8,     0,     0,     0,     0,     0,    54,
      59,     0,    74,     0,    67,    70,     0,    56,    63,     0,
      64,    66,    69,     0,     0,     0,    68,    71,    60,    62,
      65,    55,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,  -152,   170,  -152,  -152,    54,   171,  -152,  -152,
       1,  -152,   174,  -152,   168,  -152,   145,   -74,  -127,   -94,
    -152,  -152,  -152,  -151,   -10,   -91,    12,   -69,    14,    31,
    -152,  -152,  -152,   -65,   -56,   -39,   -24,   122,   -33,  -152,
    -152,   118,  -152,   125,  -152,   -48,  -152,  -152,   -26,  -152,
    -152,  -152,  -152,  -152
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,   134,    15,    16,    17,   135,
      18,    10,    19,    20,    21,    28,    29,    69,    70,    71,
     106,   137,   160,   161,   162,    72,   179,    73,   180,   142,
     165,   166,    74,    75,    76,    77,    78,    48,    49,    50,
      96,    51,    97,    52,   101,    53,    54,    55,    79,    57,
      58,   125,   126,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,     9,    47,    83,   139,   181,   102,     9,   122,    86,
      84,   158,    11,   109,    36,    37,   138,    56,    38,    39,
      40,    41,   195,    86,   184,    12,   187,    22,    56,   113,
     110,    23,   191,    42,    86,   140,    86,    26,    56,    56,
     107,   108,   196,   198,   159,    14,   124,   163,   158,    43,
     158,    44,    45,   131,   128,   175,   158,     2,     3,     4,
      56,    56,    46,   155,   132,   169,   158,   158,    27,   164,
      56,    56,   176,   167,    30,    56,   144,   145,   146,   147,
     148,   159,   168,   159,   163,   183,   163,    24,   173,   159,
      86,   194,   163,    88,    25,    25,    89,   182,    86,   159,
     159,    31,   163,   163,   177,   178,   164,   136,   164,    32,
     167,   172,   167,    34,   164,    56,    60,   170,   167,   168,
      98,   168,    99,   100,   164,   164,    61,   168,   167,   167,
      56,    81,   174,    82,   152,    22,    85,   168,   168,   103,
      86,    87,    36,    37,   104,   111,    38,    39,    40,    41,
     114,   141,    56,   123,   189,    56,    62,   190,   143,    63,
     154,    42,   150,   151,   171,   185,    64,   188,   149,    56,
      65,   200,    66,   192,    67,   193,    13,    43,    68,    44,
      45,    36,    37,   197,   199,    38,    39,    40,    41,   153,
      46,     1,     2,     3,     4,    62,    35,    33,    63,    80,
      42,     2,     3,     4,   133,    64,   105,   186,   127,    65,
     201,    66,   202,    67,   129,     0,    43,    68,    44,    45,
      36,    37,   130,     0,    38,    39,    40,    41,     0,    46,
       0,     0,     0,     0,    62,     0,     0,    63,     0,    42,
       0,     0,     0,     0,    64,     0,     0,     0,   156,     0,
     157,     0,    67,     0,     0,    43,    68,    44,    45,    36,
      37,     0,     0,    38,    39,    40,    41,     0,    46,     0,
       0,     0,     0,   112,     0,     0,    36,    37,    42,     0,
      38,    39,    40,    41,     0,     0,     0,    88,     0,     0,
      89,    90,    91,     0,    43,    42,    44,    45,     0,     0,
       0,     0,   115,    92,   103,     0,     0,    46,     0,     0,
       0,     0,     0,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    93,    94,    95,   116,   117,
     118,   119,   120,   121
};

static const yytype_int16 yycheck[] =
{
      26,     0,    26,    42,    34,     8,    54,     6,    82,    39,
      43,   138,    24,    36,     5,     6,    32,    43,     9,    10,
      11,    12,    27,    39,   175,     0,   177,    20,    54,    68,
      53,    24,   183,    24,    39,   109,    39,    27,    64,    65,
      64,    65,   193,   194,   138,    53,    85,   138,   175,    40,
     177,    42,    43,   101,    87,    36,   183,    54,    55,    56,
      86,    87,    53,   137,   103,   139,   193,   194,    53,   138,
      96,    97,    53,   138,    25,   101,   115,   116,   117,   118,
     119,   175,   138,   177,   175,    34,   177,    19,    19,   183,
      39,    32,   183,    12,    26,    26,    15,   171,    39,   193,
     194,    19,   193,   194,    30,    31,   175,   106,   177,     5,
     175,   150,   177,    53,   183,   141,    20,   141,   183,   175,
      11,   177,    13,    14,   193,   194,    26,   183,   193,   194,
     156,    21,   156,    25,   133,    20,    24,   193,   194,    20,
      39,    38,     5,     6,    21,    19,     9,    10,    11,    12,
      19,    18,   178,    25,   178,   181,    19,   181,    19,    22,
      23,    24,    26,    21,    34,   175,    29,   177,    25,   195,
      33,   195,    35,   183,    37,    34,     6,    40,    41,    42,
      43,     5,     6,   193,   194,     9,    10,    11,    12,   135,
      53,    53,    54,    55,    56,    19,    25,    23,    22,    31,
      24,    54,    55,    56,    57,    29,    61,   176,    86,    33,
     198,    35,   198,    37,    96,    -1,    40,    41,    42,    43,
       5,     6,    97,    -1,     9,    10,    11,    12,    -1,    53,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    22,    -1,    24,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    -1,
      35,    -1,    37,    -1,    -1,    40,    41,    42,    43,     5,
       6,    -1,    -1,     9,    10,    11,    12,    -1,    53,    -1,
      -1,    -1,    -1,    19,    -1,    -1,     5,     6,    24,    -1,
       9,    10,    11,    12,    -1,    -1,    -1,    12,    -1,    -1,
      15,    16,    17,    -1,    40,    24,    42,    43,    -1,    -1,
      -1,    -1,    18,    28,    20,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    50,    51,    52,    44,    45,
      46,    47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    54,    55,    56,    59,    60,    61,    62,    68,
      69,    24,     0,    61,    53,    64,    65,    66,    68,    70,
      71,    72,    20,    24,    19,    26,    27,    53,    73,    74,
      25,    19,     5,    70,    53,    65,     5,     6,     9,    10,
      11,    12,    24,    40,    42,    43,    53,    94,    95,    96,
      97,    99,   101,   103,   104,   105,   106,   107,   108,   111,
      20,    26,    19,    22,    29,    33,    35,    37,    41,    75,
      76,    77,    83,    85,    90,    91,    92,    93,    94,   106,
      72,    21,    25,    93,    96,    24,    39,    38,    12,    15,
      16,    17,    28,    50,    51,    52,    98,   100,    11,    13,
      14,   102,   103,    20,    21,    74,    78,    94,    94,    36,
      53,    19,    19,    93,    19,    18,    44,    45,    46,    47,
      48,    49,    75,    25,    93,   109,   110,    95,    96,    99,
     101,   103,    93,    57,    63,    67,    68,    79,    32,    34,
      75,    18,    87,    19,    93,    93,    93,    93,    93,    25,
      26,    21,    68,    64,    23,    75,    33,    35,    76,    77,
      80,    81,    82,    83,    85,    88,    89,    91,    92,    75,
      94,    34,    93,    19,    94,    36,    53,    30,    31,    84,
      86,     8,    75,    34,    81,    82,    87,    81,    82,    94,
      94,    81,    82,    34,    32,    27,    81,    82,    81,    82,
      94,    84,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    62,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    73,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    76,    76,
      77,    78,    78,    79,    79,    80,    80,    80,    80,    81,
      81,    81,    82,    82,    83,    84,    84,    85,    85,    85,
      86,    86,    86,    86,    87,    87,    88,    88,    88,    89,
      89,    89,    90,    90,    90,    91,    91,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   102,   103,
     103,   104,   104,   104,   105,   105,   106,   106,   107,   107,
     107,   108,   109,   109,   110,   110,   111,   111,   111,   111,
     111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     3,     3,
       1,     1,     3,     1,     4,     2,     1,     1,     1,     1,
       6,     5,     1,     0,     3,     1,     2,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       4,     2,     0,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     2,     4,     4,     5,
       4,     5,     4,     2,     4,     6,     4,     3,     5,     4,
       3,     5,     4,     3,     5,     2,     3,     2,     3,     3,
       3,     3,     3,     2,     2,     1,     3,     1,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     1,
       1,     4,     1,     0,     3,     1,     1,     1,     1,     1,
       1
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
#line 60 "parser.y" /* yacc.c:1646  */
    {
                  (yyval.Tree)=(yyvsp[0].Tree);
                  syntaxTree = (yyval.Tree);
                  if(cdbug) printf("<-program\n");
               }
#line 1481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-declarationList declaration\n");
                     (yyval.Tree) = addSibling((yyvsp[-1].Tree),(yyvsp[0].Tree));
                  }
#line 1490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-declarationList declaration\n");
                     (yyval.Tree) = (yyvsp[0].Tree);
                  }
#line 1499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 80 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-declaration varDeclaration\n");
                     (yyval.Tree) = (yyvsp[0].Tree);
                  }
#line 1508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 86 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-declaration funDeclaration\n");
                     (yyval.Tree)=(yyvsp[0].Tree);
                  }
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 93 "parser.y" /* yacc.c:1646  */
    {
                        if(cdbug) printf("<-varDeclaration typeSpecifier varDeclList SEMI\n");
                        (yyval.Tree) = (yyvsp[-1].Tree);
                        typeToSibs((yyval.Tree), (yyvsp[-2].type));
                     }
#line 1527 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 101 "parser.y" /* yacc.c:1646  */
    {
                        if(cdbug) printf("<-scopedVarDeclaration scopedTypeSpecifier varDeclList\n");
                        (yyval.Tree) = (yyvsp[-1].Tree);
                        typeToSibs((yyval.Tree), (yyvsp[-2].type));
                     }
#line 1537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 109 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-varDeclList varDeclList COM varDeclInitialize ADD SIBLINGS 6\n");
               (yyval.Tree) = addSibling((yyvsp[-2].Tree),(yyvsp[0].Tree));
            }
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-varDeclList varDeclInitialize\n");
               (yyval.Tree) = (yyvsp[0].Tree);
            }
#line 1555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 122 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-varDeclInitialize varDeclId\n");
                     (yyval.Tree) = (yyvsp[0].Tree);
                  }
#line 1564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 128 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-varDeclInitialize varDeclId COL simpleExpression \n");
                     (yyval.Tree)=(yyvsp[-2].Tree);
                     (yyval.Tree)->child[0] = (yyvsp[0].Tree);
                  }
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 136 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-varDeclId ID\n");
               (yyval.Tree) = newDecNode(VarK, (yyvsp[0].Token_Data)->Line_Num);
               (yyval.Tree)->attr.name = strdup((yyvsp[0].Token_Data)->Token_Str);
            }
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 143 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-varDeclId ID LIndex         NUMCONST RIndex \n");
               (yyval.Tree) = newDecNode(VarK, (yyvsp[-3].Token_Data)->Line_Num);
               (yyval.Tree)->attr.name = strdup((yyvsp[-3].Token_Data)->Token_Str); 
               (yyval.Tree)->TD = (yyvsp[-3].Token_Data);
               (yyval.Tree)->attr.value = (yyvsp[-1].Token_Data)->Num_Val;    //posibly not needed
               (yyval.Tree)->isArray = true;
               (yyval.Tree)->attr.op = (yyvsp[-2].Token_Data)->Token_Class;
          }
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 157 "parser.y" /* yacc.c:1646  */
    {
                        if(cdbug) printf("<-scopedTypeSpecifier STATIC typeSpecifier \n");
                        (yyval.type) = (yyvsp[0].type);
                     }
#line 1607 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 163 "parser.y" /* yacc.c:1646  */
    {
                       if(cdbug) printf("<-scopedTypeSpecifier typeSpecifier\n");
                        (yyval.type) = (yyvsp[0].type);
                    }
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 170 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-typeSpecifier INT \n");
                  (yyval.type) = Integer;             
               }
#line 1625 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 176 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-typeSpecifier BOOL\n");
                  (yyval.type) = Bool;
               }
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 181 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-typeSpecifier CHAR\n");
                  (yyval.type) = Char;
               }
#line 1643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 189 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-funDeclaration typeSpecifier ID LP params RP statement  \n");
                  (yyval.Tree) = newDecNode(FuncK, (yyvsp[-4].Token_Data)->Line_Num); 
                  (yyval.Tree)->attr.name = strdup((yyvsp[-4].Token_Data)->Token_Str);  
                  (yyval.Tree)->type = (yyvsp[-5].type);
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 199 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-funDeclaration ID LP params RP statement  \n");
                  (yyval.Tree) = newDecNode(FuncK, (yyvsp[-4].Token_Data)->Line_Num); 
                  (yyval.Tree)->attr.name = strdup((yyvsp[-4].Token_Data)->Token_Str);
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 209 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-params paramList\n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 215 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-params empty\n");
            (yyval.Tree) = NULL;
         }
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 222 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-paramList paramList SEMI paramTypeList ADD SIBLINGS 13\n");
               (yyval.Tree) = addSibling((yyvsp[-2].Tree),(yyvsp[0].Tree));
            }
#line 1695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 228 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-paramList paramTypeList\n");
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 1704 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 235 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-paramTypeList typeSpecifier paramIdList\n");
                  (yyval.Tree) = (yyvsp[0].Tree);
                  typeToSibs((yyval.Tree), (yyvsp[-1].type));      
               }
#line 1714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 243 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-declarationList paramIdList COM paramId ADD SIBLINGS 15\n");
               (yyval.Tree) = addSibling((yyvsp[-2].Tree),(yyvsp[0].Tree));
            }
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 249 "parser.y" /* yacc.c:1646  */
    {  
               if(cdbug) printf("<-paramIdList paramId\n");
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 1732 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 256 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-paramId ID\n");
            (yyval.Tree) = newDecNode(ParamK, (yyvsp[0].Token_Data)->Line_Num); 
            (yyval.Tree)->attr.name = strdup((yyvsp[0].Token_Data)->Token_Str); 
         }
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 263 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-paramId ID LIndex RIndex\n");
            (yyval.Tree) = newDecNode(ParamK, (yyvsp[-2].Token_Data)->Line_Num);
            (yyval.Tree)->attr.name = strdup((yyvsp[-2].Token_Data)->Token_Str);  
            (yyval.Tree)->isArray = true;
         }
#line 1753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 272 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-statementexpressionStmt\n");}
#line 1759 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 273 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-statement compoundStmt\n");}
#line 1765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree) = (yyvsp[0].Tree); if(cdbug) printf("<-statement matchedIf : %d\n", (yyvsp[0].Tree)->attr.value);}
#line 1771 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree) = (yyvsp[0].Tree); if(cdbug) printf("<-statement unmatchedIf\n");}
#line 1777 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-statement iterationStmt\n");}
#line 1783 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 277 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-statement returnStmt\n");}
#line 1789 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 278 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-statement breakStmt\n");}
#line 1795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 284 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-expressionStmt expression SEMI\n");
                  (yyval.Tree)=(yyvsp[-1].Tree);
               }
#line 1804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 290 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-expressionStmt SEMI\n");
                     (yyval.Tree)=NULL;
                  }
#line 1813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 298 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-compoundStmt LB localDeclarations statementList RB\n");
                  (yyval.Tree) = newStmtNode(CompoundK, (yyvsp[-3].Token_Data)->Line_Num);
                  //$$->attr.op = $1->Token_Class;
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[-1].Tree);
               }
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 308 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-localDeclarations localDeclarations scopedVarDeclaration\n");
                     (yyval.Tree) = addSibling((yyvsp[-1].Tree),(yyvsp[0].Tree));
                  }
#line 1834 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 313 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-localDeclarations empty\n");
                     (yyval.Tree)=NULL;
                  }
#line 1843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 320 "parser.y" /* yacc.c:1646  */
    {
                 if(cdbug) printf("<-statementList statementList statement ADD SIBLINGS 21\n");
                 (yyval.Tree) = addSibling((yyvsp[-1].Tree),(yyvsp[0].Tree));
              }
#line 1852 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 325 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-statementList empty\n");
                  (yyval.Tree)=NULL;
               }
#line 1861 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 331 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-partialStmt expressionStmt\n");}
#line 1867 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 332 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-partialStmt compoundStmt\n");}
#line 1873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 333 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-partialStmt returnStmt\n");}
#line 1879 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 334 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-partialStmt breakStmt\n");}
#line 1885 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 351 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-matched matchedIf \n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 1894 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 356 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-matched matchedWhile \n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 1903 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 361 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-matched partialStmt \n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 1912 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 368 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-unmatched unmatchedIf \n");
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 1921 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 373 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-unmatched unmatchedWhile \n");
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 1930 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 380 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-matchedIf IF simpleExpression THEN matched matchedElse : %d\n", (yyvsp[0].Tree)->attr.value);
               (yyval.Tree) = newStmtNode(IfK, (yyvsp[-4].Token_Data)->Line_Num); 
               (yyval.Tree)->child[0] = (yyvsp[-3].Tree);
               (yyval.Tree)->child[1] = (yyvsp[-1].Tree);
               (yyval.Tree)->child[2] = (yyvsp[0].Tree);
               
            }
#line 1943 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 391 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-matchedElse ELSIF simpleExpression THEN matched matchedElse\n");
               (yyval.Tree) = newStmtNode(ElsifK, (yyvsp[-4].Token_Data)->Line_Num); 
               (yyval.Tree)->child[0] = (yyvsp[-3].Tree);
               (yyval.Tree)->child[1] = (yyvsp[-1].Tree);
               (yyval.Tree)->child[2] = (yyvsp[0].Tree);
            }
#line 1955 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 399 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-matchedElse ELSE matched : %d\n", (yyvsp[0].Tree)->attr.value);
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 1964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 405 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedIf IF simpleExpression THEN matched \n");
                  (yyval.Tree) = newStmtNode(IfK, (yyvsp[-3].Token_Data)->Line_Num); 
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
            }
#line 1975 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 412 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedIf IF simpleExpression THEN unmatched \n");
                  (yyval.Tree) = newStmtNode(IfK, (yyvsp[-3].Token_Data)->Line_Num); 
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
            }
#line 1986 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 419 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedIf IF simpleExpression THEN matched unmatchedElse \n");
                  (yyval.Tree) = newStmtNode(IfK, (yyvsp[-4].Token_Data)->Line_Num); 
                  (yyval.Tree)->child[0] = (yyvsp[-3].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[-1].Tree);
                  (yyval.Tree)->child[2] = (yyvsp[0].Tree);
                 // $$ = addSibling($2,$5);
            }
#line 1999 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 429 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedElse ELSIF simpleExpression THEN matched \n");
                  (yyval.Tree) = newStmtNode(ElsifK, (yyvsp[-3].Token_Data)->Line_Num); 
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2010 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 436 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedElse ELSIF simpleExpression THEN matched unmatchedElse \n");
                  (yyval.Tree) = newStmtNode(ElsifK, (yyvsp[-4].Token_Data)->Line_Num); 
                  (yyval.Tree)->child[0] = (yyvsp[-3].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[-1].Tree);
                  (yyval.Tree)->child[2] = (yyvsp[0].Tree);
               }
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 444 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedElse ELSIF simpleExpression THEN unmatched \n");
                  (yyval.Tree) = newStmtNode(ElsifK, (yyvsp[-3].Token_Data)->Line_Num); 
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2033 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 451 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedElse ELSE unmatched \n");
                  (yyval.Tree) = (yyvsp[0].Tree);
               }
#line 2042 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 459 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-iterationRange ID EQ simpleExpression RANGE simpleExpression \n");
                  (yyval.Tree) = newStmtNode(RangeK, (yyvsp[-3].Token_Data)->Line_Num);      
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
                  (yyval.Tree)->child[2] = newExpNode(ConstantK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->child[2]-> attr.value = 1;
               }
#line 2055 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 469 "parser.y" /* yacc.c:1646  */
    {  
                  if(cdbug) printf("<-iterationRange ID EQ simpleExpression RANGE simpleExpression COL simpleExpression\n");
                  (yyval.Tree) = newStmtNode(RangeK, (yyvsp[-5].Token_Data)->Line_Num); 
                  
                  (yyval.Tree)->child[0] = (yyvsp[-4].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[2] = (yyvsp[0].Tree);
               }
#line 2068 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 480 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedWhile WHILE simpleExpression DO unmatched\n");
                  (yyval.Tree) = newStmtNode(WhileK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.op = (yyvsp[-3].Token_Data)->Token_Class; 
                  (yyval.Tree)->child[0]=(yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2080 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 488 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedWhile LOOP FOREVER unmatched\n");
                  (yyval.Tree) = newStmtNode(LoopForeverK, (yyvsp[-2].Token_Data)->Line_Num); 
                  (yyval.Tree)->attr.op = (yyvsp[-2].Token_Data)->Token_Class;
                  (yyval.Tree)->child[1]=(yyvsp[0].Tree); 
               }
#line 2091 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 495 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedWhile LOOP iterationRange DO unmatched\n");
                  (yyval.Tree) = newStmtNode(LoopK, (yyvsp[-4].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.op = (yyvsp[-4].Token_Data)->Token_Class;  (yyval.Tree)->type = Void;
                  (yyval.Tree)->child[0] = newExpNode(IdK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->child[0]-> attr.name = strdup((yyvsp[-3].Token_Data)->Token_Str);
                  (yyval.Tree)->child[1] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[2] = (yyvsp[0].Tree); 
               }
#line 2105 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 507 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedWhile WHILE simpleExpression DO unmatched\n");
                  (yyval.Tree) = newStmtNode(WhileK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.op = (yyvsp[-3].Token_Data)->Token_Class;  
                  (yyval.Tree)->child[0]=(yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2117 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 515 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedWhile LOOP FOREVER unmatched\n");
                  (yyval.Tree) = newStmtNode(LoopForeverK, (yyvsp[-2].Token_Data)->Line_Num); 
                  (yyval.Tree)->attr.op = (yyvsp[-2].Token_Data)->Token_Class;
                  (yyval.Tree)->child[1]=(yyvsp[0].Tree); 
               }
#line 2128 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 522 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedWhile LOOP iterationRange DO unmatched\n");
                  (yyval.Tree) = newStmtNode(LoopK, (yyvsp[-4].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.op = (yyvsp[-4].Token_Data)->Token_Class;  
                  (yyval.Tree)->child[0] = newExpNode(IdK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->child[0]->attr.name = strdup((yyvsp[-3].Token_Data)->Token_Str);
                  (yyval.Tree)->child[1] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[2] = (yyvsp[0].Tree);   
               }
#line 2142 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 535 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-iterationStmt declaration\n");
                  (yyval.Tree) = newStmtNode(WhileK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.op = (yyvsp[-3].Token_Data)->Token_Class;  
                  (yyval.Tree)->type = Void;
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);  
               }
#line 2155 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 545 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-iterationStmt declaration\n");
                  (yyval.Tree) = newStmtNode(LoopForeverK, (yyvsp[-2].Token_Data)->Line_Num); 
                  (yyval.Tree)->attr.op = (yyvsp[-2].Token_Data)->Token_Class;
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
               }
#line 2166 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 553 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-iterationStmt declaration\n");
                  (yyval.Tree) = newStmtNode(LoopK, (yyvsp[-4].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.op = (yyvsp[-4].Token_Data)->Token_Class;  (yyval.Tree)->type = Void;
                  (yyval.Tree)->child[0] = newExpNode(IdK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->child[0]->attr.name = strdup((yyvsp[-3].Token_Data)->Token_Str);
                  (yyval.Tree)->child[1] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[2] = (yyvsp[0].Tree);
               }
#line 2180 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 566 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-returnStmt declaration\n");
               (yyval.Tree) = newStmtNode(ReturnK, (yyvsp[-1].Token_Data)->Line_Num);
               (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;
            }
#line 2190 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 573 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-returnStmt declaration\n");
               (yyval.Tree) = newStmtNode(ReturnK, (yyvsp[-2].Token_Data)->Line_Num); 
               (yyval.Tree)->attr.op = (yyvsp[-2].Token_Data)->Token_Class;  
               (yyval.Tree)->type = (yyvsp[-1].Tree)->type;
               (yyval.Tree)->child[0] = (yyvsp[-1].Tree);
            }
#line 2202 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 583 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-breakStmt declaration\n");
               (yyval.Tree) = newStmtNode(BreakK, (yyvsp[-1].Token_Data)->Line_Num);
               (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;
            }
#line 2212 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 592 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-expression mutable EQ          expression\n");
               (yyval.Tree) = newExpNode(AssignK, (yyvsp[-1].Token_Data)->Line_Num); 
               (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class; 
               (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
               (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
            }
#line 2224 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 601 "parser.y" /* yacc.c:1646  */
    {
              if(cdbug) printf("<-expression mutable ADDASS expression\n");
              (yyval.Tree) = newExpNode(AssignK, (yyvsp[-1].Token_Data)->Line_Num); 
              (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;  
              (yyval.Tree)->type = Integer;
              (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
              (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
            }
#line 2237 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 611 "parser.y" /* yacc.c:1646  */
    {
              if(cdbug) printf("<-expression mutable SUBASS expression\n");
              (yyval.Tree) = newExpNode(AssignK, (yyvsp[-1].Token_Data)->Line_Num); 
              (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;  
              (yyval.Tree)->type = Integer;
              (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
              (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
            }
#line 2250 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 621 "parser.y" /* yacc.c:1646  */
    {
              if(cdbug) printf("<-expression mutable MULASS expression\n");
              (yyval.Tree) = newExpNode(AssignK, (yyvsp[-1].Token_Data)->Line_Num); 
              (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;  
              (yyval.Tree)->type = Integer;
              (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
              (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
            }
#line 2263 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 631 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-expression mutable DIVASS expression\n");
               (yyval.Tree) = newExpNode(AssignK, (yyvsp[-1].Token_Data)->Line_Num); 
               (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;  
               (yyval.Tree)->type = Integer;
               (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
               (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
            }
#line 2276 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 641 "parser.y" /* yacc.c:1646  */
    {
              if(cdbug) printf("<-expression mutable INC\n");
              (yyval.Tree) = newExpNode(AssignK, (yyvsp[0].Token_Data)->Line_Num); 
              (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
              (yyval.Tree)->type = Integer;
              (yyval.Tree)->child[0]= (yyvsp[-1].Tree);
            }
#line 2288 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 650 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-expression mutable DEC\n");
               (yyval.Tree) = newExpNode(AssignK, (yyvsp[0].Token_Data)->Line_Num);
               (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
               (yyval.Tree)->type = Integer;
               (yyval.Tree)->child[0]= (yyvsp[-1].Tree);
            }
#line 2300 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 659 "parser.y" /* yacc.c:1646  */
    {
              if(cdbug) printf("<-expression simpleExpression\n");
              (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 2309 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 666 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-simpleExpression simpleExpression OR andExpression \n");
                     (yyval.Tree) = newExpNode(OpK, (yyvsp[-1].Token_Data)->Line_Num); 
                     (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;  
                     (yyval.Tree)->type = Bool;
                     (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
                     (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
                  }
#line 2322 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 676 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-simpleExpression andExpression\n");
                     (yyval.Tree)=(yyvsp[0].Tree);
                  }
#line 2331 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 683 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-andExpression andExpression AND unaryRelExpression\n");
                  (yyval.Tree) = newExpNode(OpK, (yyvsp[-1].Token_Data)->Line_Num); 
                  (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;  
                  (yyval.Tree)->type = Bool;
                  (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
               }
#line 2344 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 693 "parser.y" /* yacc.c:1646  */
    {
                 if(cdbug) printf("<-andExpression unaryRelExpression\n");
                 (yyval.Tree)=(yyvsp[0].Tree);
                 
                 
              }
#line 2355 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 702 "parser.y" /* yacc.c:1646  */
    {
                        if(cdbug) printf("<-unaryRelExpression NOT unaryRelExpression\n");
                        (yyval.Tree) = newExpNode(OpK, (yyvsp[-1].Token_Data)->Line_Num); 
                        (yyval.Tree)->attr.op =(yyvsp[-1].Token_Data)->Token_Class;  
                        (yyval.Tree)->type = Bool;
                        (yyval.Tree)->child[0] = (yyvsp[0].Tree); 
                     }
#line 2367 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 711 "parser.y" /* yacc.c:1646  */
    {
                        if(cdbug) printf("<-unaryRelExpression relExpression\n");
                        (yyval.Tree) = (yyvsp[0].Tree);
                     }
#line 2376 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 718 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-relExpression sumExpression relop sumExpression\n");
                  (yyval.Tree) = (yyvsp[-1].Tree);
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2387 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 726 "parser.y" /* yacc.c:1646  */
    {
                 if(cdbug) printf("<-relExpression sumExpression\n");
                 (yyval.Tree)=(yyvsp[0].Tree);
               }
#line 2396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 733 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-relop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Bool; 
      }
#line 2407 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 741 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-relop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Bool; 
      }
#line 2418 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 749 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-relop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Bool; 
      }
#line 2429 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 757 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-relop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Bool; 
      }
#line 2440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 765 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-relop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Bool; 
      }
#line 2451 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 773 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-relop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Bool; 
      }
#line 2462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 782 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-sumExpression sumExpression sumop mulExpression \n");
                  (yyval.Tree) = (yyvsp[-1].Tree);
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2473 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 790 "parser.y" /* yacc.c:1646  */
    {
                 if(cdbug) printf("<-sumExpression mulExpression\n");
                 (yyval.Tree)=(yyvsp[0].Tree);
               }
#line 2482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 797 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-sumop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class; 
         (yyval.Tree)->type = Integer; 
      }
#line 2493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 805 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-sumop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Integer; 
      }
#line 2504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 814 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-mulExpression mulExpression mulop unaryExpression \n");
                  (yyval.Tree) = (yyvsp[-1].Tree); 
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2515 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 822 "parser.y" /* yacc.c:1646  */
    {
                 if(cdbug) printf("<-mulExpression unaryExpression\n");
                 (yyval.Tree)=(yyvsp[0].Tree);
               }
#line 2524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 829 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-mulop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Integer;
      }
#line 2535 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 837 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-mulop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Integer;
      }
#line 2546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 845 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-mulop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Integer;
      }
#line 2557 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 854 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-unaryExpression unaryop unaryExpression \n");
                     (yyval.Tree) = (yyvsp[-1].Tree);
                     (yyval.Tree)->child[0] = (yyvsp[0].Tree);
                  }
#line 2567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 861 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-unaryExpression factor\n");
                     (yyval.Tree)=(yyvsp[0].Tree);
                  }
#line 2576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 868 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-unaryop declaration\n");
            (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
            (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
            (yyval.Tree)->type = Integer; 
         }
#line 2587 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 876 "parser.y" /* yacc.c:1646  */
    {
           if(cdbug) printf("<-unaryop declaration\n");
           (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
           (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
           (yyval.Tree)->type = Integer; 
         }
#line 2598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 884 "parser.y" /* yacc.c:1646  */
    {
           if(cdbug) printf("<-unaryop declaration\n");
           (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
           (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
           (yyval.Tree)->type = Integer;
         }
#line 2609 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 893 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-factor immutable\n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 2618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 899 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-factor mutable\n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 2627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 906 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-mutable ID %s\n", (yyvsp[0].Token_Data)->Token_Str);
            (yyval.Tree) = newExpNode(IdK, (yyvsp[0].Token_Data)->Line_Num); 
            (yyval.Tree)->attr.name = strdup((yyvsp[0].Token_Data)->Token_Str); 
         }
#line 2637 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 913 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-mutable mutable LIndex expression RIndex\n");
            (yyval.Tree) = newExpNode(OpK, (yyvsp[-2].Token_Data)->Line_Num);
            //$$ = $3;
            (yyval.Tree)->attr.op = (yyvsp[-2].Token_Data)->Token_Class;
            //$$->kind.expr = OpK;
            //$$->child[0] = $1;
            (yyval.Tree)->child[0] = (yyvsp[-3].Tree);
            (yyval.Tree)->child[1] = (yyvsp[-1].Tree);
         }
#line 2652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 926 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-immutable LP expression RP \n");
               (yyval.Tree) = (yyvsp[-1].Tree);
            }
#line 2661 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 932 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-immutable call\n");
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 2670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 937 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-immutable constant\n");
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 2679 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 944 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-call declaration\n");
         (yyval.Tree) = newExpNode(CallK, (yyvsp[-3].Token_Data)->Line_Num); 
         //$$->type = $3->type;
         (yyval.Tree)->attr.name = strdup((yyvsp[-3].Token_Data)->Token_Str);
         (yyval.Tree)->child[0] = (yyvsp[-1].Tree) ;
      }
#line 2691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 954 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-args declaration\n");
         (yyval.Tree)=(yyvsp[0].Tree);
      }
#line 2700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 960 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-args empty\n");
         (yyval.Tree)=NULL;
      }
#line 2709 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 967 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-argList declaration\n");
            (yyval.Tree) = addSibling((yyvsp[-2].Tree),(yyvsp[0].Tree));
         }
#line 2718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 973 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-argList declaration\n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 2727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 980 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-constant NUMCONST : %d\n", (yyvsp[0].Token_Data)->Num_Val);
            (yyval.Tree) = newExpNode(ConstantK, (yyvsp[0].Token_Data)->Line_Num); 
            (yyval.Tree)-> attr.value = (yyvsp[0].Token_Data)->Num_Val;
            (yyval.Tree)->type = Integer;
         }
#line 2738 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 988 "parser.y" /* yacc.c:1646  */
    {            
            if(cdbug) printf("<-constant CHARCONST\n");
            (yyval.Tree) = newExpNode(ConstantK, (yyvsp[0].Token_Data)->Line_Num); 
            (yyval.Tree)->TD=(yyvsp[0].Token_Data);
            //printf("FOUND |%s|\n", $1->Token_Str);
            (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;
            (yyval.Tree)->type = CharInt;
         }
#line 2751 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 998 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-constant STRINGCONST\n");
            (yyval.Tree) = newExpNode(ConstantK, (yyvsp[0].Token_Data)->Line_Num); 
            (yyval.Tree)-> attr.string = strdup((yyvsp[0].Token_Data)->Raw_Str);
            (yyval.Tree)->type = Char;  
         }
#line 2762 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1006 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-constant FALSE\n");
            (yyval.Tree) = newExpNode(ConstantK, (yyvsp[0].Token_Data)->Line_Num);
            (yyval.Tree)->attr.value = 0;
            (yyval.Tree)->type = Bool;
            (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class; 
         }
#line 2774 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1015 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-constant TRUE\n");
            (yyval.Tree) = newExpNode(ConstantK, (yyvsp[0].Token_Data)->Line_Num);
            (yyval.Tree)->attr.value = 1;
            (yyval.Tree)->type = Bool; 
            (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class; 
         }
#line 2786 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2790 "parser.tab.c" /* yacc.c:1646  */
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
#line 1026 "parser.y" /* yacc.c:1906  */


int main(int argc, char **argv){
   int c = 0;
   bool printSyntaxTree;
 
      // hunt for a string of options
      while ((c = getopt(argc, argv, "cdp")) != -1) {
            switch (c) {
            case 'c':
               cdbug = true;
               break;
            case 'd': 
               yydebug=1;
              if(cdbug) printf("DEBUGGING\n");
              cdbug = true;
               break;
            case 'p': 
               printSyntaxTree=true;
               if(cdbug) printf("PRINTING\n");
               break;
            case '?':
            default: 
               exit(1);
            }
      }

      

   if(argc > 1){
      if((yyin = fopen(argv[argc-1], "r"))){
         //redirects input
      }
      else{
         if(cdbug) printf("File failed to open %s\n", argv[argc-1]);
         
      }
   }
   
   yyparse();

   if(printSyntaxTree) TreePrint(syntaxTree, 0);   
}
