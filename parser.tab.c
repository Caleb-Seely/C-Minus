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
#include "semantic.h"
#include "printtree.h"
#include "IO.h"
#include "codeGen.h"
#include "yyerror.h"

#define YYERROR_VERBOSE
int yylex();
extern int yylineno;
extern FILE *yyin;
static char *savedName;
static int savedLinenno;
static TreeNode *syntaxTree, *TreeTwo;
extern bool bug;
bool cdbug, PAST, STATIC_FLAG, PMEM;
int numErrs, numWarns, Loffset, Goffset, SYNTAXERR;
SymbolTable st;
FILE *code;



#line 93 "parser.tab.c" /* yacc.c:339  */

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
    STATIC = 312,
    unary_MUL = 313,
    unary_MIN = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "parser.y" /* yacc.c:355  */

    TokenData *Token_Data;
    TreeNode *Tree;
    ExpType type;

#line 199 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 216 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  219
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  373

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    73,    79,    86,    92,    98,   101,   110,
     111,   114,   132,   133,   138,   147,   153,   154,   155,   158,
     164,   171,   172,   173,   176,   184,   198,   199,   203,   210,
     216,   219,   225,   230,   238,   248,   259,   260,   261,   262,
     263,   266,   272,   279,   287,   293,   294,   295,   298,   305,
     308,   316,   322,   323,   326,   335,   347,   348,   352,   353,
     354,   355,   356,   357,   358,   363,   371,   379,   383,   394,
     395,   398,   403,   410,   415,   422,   423,   424,   425,   428,
     433,   438,   443,   446,   451,   458,   468,   469,   472,   480,
     486,   488,   495,   502,   512,   513,   515,   522,   530,   537,
     543,   547,   559,   569,   570,   573,   582,   589,   602,   603,
     604,   605,   606,   609,   617,   624,   637,   638,   642,   652,
     660,   673,   674,   680,   688,   700,   710,   720,   730,   740,
     750,   760,   770,   780,   786,   787,   789,   790,   791,   792,
     793,   795,   796,   797,   798,   799,   801,   802,   803,   804,
     805,   809,   819,   825,   826,   827,   830,   840,   846,   847,
     848,   851,   860,   866,   869,   877,   883,   884,   885,   888,
     896,   904,   912,   920,   928,   937,   945,   951,   952,   953,
     956,   964,   973,   981,   987,   988,   989,   992,  1000,  1008,
    1017,  1024,  1030,  1033,  1042,  1051,  1061,  1067,  1074,  1084,
    1097,  1098,  1101,  1110,  1115,  1121,  1125,  1135,  1136,  1139,
    1145,  1152,  1161,  1167,  1168,  1171,  1181,  1194,  1203,  1214
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
  "INT", "BOOL", "CHAR", "STATIC", "unary_MUL", "unary_MIN", "$accept",
  "program", "declarationList", "declaration", "varDeclaration",
  "scopedVarDeclaration", "varDeclList", "varDeclInitialize", "varDeclId",
  "scopedTypeSpecifier", "typeSpecifier", "funDeclaration", "params",
  "paramList", "paramTypeList", "paramIdList", "paramId", "statement",
  "expressionStmt", "compoundStmt", "localDeclarations", "statementList",
  "partialStmt", "matched", "unmatched", "matchedIf", "matchedElse",
  "unmatchedIf", "unmatchedElse", "iterationRange", "matchedWhile",
  "unmatchedWhile", "iterationStmt", "returnStmt", "breakStmt",
  "expression", "simpleExpression", "andExpression", "unaryRelExpression",
  "relExpression", "relop", "sumExpression", "sumop", "mulExpression",
  "mulop", "unaryExpression", "unaryop", "factor", "mutable", "immutable",
  "call", "args", "argList", "constant", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -278

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-278)))

