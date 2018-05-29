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
#line 1 "./syntax.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "lex.yy.c"
#include "ast.h"

extern int yylex();
extern void yyerror(const char *);
extern int error;
#define YYERROR_VERBOSE

#line 79 "./syntax.tab.c" /* yacc.c:339  */

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
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    TYPE = 260,
    IF = 261,
    ELSE = 262,
    WHILE = 263,
    STRUCT = 264,
    RETURN = 265,
    RELOP = 266,
    LC = 267,
    RC = 268,
    LB = 269,
    RB = 270,
    LP = 271,
    RP = 272,
    COMMA = 273,
    SEMI = 274,
    ID = 275,
    ASSIGNOP = 276,
    AND = 277,
    OR = 278,
    PLUS = 279,
    MINUS = 280,
    STAR = 281,
    DIV = 282,
    NOT = 283,
    DOT = 284,
    LOWER_THAN_ELSE = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "./syntax.y" /* yacc.c:355  */

	struct Node * node;

#line 154 "./syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 171 "./syntax.tab.c" /* yacc.c:358  */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   309

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    49,    56,    61,    67,    73,    80,    87,
      93,    99,   109,   115,   123,   129,   137,   144,   149,   158,
     164,   170,   176,   182,   188,   194,   200,   206,   212,   221,
     228,   235,   240,   246,   252,   258,   264,   270,   276,   283,
     290,   294,   300,   306,   312,   318,   324,   330,   339,   345,
     351,   357,   363,   369,   375,   381,   387,   393,   399,   405,
     411,   417,   423,   429,   436,   442,   448,   454,   460,   466
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "TYPE", "IF", "ELSE",
  "WHILE", "STRUCT", "RETURN", "RELOP", "LC", "RC", "LB", "RB", "LP", "RP",
  "COMMA", "SEMI", "ID", "ASSIGNOP", "AND", "OR", "PLUS", "MINUS", "STAR",
  "DIV", "NOT", "DOT", "LOWER_THAN_ELSE", "$accept", "Program",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "StructSpecifier",
  "OptTag", "Tag", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
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
     285
};
# endif

