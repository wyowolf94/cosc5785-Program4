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
#line 9 "program4.y" /* yacc.c:339  */


#include <iostream>
#include <FlexLexer.h>
#include "node.hpp"
#include "attributes.h"

using namespace std;
//using std::cerr;
//using std::cout;
//using std::endl;

// externs defined in program3.cpp 
extern vector<Node*> forest;
extern yyFlexLexer myScanner;

// Make C++ scanner play nice with C parser
#define yylex() myScanner.yylex()

// Parser function prototype
void yyerror(const char *);


#line 90 "program4.tab.c" /* yacc.c:339  */

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
   by #include "program4.tab.h".  */
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
#line 33 "program4.y" /* yacc.c:355  */

  Node *ttype;
  struct attributes* atts;

#line 180 "program4.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROGRAM4_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 197 "program4.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   302

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    74,    78,    79,    82,    85,    94,   102,
     109,   116,   119,   126,   131,   136,   143,   154,   158,   163,
     168,   176,   179,   185,   188,   194,   201,   203,   208,   211,
     214,   217,   222,   229,   234,   241,   248,   254,   259,   264,
     269,   273,   278,   287,   294,   302,   313,   315,   322,   324,
     330,   342,   344,   349,   352,   359,   362,   365,   370,   376,
     386,   390,   398,   401,   407,   409,   413,   415,   417,   419,
     421,   423,   427,   429,   431,   435,   437,   439,   441,   445,
     447,   449
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT", "THIS", "LBRACK", "RBRACK",
  "DOUBBRACK", "LBRACE", "RBRACE", "INT", "IDEN", "NUM", "NLL", "READ",
  "NEW", "LPAREN", "RPAREN", "IF", "ELSE", "DEQ", "NEQ", "LEQ", "GEQ",
  "GT", "LT", "PLUS", "MINUS", "OR", "MULT", "DIVD", "MOD", "AND", "BANG",
  "SEMI", "EQ", "COMMA", "RETURN", "WHILE", "PRINT", "RO", "SO", "PO",
  "UO", "DE", "$accept", "start", "elem", "statement", "condstatement",
  "block", "stateplus", "locvardecplus", "locvardec", "optexp", "exp",
  "newexp", "brackstar", "expstar", "arglist", "explist", "name", "varDec",
  "type", "simpleType", "relop", "sumop", "proop", "unyop", YY_NULLPTR
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
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -42

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-42)))