#define YYTABLE_NINF -211

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,    48,    -2,  -278,  -278,  -278,   157,    61,  -278,  -278,
      38,  -278,   203,    10,     9,  -278,   106,    54,  -278,  -278,
     126,   300,   113,  -278,    43,   879,   327,  -278,    45,   896,
      99,   128,   111,   143,  -278,  -278,   129,  -278,     6,  -278,
    2268,  -278,  -278,  -278,  -278,  -278,  -278,   936,   953,  -278,
    -278,   336,   217,   152,  -278,  -278,   425,   328,  -278,  1791,
    -278,   154,  -278,  -278,  -278,  -278,   207,     6,  -278,  2268,
     217,   293,   289,   253,   250,  -278,   597,    87,    99,   254,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
     993,  1010,  -278,  -278,  -278,  1807,  1831,  1847,  2016,   265,
     217,   476,   900,  -278,   307,   822,   318,  1050,  1067,  1871,
    1887,  1911,   343,  -278,  1107,  -278,  -278,  -278,   133,   323,
     134,  1932,  -278,   393,  1124,  1164,   -21,   312,   839,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,   332,  -278,  -278,
     642,   900,  -278,  2268,   217,   262,   281,    44,   192,   328,
     343,  -278,  1181,  1221,  1238,  1278,  1295,  -278,  -278,  -278,
    1335,  1352,  1392,  1409,  1449,  -278,  -278,  -278,  1974,  -278,
     334,   326,  -278,  2268,   152,   900,  -278,   281,    44,   192,
     328,   343,  -278,  2016,   341,   342,  -278,  -278,   342,  -278,
    -278,  -278,   450,  2058,   139,  2088,   161,   687,    18,  -278,
    -278,   348,  -278,  1932,  -278,  2016,  -278,  2016,  -278,  2016,
    -278,  2016,  -278,  2016,  -278,  2016,  -278,  2016,  -278,  2016,
    -278,  2016,  -278,  2016,  -278,  1107,  -278,  1466,  -278,   507,
      15,   293,  -278,   136,   145,   552,   732,   777,   687,   687,
    1932,  -278,   337,   879,   339,  -278,  -278,  2016,  -278,  -278,
    -278,  -278,   130,  -278,   175,   201,  -278,  -278,  1932,  1506,
    1523,    91,  -278,  -278,  -278,    27,  -278,  -278,  -278,  -278,
    1563,   112,    27,  -278,  -278,  -278,  -278,  -278,   687,    12,
     687,  -278,  -278,  -278,  2118,   172,  2148,   249,  -278,   732,
      23,   777,  1580,  -278,  -278,  2178,   264,   777,    23,  -278,
    -278,  -278,  1620,  -278,   732,   732,   732,   732,  -278,   344,
     345,  -278,  -278,  2268,   205,   777,   777,  -278,     8,  2268,
      25,   295,   295,  -278,  -278,   732,   732,   777,  -278,  -278,
     347,   777,  1637,   732,  1677,  -278,  -278,    27,  -278,   218,
    -278,  2268,   217,  2268,   227,  -278,  -278,  1694,  1734,   -10,
    -278,   732,  2208,   243,  2238,   279,   218,   359,   295,   732,
     777,   218,   218,    13,   306,   306,   218,   218,  1751,  2268,
     273,   777,   306
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    31,    32,    33,     0,     0,     4,     5,
       0,     6,    18,    24,     0,    15,    19,     0,     1,     3,
      40,    24,     0,    27,     0,     0,     0,     9,     0,     0,
      38,     0,     0,    41,    44,    10,     0,     8,    23,    17,
       0,   215,   216,   217,   195,   194,   193,     0,     0,   219,
     218,   198,    21,   152,   157,   162,   165,   176,   183,     0,
     191,   197,   196,   203,   204,    26,     0,    16,    14,    22,
      20,     0,    49,    54,    48,    51,     0,     0,    36,     0,
     187,   181,   189,   188,   180,   170,   171,   201,   207,   169,
       0,     0,   174,   173,   172,     0,     0,     0,   205,     0,
     133,   197,   163,   161,     0,     0,     0,     0,     0,     0,
       0,     0,   192,   190,     0,    25,    46,    56,     0,     0,
       0,    39,    66,     0,     0,     0,     0,     0,     0,    35,
      58,    59,    60,    61,    62,    63,    64,     0,    45,    43,
       0,   160,   159,   155,     0,   154,   168,   167,   179,   178,
     186,   185,     0,     0,     0,     0,     0,   135,   134,   202,
       0,     0,     0,     0,     0,   132,   131,   200,   208,   212,
       0,   209,   158,   153,   151,     0,   156,   166,   164,   177,
     175,   184,   182,     0,     0,    57,    53,    55,    52,    50,
      67,    74,     0,    86,     0,     0,     0,     0,     0,   125,
     123,     0,    65,    37,    34,   140,   145,   136,   141,   137,
     142,   138,   143,   139,   144,   150,   126,   146,   127,   147,
     128,   148,   129,   149,   130,     0,   206,     0,   199,     0,
       0,     0,    71,     0,     0,     0,     0,     0,     0,     0,
       0,   119,     0,     0,     0,   124,   214,   213,   211,    69,
      73,    70,     0,    28,     0,     0,    30,    68,    82,     0,
       0,     0,    75,    76,    81,    94,    79,    80,    77,    78,
       0,     0,    91,    92,    83,    84,   121,   118,     0,     0,
       0,    13,    12,    11,    86,     0,   109,     0,   112,     0,
       0,     0,     0,    87,    95,   109,     0,     0,     0,    85,
      93,   122,     0,   120,     0,     0,     0,     0,   106,   111,
       0,    89,    99,    90,     0,     0,     0,   114,     0,   103,
     101,     0,     0,   108,   105,     0,     0,     0,   116,   113,
       0,     0,     0,     0,     0,   110,   107,    96,    98,     0,
     115,   104,   102,    90,     0,    88,    97,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    91,     0,     0,     0,   100,
       0,     0,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -278,  -278,  -278,   376,  -278,  -278,    -7,   310,  -278,  -278,
       1,  -278,   349,  -278,    89,  -278,   252,     0,   -71,   -66,
    -278,   195,  -278,    49,    30,   -59,  -247,   -47,  -260,  -277,
    -278,  -278,  -278,    11,    19,   108,   -18,   -54,   -30,  -278,
     333,   -64,   -50,   -56,   -55,    64,  -278,  -278,   -25,  -278,
    -278,  -278,  -278,  -278
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,   232,    14,    15,    16,   233,
      31,    11,    32,    33,    34,    74,    75,   250,   262,   263,
     192,   229,   264,   308,   273,   266,   293,   274,   294,   244,
     267,   275,   134,   268,   269,   137,   100,    53,    54,    55,
      95,    56,    96,    57,    97,    58,    59,    60,   101,    62,
      63,   170,   171,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    10,   111,    22,    61,   130,   110,    52,    10,   330,
     131,    70,   300,   310,   330,   197,    12,   132,   103,   242,
     302,   318,    17,    61,   309,   299,   356,    23,    27,   133,
      26,   147,   198,    25,    61,    28,   243,   145,   251,    20,
     149,   243,   331,   357,    38,   178,    67,   366,    -7,    12,
     106,   107,   332,   174,   180,    30,    81,   291,   292,    84,
     142,    -2,     1,   106,   107,    61,    61,     1,    13,   130,
      61,    61,    61,   144,   131,   299,   129,   346,   176,   -42,
     363,   132,    61,    61,    61,    61,    61,   135,   138,   144,
     345,    21,   288,   133,   111,   136,    13,   110,    13,    61,
      61,    13,    -7,    -7,    -7,   300,   194,   196,     3,     4,
       5,   345,   346,   288,     2,     3,     4,     5,    71,     2,
       3,     4,     5,   113,   -47,   111,   130,   289,   110,    72,
      78,   131,    37,    29,   185,   188,    76,   254,   132,    28,
     204,     3,     4,     5,   290,    35,   256,    23,   297,   281,
     133,   135,    24,    25,   -42,    99,    28,    18,   130,   136,
     116,   151,    77,   131,   130,   298,   139,   130,   130,   131,
     132,   237,   131,   131,   114,   182,   132,   106,   107,   132,
     132,    73,   133,     3,     4,     5,    73,    73,   133,    13,
     108,   133,   133,   234,   282,   239,    23,   241,   -29,   106,
     107,    24,    25,    80,   305,    82,    83,   130,   135,   130,
     106,   107,   131,   169,   131,    87,   136,    88,    61,   132,
     283,   132,   184,   252,    23,   279,   255,    28,   115,    24,
      25,   133,   253,   133,    61,    61,   201,   327,   276,   277,
     135,   285,   287,   106,   107,    61,   135,   347,   136,   135,
     135,   348,   296,   349,   136,   106,   107,   136,   136,   351,
     206,   208,   210,   212,   214,   106,   107,    61,   216,   218,
     220,   222,   224,   119,   314,   360,   120,    61,   301,   140,
     303,   106,   107,   307,   320,   265,   272,   106,   107,   135,
     159,   135,    80,    81,    82,    83,    84,   136,   316,   136,
     108,  -152,   106,   107,    87,   371,    88,    61,   167,    61,
     117,   106,   107,   362,   342,   118,   344,   106,   107,   172,
      26,   312,    61,    61,    36,   333,   334,   317,    65,   353,
     355,   199,    66,   246,    39,   248,   367,   368,    68,    80,
     311,    82,    83,    61,   187,   328,   329,     3,     4,     5,
     370,   202,   227,   321,   322,   323,   324,   338,   104,   226,
     105,   340,   228,   117,   323,   324,    87,   245,    88,   350,
     186,   278,   189,   280,   335,   336,   337,   243,   325,   326,
     336,   339,   311,    19,     0,    79,   317,   235,     0,   109,
       0,   328,   329,     0,   191,     0,   340,   312,   -72,   -72,
     358,   338,   -72,   -72,   -72,   -72,     0,     0,   364,   365,
       0,     0,   -72,     0,     0,   -72,   -72,   -72,     0,     0,
     372,     0,   -72,     0,     0,     0,   -72,     0,   -72,     0,
     -72,     0,     0,   -72,   -72,   -72,   -72,    81,     0,     0,
      84,    85,    86,     0,     0,     0,   -72,   -72,   -72,   -72,
     -72,   230,     0,    89,     0,   -74,   -74,     0,     0,   -74,
     -74,   -74,   -74,     0,     0,     0,     0,     0,     0,   -74,
       0,     0,   -74,   -74,   -74,    92,    93,    94,     0,   -74,
       0,     0,     0,   -74,     0,   -74,     0,   -74,     0,     0,
     -74,   -74,   -74,   -74,   160,     0,   114,     0,     0,     0,
       0,     0,     0,   -74,     3,     4,     5,   231,   240,     0,
       0,     0,    41,    42,     0,     0,    43,    44,    45,    46,
     161,   162,   163,   164,   165,   166,   122,     0,     0,   123,
     249,    47,     0,     0,     0,     0,   124,     0,     0,     0,
     125,     0,   126,     0,   127,     0,     0,    48,   128,    49,
      50,     0,     0,   240,     0,     0,     0,    41,    42,     0,
      51,    43,    44,    45,    46,     0,     0,     0,     0,     0,
       0,   122,     0,     0,   123,   257,    47,     0,     0,     0,
       0,   124,     0,     0,     0,   125,     0,   126,     0,   127,
       0,     0,    48,   128,    49,    50,     0,     0,   121,     0,
       0,     0,    41,    42,     0,    51,    43,    44,    45,    46,
       0,     0,     0,     0,     0,     0,   122,     0,     0,   123,
       0,    47,     0,     0,     0,     0,   124,     0,     0,     0,
     125,     0,   126,     0,   127,     0,     0,    48,   128,    49,
      50,     0,     0,   203,     0,     0,     0,    41,    42,     0,
      51,    43,    44,    45,    46,     0,     0,     0,     0,     0,
       0,   122,     0,     0,   123,     0,    47,     0,     0,     0,
       0,   124,     0,     0,     0,   125,     0,   126,     0,   127,
       0,     0,    48,   128,    49,    50,     0,     0,   240,     0,
       0,     0,    41,    42,     0,    51,    43,    44,    45,    46,
       0,     0,     0,     0,     0,     0,   122,     0,     0,   123,
       0,    47,     0,     0,     0,     0,   124,     0,     0,     0,
     125,     0,   126,     0,   127,     0,     0,    48,   128,    49,
      50,     0,     0,   258,     0,     0,     0,    41,    42,     0,
      51,    43,    44,    45,    46,     0,     0,     0,     0,     0,
       0,   122,     0,     0,   123,     0,    47,     0,     0,     0,
       0,   259,     0,     0,     0,   260,     0,   261,     0,   127,
       0,     0,    48,   128,    49,    50,     0,     0,   258,     0,
       0,     0,    41,    42,     0,    51,    43,    44,    45,    46,
       0,     0,     0,     0,     0,     0,   122,     0,     0,   123,
       0,    47,     0,     0,     0,     0,   124,     0,     0,     0,
     270,     0,   271,     0,   127,     0,     0,    48,   128,    49,
      50,     0,     0,   168,     0,     0,     0,    41,    42,     0,
      51,    43,    44,    45,    46,     0,     0,     0,     0,     0,
     183,     0,     0,     0,    41,    42,    47,  -210,    43,    44,
      45,    46,     0,     0,     0,     0,     0,     0,   200,     0,
       0,     0,    48,    47,    49,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,    48,
      40,    49,    50,     0,    41,    42,     0,     0,    43,    44,
      45,    46,    51,     0,     0,     0,     0,    69,     0,     0,
       0,    41,    42,    47,     0,    43,    44,    45,    46,     0,
       0,    80,    81,    82,    83,    84,    85,    86,     0,    48,
      47,    49,    50,    87,     0,    88,     0,     0,    89,     0,
       0,     0,    51,     0,     0,     0,    48,    98,    49,    50,
       0,    41,    42,     0,     0,    43,    44,    45,    46,    51,
      92,    93,    94,     0,   102,     0,     0,     0,    41,    42,
      47,     0,    43,    44,    45,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    47,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,     0,    48,   141,    49,    50,     0,    41,    42,
       0,     0,    43,    44,    45,    46,    51,     0,     0,     0,
       0,   143,     0,     0,     0,    41,    42,    47,     0,    43,
      44,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    47,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
      48,   173,    49,    50,     0,    41,    42,     0,     0,    43,
      44,    45,    46,    51,     0,     0,     0,     0,   175,     0,
       0,     0,    41,    42,    47,     0,    43,    44,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,    47,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,     0,    48,   183,    49,
      50,     0,    41,    42,     0,     0,    43,    44,    45,    46,
      51,     0,     0,     0,     0,   193,     0,     0,     0,    41,
      42,    47,     0,    43,    44,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    47,    49,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,    48,   195,    49,    50,     0,    41,
      42,     0,     0,    43,    44,    45,    46,    51,     0,     0,
       0,     0,   205,     0,     0,     0,    41,    42,    47,     0,
      43,    44,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    47,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
       0,    48,   207,    49,    50,     0,    41,    42,     0,     0,
      43,    44,    45,    46,    51,     0,     0,     0,     0,   209,
       0,     0,     0,    41,    42,    47,     0,    43,    44,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    47,    49,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,    48,   211,
      49,    50,     0,    41,    42,     0,     0,    43,    44,    45,
      46,    51,     0,     0,     0,     0,   213,     0,     0,     0,
      41,    42,    47,     0,    43,    44,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    47,
      49,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,     0,    48,   215,    49,    50,     0,
      41,    42,     0,     0,    43,    44,    45,    46,    51,     0,
       0,     0,     0,   217,     0,     0,     0,    41,    42,    47,
       0,    43,    44,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    47,    49,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,    48,   219,    49,    50,     0,    41,    42,     0,
       0,    43,    44,    45,    46,    51,     0,     0,     0,     0,
     221,     0,     0,     0,    41,    42,    47,     0,    43,    44,
      45,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    47,    49,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,    48,
     223,    49,    50,     0,    41,    42,     0,     0,    43,    44,
      45,    46,    51,     0,     0,     0,     0,   247,     0,     0,
       0,    41,    42,    47,     0,    43,    44,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      47,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,    48,   284,    49,    50,
       0,    41,    42,     0,     0,    43,    44,    45,    46,    51,
       0,     0,     0,     0,   286,     0,     0,     0,    41,    42,
      47,     0,    43,    44,    45,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    47,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,     0,    48,   295,    49,    50,     0,    41,    42,
       0,     0,    43,    44,    45,    46,    51,     0,     0,     0,
       0,   313,     0,     0,     0,    41,    42,    47,     0,    43,
      44,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    47,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,     0,
      48,   319,    49,    50,     0,    41,    42,     0,     0,    43,
      44,    45,    46,    51,     0,     0,     0,     0,   341,     0,
       0,     0,    41,    42,    47,     0,    43,    44,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,    47,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,     0,     0,     0,    48,   343,    49,
      50,     0,    41,    42,     0,     0,    43,    44,    45,    46,
      51,     0,     0,     0,     0,   352,     0,     0,     0,    41,
      42,    47,     0,    43,    44,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    47,    49,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,    48,   354,    49,    50,     0,    41,
      42,     0,     0,    43,    44,    45,    46,    51,     0,     0,
       0,     0,   369,     0,     0,     0,    41,    42,    47,     0,
      43,    44,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    47,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
       0,    48,   112,    49,    50,     0,    41,    42,     0,     0,
      43,    44,    45,    46,    51,     0,     0,     0,   146,     0,
       0,     0,    41,    42,     0,    47,    43,    44,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,   148,    49,    50,     0,    41,    42,     0,     0,
      43,    44,    45,    46,    51,     0,     0,     0,   150,    49,
      50,     0,    41,    42,     0,    47,    43,    44,    45,    46,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,   177,    49,    50,     0,    41,    42,     0,     0,
      43,    44,    45,    46,    51,     0,     0,     0,   179,    49,
      50,     0,    41,    42,     0,    47,    43,    44,    45,    46,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,   181,    49,    50,     0,    41,    42,     0,     0,
      43,    44,    45,    46,    51,     0,     0,     0,     0,    49,
      50,     0,     0,     0,     0,    47,     0,     0,     0,     0,
      51,     0,     0,    80,    81,    82,    83,    84,    85,    86,
     152,   190,     0,    49,    50,    87,     0,    88,     0,     0,
      89,     0,     0,     0,    51,     0,     0,     0,     0,     0,
      90,    91,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   158,    92,    93,    94,    80,    81,    82,    83,    84,
      85,    86,   152,     0,     0,     0,     0,    87,     0,    88,
     225,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,     0,     0,     0,     0,   153,   154,
     155,   156,   157,   158,    92,    93,    94,    80,    81,    82,
      83,    84,    85,    86,   152,     0,     0,     0,     0,    87,
       0,    88,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,    92,    93,    94,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,    87,     0,    88,     0,     0,    89,     0,     0,     0,
     236,     0,     0,     0,     0,     0,    90,    91,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,    92,    93,
      94,    87,     0,    88,     0,     0,    89,     0,     0,     0,
       0,     0,   238,     0,     0,     0,    90,    91,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,    92,    93,
      94,    87,     0,    88,     0,     0,    89,     0,     0,     0,
     304,     0,     0,     0,     0,     0,    90,    91,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,    92,    93,
      94,    87,     0,    88,     0,     0,    89,     0,     0,     0,
       0,     0,   306,     0,     0,     0,    90,    91,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,    92,    93,
      94,    87,     0,    88,     0,     0,    89,     0,     0,     0,
       0,     0,   315,     0,     0,     0,    90,    91,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,    92,    93,
      94,    87,     0,    88,     0,     0,    89,     0,     0,     0,
     359,     0,     0,     0,     0,     0,    90,    91,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,    92,    93,
      94,    87,     0,    88,     0,     0,    89,     0,     0,     0,
       0,     0,   361,     0,     0,     0,    90,    91,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,    92,    93,
      94,    87,     0,    88,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94
};