#define YYPACT_NINF -107

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define YYTABLE_NINF -41

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     125,   -11,  -107,     0,    58,  -107,   125,     4,  -107,  -107,
      47,    67,  -107,  -107,  -107,    85,  -107,    21,    64,    63,
      36,   296,  -107,  -107,    73,  -107,    89,     5,    37,  -107,
    -107,    82,     8,   107,    37,   109,  -107,     5,   122,   133,
     139,   140,  -107,  -107,    60,  -107,    97,    84,   134,   150,
    -107,  -107,  -107,   142,  -107,    10,  -107,   105,  -107,  -107,
     154,   157,   103,   103,   158,   103,   103,  -107,   145,    60,
     121,  -107,   103,  -107,     8,  -107,  -107,  -107,   103,   103,
     168,   138,   155,    93,    25,    42,  -107,  -107,   103,   103,
    -107,   103,   103,   103,   103,   103,   103,   103,   151,   240,
    -107,   172,   189,  -107,  -107,   119,  -107,   206,   170,   269,
     223,   240,   263,   246,    25,    25,    42,    42,  -107,    83,
      83,  -107,   113,  -107,  -107,   181,  -107,  -107,    83,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,    17,     0,     2,     0,     0,    13,     9,
      18,     0,    15,     1,     3,     0,     6,    19,     0,    10,
       0,     0,    21,    24,     0,     5,     0,     0,     0,     8,
       7,     0,     0,     0,     0,     0,    23,     0,     0,    26,
       0,     0,    19,    11,     0,    42,     0,    46,     0,    43,
      14,    39,    27,    28,    22,     0,    20,     0,    64,    65,
       0,     0,     0,     0,    63,     0,     0,    33,     0,     0,
       0,    45,     0,    41,     0,    25,    66,    38,     0,     0,
       0,     0,     0,     0,    57,    58,    29,    30,     0,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      44,     0,     0,    34,    56,     0,    60,    68,     0,    51,
       0,    48,    49,    50,    52,    53,    54,    55,    62,     0,
       0,    69,     0,    59,    61,    35,    37,    67,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,   169,  -107,   163,    12,  -107,  -107,  -107,   -30,
    -107,   136,  -107,   182,   123,  -106,    41,  -107,   130,  -107,
     -62,    86
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    18,    32,     8,    11,    12,    19,
      20,    38,    39,    67,    68,    69,    33,    34,    48,    49,
      70,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    82,    47,    84,    85,    15,    41,    53,     9,    46,
      99,    35,     7,   125,   126,     2,   101,   102,     7,     3,
      10,   107,   129,    16,    17,    42,   109,   110,    42,   111,
     112,   113,   114,   115,   116,   117,    37,    24,    31,    89,
     -40,   -40,     2,   -40,    47,   -40,     3,   -40,    28,   -40,
     -40,    96,    97,   -40,    98,    29,    89,   -40,    13,   -16,
     107,    57,   -40,    58,    59,   -40,    60,    37,    61,    44,
      62,    98,    28,   -31,    35,    51,    63,    26,     2,    21,
      64,    27,     3,    25,    57,    65,    58,    59,    66,    60,
      36,    61,    40,    62,   105,    28,    58,    59,    26,    63,
      22,    45,    23,    64,    80,    72,    58,    59,    65,    63,
     106,    66,    22,    64,   105,    71,    58,    59,    65,    63,
      50,    66,    76,    64,    77,    -4,     1,    52,    65,    63,
       2,    66,    88,    64,     3,    89,    76,   121,    65,    54,
      90,    66,    91,    92,    93,    94,    95,    96,    97,    88,
      98,    55,    89,    73,    56,    22,    26,   103,    86,    91,
      92,    93,    94,    95,    96,    97,    88,    98,    74,    89,
      78,   118,   104,    79,    83,    14,    91,    92,    93,    94,
      95,    96,    97,    88,    98,    76,    89,   123,   128,   119,
      43,    75,    87,    91,    92,    93,    94,    95,    96,    97,
      88,    98,    30,    89,   100,     0,   120,     0,   127,     0,
      91,    92,    93,    94,    95,    96,    97,    88,    98,     0,
      89,     0,     0,     0,   122,     0,     0,    91,    92,    93,
      94,    95,    96,    97,    88,    98,     0,    89,   124,     0,
       0,     0,     0,     0,    91,    92,    93,    94,    95,    96,
      97,    88,    98,     0,    89,     0,     0,    88,     0,     0,
      89,    91,    92,    93,    94,    95,    96,    97,    92,    98,
      94,    95,    96,    97,    88,    98,     0,    89,     0,     0,
       0,     0,     0,    89,     0,     0,     0,    94,    95,    96,
      97,     0,    98,    94,    95,    96,    97,    31,    98,     0,
       0,     2,     0,     0,     0,     3,     0,     0,     0,   -40
};