#define YYTABLE_NINF -66

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -42,     9,   -42,   -42,    48,   -42,     3,   -11,   -42,   243,
       0,    13,   -42,   -42,   -42,   -42,    73,   -42,    38,   -42,
     -42,   -42,    26,    92,   -42,    43,   243,   -42,   -42,   -42,
      10,    -3,   243,   -42,   -42,   -42,     6,   270,   -42,    67,
     243,   243,   243,    31,   243,   243,   243,   -42,     5,   -42,
     -42,   -42,   105,   -42,    27,   201,    45,    11,    55,   -42,
     169,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   243,   243,   243,    14,   -42,
     257,   270,    56,    39,   -42,   182,    57,   137,   -42,   -42,
     -42,   -42,   117,   -42,   -42,   -42,   243,    72,   -42,   -42,
     146,   116,   -42,   -42,   -42,   117,    46,   243,   -42,   -42,
      47,   -42,   -42,    60,    24,   243,    77,   -42,   -42,   270,
     -42,   117,   -42,   -42,   214,   -42,   -42,   -42,   -42
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    55,     0,    64,    56,     0,     6,    26,
       0,     0,     3,     4,    11,    14,     0,     5,     0,    62,
      17,    21,     0,     0,    23,     0,     0,    56,    29,    30,
       0,     0,     0,    79,    80,    81,     0,    27,    36,    28,
       0,     0,    51,     0,     0,    51,     0,    63,     0,    19,
      22,    18,     0,    24,     0,     0,     0,     0,    65,    48,
       0,    13,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,     0,     0,     0,    40,
       0,    53,     0,    52,    57,     0,     0,     0,    61,    60,
      20,    25,     0,    35,    34,    33,    51,    46,    42,    41,
      37,    38,    39,    32,    31,     0,     0,     0,    59,    58,
       0,     8,     7,    15,     0,     0,    45,    12,    10,    54,
       9,     0,    44,    43,     0,    47,    16,    50,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -42,     1,   -42,   -42,    65,   -42,    69,   -42,
      -8,   -42,   -42,   -42,   -41,   -42,    -1,   -42,    89,    63,
     -42,   -42,   -42,   -42
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    12,    21,    14,    15,    22,    23,    24,    36,
      81,    38,   116,    97,    82,    83,    39,    17,    25,    19,
      75,    76,    77,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,    37,    13,    16,    86,    26,    88,     5,    58,     2,
     -65,    56,    94,     3,   -65,   103,    41,     4,    55,     5,
       6,    16,    16,    50,    60,   122,    57,     7,    95,    42,
       3,   104,    79,    80,     4,    49,    85,    27,    87,    89,
      61,   123,    84,     8,     7,    47,     9,    10,    11,    48,
      47,    16,     3,    50,    54,   114,     4,    20,     5,     6,
       8,    91,    93,     9,    10,    11,     7,   100,   101,   102,
      43,    96,    44,   106,   110,   107,    43,   115,    44,   121,
     118,   120,     8,    78,   125,     9,    10,    11,    52,    45,
      18,    16,    53,   113,    59,     0,     3,     0,     0,   119,
       4,    51,     5,     6,    16,     0,   117,   124,    46,     3,
       7,     0,     0,     4,    90,     0,    27,     0,     0,     0,
      16,     3,   126,     7,     0,     4,     8,     0,    27,     9,
      10,    11,     0,     0,     0,     7,     0,     0,   111,     8,
       0,     0,     9,    10,    11,    71,    72,    73,    74,     0,
       0,     8,     0,     0,     9,    10,    11,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      98,   112,    68,    69,    70,    71,    72,    73,    74,     0,
       0,     0,     0,   108,     0,     0,    99,     0,   109,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,   127,     0,     0,    92,     0,
     128,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     3,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,     0,     0,     0,   105,     0,    35,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74
};

static const yytype_int8 yycheck[] =
{
       1,     9,     1,     4,    45,    16,     1,    10,    11,     0,
       7,     1,     1,     4,    11,     1,    16,     8,    26,    10,
      11,    22,    23,    22,    32,     1,    16,    18,    17,    16,
       4,    17,    40,    41,     8,     9,    44,    11,    46,    34,
      34,    17,    11,    34,    18,     7,    37,    38,    39,    11,
       7,    52,     4,    52,    11,    96,     8,     9,    10,    11,
      34,    34,    17,    37,    38,    39,    18,    75,    76,    77,
       3,    16,     5,    17,    17,    36,     3,     5,     5,    19,
      34,    34,    34,    16,     7,    37,    38,    39,    23,    16,
       1,    92,    23,    92,    31,    -1,     4,    -1,    -1,   107,
       8,     9,    10,    11,   105,    -1,   105,   115,    35,     4,
      18,    -1,    -1,     8,     9,    -1,    11,    -1,    -1,    -1,
     121,     4,   121,    18,    -1,     8,    34,    -1,    11,    37,
      38,    39,    -1,    -1,    -1,    18,    -1,    -1,     1,    34,
      -1,    -1,    37,    38,    39,    29,    30,    31,    32,    -1,
      -1,    34,    -1,    -1,    37,    38,    39,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       1,    34,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    17,    -1,     6,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     1,    -1,    -1,    17,    -1,
       6,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    -1,    -1,    17,    -1,    33,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,     0,     4,     8,    10,    11,    18,    34,    37,
      38,    39,    47,    48,    49,    50,    61,    62,    63,    64,
       9,    48,    51,    52,    53,    63,    16,    11,    12,    13,
      14,    15,    16,    26,    27,    33,    54,    55,    56,    61,
      68,    16,    16,     3,     5,    16,    35,     7,    11,     9,
      48,     9,    51,    53,    11,    55,     1,    16,    11,    64,
      55,    34,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    65,    66,    67,    16,    55,
      55,    55,    59,    60,    11,    55,    59,    55,     1,    34,
       9,    34,    17,    17,     1,    17,    16,    58,     1,    17,
      55,    55,    55,     1,    17,    17,    17,    36,     1,     6,
      17,     1,    34,    48,    59,     5,    57,    48,    34,    55,
      34,    19,     1,    17,    55,     7,    48,     1,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    49,    50,    50,    50,
      50,    51,    51,    52,    52,    53,    54,    54,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    57,    57,    58,    58,
      58,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    66,    66,    66,    67,    67,    67,    67,    68,
      68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     4,     4,     5,
       5,     1,     5,     3,     1,     5,     7,     2,     3,     3,
       4,     1,     2,     1,     2,     3,     0,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       2,     3,     3,     5,     5,     4,     0,     2,     0,     4,
       4,     0,     1,     1,     3,     1,     1,     3,     4,     4,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
#line 73 "program4.y" /* yacc.c:1646  */
    {}
#line 1401 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "program4.y" /* yacc.c:1646  */
    {if((yyvsp[0].ttype)->getValid()) forest.push_back((yyvsp[0].ttype));
                    else delete (yyvsp[0].ttype);}
#line 1408 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 78 "program4.y" /* yacc.c:1646  */
    {}
#line 1414 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "program4.y" /* yacc.c:1646  */
    {}
#line 1420 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 83 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("semi");
               delete (yyvsp[0].atts);}