static const yytype_int16 yycheck[] =
{
      25,     0,    57,    10,    29,    76,    56,    25,     7,     1,
      76,    29,   272,   290,     1,    36,     1,    76,    48,     1,
       8,   298,    24,    48,     1,   272,    36,    21,    19,    76,
      20,    95,    53,    27,    59,    26,    18,    91,    23,     1,
      96,    18,    34,    53,     1,   109,     1,    34,     0,     1,
      38,    39,    27,   107,   110,     1,    12,    30,    31,    15,
      90,     0,     1,    38,    39,    90,    91,     1,    53,   140,
      95,    96,    97,    91,   140,   322,    76,   337,   108,    25,
     357,   140,   107,   108,   109,   110,   111,    76,     1,   107,
     337,    53,     1,   140,   149,    76,    53,   147,    53,   124,
     125,    53,    54,    55,    56,   365,   124,   125,    54,    55,
      56,   358,   372,     1,    53,    54,    55,    56,    19,    53,
      54,    55,    56,    59,    25,   180,   197,    36,   178,     1,
       1,   197,    19,    27,     1,     1,    25,     1,   197,    26,
     140,    54,    55,    56,    53,    19,     1,    21,    36,    19,
     197,   140,    26,    27,    25,    47,    26,     0,   229,   140,
      71,    97,    19,   229,   235,    53,    77,   238,   239,   235,
     229,    32,   238,   239,    20,   111,   235,    38,    39,   238,
     239,    53,   229,    54,    55,    56,    53,    53,   235,    53,
      38,   238,   239,   192,    19,    34,    21,   197,    53,    38,
      39,    26,    27,    11,    32,    13,    14,   278,   197,   280,
      38,    39,   278,   105,   280,    23,   197,    25,   243,   278,
      19,   280,   114,   230,    21,   243,   233,    26,    21,    26,
      27,   278,   231,   280,   259,   260,   128,    32,   238,   239,
     229,   259,   260,    38,    39,   270,   235,    29,   229,   238,
     239,    33,   270,    35,   235,    38,    39,   238,   239,    32,
     152,   153,   154,   155,   156,    38,    39,   292,   160,   161,
     162,   163,   164,    20,   292,    32,    26,   302,   278,    25,
     280,    38,    39,    34,   302,   236,   237,    38,    39,   278,
      25,   280,    11,    12,    13,    14,    15,   278,    34,   280,
      38,    39,    38,    39,    23,    32,    25,   332,     1,   334,
      21,    38,    39,    34,   332,    26,   334,    38,    39,     1,
      20,   291,   347,   348,    24,    30,    31,   297,     1,   347,
     348,    19,     5,   225,    24,   227,    30,    31,    28,    11,
     291,    13,    14,   368,    21,   315,   316,    54,    55,    56,
     368,    19,    26,   304,   305,   306,   307,   327,    22,    25,
      24,   331,    21,    21,   315,   316,    23,    19,    25,   339,
     118,    34,   120,    34,   325,   326,   327,    18,    34,    34,
     331,    34,   333,     7,    -1,    36,   356,   192,    -1,    56,
      -1,   361,   362,    -1,     1,    -1,   366,   367,     5,     6,
     351,   371,     9,    10,    11,    12,    -1,    -1,   359,   360,
      -1,    -1,    19,    -1,    -1,    22,    23,    24,    -1,    -1,
     371,    -1,    29,    -1,    -1,    -1,    33,    -1,    35,    -1,
      37,    -1,    -1,    40,    41,    42,    43,    12,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    53,    54,    55,    56,
      57,     1,    -1,    28,    -1,     5,     6,    -1,    -1,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    24,    50,    51,    52,    -1,    29,
      -1,    -1,    -1,    33,    -1,    35,    -1,    37,    -1,    -1,
      40,    41,    42,    43,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    57,     1,    -1,
      -1,    -1,     5,     6,    -1,    -1,     9,    10,    11,    12,
      44,    45,    46,    47,    48,    49,    19,    -1,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    -1,    35,    -1,    37,    -1,    -1,    40,    41,    42,
      43,    -1,    -1,     1,    -1,    -1,    -1,     5,     6,    -1,
      53,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    -1,    35,    -1,    37,
      -1,    -1,    40,    41,    42,    43,    -1,    -1,     1,    -1,
      -1,    -1,     5,     6,    -1,    53,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    -1,    35,    -1,    37,    -1,    -1,    40,    41,    42,
      43,    -1,    -1,     1,    -1,    -1,    -1,     5,     6,    -1,
      53,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    22,    -1,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    -1,    35,    -1,    37,
      -1,    -1,    40,    41,    42,    43,    -1,    -1,     1,    -1,
      -1,    -1,     5,     6,    -1,    53,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    -1,    35,    -1,    37,    -1,    -1,    40,    41,    42,
      43,    -1,    -1,     1,    -1,    -1,    -1,     5,     6,    -1,
      53,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    22,    -1,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    -1,    35,    -1,    37,
      -1,    -1,    40,    41,    42,    43,    -1,    -1,     1,    -1,
      -1,    -1,     5,     6,    -1,    53,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    -1,    35,    -1,    37,    -1,    -1,    40,    41,    42,
      43,    -1,    -1,     1,    -1,    -1,    -1,     5,     6,    -1,
      53,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,     5,     6,    24,    25,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    40,    24,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    40,
       1,    42,    43,    -1,     5,     6,    -1,    -1,     9,    10,
      11,    12,    53,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,     5,     6,    24,    -1,     9,    10,    11,    12,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    -1,    40,
      24,    42,    43,    23,    -1,    25,    -1,    -1,    28,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    40,     1,    42,    43,
      -1,     5,     6,    -1,    -1,     9,    10,    11,    12,    53,
      50,    51,    52,    -1,     1,    -1,    -1,    -1,     5,     6,
      24,    -1,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    24,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    40,     1,    42,    43,    -1,     5,     6,
      -1,    -1,     9,    10,    11,    12,    53,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,     5,     6,    24,    -1,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    24,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      40,     1,    42,    43,    -1,     5,     6,    -1,    -1,     9,
      10,    11,    12,    53,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,     5,     6,    24,    -1,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    24,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    40,     1,    42,
      43,    -1,     5,     6,    -1,    -1,     9,    10,    11,    12,
      53,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,     5,
       6,    24,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    24,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    40,     1,    42,    43,    -1,     5,
       6,    -1,    -1,     9,    10,    11,    12,    53,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,     5,     6,    24,    -1,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    24,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    40,     1,    42,    43,    -1,     5,     6,    -1,    -1,
       9,    10,    11,    12,    53,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,     5,     6,    24,    -1,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    24,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    40,     1,
      42,    43,    -1,     5,     6,    -1,    -1,     9,    10,    11,
      12,    53,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
       5,     6,    24,    -1,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    24,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    40,     1,    42,    43,    -1,
       5,     6,    -1,    -1,     9,    10,    11,    12,    53,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,     5,     6,    24,
      -1,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    24,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    40,     1,    42,    43,    -1,     5,     6,    -1,
      -1,     9,    10,    11,    12,    53,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,     5,     6,    24,    -1,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    24,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    40,
       1,    42,    43,    -1,     5,     6,    -1,    -1,     9,    10,
      11,    12,    53,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,     5,     6,    24,    -1,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      24,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    40,     1,    42,    43,
      -1,     5,     6,    -1,    -1,     9,    10,    11,    12,    53,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,     5,     6,
      24,    -1,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    24,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    40,     1,    42,    43,    -1,     5,     6,
      -1,    -1,     9,    10,    11,    12,    53,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,     5,     6,    24,    -1,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    24,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      40,     1,    42,    43,    -1,     5,     6,    -1,    -1,     9,
      10,    11,    12,    53,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,     5,     6,    24,    -1,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    24,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    40,     1,    42,
      43,    -1,     5,     6,    -1,    -1,     9,    10,    11,    12,
      53,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,     5,
       6,    24,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    24,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    40,     1,    42,    43,    -1,     5,
       6,    -1,    -1,     9,    10,    11,    12,    53,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,     5,     6,    24,    -1,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    24,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    40,     1,    42,    43,    -1,     5,     6,    -1,    -1,
       9,    10,    11,    12,    53,    -1,    -1,    -1,     1,    -1,
      -1,    -1,     5,     6,    -1,    24,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,     1,    42,    43,    -1,     5,     6,    -1,    -1,
       9,    10,    11,    12,    53,    -1,    -1,    -1,     1,    42,
      43,    -1,     5,     6,    -1,    24,     9,    10,    11,    12,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,     1,    42,    43,    -1,     5,     6,    -1,    -1,
       9,    10,    11,    12,    53,    -1,    -1,    -1,     1,    42,
      43,    -1,     5,     6,    -1,    24,     9,    10,    11,    12,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,     1,    42,    43,    -1,     5,     6,    -1,    -1,
       9,    10,    11,    12,    53,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    42,    43,    23,    -1,    25,    -1,    -1,
      28,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    -1,    25,
      26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,
      -1,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    25,    -1,    -1,    28,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    50,    51,
      52,    23,    -1,    25,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    38,    39,    -1,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    50,    51,
      52,    23,    -1,    25,    -1,    -1,    28,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    50,    51,
      52,    23,    -1,    25,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    38,    39,    -1,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    50,    51,
      52,    23,    -1,    25,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    38,    39,    -1,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    50,    51,
      52,    23,    -1,    25,    -1,    -1,    28,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    50,    51,
      52,    23,    -1,    25,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    38,    39,    -1,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    50,    51,
      52,    23,    -1,    25,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    53,    54,    55,    56,    61,    62,    63,    64,
      70,    71,     1,    53,    66,    67,    68,    24,     0,    63,
       1,    53,    66,    21,    26,    27,    20,    19,    26,    27,
       1,    70,    72,    73,    74,    19,    24,    19,     1,    67,
       1,     5,     6,     9,    10,    11,    12,    24,    40,    42,
      43,    53,    96,    97,    98,    99,   101,   103,   105,   106,
     107,   108,   109,   110,   113,     1,     5,     1,    67,     1,
      96,    19,     1,    53,    75,    76,    25,    19,     1,    72,
      11,    12,    13,    14,    15,    16,    17,    23,    25,    28,
      38,    39,    50,    51,    52,   100,   102,   104,     1,    95,
      96,   108,     1,    98,    22,    24,    38,    39,    38,   100,
     102,   104,     1,   105,    20,    21,    74,    21,    26,    20,
      26,     1,    19,    22,    29,    33,    35,    37,    41,    77,
      78,    79,    85,    87,    92,    93,    94,    95,     1,    74,
      25,     1,    98,     1,    96,    97,     1,   101,     1,   103,
       1,   105,    18,    44,    45,    46,    47,    48,    49,    25,
      18,    44,    45,    46,    47,    48,    49,     1,     1,    95,
     111,   112,     1,     1,    97,     1,    98,     1,   101,     1,
     103,     1,   105,     1,    95,     1,    76,    21,     1,    76,
      19,     1,    80,     1,    96,     1,    96,    36,    53,    19,
      19,    95,    19,     1,    77,     1,    95,     1,    95,     1,
      95,     1,    95,     1,    95,     1,    95,     1,    95,     1,
      95,     1,    95,     1,    95,    26,    25,    26,    21,    81,
       1,    57,    65,    69,    70,    81,    32,    32,    34,    34,
       1,    77,     1,    18,    89,    19,    95,     1,    95,    23,
      77,    23,    66,    70,     1,    66,     1,    23,     1,    29,
      33,    35,    78,    79,    82,    83,    85,    90,    93,    94,
      33,    35,    83,    84,    87,    91,    77,    77,    34,    96,
      34,    19,    19,    19,     1,    96,     1,    96,     1,    36,
      53,    30,    31,    86,    88,     1,    96,    36,    53,    86,
      88,    77,     8,    77,    32,    32,    34,    34,    83,     1,
      89,    83,    84,     1,    96,    34,    34,    84,    89,     1,
      96,    83,    83,    83,    83,    34,    34,    32,    84,    84,
       1,    34,    27,    30,    31,    83,    83,    83,    84,    34,
      84,     1,    96,     1,    96,    86,    88,    29,    33,    35,
      84,    32,     1,    96,     1,    96,    36,    53,    83,    32,
      32,    34,    34,    89,    83,    83,    34,    30,    31,     1,
      96,    32,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    64,    64,
      64,    65,    65,    65,    66,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    69,    69,
      69,    70,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    74,    74,
      75,    75,    75,    75,    76,    76,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    78,    79,    79,
      79,    80,    80,    81,    81,    82,    82,    82,    82,    83,
      83,    83,    83,    84,    84,    85,    85,    85,    86,    86,
      86,    87,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    93,    93,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    96,    96,    96,    96,    96,    97,    97,    97,    97,
      97,    98,    98,    98,    99,    99,    99,    99,    99,   100,
     100,   100,   100,   100,   100,   101,   101,   101,   101,   101,
     102,   102,   103,   103,   103,   103,   103,   104,   104,   104,
     105,   105,   105,   106,   106,   106,   107,   107,   108,   108,
     108,   108,   109,   109,   109,   109,   110,   110,   110,   111,
     111,   112,   112,   112,   112,   113,   113,   113,   113,   113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     1,
       3,     3,     3,     1,     1,     4,     3,     2,     2,     1,
       2,     1,     1,     1,     6,     5,     4,     6,     3,     5,
       2,     1,     0,     3,     1,     3,     3,     1,     2,     2,
       3,     1,     3,     3,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     4,     4,
       4,     2,     0,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     2,     5,     5,     2,
       2,     4,     4,     5,     4,     5,     4,     5,     4,     2,
       2,     4,     6,     4,     6,     4,     3,     5,     4,     2,
       5,     3,     2,     4,     3,     5,     4,     6,     4,     3,
       5,     4,     5,     2,     3,     2,     3,     3,     3,     3,
       3,     2,     2,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       3,     2,     1,     2,     3,     1,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     3,     3,
       1,     1,     3,     1,     3,     3,     3,     1,     1,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     4,
       3,     2,     3,     1,     1,     2,     4,     2,     3,     1,
       0,     3,     1,     3,     3,     1,     1,     1,     1,     1
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
#line 67 "parser.y" /* yacc.c:1646  */
    {
                  (yyval.Tree)=(yyvsp[0].Tree);
                  syntaxTree = (yyval.Tree);
                  if(cdbug) printf("<-program\n");
               }
#line 1962 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-declarationList declaration\n");
                     (yyval.Tree) = addSibling((yyvsp[-1].Tree),(yyvsp[0].Tree));
                  }