static const yytype_int16 yycheck[] =
{
      62,    63,    32,    65,    66,     1,     1,    37,    19,     1,
      72,     1,     0,   119,   120,     5,    78,    79,     6,     9,
      20,    83,   128,    19,    20,    20,    88,    89,    20,    91,
      92,    93,    94,    95,    96,    97,    24,    16,     1,    14,
       3,     4,     5,     6,    74,     8,     9,    10,    12,    12,
      13,    26,    27,    16,    29,    19,    14,    20,     0,    12,
     122,     1,    25,     3,     4,    28,     6,    55,     8,    28,
      10,    29,    12,    13,     1,    34,    16,    14,     5,    12,
      20,    18,     9,    19,     1,    25,     3,     4,    28,     6,
      17,     8,     3,    10,     1,    12,     3,     4,    14,    16,
      15,    19,    17,    20,     1,    21,     3,     4,    25,    16,
      17,    28,    15,    20,     1,    18,     3,     4,    25,    16,
      13,    28,    17,    20,    19,     0,     1,    18,    25,    16,
       5,    28,    11,    20,     9,    14,    17,    18,    25,    17,
      19,    28,    21,    22,    23,    24,    25,    26,    27,    11,
      29,    18,    14,    19,    15,    15,    14,    19,    13,    21,
      22,    23,    24,    25,    26,    27,    11,    29,    18,    14,
      16,    20,    17,    16,    16,     6,    21,    22,    23,    24,
      25,    26,    27,    11,    29,    17,    14,    17,     7,    17,
      27,    55,    69,    21,    22,    23,    24,    25,    26,    27,
      11,    29,    20,    14,    74,    -1,    17,    -1,   122,    -1,
      21,    22,    23,    24,    25,    26,    27,    11,    29,    -1,
      14,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    11,    29,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    11,    29,    -1,    14,    -1,    -1,    11,    -1,    -1,
      14,    21,    22,    23,    24,    25,    26,    27,    22,    29,
      24,    25,    26,    27,    11,    29,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    29,    24,    25,    26,    27,     1,    29,    -1,
      -1,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    13
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     5,     9,    32,    33,    34,    36,    37,    19,
      20,    38,    39,     0,    33,     1,    19,    20,    35,    40,
      41,    12,    15,    17,    16,    19,    14,    18,    12,    19,
      44,     1,    36,    47,    48,     1,    17,    36,    42,    43,
       3,     1,    20,    35,    47,    19,     1,    40,    49,    50,
      13,    47,    18,    40,    17,    18,    15,     1,     3,     4,
       6,     8,    10,    16,    20,    25,    28,    44,    45,    46,
      51,    18,    21,    19,    18,    42,    17,    19,    16,    16,
       1,    51,    51,    16,    51,    51,    13,    45,    11,    14,
      19,    21,    22,    23,    24,    25,    26,    27,    29,    51,
      49,    51,    51,    19,    17,     1,    17,    51,    52,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    20,    17,
      17,    18,    18,    17,    15,    46,    46,    52,     7,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    34,    34,    34,
      35,    35,    36,    36,    37,    37,    38,    38,    39,    40,
      40,    40,    41,    41,    41,    42,    42,    42,    43,    44,
      45,    45,    46,    46,    46,    46,    46,    46,    46,    47,
      47,    48,    48,    49,    49,    49,    50,    50,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    52,    52
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     3,     2,
       1,     3,     1,     1,     5,     2,     1,     0,     1,     1,
       4,     2,     4,     3,     2,     3,     1,     2,     2,     4,
       2,     0,     2,     1,     3,     5,     7,     5,     2,     2,
       0,     3,     2,     1,     3,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     4,
       3,     4,     3,     1,     1,     1,     2,     3,     1,     2
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
#line 42 "./syntax.y" /* yacc.c:1646  */
    { 
				root = createNode("Program", SYNTACTIC); 
				struct Node *children[] = {(yyvsp[0].node)}; 
				addchildren(root, children, 1);
		   }
#line 1369 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 50 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("ExtDefList", SYNTACTIC);
				struct Node *children[] = {(yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 2);	
		   }
#line 1379 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 56 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("ExtDefList", SYNTACTIC);	
		   }
#line 1387 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 62 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("ExtDef", SYNTACTIC);
				struct Node *children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		   }
#line 1397 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 68 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("ExtDef", SYNTACTIC);
				struct Node *children[] = {(yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 2);
		   }
#line 1407 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 74 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("ExtDef", SYNTACTIC);
				struct Node *children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
				//printf("Function Define at line %d\n", yylineno);
		   }
#line 1418 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 81 "./syntax.y" /* yacc.c:1646  */
    {
				//printf("Function Declarators at line %d\n", yylineno);
				(yyval.node) = createNode("ExtDef", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		   }
#line 1429 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 88 "./syntax.y" /* yacc.c:1646  */
    {

		   }
#line 1437 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 94 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("ExtDecList", SYNTACTIC);
				struct Node *children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		   }
#line 1447 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 100 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("ExtDecList", SYNTACTIC);
				struct Node *children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		   }
#line 1457 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 110 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Specifier", SYNTACTIC);
				struct Node *children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		  }
#line 1467 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 116 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Specifier", SYNTACTIC);
				struct Node *children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);		
		  }
#line 1477 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 124 "./syntax.y" /* yacc.c:1646  */
    { 
				(yyval.node) = createNode("StructSpecifier", SYNTACTIC);
				struct Node *children[] = {(yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 5);
		  }
#line 1487 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 130 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("StructSpecifier", SYNTACTIC);
				struct Node *children[] = {(yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 2);
		  }
#line 1497 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 138 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("OptTag", SYNTACTIC);
				struct Node *children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		  }
#line 1507 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 144 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("OptTag", SYNTACTIC);
		  }
#line 1515 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 150 "./syntax.y" /* yacc.c:1646  */
    { 
				(yyval.node) = createNode("Tag", SYNTACTIC);
				struct Node *children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		  }
#line 1525 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 159 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("VarDec", SYNTACTIC);
				struct Node *children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		  }
#line 1535 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 165 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("VarDec", SYNTACTIC);
				struct Node *children[] = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 4);
		  }
#line 1545 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 171 "./syntax.y" /* yacc.c:1646  */
    {

		  }
