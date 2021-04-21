/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lab9.y"


/* Lab9 yacc file
 * FILE: lab9.y
   Added a symbol table help semantic action set.
   Using the symbol table yacc checks if variables have been declared
   and therefore can or cant be used
   Also yacc now does rudimentary type checking so that two different types cant be mixed
   Yacc take input tokens from lex
   and outputs any semantic or syntacticall errors. If no errors are found yacc calls ast to print the tree(from last lab)
 * 
   NEW 
   Main now reads input to generate a .asm file with a given name using -o argument when running the program
   Main now also prints 3 lines to the given file and calls emit_globals and emit_strings to print the MIPS
   code for writing strings and globals.
   Lastly  main calls emit_AST in emit.c to emit MIPS code based on the AST
   Inside the yacc code strings have been added in writestmt using a label instead of s1
   expr functions now also create temperary symbols used inside emit.c
   
 * Santiago Flores
 * 5/8/2020
 * 
 */

int yylex();
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "AST.h"
#include "symtable.h"
#include "emit.h"

ASTNode *GP; //global pointer

extern int linecount; // take the linecount from lex to print where error was found
int mydebug = 0;
int level = 0;
int offset = 0; //current offset
int GOFFSET;    //Global offset
int MAXOFFSET;  // the max amount of memory needed for the current function

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on line %d\n", s, linecount);
}


#line 120 "y.tab.c"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    INT = 258,
    BOOLEAN = 259,
    VOID = 260,
    MYBEGIN = 261,
    END = 262,
    IF = 263,
    THEN = 264,
    ELSE = 265,
    WHILE = 266,
    DO = 267,
    MYRETURN = 268,
    READ = 269,
    WRITE = 270,
    AND = 271,
    OR = 272,
    TRUE = 273,
    FALSE = 274,
    NOT = 275,
    GE = 276,
    LE = 277,
    EQ = 278,
    NE = 279,
    NUM = 280,
    ID = 281,
    STRING = 282
  };
#endif
/* Tokens.  */
#define INT 258
#define BOOLEAN 259
#define VOID 260
#define MYBEGIN 261
#define END 262
#define IF 263
#define THEN 264
#define ELSE 265
#define WHILE 266
#define DO 267
#define MYRETURN 268
#define READ 269
#define WRITE 270
#define AND 271
#define OR 272
#define TRUE 273
#define FALSE 274
#define NOT 275
#define GE 276
#define LE 277
#define EQ 278
#define NE 279
#define NUM 280
#define ID 281
#define STRING 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 51 "lab9.y"

    int number;
    char *string;
    struct ASTNodeType *node;
    enum OPERATORS operator;

#line 224 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

#define YYUNDEFTOK  2
#define YYMAXUTOK   282

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    39,    37,    31,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
      35,    34,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    78,    79,    84,    85,    88,    99,   116,
     133,   152,   171,   172,   173,   176,   188,   176,   204,   205,
     208,   209,   214,   230,   247,   247,   259,   261,   266,   268,
     273,   274,   275,   276,   277,   278,   279,   280,   283,   285,
     289,   293,   306,   312,   313,   318,   323,   327,   333,   347,
     350,   366,   386,   387,   402,   403,   404,   405,   406,   407,
     410,   411,   426,   427,   430,   431,   446,   447,   448,   449,
     452,   453,   457,   458,   459,   463,   468,   483,   505,   506,
     509,   517
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "BOOLEAN", "VOID", "MYBEGIN",
  "END", "IF", "THEN", "ELSE", "WHILE", "DO", "MYRETURN", "READ", "WRITE",
  "AND", "OR", "TRUE", "FALSE", "NOT", "GE", "LE", "EQ", "NE", "NUM", "ID",
  "STRING", "';'", "'['", "']'", "','", "'('", "')'", "'='", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "$accept", "program", "declist", "dec",
  "vardec", "varlist", "typespec", "fundec", "$@1", "$@2", "params",
  "paramlist", "param", "compstmt", "$@3", "locdec", "stmtlist", "stmt",
  "exprstmt", "selecstmt", "iterstmt", "retstmt", "readstmt", "writestmt",
  "assignstmt", "expr", "var", "simpexpr", "relop", "addexpr", "addop",
  "term", "multop", "factor", "call", "args", "arglist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    59,    91,
      93,    44,    40,    41,    61,    60,    62,    43,    45,    42,
      47
};
# endif

#define YYPACT_NINF -104

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-104)))