#line 1971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 80 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-declarationList declaration\n");
                     (yyval.Tree) = (yyvsp[0].Tree);
                  }
#line 1980 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 87 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-declaration varDeclaration\n");
                     (yyval.Tree) = (yyvsp[0].Tree);
                  }
#line 1989 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 93 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-declaration funDeclaration\n");
                     (yyval.Tree)=(yyvsp[0].Tree);
                  }
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree) = NULL; if(cdbug) printf("declaration error\n");}
#line 2004 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 102 "parser.y" /* yacc.c:1646  */
    {
                        yyerrok;

                        if(cdbug) printf("<-varDeclaration typeSpecifier varDeclList SEMI\n");
                        (yyval.Tree) = (yyvsp[-1].Tree);
                        typeToSibs((yyval.Tree), (yyvsp[-2].Tree)->type);
                     }
#line 2016 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree) = NULL; if(cdbug) printf(" error varDeclaration\n");}
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree) = NULL; yyerrok; if(cdbug) printf("typeSpecifier error SEMI\n");}
#line 2028 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 115 "parser.y" /* yacc.c:1646  */
    {
                        yyerrok;
                        if(cdbug) printf("<-scopedVarDeclaration scopedTypeSpecifier varDeclList\n");
                        (yyval.Tree) = (yyvsp[-1].Tree);
                        if((yyvsp[-1].Tree) != NULL){
                          (yyval.Tree)->type = (yyvsp[-2].Tree)->type; 
                        }
                        
                        if(STATIC_FLAG) {
                           (yyval.Tree)->isStatic = true;
                           STATIC_FLAG = false;
                        }
                        typeToSibs((yyval.Tree), (yyvsp[-2].Tree)->type);

                        
                     }