#line 1553 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 177 "./syntax.y" /* yacc.c:1646  */
    { 
				(yyval.node) = createNode("FunDec", SYNTACTIC);
				struct Node *children[] = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 4);
		  }
#line 1563 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 183 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("FunDec", SYNTACTIC);
				struct Node *children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		  }
#line 1573 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 189 "./syntax.y" /* yacc.c:1646  */
    {

		  }
#line 1581 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 195 "./syntax.y" /* yacc.c:1646  */
    { 
				(yyval.node) = createNode("VarList", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		  }
#line 1591 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 201 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("VarList", SYNTACTIC);
				struct Node* children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		  }
#line 1601 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 207 "./syntax.y" /* yacc.c:1646  */
    {

		  }
#line 1609 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 213 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("ParamDec", SYNTACTIC);
				struct Node *children[] = {(yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 2);
		  }
#line 1619 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 222 "./syntax.y" /* yacc.c:1646  */
    { 
				(yyval.node) = createNode("CompSt", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 4);
		  }
#line 1629 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 229 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("StmtList", SYNTACTIC);
				struct Node *children[] = {(yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 2);
		  }
#line 1639 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 235 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("StmtList", SYNTACTIC);
		  }
#line 1647 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 241 "./syntax.y" /* yacc.c:1646  */
    { 
				(yyval.node) = createNode("Stmt", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 2);
		  }
#line 1657 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 247 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Stmt", SYNTACTIC);
				struct Node* children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		  }
#line 1667 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 253 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Stmt", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		  }
#line 1677 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 259 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Stmt", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 5);
		  }
#line 1687 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 265 "./syntax.y" /* yacc.c:1646  */
    { 
				(yyval.node) = createNode("Stmt", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 7);
		  }
#line 1697 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 271 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Stmt", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 5);
		  }
#line 1707 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 277 "./syntax.y" /* yacc.c:1646  */
    {

		  }
#line 1715 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 284 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("DefList", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 2);
		  }
#line 1725 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 290 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("DefList", SYNTACTIC);
	      }
#line 1733 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 295 "./syntax.y" /* yacc.c:1646  */
    { 
				(yyval.node) = createNode("Def", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		  }
#line 1743 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 301 "./syntax.y" /* yacc.c:1646  */
    {

		  }
#line 1751 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 307 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("DecList", SYNTACTIC);
				struct Node* children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		  }
#line 1761 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 313 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("DecList", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		  }
#line 1771 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 319 "./syntax.y" /* yacc.c:1646  */
    {

		  }
#line 1779 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 325 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Dec", SYNTACTIC);
				struct Node* children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		  }
#line 1789 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 331 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Dec", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		  }
#line 1799 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 340 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
	  	  }
#line 1809 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 346 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
 	      }
#line 1819 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 352 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		  }
#line 1829 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 358 "./syntax.y" /* yacc.c:1646  */
    { 
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
	 	  }
#line 1839 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 364 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
 		  }
#line 1849 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 370 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		  }
#line 1859 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 376 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		  }
#line 1869 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 382 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
	      }
#line 1879 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 388 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		  }
#line 1889 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 394 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 2);
		  }
#line 1899 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 400 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 2);
		  }
#line 1909 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 406 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 4);
		  }
#line 1919 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 412 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		  }
#line 1929 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 418 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};	
				addchildren((yyval.node), children, 4);
	 	  }
#line 1939 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 424 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
		  }
#line 1949 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 430 "./syntax.y" /* yacc.c:1646  */
    {

				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		  }
#line 1960 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 437 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		  }
#line 1970 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 443 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Exp", SYNTACTIC);
				struct Node* children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		  }
#line 1980 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 449 "./syntax.y" /* yacc.c:1646  */
    {

		  }
#line 1988 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 455 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Args", SYNTACTIC);
				struct Node* children[] = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
				addchildren((yyval.node), children, 3);
	      }
#line 1998 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 461 "./syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = createNode("Args", SYNTACTIC);
				struct Node* children[] = {(yyvsp[0].node)};
				addchildren((yyval.node), children, 1);
		  }
#line 2008 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 467 "./syntax.y" /* yacc.c:1646  */
    {

		  }
#line 2016 "./syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2020 "./syntax.tab.c" /* yacc.c:1646  */
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
#line 473 "./syntax.y" /* yacc.c:1906  */


void yyerror(const char *s)
{
	error = 1;
	fprintf(stderr, "Error type B at Line %d: %s\n", yylineno,s);
}