#define YYTABLE_NINF -19

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      45,  -104,  -104,  -104,     4,  -104,    45,  -104,   -12,  -104,
    -104,  -104,   -20,    -9,     5,    10,  -104,  -104,    11,    42,
    -104,    56,    22,    14,    46,    43,  -104,    55,    10,     9,
    -104,    45,  -104,    57,    84,  -104,  -104,  -104,  -104,    45,
      45,    10,     7,  -104,    78,    78,    63,    76,    74,  -104,
    -104,    78,  -104,     8,  -104,    78,  -104,    98,     7,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,    79,    75,    44,    37,
      12,  -104,  -104,    99,  -104,   100,  -104,    83,    85,    87,
      88,    89,  -104,    78,    78,    80,  -104,  -104,  -104,    78,
    -104,  -104,  -104,  -104,  -104,  -104,    78,  -104,  -104,    78,
    -104,  -104,  -104,  -104,    78,     7,     7,  -104,  -104,  -104,
    -104,    90,    91,    86,  -104,  -104,    34,    37,    12,  -104,
     108,  -104,  -104,    78,  -104,  -104,     7,  -104,  -104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    14,    13,     0,     2,     3,     5,     0,     6,
       1,     4,     8,     0,     0,     0,    15,     7,     0,     8,
      10,     0,     9,    13,     0,     0,    19,    20,     0,    22,
      16,     0,    11,     0,     0,    21,    23,    24,    17,    26,
      26,     0,    28,    27,     0,     0,     0,     0,     0,    74,
      75,     0,    71,    50,    39,     0,    31,     0,    28,    30,
      32,    33,    35,    36,    37,    34,     0,    72,    49,    52,
      60,    64,    73,     0,    72,     0,    43,     0,    50,     0,
       0,     0,    76,     0,    79,     0,    25,    29,    38,     0,
      54,    55,    56,    57,    58,    59,     0,    62,    63,     0,
      68,    69,    66,    67,     0,     0,     0,    44,    45,    47,
      46,     0,    80,     0,    78,    70,     0,    53,    61,    65,
      40,    42,    51,     0,    77,    48,     0,    81,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,  -104,   115,  -104,    38,    16,     3,  -104,  -104,  -104,
    -104,    92,  -104,    93,  -104,    94,    66,  -103,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,   -38,   -42,    36,  -104,    30,
    -104,    29,  -104,   -50,  -104,  -104,     6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,     8,     9,    21,    34,
      25,    26,    27,    56,    39,    42,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    74,    68,    96,    69,
      99,    70,   104,    71,    72,   113,   114
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    82,   120,   121,    10,    79,    73,    75,    77,    14,
      81,    15,    16,    37,    12,    44,    67,    85,    45,    17,
      46,    47,    48,   128,    24,    49,    50,    51,   100,   101,
      18,    20,    52,    53,    24,    54,    19,    83,    33,    55,
      84,    22,    41,    41,    32,   111,   112,   -18,     1,     2,
       3,   102,   103,    28,   119,    90,    91,    92,    93,     1,
       2,    23,   125,    67,    67,    90,    91,    92,    93,    94,
      95,    14,    29,    15,    97,    98,    30,    40,    40,    94,
      95,    49,    50,    51,    67,   112,    31,    36,    52,    53,
      37,    76,    49,    50,    51,    55,    49,    50,    51,    52,
      53,    80,    78,    52,    53,    86,    55,    88,   105,    89,
      55,   107,   106,   115,    83,   108,   109,   110,   126,   124,
     122,    11,   123,    35,    87,   116,   117,    38,   118,   127,
       0,     0,     0,     0,    43
};