#line 2049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree) = NULL; yyerrok; if(cdbug) printf("scopedTypeSpecifier error SEMI\n");}
#line 2055 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree) = NULL; yyerrok; if(cdbug) printf("error vardeclist SEMI\n");}
#line 2061 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 139 "parser.y" /* yacc.c:1646  */
    {
               yyerrok;
               if(cdbug) printf("<-varDeclList varDeclList COM varDeclInitialize ADD SIBLINGS 6\n");
               (yyval.Tree) = addSibling((yyvsp[-2].Tree),(yyvsp[0].Tree));

               
            }
#line 2073 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 148 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-varDeclList varDeclInitialize\n");
               (yyval.Tree) = (yyvsp[0].Tree);
            }
#line 2082 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) printf("varDeclList error\n");}
#line 2088 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 154 "parser.y" /* yacc.c:1646  */
    {  (yyval.Tree) = NULL; if(cdbug) printf("error COM varDeclInitialize\n");}
#line 2094 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) printf(" vardclist error\n");}
#line 2100 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 159 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-varDeclInitialize varDeclId\n");
                     (yyval.Tree) = (yyvsp[0].Tree);
                  }
#line 2109 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 165 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-varDeclInitialize varDeclId COL simpleExpression \n");
                     (yyval.Tree)=(yyvsp[-2].Tree);
                     (yyval.Tree)->child[0] = (yyvsp[0].Tree);
                  }
#line 2119 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 171 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL; if(cdbug) printf("varDeclInitialize error\n");}
#line 2125 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) ("varDeclInitialize error\n");}
#line 2131 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) printf("varDeclInitialize error\n"); }
#line 2137 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 177 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-varDeclId ID\n");
               (yyval.Tree) = newDecNode(VarK, (yyvsp[0].Token_Data)->Line_Num);
               (yyval.Tree)->attr.name = strdup((yyvsp[0].Token_Data)->Token_Str);
               yyerrok;
            }
#line 2148 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 185 "parser.y" /* yacc.c:1646  */
    {
               yyerrok;
                  if(cdbug) printf("<-varDeclId ID LIndex NUMCONST RIndex \n");  //array define
                  (yyval.Tree) = newDecNode(VarK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.name = strdup((yyvsp[-3].Token_Data)->Token_Str); 
                  (yyval.Tree)->TD = (yyvsp[-3].Token_Data);
                  (yyval.Tree)->attr.value = (yyvsp[-1].Token_Data)->Num_Val;    //posibly not needed
                  (yyval.Tree)->isArray = true;
                  (yyval.Tree)->arraySize = (yyvsp[-1].Token_Data)->Num_Val;
                  (yyval.Tree)->attr.op = (yyvsp[-2].Token_Data)->Token_Class;
                  (yyval.Tree)->type = UndefinedType;
            }
#line 2165 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 198 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2171 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 199 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL; }
#line 2177 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 204 "parser.y" /* yacc.c:1646  */
    {
                        if(cdbug) printf("<-scopedTypeSpecifier STATIC typeSpecifier \n");
                        (yyval.Tree) = (yyvsp[0].Tree);
                        STATIC_FLAG = true;
                     }
#line 2187 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 211 "parser.y" /* yacc.c:1646  */
    {
                       if(cdbug) printf("<-scopedTypeSpecifier typeSpecifier\n");
                        (yyval.Tree) = (yyvsp[0].Tree);
                    }
#line 2196 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) printf("typeSpecifier error\n"); }
#line 2202 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 220 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-typeSpecifier INT \n");
                  (yyval.Tree)->type =  Integer;             
               }
#line 2211 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 226 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-typeSpecifier BOOL\n");
                  (yyval.Tree)->type = Bool;
               }
#line 2220 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 231 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-typeSpecifier CHAR\n");
                  (yyval.Tree)->type = Char;
               }
#line 2229 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 239 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-funDeclaration typeSpecifier ID LP params RP statement  \n");
                  (yyval.Tree) = newDecNode(FuncK, (yyvsp[-4].Token_Data)->Line_Num); 
                  (yyval.Tree)->attr.name = strdup((yyvsp[-4].Token_Data)->Token_Str);  
                  (yyval.Tree)->type = (yyvsp[-5].Tree)->type;
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2242 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 249 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-funDeclaration ID LP params RP statement  \n");
                  (yyval.Tree) = newDecNode(FuncK, (yyvsp[-4].Token_Data)->Line_Num); 
                  (yyval.Tree)->attr.name = strdup((yyvsp[-4].Token_Data)->Token_Str);
                  (yyval.Tree)->type = Void;
                  (yyval.Tree)->TD = (yyvsp[-4].Token_Data);
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2256 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2262 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2268 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2274 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2280 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) printf("typeSpecifier error\n"); }
#line 2286 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 267 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-params paramList\n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 2295 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 273 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-params empty\n");
            (yyval.Tree) = NULL;
         }
#line 2304 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 280 "parser.y" /* yacc.c:1646  */
    {
               yyerrok;
               
               if(cdbug) printf("<-paramList paramList SEMI paramTypeList ADD SIBLINGS 13\n");
               (yyval.Tree) = addSibling((yyvsp[-2].Tree),(yyvsp[0].Tree));
            }
#line 2315 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 288 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-paramList paramTypeList\n");
                  (yyval.Tree)=(yyvsp[0].Tree);
               }
#line 2324 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 293 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) printf("paramList SEMI error\n"); }
#line 2330 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 294 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL; if(cdbug) printf(" error SEMI paramTypeList\n");}
#line 2336 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 295 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) printf("Paramlist error\n"); }
#line 2342 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 299 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-paramTypeList typeSpecifier paramIdList\n");
                  (yyval.Tree) = (yyvsp[0].Tree);
                  typeToSibs((yyval.Tree), (yyvsp[-1].Tree)->type);      
               }
#line 2352 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 305 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) printf("typeSpecifier error\n"); }
#line 2358 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 309 "parser.y" /* yacc.c:1646  */
    {
               yyerrok;

               if(cdbug) printf("<-declarationList paramIdList COM paramId ADD SIBLINGS 15\n");
               (yyval.Tree) = addSibling((yyvsp[-2].Tree),(yyvsp[0].Tree));
            }
#line 2369 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 317 "parser.y" /* yacc.c:1646  */
    {  
               if(cdbug) printf("<-paramIdList paramId\n");
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 2378 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) printf("paramIdList COM error\n"); }
#line 2384 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 323 "parser.y" /* yacc.c:1646  */
    {yyerrok; (yyval.Tree) = NULL; if(cdbug) printf(" error COM paramId\n");}
#line 2390 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 327 "parser.y" /* yacc.c:1646  */
    {
            yyerrok;
            if(cdbug) printf("<-paramId ID\n");
            (yyval.Tree) = newDecNode(ParamK, (yyvsp[0].Token_Data)->Line_Num); 
            (yyval.Tree)->attr.name = strdup((yyvsp[0].Token_Data)->Token_Str); 
            (yyval.Tree)->isInit = true;
         }
#line 2402 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 336 "parser.y" /* yacc.c:1646  */
    {
            yyerrok;

            if(cdbug) printf("<-paramId ID LIndex RIndex\n");
            (yyval.Tree) = newDecNode(ParamK, (yyvsp[-2].Token_Data)->Line_Num);
            (yyval.Tree)->attr.name = strdup((yyvsp[-2].Token_Data)->Token_Str);  
            (yyval.Tree)->isArray = true;
            (yyval.Tree)->isInit = true;
            (yyval.Tree)->type = UndefinedType;
         }
#line 2417 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 347 "parser.y" /* yacc.c:1646  */
    {yyerrok; (yyval.Tree) = NULL; }
#line 2423 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 348 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2429 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 352 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-statementexpressionStmt\n");}
#line 2435 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 353 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-statement compoundStmt\n");}
#line 2441 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 354 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree) = (yyvsp[0].Tree); if(cdbug) printf("<-statement matchedIf : %d\n", (yyvsp[0].Tree)->attr.value);}
#line 2447 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 355 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree) = (yyvsp[0].Tree); if(cdbug) printf("<-statement unmatchedIf\n");}
#line 2453 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 356 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-statement iterationStmt\n");}
#line 2459 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 357 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-statement returnStmt\n");}
#line 2465 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 358 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-statement breakStmt\n");}
#line 2471 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 364 "parser.y" /* yacc.c:1646  */
    {
                  yyerrok;

                  if(cdbug) printf("<-expressionStmt expression SEMI\n");
                  (yyval.Tree)=(yyvsp[-1].Tree);
               }
#line 2482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 372 "parser.y" /* yacc.c:1646  */
    {
                     yyerrok; 

                     if(cdbug) printf("<-expressionStmt SEMI\n");
                     (yyval.Tree)=NULL;                     
                  }