#line 1427 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 86 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("nameeq");
               if(!(yyvsp[-3].ttype)->getValid() || !(yyvsp[-1].ttype)->getValid()) {
                 (yyval.ttype)->setValid(false);
               }
               (yyval.ttype)->addChild((yyvsp[-3].ttype));
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-2].atts);
               delete (yyvsp[0].atts);}
#line 1440 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 95 "program4.y" /* yacc.c:1646  */
    {cerr << "Missing ';' after statement: line " << (yyvsp[-2].atts)->lNum << endl << endl;
               (yyval.ttype) = new errorNode("<Statement>");
               (yyval.ttype)->setValid(false);
               (yyval.ttype)->addChild((yyvsp[-3].ttype));
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-2].atts);
               yyerrok;}
#line 1452 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 103 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("namearglist");
               (yyval.ttype)->addChild((yyvsp[-4].ttype));
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               delete (yyvsp[-3].atts);
               delete (yyvsp[-1].atts);
               delete (yyvsp[0].atts);}
#line 1463 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 110 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("printarglist");
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               delete (yyvsp[-4].atts);
               delete (yyvsp[-3].atts);
               delete (yyvsp[-1].atts);
               delete (yyvsp[0].atts);}
#line 1474 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 117 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("cond");
               (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1481 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("while");
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               (yyval.ttype)->addChild((yyvsp[0].ttype));
               delete (yyvsp[-4].atts);
               delete (yyvsp[-3].atts);
               delete (yyvsp[-1].atts);}
#line 1492 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("optexp");
               (yyval.ttype)->addChild((yyvsp[-1].ttype));
               delete (yyvsp[-2].atts);
               delete (yyvsp[0].atts);}
#line 1501 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 132 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new statementNode("block");
               (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1508 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 137 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new condstatementNode("if");
                   (yyval.ttype)->addChild((yyvsp[-2].ttype));
                   (yyval.ttype)->addChild((yyvsp[0].ttype));
                   delete (yyvsp[-4].atts);
                   delete (yyvsp[-3].atts);
                   delete (yyvsp[-1].atts);}
#line 1519 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 144 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new condstatementNode("if-else");
                   (yyval.ttype)->addChild((yyvsp[-4].ttype));
                   (yyval.ttype)->addChild((yyvsp[-2].ttype));
                   (yyval.ttype)->addChild((yyvsp[0].ttype));
                   delete (yyvsp[-6].atts);
                   delete (yyvsp[-5].atts);
                   delete (yyvsp[-3].atts);
                   delete (yyvsp[-1].atts);}