static const yytype_int8 yycheck[] =
{
      42,    51,   105,   106,     0,    47,    44,    45,    46,    29,
      48,    31,    32,     6,    26,     8,    58,    55,    11,    28,
      13,    14,    15,   126,    21,    18,    19,    20,    16,    17,
      25,    15,    25,    26,    31,    28,    26,    29,    29,    32,
      32,    30,    39,    40,    28,    83,    84,    33,     3,     4,
       5,    39,    40,    31,   104,    21,    22,    23,    24,     3,
       4,     5,    28,   105,   106,    21,    22,    23,    24,    35,
      36,    29,    26,    31,    37,    38,    33,    39,    40,    35,
      36,    18,    19,    20,   126,   123,    31,    30,    25,    26,
       6,    28,    18,    19,    20,    32,    18,    19,    20,    25,
      26,    27,    26,    25,    26,     7,    32,    28,     9,    34,
      32,    28,    12,    33,    29,    28,    28,    28,    10,    33,
      30,     6,    31,    31,    58,    89,    96,    34,    99,   123,
      -1,    -1,    -1,    -1,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    42,    43,    44,    45,    47,    48,
       0,    43,    26,    46,    29,    31,    32,    28,    25,    26,
      46,    49,    30,     5,    47,    51,    52,    53,    31,    26,
      33,    31,    46,    29,    50,    52,    30,     6,    54,    55,
      45,    47,    56,    56,     8,    11,    13,    14,    15,    18,
      19,    20,    25,    26,    28,    32,    54,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    70,
      72,    74,    75,    66,    67,    66,    28,    66,    26,    67,
      27,    66,    74,    29,    32,    66,     7,    57,    28,    34,
      21,    22,    23,    24,    35,    36,    69,    37,    38,    71,
      16,    17,    39,    40,    73,     9,    12,    28,    28,    28,
      28,    66,    66,    76,    77,    33,    68,    70,    72,    74,
      58,    58,    30,    31,    33,    28,    10,    77,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    46,    46,
      46,    46,    47,    47,    47,    49,    50,    48,    51,    51,
      52,    52,    53,    53,    55,    54,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    62,    62,    63,    64,    64,    65,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    75,    76,    76,
      77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     0,     0,     8,     1,     1,
       1,     3,     2,     4,     0,     5,     0,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       4,     6,     4,     2,     3,     3,     3,     3,     4,     1,
       1,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     2,     4,     1,     0,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 75 "lab9.y"
    {GP = (yyvsp[0].node);}
#line 1412 "y.tab.c"
    break;

  case 3:
#line 78 "lab9.y"
    { (yyval.node) = (yyvsp[0].node);}
#line 1418 "y.tab.c"
    break;

  case 4:
#line 79 "lab9.y"
    { (yyval.node) = (yyvsp[-1].node);
                          (yyvsp[-1].node)->next = (yyvsp[0].node); 
                        }
#line 1426 "y.tab.c"
    break;

  case 5:
#line 84 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1432 "y.tab.c"
    break;

  case 6:
#line 85 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1438 "y.tab.c"
    break;

  case 7:
#line 88 "lab9.y"
    {(yyval.node) = (yyvsp[-1].node);
                                  ASTNode *p;
                                  p = (yyvsp[-1].node);
                                  while(p != NULL){
                                    p->operator = (yyvsp[-2].operator);
                                    Search(p->name,level,0)->Type = (yyvsp[-2].operator); // add the type to the newly entered symbol
                                    p = p->s1;
                                    }//while
                                  }
#line 1452 "y.tab.c"
    break;

  case 8:
#line 99 "lab9.y"
    {struct SymbTab *s;
                if(Search((yyvsp[0].string),level,0) != NULL){   //search to see if variable already exits before adding new entry, if it exits exit with error
                    yyerror("Duplicate Variable");
                    yyerror((yyvsp[0].string));
                    exit(1);
                  }//end if
                  else {//insert symbol
                     s = Insert((yyvsp[0].string), -1, 1, level, 1, offset, NULL); //Insert(name, operator type, isafunc, level, mysize, offset, ASTNode fparms)
                     offset=offset+1;
                     //Display();
                  }
                  (yyval.node) = ASTCreateNode(vardec);
                  (yyval.node)->name = (yyvsp[0].string);
                  (yyval.node)->size = 1;
                  (yyval.node)->symbol = s;
                }
#line 1473 "y.tab.c"
    break;

  case 9:
#line 116 "lab9.y"
    {   struct SymbTab *s;
                            if( Search((yyvsp[-3].string),level,0) != NULL){
                                yyerror("Duplicate Variable");
                                yyerror((yyvsp[-3].string));
                                exit(1);
                            }//end if
                            else {
                                s = Insert((yyvsp[-3].string), -1, 2, level, (yyvsp[-1].number), offset, NULL); 
                                offset=offset+(yyvsp[-1].number);
                                //Display();
                            }
                            (yyval.node) = ASTCreateNode(vardec);
                            (yyval.node)->name = (yyvsp[-3].string);
                            (yyval.node)->size = (yyvsp[-1].number);
                            (yyval.node)->symbol = s;
                        }
#line 1494 "y.tab.c"
    break;

  case 10:
#line 133 "lab9.y"
    { struct SymbTab *s;
                             if(Search((yyvsp[-2].string),level,0) != NULL){   //struct SymbTab * Search(char name[], int level, int recur)
                                yyerror("Duplicate Variable");
                                yyerror((yyvsp[-2].string));
                                exit(1);
                             }//end if
                             else {//insert symbol
                                s = Insert((yyvsp[-2].string), -1, 1, level, 1, offset, NULL); //Insert(name, operator type, isafunc, level, mysize, offset, ASTNode fparms)
                                offset=offset+1;
                                //Display();
                             }//end else
                             (yyval.node) = ASTCreateNode(vardec);
                             (yyval.node)->name = (yyvsp[-2].string);
                             (yyval.node)->size = 1;
                             (yyval.node)->s1 = (yyvsp[0].node);
                             (yyval.node)->symbol = s;
                             
                           }
#line 1517 "y.tab.c"
    break;

  case 11:
#line 152 "lab9.y"
    { struct SymbTab *s;
                                      if( Search((yyvsp[-5].string),level,0) != NULL){
                                        yyerror("Duplicate Variable");
                                        yyerror((yyvsp[-5].string));
                                        exit(1);
                                      }//end if
                                      else {
                                        s = Insert((yyvsp[-5].string), -1, 2, level, (yyvsp[-3].number), offset, NULL);
                                        offset=offset+(yyvsp[-3].number);
                                        //Display();
                                      }
                                      (yyval.node) = ASTCreateNode(vardec);
                                      (yyval.node)->name = (yyvsp[-5].string);
                                      (yyval.node)->size = (yyvsp[-3].number);
                                      (yyval.node)->s1 = (yyvsp[0].node);
                                      (yyval.node)->symbol = s;
                                     }
#line 1539 "y.tab.c"
    break;

  case 12:
#line 171 "lab9.y"
    {(yyval.operator) = intType; }
#line 1545 "y.tab.c"
    break;

  case 13:
#line 172 "lab9.y"
    {(yyval.operator) = voidType;}
#line 1551 "y.tab.c"
    break;

  case 14:
#line 173 "lab9.y"
    {(yyval.operator) = boolType;}
#line 1557 "y.tab.c"
    break;

  case 15:
#line 176 "lab9.y"
    {  if(Search((yyvsp[-1].string),level,0) != NULL) {
                                  yyerror("Duplicate name");
                                  yyerror((yyvsp[-1].string));
                                  exit(1);
                                }
                                else {//insert with no size or offset
                                  Insert((yyvsp[-1].string),(yyvsp[-2].operator), 0,level, 0, 0,NULL);
                                }
                             GOFFSET = offset; //save global offset before entering a function 
                             offset = 2; //change to 2 later
                             MAXOFFSET = offset;
                            }
#line 1574 "y.tab.c"
    break;

  case 16:
#line 188 "lab9.y"
    { Search((yyvsp[-4].string),level,0)->fparms = (yyvsp[-1].node);}
#line 1580 "y.tab.c"
    break;

  case 17:
#line 188 "lab9.y"
    {
                                                struct SymbTab *s;
                                                (yyval.node) = ASTCreateNode(fundec);
                                                (yyval.node)->name = (yyvsp[-6].string);
                                                (yyval.node)->operator = (yyvsp[-7].operator);
                                                (yyval.node)->s1 = (yyvsp[-3].node);
                                                (yyval.node)->s2 = (yyvsp[0].node);
                                                (yyval.node)->size = MAXOFFSET;
                                                s = Search((yyvsp[-6].string),0,0);
                                                offset = GOFFSET;
                                                Search((yyvsp[-6].string),0,0)->mysize = MAXOFFSET;
                                                (yyval.node)->symbol = s;
                                                //Display();
                                              }
#line 1599 "y.tab.c"
    break;

  case 18:
#line 204 "lab9.y"
    {(yyval.node) = NULL;}
#line 1605 "y.tab.c"
    break;

  case 19:
#line 205 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1611 "y.tab.c"
    break;

  case 20:
#line 208 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1617 "y.tab.c"
    break;

  case 21:
#line 209 "lab9.y"
    {(yyval.node) = (yyvsp[-2].node);
                                  (yyvsp[-2].node)->next = (yyvsp[0].node);
                                 }
#line 1625 "y.tab.c"
    break;

  case 22:
#line 214 "lab9.y"
    {if( Search((yyvsp[0].string),level+1, 0) != NULL ) { //set one level up(inside function) since it starts at function level
                                    yyerror("Duplicate Vairable");
                                    yyerror((yyvsp[0].string));
                                    exit(1);
                                 }
                                else {
                                    Insert((yyvsp[0].string), (yyvsp[-1].operator), 1, level+1, 1, offset, NULL);
                                    offset = offset+1;
                                }
                                (yyval.node) = ASTCreateNode(param);
                                (yyval.node)->name = (yyvsp[0].string);
                                (yyval.node)->operator = (yyvsp[-1].operator);
                                (yyval.node)->size = 0;
                                (yyval.node)->sem_type = (yyvsp[-1].operator);
                               }
#line 1645 "y.tab.c"
    break;

  case 23:
#line 230 "lab9.y"
    {if( Search((yyvsp[-2].string),level+1, 0) != NULL ) {
                                    yyerror("Duplicate Vairable");
                                    yyerror((yyvsp[-2].string));
                                    exit(1);
                                 }
                                else {
                                    Insert((yyvsp[-2].string), (yyvsp[-3].operator), 2, level+1, 1, offset, NULL);
                                    offset = offset+1;
                                }
                                (yyval.node) = ASTCreateNode(param);
                                (yyval.node)->name = (yyvsp[-2].string);
                                (yyval.node)->operator = (yyvsp[-3].operator);
                                (yyval.node)->size = -1; //size is -1 to tell the c program that this is an array
                                (yyval.node)->sem_type = (yyvsp[-3].operator);
                               }
#line 1665 "y.tab.c"
    break;

  case 24:
#line 247 "lab9.y"
    {level++;}
#line 1671 "y.tab.c"
    break;

  case 25:
#line 247 "lab9.y"
    {
                                         (yyval.node) = ASTCreateNode(block);
                                         (yyval.node)->s1 = (yyvsp[-2].node);
                                         (yyval.node)->s2 = (yyvsp[-1].node);
                                         if (offset > MAXOFFSET) MAXOFFSET = offset;
                                         Display();
                                         offset -= Delete(level);//reset offset when leaving a compstmt
                                         level--; //reduce level

                                        }
#line 1686 "y.tab.c"
    break;

  case 26:
#line 259 "lab9.y"
    {(yyval.node) = NULL;}
#line 1692 "y.tab.c"
    break;

  case 27:
#line 261 "lab9.y"
    {(yyval.node) = (yyvsp[-1].node);
                           (yyvsp[-1].node)->next = (yyvsp[0].node);
                          }
#line 1700 "y.tab.c"
    break;

  case 28:
#line 266 "lab9.y"
    {(yyval.node) = NULL;}
#line 1706 "y.tab.c"
    break;

  case 29:
#line 268 "lab9.y"
    {(yyval.node) = (yyvsp[-1].node);
                           (yyvsp[-1].node)->next = (yyvsp[0].node);
                          }
#line 1714 "y.tab.c"
    break;

  case 30:
#line 273 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1720 "y.tab.c"
    break;

  case 31:
#line 274 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1726 "y.tab.c"
    break;

  case 32:
#line 275 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1732 "y.tab.c"
    break;

  case 33:
#line 276 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1738 "y.tab.c"
    break;

  case 34:
#line 277 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1744 "y.tab.c"
    break;

  case 35:
#line 278 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1750 "y.tab.c"
    break;

  case 36:
#line 279 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1756 "y.tab.c"
    break;

  case 37:
#line 280 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1762 "y.tab.c"
    break;

  case 38:
#line 283 "lab9.y"
    {(yyval.node) = ASTCreateNode(exprstmt);
                      (yyval.node)->s1 = (yyvsp[-1].node);}
#line 1769 "y.tab.c"
    break;

  case 39:
#line 285 "lab9.y"
    {(yyval.node) = ASTCreateNode(exprstmt);
                      (yyval.node)->s1 = NULL;}
#line 1776 "y.tab.c"
    break;

  case 40:
#line 289 "lab9.y"
    {(yyval.node) = ASTCreateNode(selecstmt);
                                          (yyval.node)->s1 = (yyvsp[-2].node);
                                          (yyval.node)->s2 = (yyvsp[0].node);
                                         }
#line 1785 "y.tab.c"
    break;

  case 41:
#line 293 "lab9.y"
    {ASTNode *p;
                                          (yyval.node) = ASTCreateNode(ifelse);
                                          p = ASTCreateNode(ifelse1);
                                          
                                          (yyval.node)->s1 = (yyvsp[-4].node);
                                          (yyval.node)->s2 = p;
                                          
                                          p->s1 = (yyvsp[-2].node);
                                          p->s2 = (yyvsp[0].node);
                                
                                         }
#line 1801 "y.tab.c"
    break;

  case 42:
#line 306 "lab9.y"
    {(yyval.node) = ASTCreateNode(whilestmt);
                                 (yyval.node)->s1 = (yyvsp[-2].node);
                                 (yyval.node)->s2 = (yyvsp[0].node);
                                }
#line 1810 "y.tab.c"
    break;

  case 43:
#line 312 "lab9.y"
    {(yyval.node) = ASTCreateNode(myReturn);}
#line 1816 "y.tab.c"
    break;

  case 44:
#line 313 "lab9.y"
    {(yyval.node) = ASTCreateNode(myReturn);
                                (yyval.node)->s1 = (yyvsp[-1].node);
                               }
#line 1824 "y.tab.c"
    break;

  case 45:
#line 318 "lab9.y"
    {(yyval.node) = ASTCreateNode(myRead);
                              (yyval.node)->s1 = (yyvsp[-1].node);
                             }
#line 1832 "y.tab.c"
    break;

  case 46:
#line 323 "lab9.y"
    {(yyval.node) = ASTCreateNode(myWrite);
                              (yyval.node)->s1 = (yyvsp[-1].node);
                             }
#line 1840 "y.tab.c"
    break;

  case 47:
#line 327 "lab9.y"
    {(yyval.node) = ASTCreateNode(myWrite);
                              (yyval.node)->name = (yyvsp[-1].string);
                              (yyval.node)->label = genlabel();
                             }
#line 1849 "y.tab.c"
    break;

  case 48:
#line 333 "lab9.y"
    {if((yyvsp[-3].node)->sem_type != (yyvsp[-1].node)->sem_type){//type checking - if they dont have the same type, error and exit
                                        yyerror("type conflict in assignstmt");
                                        exit(1);
                                   }
                                   (yyval.node) = ASTCreateNode(assignstmt);
                                   (yyval.node)->s1 = (yyvsp[-3].node);
                                   (yyval.node)->s2 = (yyvsp[-1].node);
                                   (yyval.node)->operator = myEqual;
                                   (yyval.node)->name = CreateTemp();
                                   (yyval.node)->symbol = Insert((yyval.node)->name, intType, 0, level,1,offset,NULL);
                                   offset++;
                                  }
#line 1866 "y.tab.c"
    break;

  case 49:
#line 347 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1872 "y.tab.c"
    break;

  case 50:
#line 350 "lab9.y"
    {  struct SymbTab *p = Search((yyvsp[0].string), level, 1);//search all level up
                                if(p == NULL){
                                    yyerror("Variable does not exist");
                                    yyerror((yyvsp[0].string));
                                    exit(1);
                                }
                                if(p->IsAFunc != 1){ //error if not a scalar
                                    yyerror("Variable is not scalar");
                                    yyerror((yyvsp[0].string));
                                    exit(1);
                                }
                                (yyval.node) = ASTCreateNode(identifier);
                                (yyval.node)->name = (yyvsp[0].string);
                                (yyval.node)->symbol = p; //add the symbol to the ast
                                (yyval.node)->sem_type = p->Type; //set the semantic type to the same type of the symbol
                             }
#line 1893 "y.tab.c"
    break;

  case 51:
#line 366 "lab9.y"
    {  struct SymbTab *p;
                                p = Search((yyvsp[-3].string),level,1);
                                if(p == NULL) { // Check to make sure the variable exist in the table
                                    yyerror("Variable does not exist");
                                    yyerror((yyvsp[-3].string));
                                    exit(1);
                                }
                                if(p->IsAFunc != 2) { //the symbol does exist so check if id is not an array throw error and exit
                                    yyerror("Variable is not an array");
                                    yyerror((yyvsp[-3].string));
                                    exit(1);
                                }
                                (yyval.node) = ASTCreateNode(identifier);
                                (yyval.node)->name = (yyvsp[-3].string);
                                (yyval.node)->s1 = (yyvsp[-1].node);
                                (yyval.node)->symbol = p;
                                (yyval.node)->sem_type = p->Type;
                             }
#line 1916 "y.tab.c"
    break;

  case 52:
#line 386 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1922 "y.tab.c"
    break;

  case 53:
#line 387 "lab9.y"
    {if((yyvsp[-2].node)->sem_type != (yyvsp[0].node)->sem_type) { //type checking
                                        yyerror("type conflict in simpexpr");
                                        exit(1);
                                      }
                                      (yyval.node) = ASTCreateNode(expr);
                                      (yyval.node)->s1 = (yyvsp[-2].node);
                                      (yyval.node)->s2 = (yyvsp[0].node);
                                      (yyval.node)->operator = (yyvsp[-1].operator);
                                      (yyval.node)->sem_type = (yyvsp[-2].node)->sem_type; //pass up the type of the symbol 
                                      (yyval.node)->name = CreateTemp();
                                      (yyval.node)->symbol = Insert((yyval.node)->name, intType, 0, level,1,offset,NULL);
                                      offset++;
                                     }
#line 1940 "y.tab.c"
    break;

  case 54:
#line 402 "lab9.y"
    {(yyval.operator) = greaterEqual;}
#line 1946 "y.tab.c"
    break;

  case 55:
#line 403 "lab9.y"
    {(yyval.operator) = lessEqual;}
#line 1952 "y.tab.c"
    break;

  case 56:
#line 404 "lab9.y"
    {(yyval.operator) = equal;}
#line 1958 "y.tab.c"
    break;

  case 57:
#line 405 "lab9.y"
    {(yyval.operator) = notEqual;}
#line 1964 "y.tab.c"
    break;

  case 58:
#line 406 "lab9.y"
    {(yyval.operator) = less;}
#line 1970 "y.tab.c"
    break;

  case 59:
#line 407 "lab9.y"
    {(yyval.operator) = greater;}
#line 1976 "y.tab.c"
    break;

  case 60:
#line 410 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1982 "y.tab.c"
    break;

  case 61:
#line 411 "lab9.y"
    {if((yyvsp[-2].node)->sem_type != (yyvsp[0].node)->sem_type){ //type checking
                                    yyerror("type conflict in addexpr");
                                    exit(1);
                                 }
                                 (yyval.node) = ASTCreateNode(expr);
                                 (yyval.node)->s1 = (yyvsp[-2].node);
                                 (yyval.node)->s2 = (yyvsp[0].node);
                                 (yyval.node)->operator = (yyvsp[-1].operator);
                                 (yyval.node)->sem_type = (yyvsp[-2].node)->sem_type;
                                 (yyval.node)->name = CreateTemp();
                                 (yyval.node)->symbol = Insert((yyval.node)->name, intType, 0, level,1,offset,NULL);
                                 offset++;
                                }
#line 2000 "y.tab.c"
    break;

  case 62:
#line 426 "lab9.y"
    {(yyval.operator) = plus;}
#line 2006 "y.tab.c"
    break;

  case 63:
#line 427 "lab9.y"
    {(yyval.operator) = minus;}
#line 2012 "y.tab.c"
    break;

  case 64:
#line 430 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2018 "y.tab.c"
    break;

  case 65:
#line 431 "lab9.y"
    {if((yyvsp[-2].node)->sem_type != (yyvsp[0].node)->sem_type){ //type checking
                                    yyerror("type conflict in term");
                                    exit(1);
                                 }
                                 (yyval.node) = ASTCreateNode(expr);
                                 (yyval.node)->s1 = (yyvsp[-2].node);
                                 (yyval.node)->s2 = (yyvsp[0].node);
                                 (yyval.node)->operator = (yyvsp[-1].operator);
                                 (yyval.node)->sem_type = (yyvsp[-2].node)->sem_type;
                                 (yyval.node)->name = CreateTemp();
                                 (yyval.node)->symbol = Insert((yyval.node)->name, intType, 0, level,1,offset,NULL);
                                 offset++;
                                }
#line 2036 "y.tab.c"
    break;

  case 66:
#line 446 "lab9.y"
    {(yyval.operator) = times;}
#line 2042 "y.tab.c"
    break;

  case 67:
#line 447 "lab9.y"
    {(yyval.operator) = divide;}
#line 2048 "y.tab.c"
    break;

  case 68:
#line 448 "lab9.y"
    {(yyval.operator) = myAnd;}
#line 2054 "y.tab.c"
    break;

  case 69:
#line 449 "lab9.y"
    {(yyval.operator) = myOr;}
#line 2060 "y.tab.c"
    break;

  case 70:
#line 452 "lab9.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2066 "y.tab.c"
    break;

  case 71:
#line 453 "lab9.y"
    {(yyval.node) = ASTCreateNode(myNum);
                             (yyval.node)->size = (yyvsp[0].number);
                             (yyval.node)->sem_type = intType; //all numbers have type int
                            }
#line 2075 "y.tab.c"
    break;

  case 72:
#line 457 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2081 "y.tab.c"
    break;

  case 73:
#line 458 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2087 "y.tab.c"
    break;

  case 74:
#line 459 "lab9.y"
    {(yyval.node) = ASTCreateNode(mybool);
                             (yyval.node)->size = 1; //use size one so that we know its true
                             (yyval.node)->sem_type = boolType; //true is a boolean type
                            }
#line 2096 "y.tab.c"
    break;

  case 75:
#line 463 "lab9.y"
    {(yyval.node) = ASTCreateNode(mybool);
                             (yyval.node)->size = 0; //set to zero so we know to print false
                             (yyval.node)->sem_type = boolType; //false is a boolean type

                            }
#line 2106 "y.tab.c"
    break;

  case 76:
#line 468 "lab9.y"
    {if((yyvsp[0].node)->sem_type != boolType){ //only booleans can have NOT in front
                                exit(1);
                             }
                             (yyval.node) = ASTCreateNode(expr);
                             (yyval.node)->s1 = (yyvsp[0].node);
                             (yyval.node)->operator = myNot;
                             (yyval.node)->sem_type = (yyvsp[0].node)->sem_type;
                             (yyval.node)->name = CreateTemp();
                             (yyval.node)->symbol = Insert((yyval.node)->name, intType, 0, level,1,offset,NULL);
                             offset++;
                            }
#line 2122 "y.tab.c"
    break;

  case 77:
#line 483 "lab9.y"
    {struct SymbTab *p = Search((yyvsp[-3].string),level,1);
                             if(p == NULL){
                                yyerror("The function does not exist");
                                yyerror((yyvsp[-3].string));
                                exit(1);
                             }
                             if(p->IsAFunc != 0) { // symbol must be a function
                                yyerror("The ID is not a function");
                                exit(1);
                             }
                             if(check_params(p->fparms, (yyvsp[-1].node)) != 1){ //the function call must have the correct parameters as the actual function
                                yyerror("Function acutal and formal parameters mismatch");
                                exit(1);
                             }
                             (yyval.node) = ASTCreateNode(call);
                             (yyval.node)->name = (yyvsp[-3].string);
                             (yyval.node)->s1 = (yyvsp[-1].node);
                             (yyval.node)->symbol = p;
                             (yyval.node)->sem_type = p->Type;
                            }
#line 2147 "y.tab.c"
    break;

  case 78:
#line 505 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2153 "y.tab.c"
    break;

  case 79:
#line 506 "lab9.y"
    {(yyval.node) = NULL;}
#line 2159 "y.tab.c"
    break;

  case 80:
#line 509 "lab9.y"
    {(yyval.node) = ASTCreateNode(arg);
                                 (yyval.node)->sem_type = (yyvsp[0].node)->sem_type;
                                 (yyval.node)->s1 = (yyvsp[0].node);
                                 (yyval.node)->next = NULL;
                                 (yyval.node)->name = CreateTemp();
                                 (yyval.node)->symbol = Insert((yyval.node)->name, intType, 0, level,1,offset,NULL);
                                 offset++;
                                }
#line 2172 "y.tab.c"
    break;

  case 81:
#line 517 "lab9.y"
    {
                                 ASTCreateNode(arg);
                                 (yyval.node)->sem_type = (yyvsp[-2].node)->sem_type;
                                 (yyval.node)->s1 = (yyvsp[-2].node);
                                 (yyval.node)->next = (yyvsp[0].node);
                                 (yyval.node)->name = CreateTemp();
                                 (yyval.node)->symbol = Insert((yyval.node)->name, intType, 0, level,1,offset,NULL);
                                 offset++;
                                }
#line 2186 "y.tab.c"
    break;


#line 2190 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 528 "lab9.y"
	/* end of rules, start of program */

int main(int argc, char * argv[]) {

    FILE *fp;
    char s[100];
    int i = 1;
    int found = 0;
    
    //if -d is given when running the code turn on debug
    while(i < argc) {
        if (strcmp(argv[i], "-d")==0) {
            mydebug = 1;
            i = i + 1;
        }// use the argument after -o to get the name of the .asm file -o must be given followed by a name
        else if (strcmp(argv[i], "-o")==0) {
            if(argc > i+1) found = 1;
            sprintf(s,"%s.asm",argv[i+1]);
            i=i+2;
        }
    else i = i+1;
    }
    
    if(found == 0) {
        printf("An argument must be given after -o\n");
        exit(1);
    }
    fp = fopen(s,"w");
    if (fp == NULL){
        printf("The file %s cannot be opened \n",s);
        exit(1);
    }
    
    printf("My file is %s\n", s);        

    yyparse();
    
    //print out the tree using the global pointer
    ASTprint(GP, 0);
    
    fprintf(fp, ".data\n");
    emit_strings(GP,fp); //find string and create labels in the file before writing other code
    fprintf(fp, "\n.align 2\n\n");
    emit_globals(GP,fp);//find global variables and create before code
    fprintf(fp, "\n.text\n\n");

    emit_AST(GP,fp); //call to write MIPS code to file
    
}//end main