#line 2493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 379 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL; }
#line 2499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 384 "parser.y" /* yacc.c:1646  */
    {
                  yyerrok; 

                  if(cdbug) printf("<-compoundStmt LB localDeclarations statementList RB\n");
                  (yyval.Tree) = newStmtNode(CompoundK, (yyvsp[-3].Token_Data)->Line_Num);
                  //$$->attr.op = $1->Token_Class;
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[-1].Tree);
               }
#line 2513 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 394 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2519 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 395 "parser.y" /* yacc.c:1646  */
    {yyerrok; (yyval.Tree) = NULL; }
#line 2525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 399 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-localDeclarations localDeclarations scopedVarDeclaration\n");
                     (yyval.Tree) = addSibling((yyvsp[-1].Tree),(yyvsp[0].Tree));
                  }
#line 2534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 404 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-localDeclarations empty\n");
                     (yyval.Tree)=NULL;
                  }
#line 2543 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 411 "parser.y" /* yacc.c:1646  */
    {
                 if(cdbug) printf("<-statementList statementList statement ADD SIBLINGS 21\n");
                 (yyval.Tree) = addSibling((yyvsp[-1].Tree),(yyvsp[0].Tree));
              }
#line 2552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 416 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-statementList empty\n");
                  (yyval.Tree)=NULL;
               }
#line 2561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 422 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-partialStmt expressionStmt\n");}
#line 2567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 423 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-partialStmt compoundStmt\n");}
#line 2573 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 424 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-partialStmt returnStmt\n");}
#line 2579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 425 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree)=(yyvsp[0].Tree); if(cdbug) printf("<-partialStmt breakStmt\n");}
#line 2585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 429 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-matched matchedIf \n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 2594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 434 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-matched matchedWhile \n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 2603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 439 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-matched partialStmt \n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 2612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 443 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 447 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-unmatched unmatchedIf \n");
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 2627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 452 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-unmatched unmatchedWhile \n");
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 2636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 459 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-matchedIf IF simpleExpression THEN matched matchedElse : %d\n", (yyvsp[0].Tree)->attr.value);
               (yyval.Tree) = newStmtNode(IfK, (yyvsp[-4].Token_Data)->Line_Num); 
               (yyval.Tree)->child[0] = (yyvsp[-3].Tree);
               (yyval.Tree)->child[1] = (yyvsp[-1].Tree);
               (yyval.Tree)->child[2] = (yyvsp[0].Tree);
               
            }
#line 2649 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 468 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2655 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 469 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; yyerrok;}
#line 2661 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 473 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-matchedElse ELSIF simpleExpression THEN matched matchedElse\n");
               (yyval.Tree) = newStmtNode(ElsifK, (yyvsp[-4].Token_Data)->Line_Num); 
               (yyval.Tree)->child[0] = (yyvsp[-3].Tree);
               (yyval.Tree)->child[1] = (yyvsp[-1].Tree);
               (yyval.Tree)->child[2] = (yyvsp[0].Tree);
            }
#line 2673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 481 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-matchedElse ELSE matched : %d\n", (yyvsp[0].Tree)->attr.value);
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 2682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 486 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 489 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedIf IF simpleExpression THEN matched \n");
                  (yyval.Tree) = newStmtNode(IfK, (yyvsp[-3].Token_Data)->Line_Num); 
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
            }
#line 2699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 496 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedIf IF simpleExpression THEN unmatched \n");
                  (yyval.Tree) = newStmtNode(IfK, (yyvsp[-3].Token_Data)->Line_Num); 
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
            }
#line 2710 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 503 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedIf IF simpleExpression THEN matched unmatchedElse \n");
                  (yyval.Tree) = newStmtNode(IfK, (yyvsp[-4].Token_Data)->Line_Num); 
                  (yyval.Tree)->child[0] = (yyvsp[-3].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[-1].Tree);
                  (yyval.Tree)->child[2] = (yyvsp[0].Tree);
                 // $$ = addSibling($2,$5);
            }
#line 2723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 512 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; yyerrok;}
#line 2729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 513 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; yyerrok;}
#line 2735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 516 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedElse ELSIF simpleExpression THEN matched \n");
                  (yyval.Tree) = newStmtNode(ElsifK, (yyvsp[-3].Token_Data)->Line_Num); 
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 523 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedElse ELSIF simpleExpression THEN matched unmatchedElse \n");
                  (yyval.Tree) = newStmtNode(ElsifK, (yyvsp[-4].Token_Data)->Line_Num); 
                  (yyval.Tree)->child[0] = (yyvsp[-3].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[-1].Tree);
                  (yyval.Tree)->child[2] = (yyvsp[0].Tree);
               }
#line 2758 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 531 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedElse ELSIF simpleExpression THEN unmatched \n");
                  (yyval.Tree) = newStmtNode(ElsifK, (yyvsp[-3].Token_Data)->Line_Num); 
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2769 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 538 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedElse ELSE unmatched \n");
                  (yyval.Tree) = (yyvsp[0].Tree);
               }
#line 2778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 543 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 548 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-iterationRange ID EQ simpleExpression RANGE simpleExpression \n");
                  (yyval.Tree) = newStmtNode(RangeK, (yyvsp[-3].Token_Data)->Line_Num);      
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
                  (yyval.Tree)->child[2] = newExpNode(ConstantK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->child[2]-> attr.value = 1;
                  (yyval.Tree)->child[2]->type = Integer;

               }