#line 1532 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 155 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new blockNode("empty");
           delete (yyvsp[-1].atts);
           delete (yyvsp[0].atts);}
#line 1540 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 159 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new blockNode("locvardecs");
           (yyval.ttype)->addChild((yyvsp[-1].ttype));
           delete (yyvsp[-2].atts);
           delete (yyvsp[0].atts);}
#line 1549 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 164 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new blockNode("statements");
           (yyval.ttype)->addChild((yyvsp[-1].ttype));
           delete (yyvsp[-2].atts);
           delete (yyvsp[0].atts);}
#line 1558 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 169 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new blockNode("both");
           (yyval.ttype)->addChild((yyvsp[-2].ttype));
           (yyval.ttype)->addChild((yyvsp[-1].ttype));
           delete (yyvsp[-3].atts);
           delete (yyvsp[0].atts);}
#line 1568 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 177 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new stateplusNode();
               (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1575 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 180 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new stateplusNode();
               (yyvsp[-1].ttype)->addChild((yyvsp[0].ttype));
               (yyval.ttype) = (yyvsp[-1].ttype);}
#line 1583 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 186 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new locvardecplusNode();
                   (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1590 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 189 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new locvardecplusNode();
                   (yyvsp[-1].ttype)->addChild((yyvsp[0].ttype));
                   (yyval.ttype) = (yyvsp[-1].ttype);}
#line 1598 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 195 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new locvardecNode((yyvsp[-1].atts)->value);
               (yyval.ttype)->addChild((yyvsp[-2].ttype));
               delete (yyvsp[-1].atts);
               delete (yyvsp[0].atts);}
#line 1607 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 202 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new optexpNode("empty");}
#line 1613 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 204 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new optexpNode("exp");
            (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1620 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 209 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("name");
         (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1627 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 212 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("num", (yyvsp[0].atts)->value);
         delete (yyvsp[0].atts);}
#line 1634 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 215 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("null");
         delete (yyvsp[0].atts);}
#line 1641 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 218 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("name paren");
         (yyval.ttype)->addChild((yyvsp[-2].ttype));
         delete (yyvsp[-1].atts);
         delete (yyvsp[0].atts);}
#line 1650 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 223 "program4.y" /* yacc.c:1646  */
    {cerr << "Missing ')' after name declaration: line " << (yyvsp[-1].atts)->lNum << endl << endl;
         (yyval.ttype) = new errorNode("<Expression>");
         (yyval.ttype)->setValid(false);
         (yyval.ttype)->addChild((yyvsp[-2].ttype));
         delete (yyvsp[-1].atts);
         yyerrok;}
#line 1661 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 230 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("read");
         delete (yyvsp[-2].atts);
         delete (yyvsp[-1].atts);
         delete (yyvsp[0].atts);}
#line 1670 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 235 "program4.y" /* yacc.c:1646  */
    {cerr << "Missing ')' after read: line " << (yyvsp[-2].atts)->lNum << endl << endl;
         (yyval.ttype) = new errorNode("<Expression>");
         (yyval.ttype)->setValid(false);
         delete (yyvsp[-2].atts);
         delete (yyvsp[-1].atts);
         yyerrok;}
#line 1681 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 242 "program4.y" /* yacc.c:1646  */
    {cerr << "Missing '(' after read: line " << (yyvsp[-2].atts)->lNum << endl << endl;
         (yyval.ttype) = new errorNode("<Expression>");
         (yyval.ttype)->setValid(false);
         delete (yyvsp[-2].atts);
         delete (yyvsp[0].atts);
         yyerrok;}