#line 2799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 560 "parser.y" /* yacc.c:1646  */
    {  
                  if(cdbug) printf("<-iterationRange ID EQ simpleExpression RANGE simpleExpression COL simpleExpression\n");
                  (yyval.Tree) = newStmtNode(RangeK, (yyvsp[-5].Token_Data)->Line_Num); 
                  
                  (yyval.Tree)->child[0] = (yyvsp[-4].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[2] = (yyvsp[0].Tree);
               }
#line 2812 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 569 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2818 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 570 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 2824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 574 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-matchedWhile WHILE simpleExpression DO unmatched\n");
                  (yyval.Tree) = newStmtNode(WhileK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.op = (yyvsp[-3].Token_Data)->Token_Class; 
                  (yyval.Tree)->child[0]=(yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2836 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 583 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-matchedWhile LOOP FOREVER matched\n");
                  (yyval.Tree) = newStmtNode(LoopForeverK, (yyvsp[-2].Token_Data)->Line_Num); 
                  (yyval.Tree)->attr.op = (yyvsp[-2].Token_Data)->Token_Class;
                  (yyval.Tree)->child[1]=(yyvsp[0].Tree); 
               }
#line 2847 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 590 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-matchedWhile ID iterationRange DO matched\n");
                  (yyval.Tree) = newStmtNode(LoopK, (yyvsp[-4].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.op = (yyvsp[-4].Token_Data)->Token_Class;  (yyval.Tree)->type = Void;
                  (yyval.Tree)->child[0] = newDecNode(VarK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->child[0]->type = Integer;
                  (yyval.Tree)->child[0]-> attr.name = strdup((yyvsp[-3].Token_Data)->Token_Str);
                  (yyval.Tree)->child[0]->isInit = true;
                  (yyval.Tree)->child[1] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[2] = (yyvsp[0].Tree); 
               }
#line 2863 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 602 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL;if(cdbug) printf("matchedWhile WHILE error DO matched\n");}
#line 2869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 603 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) printf("matchedWhile WHILE error\n");}
#line 2875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 604 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL; if(cdbug) printf("matchedWhile LOOP ID error DO matched\n");}
#line 2881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 605 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) printf("matchedWhile LOOP ID error\n");}
#line 2887 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 606 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; if(cdbug) printf("matchedWhile LOOP error\n");}
#line 2893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 610 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedWhile WHILE simpleExpression DO unmatched\n");
                  (yyval.Tree) = newStmtNode(WhileK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.op = (yyvsp[-3].Token_Data)->Token_Class;  
                  (yyval.Tree)->child[0]=(yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 2905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 618 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedWhile LOOP FOREVER unmatched\n");
                  (yyval.Tree) = newStmtNode(LoopForeverK, (yyvsp[-2].Token_Data)->Line_Num); 
                  (yyval.Tree)->attr.op = (yyvsp[-2].Token_Data)->Token_Class;
                  (yyval.Tree)->child[1]=(yyvsp[0].Tree); 
               }
#line 2916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 625 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-unmatchedWhile LOOP iterationRange DO unmatched\n");
                  (yyval.Tree) = newStmtNode(LoopK, (yyvsp[-4].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.op = (yyvsp[-4].Token_Data)->Token_Class;  
                  (yyval.Tree)->child[0] = newDecNode(VarK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->child[0]->type = Integer;
                  (yyval.Tree)->child[0]->attr.name = strdup((yyvsp[-3].Token_Data)->Token_Str);
                  (yyval.Tree)->child[0]->isInit = true;
                  (yyval.Tree)->child[1] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[2] = (yyvsp[0].Tree);   
               }
#line 2932 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 637 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; yyerrok;}
#line 2938 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 638 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; yyerrok;}
#line 2944 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 643 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-iterationStmt declaration\n");
                  (yyval.Tree) = newStmtNode(WhileK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.op = (yyvsp[-3].Token_Data)->Token_Class;  
                  (yyval.Tree)->type = Void;
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);  
               }
#line 2957 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 653 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-iterationStmt declaration\n");
                     (yyval.Tree) = newStmtNode(LoopForeverK, (yyvsp[-2].Token_Data)->Line_Num); 
                     (yyval.Tree)->attr.op = (yyvsp[-2].Token_Data)->Token_Class;
                     (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
                  }
#line 2968 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 661 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-iterationStmt declaration\n");
                  (yyval.Tree) = newStmtNode(LoopK, (yyvsp[-4].Token_Data)->Line_Num);
                  (yyval.Tree)->attr.op = (yyvsp[-4].Token_Data)->Token_Class;  (yyval.Tree)->type = Void;
                  (yyval.Tree)->child[0] = newDecNode(VarK, (yyvsp[-3].Token_Data)->Line_Num);
                  (yyval.Tree)->child[0]->attr.name = strdup((yyvsp[-3].Token_Data)->Token_Str);
                  (yyval.Tree)->child[0]->type = Integer;
                  (yyval.Tree)->child[0]->isInit = true;
                  (yyval.Tree)->child[1] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[2] = (yyvsp[0].Tree);
               }
#line 2984 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 673 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; yyerrok;}
#line 2990 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 674 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; yyerrok;}
#line 2996 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 681 "parser.y" /* yacc.c:1646  */
    {
               yyerrok;
               if(cdbug) printf("<-returnStmt declaration\n");
               (yyval.Tree) = newStmtNode(ReturnK, (yyvsp[-1].Token_Data)->Line_Num);
               (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;
            }
#line 3007 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 689 "parser.y" /* yacc.c:1646  */
    {
               yyerrok;
               if(cdbug) printf("<-returnStmt declaration\n");
               (yyval.Tree) = newStmtNode(ReturnK, (yyvsp[-2].Token_Data)->Line_Num); 
               (yyval.Tree)->attr.op = (yyvsp[-2].Token_Data)->Token_Class;  
               (yyval.Tree)->type = (yyvsp[-1].Tree)->type;
               (yyval.Tree)->child[0] = (yyvsp[-1].Tree);
            }
#line 3020 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 701 "parser.y" /* yacc.c:1646  */
    {
               yyerrok;
               if(cdbug) printf("<-breakStmt declaration\n");
               (yyval.Tree) = newStmtNode(BreakK, (yyvsp[-1].Token_Data)->Line_Num);
               (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;
            }
#line 3031 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 711 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-expression mutable EQ          expression\n");
               (yyval.Tree) = newExpNode(AssignK, (yyvsp[-1].Token_Data)->Line_Num); 
               (yyval.Tree)->type = UndefinedType;
               (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class; 
               (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
               (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
            }
#line 3044 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 721 "parser.y" /* yacc.c:1646  */
    {
              if(cdbug) printf("<-expression mutable ADDASS expression\n");
              (yyval.Tree) = newExpNode(AssignK, (yyvsp[-1].Token_Data)->Line_Num); 
              (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;  
              (yyval.Tree)->type = Integer;
              (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
              (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
            }
#line 3057 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 731 "parser.y" /* yacc.c:1646  */
    {
              if(cdbug) printf("<-expression mutable SUBASS expression\n");
              (yyval.Tree) = newExpNode(AssignK, (yyvsp[-1].Token_Data)->Line_Num); 
              (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;  
              (yyval.Tree)->type = Integer;
              (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
              (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
            }
#line 3070 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 741 "parser.y" /* yacc.c:1646  */
    {
              if(cdbug) printf("<-expression mutable MULASS expression\n");
              (yyval.Tree) = newExpNode(AssignK, (yyvsp[-1].Token_Data)->Line_Num); 
              (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;  
              (yyval.Tree)->type = Integer;
              (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
              (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
            }
#line 3083 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 751 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-expression mutable DIVASS expression\n");
               (yyval.Tree) = newExpNode(AssignK, (yyvsp[-1].Token_Data)->Line_Num); 
               (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;  
               (yyval.Tree)->type = Integer;
               (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
               (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
            }
#line 3096 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 761 "parser.y" /* yacc.c:1646  */
    {
              if(cdbug) printf("<-expression mutable INC\n");
              (yyval.Tree) = newExpNode(AssignK, (yyvsp[0].Token_Data)->Line_Num); 
              (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
              (yyval.Tree)->type = Integer;
              (yyval.Tree)->child[0]= (yyvsp[-1].Tree);
              yyerrok;
            }
#line 3109 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 771 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-expression mutable DEC\n");
               (yyval.Tree) = newExpNode(AssignK, (yyvsp[0].Token_Data)->Line_Num);
               (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
               (yyval.Tree)->type = Integer;
               (yyval.Tree)->child[0]= (yyvsp[-1].Tree);
               yyerrok;
            }
#line 3122 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 781 "parser.y" /* yacc.c:1646  */
    {
              if(cdbug) printf("<-expression simpleExpression\n");
              (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 3131 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 786 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; yyerrok;}
#line 3137 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 787 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; yyerrok;}
#line 3143 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 789 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3149 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 790 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3155 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 791 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3161 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 792 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3167 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 793 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3173 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 795 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL;}
#line 3179 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 796 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL;}
#line 3185 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 797 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL;}
#line 3191 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 798 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL;}
#line 3197 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 799 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL;}
#line 3203 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 801 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3209 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 802 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3215 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 803 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3221 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 804 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3227 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 805 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3233 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 810 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-simpleExpression simpleExpression OR andExpression \n");
                     (yyval.Tree) = newExpNode(OpK, (yyvsp[-1].Token_Data)->Line_Num); 
                     (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;  
                     (yyval.Tree)->type = Bool;
                     (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
                     (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
                  }
#line 3246 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 820 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-simpleExpression andExpression\n");
                     (yyval.Tree)=(yyvsp[0].Tree);
                  }
#line 3255 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 825 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 3261 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 826 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL; }
#line 3267 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 827 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 3273 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 831 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-andExpression andExpression AND unaryRelExpression\n");
                  (yyval.Tree) = newExpNode(OpK, (yyvsp[-1].Token_Data)->Line_Num); 
                  (yyval.Tree)->attr.op = (yyvsp[-1].Token_Data)->Token_Class;  
                  (yyval.Tree)->type = Bool;
                  (yyval.Tree)->child[0]= (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree); 
               }
#line 3286 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 841 "parser.y" /* yacc.c:1646  */
    {
                 if(cdbug) printf("<-andExpression unaryRelExpression\n");
                 (yyval.Tree)=(yyvsp[0].Tree);         
              }
#line 3295 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 846 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 3301 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 847 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL;}
#line 3307 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 848 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 3313 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 852 "parser.y" /* yacc.c:1646  */
    {
                        if(cdbug) printf("<-unaryRelExpression NOT unaryRelExpression\n");
                        (yyval.Tree) = newExpNode(OpK, (yyvsp[-1].Token_Data)->Line_Num); 
                        (yyval.Tree)->attr.op =(yyvsp[-1].Token_Data)->Token_Class;  
                        (yyval.Tree)->type = Bool;
                        (yyval.Tree)->child[0] = (yyvsp[0].Tree); 
                     }
#line 3325 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 861 "parser.y" /* yacc.c:1646  */
    {
                        if(cdbug) printf("<-unaryRelExpression relExpression\n");
                        (yyval.Tree) = (yyvsp[0].Tree);
                     }
#line 3334 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 866 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 3340 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 870 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-relExpression sumExpression relop sumExpression\n");
                  (yyval.Tree) = (yyvsp[-1].Tree);
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 3351 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 878 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-relExpression sumExpression\n");
                  (yyval.Tree)=(yyvsp[0].Tree);
               }
#line 3360 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 883 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 3366 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 884 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL; }
#line 3372 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 885 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3378 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 889 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-relop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Bool; 
      }
#line 3389 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 897 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-relop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Bool; 
      }
#line 3400 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 905 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-relop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Bool; 
      }
#line 3411 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 913 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-relop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Bool; 
      }
#line 3422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 921 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-relop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Bool; 
      }
#line 3433 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 929 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-relop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Bool; 
      }
#line 3444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 938 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-sumExpression sumExpression sumop mulExpression \n");
                  (yyval.Tree) = (yyvsp[-1].Tree);
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 3455 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 946 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-sumExpression mulExpression\n");
                  (yyval.Tree)=(yyvsp[0].Tree);
               }
#line 3464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 951 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 952 "parser.y" /* yacc.c:1646  */
    {yyerrok; (yyval.Tree) = NULL;}
#line 3476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 953 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree) = NULL;}
#line 3482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 957 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-sumop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class; 
         (yyval.Tree)->type = Integer; 
      }
#line 3493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 965 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-sumop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Integer; 
      }
#line 3504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 974 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-mulExpression mulExpression mulop unaryExpression \n");
                  (yyval.Tree) = (yyvsp[-1].Tree); 
                  (yyval.Tree)->child[0] = (yyvsp[-2].Tree);
                  (yyval.Tree)->child[1] = (yyvsp[0].Tree);
               }
#line 3515 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 982 "parser.y" /* yacc.c:1646  */
    {
                  if(cdbug) printf("<-mulExpression unaryExpression\n");
                  (yyval.Tree)=(yyvsp[0].Tree);
               }
#line 3524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 987 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 3530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 988 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL;}
#line 3536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 989 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL;}
#line 3542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 993 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-mulop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Integer;
      }
#line 3553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1001 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-mulop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Integer;
      }
#line 3564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1009 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-mulop declaration\n");
         (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
         (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
         (yyval.Tree)->type = Integer;
      }
#line 3575 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1018 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-unaryExpression unaryop unaryExpression \n");
                     (yyval.Tree) = (yyvsp[-1].Tree);
                     (yyval.Tree)->child[0] = (yyvsp[0].Tree);
                  }
#line 3585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1025 "parser.y" /* yacc.c:1646  */
    {
                     if(cdbug) printf("<-unaryExpression factor\n");
                     (yyval.Tree)=(yyvsp[0].Tree);
                  }
#line 3594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1030 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 3600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1034 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-unaryop declaration\n");
            (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
            (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
            (yyval.Tree)->type = Integer; 
            (yyval.Tree)->unary = true;
         }
#line 3612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1043 "parser.y" /* yacc.c:1646  */
    {
           if(cdbug) printf("<-unaryop declaration\n");
           (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
           (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class; 
           (yyval.Tree)->type = Integer; 
           (yyval.Tree)->unary = true;
         }
#line 3624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1052 "parser.y" /* yacc.c:1646  */
    {
           if(cdbug) printf("<-unaryop declaration\n");
           (yyval.Tree) = newExpNode(OpK, (yyvsp[0].Token_Data)->Line_Num); 
           (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;  
           (yyval.Tree)->type = Integer;
           //$$->unary = true;
         }
#line 3636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1062 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-factor immutable\n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 3645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1068 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-factor mutable\n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 3654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1075 "parser.y" /* yacc.c:1646  */
    {
            yyerrok;

            if(cdbug) printf("<-mutable ID %s\n", (yyvsp[0].Token_Data)->Token_Str);
            (yyval.Tree) = newExpNode(IdK, (yyvsp[0].Token_Data)->Line_Num); 
            (yyval.Tree)->attr.name = strdup((yyvsp[0].Token_Data)->Token_Str); 
            (yyval.Tree)->type = UndefinedType;
         }
#line 3667 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1085 "parser.y" /* yacc.c:1646  */
    {
            yyerrok;

            if(cdbug) printf("<-mutable mutable LIndex expression RIndex\n");
            (yyval.Tree) = newExpNode(OpK, (yyvsp[-2].Token_Data)->Line_Num);
            (yyval.Tree)->attr.op = (yyvsp[-2].Token_Data)->Token_Class;
            (yyval.Tree)->child[0] = (yyvsp[-3].Tree);
            (yyval.Tree)->child[0]->isArray = true;
            (yyval.Tree)->child[1] = (yyvsp[-1].Tree);
            (yyval.Tree)->type = UndefinedType;
         }
#line 3683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1097 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree) = NULL;}
#line 3689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1098 "parser.y" /* yacc.c:1646  */
    {yyerrok; (yyval.Tree) = NULL;}
#line 3695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1102 "parser.y" /* yacc.c:1646  */
    {
               yyerrok;
               if(cdbug) printf("<-immutable LP expression RP \n");
               (yyval.Tree) = (yyvsp[-1].Tree);

              
            }
#line 3707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1111 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-immutable call\n");
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 3716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1116 "parser.y" /* yacc.c:1646  */
    {
               if(cdbug) printf("<-immutable constant\n");
               (yyval.Tree)=(yyvsp[0].Tree);
            }
#line 3725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1121 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 3731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1126 "parser.y" /* yacc.c:1646  */
    {
         yyerrok;
         if(cdbug) printf("<-call declaration\n");
         (yyval.Tree) = newExpNode(CallK, (yyvsp[-3].Token_Data)->Line_Num); 
         //$$->type = $3->type;
         (yyval.Tree)->attr.name = strdup((yyvsp[-3].Token_Data)->Token_Str);
         (yyval.Tree)->child[0] = (yyvsp[-1].Tree) ;
      }
#line 3744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1135 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; yyerrok;}
#line 3750 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1136 "parser.y" /* yacc.c:1646  */
    {(yyval.Tree) = NULL;}
#line 3756 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1140 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-args declaration\n");
         (yyval.Tree)=(yyvsp[0].Tree);
      }
#line 3765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1146 "parser.y" /* yacc.c:1646  */
    {
         if(cdbug) printf("<-args empty\n");
         (yyval.Tree)=NULL;
      }
#line 3774 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1153 "parser.y" /* yacc.c:1646  */
    {
            yyerrok;
            if(cdbug) printf("<-argList declaration\n");
            (yyval.Tree) = addSibling((yyvsp[-2].Tree),(yyvsp[0].Tree));

            
         }
#line 3786 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1162 "parser.y" /* yacc.c:1646  */
    {
            if(cdbug) printf("<-argList declaration\n");
            (yyval.Tree)=(yyvsp[0].Tree);
         }
#line 3795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1167 "parser.y" /* yacc.c:1646  */
    { (yyval.Tree) = NULL; }
#line 3801 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1168 "parser.y" /* yacc.c:1646  */
    { yyerrok; (yyval.Tree) = NULL;}
#line 3807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1172 "parser.y" /* yacc.c:1646  */
    {
            yyerrok;
            if(cdbug) printf("<-constant NUMCONST : %d\n", (yyvsp[0].Token_Data)->Num_Val);
            (yyval.Tree) = newExpNode(ConstantK, (yyvsp[0].Token_Data)->Line_Num); 
            (yyval.Tree)-> attr.value = (yyvsp[0].Token_Data)->Num_Val;
            (yyval.Tree)->type = Integer;
            (yyval.Tree)->isInit = true;
         }
#line 3820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1182 "parser.y" /* yacc.c:1646  */
    {      
            yyerrok;      
            if(cdbug) printf("<-constant CHARCONST\n");
            (yyval.Tree) = newExpNode(ConstantK, (yyvsp[0].Token_Data)->Line_Num); 
            (yyval.Tree)->TD=(yyvsp[0].Token_Data);
            //printf("FOUND |%s|\n", $1->Token_Str);
            (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class;
            (yyval.Tree)->type = Char;
            (yyval.Tree)->isInit = true;
            (yyval.Tree)->attr.cvalue = (yyvsp[0].Token_Data)->Token_Str[1];
         }
#line 3836 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1195 "parser.y" /* yacc.c:1646  */
    {
            yyerrok;
            if(cdbug) printf("<-constant STRINGCONST\n");
            (yyval.Tree) = newExpNode(ConstantK, (yyvsp[0].Token_Data)->Line_Num); 
            (yyval.Tree)-> attr.string = strdup((yyvsp[0].Token_Data)->Raw_Str);
            (yyval.Tree)->type = Char;  
         }
#line 3848 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1204 "parser.y" /* yacc.c:1646  */
    {
            yyerrok;
            if(cdbug) printf("<-constant FALSE\n");
            (yyval.Tree) = newExpNode(ConstantK, (yyvsp[0].Token_Data)->Line_Num);
            (yyval.Tree)->attr.value = 0;
            (yyval.Tree)->type = Bool;
            (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class; 
            (yyval.Tree)->isInit = true;
         }
#line 3862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1215 "parser.y" /* yacc.c:1646  */
    {
            yyerrok;
            if(cdbug) printf("<-constant TRUE\n");
            (yyval.Tree) = newExpNode(ConstantK, (yyvsp[0].Token_Data)->Line_Num);
            (yyval.Tree)->attr.value = 1;
            (yyval.Tree)->type = Bool; 
            (yyval.Tree)->attr.op = (yyvsp[0].Token_Data)->Token_Class; 
            (yyval.Tree)->isInit = true;
         }
#line 3876 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 3880 "parser.tab.c" /* yacc.c:1646  */
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
#line 1228 "parser.y" /* yacc.c:1906  */


int main(int argc, char **argv){
   int c = 0;
   numErrs = 0, numWarns = 0, Loffset = 0, Goffset = 0, SYNTAXERR = false;
   bool printSyntaxTree = 0;
   TreeNode *mainNode;
   char *filename ;
   TreeTwo = syntaxTree;
   
   



      // hunt for a string of options
      while ((c = getopt(argc, argv, "bcdpP")) != -1) {
            switch (c) {
            case 'b':
               bug = true;
               break;
            case 'c':
               cdbug = true;
               break;
            case 'd': 
               yydebug=1;
              if(cdbug) printf("DEBUGGING\n");
               break;
            case 'p': //lowercase p
               if(cdbug)printf("PRINTING SYNTAX TREE\n");
               printSyntaxTree=true;
               break;
            case 'P':   //Capitol P
            if(cdbug) printf("PRINTING THE ANNOTATED SYNTAX TREE\n");
            printSyntaxTree = true;
            //PAST = true;
            PMEM = true;
            break;
            case '?':
            default: 
               exit(1);
            }
      }


   if(argc > 1){
      filename = strdup(argv[1]);
      //printf("Changing name\n");
      filename[strlen(filename)-2] = 116; //t
      filename[strlen(filename)-1] = 109; //m

      if((yyin = fopen(argv[argc-1], "r"))){    //not sure if this actually works argc -1 is wack 
         //redirects input
      }
      else{
         if(cdbug) printf("File failed to open %s\n", argv[argc-1]);
         
      }
   }

   code = fopen(filename, "w");     //open tm file

   if(code == NULL){
      printf("Error opening %s\n",filename);
   }
   else{
      //printf("%s sucesfully opened \n", filename);
   }
      
   
   //fprintf(code, )
   initErrorProcessing();
   yyparse();     //tokenize the entire file

   // If there are syntax errors, we can now look for semantic ones
   
   if(numErrs == 0){          
      prototype();         //IO prototypes
      analyze(syntaxTree);   //syntax anlysis  
      st.applyToAll(wasUsed); //check globals

      mainNode = st.lookupNode((char *)"main");
      if(mainNode != NULL && mainNode->nodekind == DeclK && mainNode->kind.decl != FuncK || mainNode == NULL){      //if its not a function or not found at all
         printf("ERROR(LINKER): Procedure main is not declared.\n");
         numErrs++;      
      }
      else{
            //main found
      }
   }
   else{
      SYNTAXERR = true;
   }

   //printf("Print FINAL table.\n");              
   //st.print(pointerPrintStr);
   if(printSyntaxTree) TreePrint(syntaxTree, 0);   //print the tree
   //Goffset = Goffset +1;                           //bc i use post decrement (x--)
   printf("Offset for end of global space: %d\n", Goffset);
   printf("Number of warnings: %d\n",numWarns );
   printf("Number of errors: %d\n",numErrs);
   //st.print(pointerPrintStr);
   
   IOSetup(syntaxTree);
   //treeCode(syntaxTree);
   init();
   
   fclose(code);     //close tm file

}