#line 1692 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 249 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("newexp");
         if(!(yyvsp[0].ttype)->getValid()) {
           (yyval.ttype)->setValid(false);
         }
         (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1702 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 255 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("relop");
         (yyval.ttype)->addChild((yyvsp[-2].ttype));
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1711 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 260 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("sumop");
         (yyval.ttype)->addChild((yyvsp[-2].ttype));
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1720 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 265 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("proop");
         (yyval.ttype)->addChild((yyvsp[-2].ttype));
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1729 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 270 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("unyop");
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1737 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 274 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expNode("paren");
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         delete (yyvsp[-2].atts);
         delete (yyvsp[0].atts);}
#line 1746 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 279 "program4.y" /* yacc.c:1646  */
    {cerr << "Missing ')' after expression: line " << (yyvsp[-2].atts)->lNum << endl << endl;
         (yyval.ttype) = new errorNode("<Expression>");
         (yyval.ttype)->addChild((yyvsp[-1].ttype));
         (yyval.ttype)->setValid(false);
         delete (yyvsp[-2].atts);
         yyerrok;}
#line 1757 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 288 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new newexpNode("parens", (yyvsp[-3].atts)->value);
            (yyval.ttype)->addChild((yyvsp[-1].ttype));
            delete (yyvsp[-4].atts);
            delete (yyvsp[-3].atts);
            delete (yyvsp[-2].atts);
            delete (yyvsp[0].atts);}
#line 1768 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 295 "program4.y" /* yacc.c:1646  */
    {cerr << "Missing ')' after type: line " << (yyvsp[-4].atts)->lNum << endl << endl;
            (yyval.ttype) = new errorNode("<NewExpression>");
            (yyval.ttype)->addChild((yyvsp[-1].ttype));
            (yyval.ttype)->setValid(false);
            delete (yyvsp[-4].atts);
            delete (yyvsp[-2].atts);
            yyerrok;}
#line 1780 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 303 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new newexpNode("bracks");
            if(!(yyvsp[-1].ttype)->getValid()) {
              (yyval.ttype)->setValid(false);
            }
            (yyval.ttype)->addChild((yyvsp[-2].ttype)); 
            (yyval.ttype)->addChild((yyvsp[-1].ttype));
            (yyval.ttype)->addChild((yyvsp[0].ttype));
            delete (yyvsp[-3].atts);}
#line 1793 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 314 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new brackstarNode();}
#line 1799 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 316 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new brackstarNode();
               (yyvsp[-1].ttype)->addChild(new brackstarNode());
               (yyval.ttype) = (yyvsp[-1].ttype);
               delete (yyvsp[0].atts);}
#line 1808 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 323 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expstarNode();}
#line 1814 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 325 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new expstarNode();
             (yyvsp[-3].ttype)->addChild((yyvsp[-1].ttype));
             (yyval.ttype) = (yyvsp[-3].ttype);
             delete (yyvsp[-2].atts);
             delete (yyvsp[0].atts);}
#line 1824 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 331 "program4.y" /* yacc.c:1646  */
    {cerr << "Missing ']' after expression: line " << (yyvsp[-2].atts)->lNum << endl << endl;
             (yyval.ttype) = new errorNode("<expstar>");
             (yyval.ttype)->addChild((yyvsp[-3].ttype));
             (yyval.ttype)->addChild((yyvsp[-1].ttype));
             (yyval.ttype)->setValid(false);
             (yyvsp[-3].ttype)->setValid(false);
             (yyvsp[-1].ttype)->setValid(false);
             delete (yyvsp[-2].atts);
             yyerrok;}
#line 1838 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 343 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new arglistNode("empty");}
#line 1844 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 345 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new arglistNode("rec");
             (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1851 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 350 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new explistNode("exp");
             (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1858 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 353 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new explistNode("rec");
             (yyval.ttype)->addChild((yyvsp[-2].ttype));
             (yyval.ttype)->addChild((yyvsp[0].ttype));
             delete (yyvsp[-1].atts);}
#line 1867 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 360 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new nameNode("this", "");
          delete (yyvsp[0].atts);}
#line 1874 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 363 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new nameNode("id", (yyvsp[0].atts)->value);
          delete (yyvsp[0].atts);}
#line 1881 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 366 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new nameNode("dotid", (yyvsp[0].atts)->value);
          (yyval.ttype)->addChild((yyvsp[-2].ttype));
          delete (yyvsp[-1].atts);
          delete (yyvsp[0].atts);}
#line 1890 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 371 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new nameNode("exp", "");
          (yyval.ttype)->addChild((yyvsp[-3].ttype));
          (yyval.ttype)->addChild((yyvsp[-1].ttype));
          delete (yyvsp[-2].atts);
          delete (yyvsp[0].atts);}
#line 1900 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 377 "program4.y" /* yacc.c:1646  */
    {cerr << "Missing ']' after name: line " << (yyvsp[-2].atts)->lNum << endl << endl;
          (yyval.ttype) = new errorNode("<Name>");
          (yyval.ttype)->setValid(false);
          (yyval.ttype)->addChild((yyvsp[-3].ttype));
          (yyval.ttype)->addChild((yyvsp[-1].ttype));
          delete (yyvsp[-2].atts);
          yyerrok;}
#line 1912 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 386 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new varDecNode((yyvsp[-1].atts)->value);
                          (yyval.ttype)->addChild((yyvsp[-2].ttype));
                          delete (yyvsp[-1].atts);
                          delete (yyvsp[0].atts);}
#line 1921 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 390 "program4.y" /* yacc.c:1646  */
    {cerr << "Missing ';' after identifier: line " << (yyvsp[-1].atts)->lNum << endl << endl;
                          (yyval.ttype) = new errorNode("<VarDeclaration>");
                          (yyval.ttype)->addChild((yyvsp[-2].ttype));
                          (yyval.ttype)->setValid(false);
                          delete (yyvsp[-1].atts);
                          yyerrok;}
#line 1932 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 399 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new typeNode("simpleType");
          (yyval.ttype)->addChild((yyvsp[0].ttype));}
#line 1939 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 402 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new typeNode("type");
          (yyval.ttype)->addChild((yyvsp[-1].ttype));
          delete (yyvsp[0].atts);}
#line 1947 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 407 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new simpleTypeNode((yyvsp[0].atts)->token, "");
                   delete (yyvsp[0].atts);}
#line 1954 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 409 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new simpleTypeNode("id", (yyvsp[0].atts)->value);
                   delete (yyvsp[0].atts);}
#line 1961 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 413 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new relopNode("==");
               delete (yyvsp[0].atts);}
#line 1968 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 415 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new relopNode("!=");
               delete (yyvsp[0].atts);}
#line 1975 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 417 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new relopNode("<=");
               delete (yyvsp[0].atts);}
#line 1982 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 419 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new relopNode(">=");
               delete (yyvsp[0].atts);}
#line 1989 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 421 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new relopNode(">");
               delete (yyvsp[0].atts);}
#line 1996 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 423 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new relopNode("<");
               delete (yyvsp[0].atts);}
#line 2003 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 427 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new sumopNode("+");
               delete (yyvsp[0].atts);}
#line 2010 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 429 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new sumopNode("-");
               delete (yyvsp[0].atts);}
#line 2017 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 431 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new sumopNode("||");
               delete (yyvsp[0].atts);}
#line 2024 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 435 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new proopNode("*");
               delete (yyvsp[0].atts);}
#line 2031 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 437 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new proopNode("/");
               delete (yyvsp[0].atts);}
#line 2038 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 439 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new proopNode("%");
               delete (yyvsp[0].atts);}
#line 2045 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 441 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new proopNode("&&");
               delete (yyvsp[0].atts);}
#line 2052 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 445 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new unyopNode("+");
               delete (yyvsp[0].atts);}
#line 2059 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 447 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new unyopNode("-");
               delete (yyvsp[0].atts);}
#line 2066 "program4.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 449 "program4.y" /* yacc.c:1646  */
    {(yyval.ttype) = new unyopNode("!");
               delete (yyvsp[0].atts);}
#line 2073 "program4.tab.c" /* yacc.c:1646  */
    break;


#line 2077 "program4.tab.c" /* yacc.c:1646  */
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
#line 453 "program4.y" /* yacc.c:1906  */

