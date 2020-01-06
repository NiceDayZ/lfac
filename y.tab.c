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
#line 1 "a.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

#define debug(x)    cerr << #x": " << x << " "
#define debugln(x)  cerr << #x": " << x << "\n"

extern FILE* yyin;
extern char* yytext;
extern int yylineno;

int yyerror(char * s);
int yylex();

using namespace std;

vector <vector <pair <int, int> > > wordScope;

vector <string> fileContent;

set <tuple <int, string, string, int, int, string>> initMapping;
set <tuple <int, string, string, int, int, string>> currMapping;

set <tuple <int, string, string, int, int, string>> objMapping;

bool checkDeclare(string name, int idScope, int idDepth){
  for (auto it : initMapping){
    int a;
    string b;
    string c;
    int d;
    int e;
    string f;

    tie(a,b,c,d,e,f) = it;
    if (c == name and d == idScope and e == idDepth)
      return 0;
  }
  return 1;
}

bool deleteFromMap(string name, int idScope, int idDepth, tuple <int, string, string, int, int, string> &arg){
  tuple <int, string, string, int, int, string> toDelete;
  int found = 0;
  for (auto it : currMapping){
    int a;
    string b;
    string c;
    int d;
    int e;
    string f;

    tie(a,b,c,d,e,f) = it;
    if (c == name and e < idDepth){
      toDelete = it;
      found += 1;
      break;
    }
    else
    if (c == name and e == idDepth and d == idScope){
      toDelete = it;
      found += 1;
      break;
    }
  }

  if (found){
    currMapping.erase(toDelete);
    arg = toDelete;
    return 1;
  }

  return 0;
}

bool checkDeclareObj(string name, int idScope, int idDepth){
  for (auto it : objMapping){
    int a;
    string b;
    string c;
    int d;
    int e;
    string f;

    tie(a,b,c,d,e,f) = it;
    if (c == name and d == idScope and e == idDepth)
      return 0;
  }
  return 1;
}

string convertType(string type){
  if (type == "intreg")
    return "0$";
  if (type == "rational")
    return "1$";
  if (type == "text")
    return "2$";
  if (type == "caracter")
    return "3$";
  if (type == "intrerupator")
    return "4$";
  return "9$";
}

string checkVarExistence(string name, int idScope, int idDepth){
  for (auto it : currMapping){
    int a;
    string b;
    string c;
    int d;
    int e;
    string f;

    tie(a,b,c,d,e,f) = it;
    if (c == name and e < idDepth){
      return convertType(b) + f;
    }
    else
    if (c == name and e == idDepth and d == idScope)
      return convertType(b) + f;
  }
  for (auto it : objMapping){
    int a;
    string b;
    string c;
    int d;
    int e;
    string f;

    tie(a,b,c,d,e,f) = it;
    if (c == name and e < idDepth)
      return convertType(b) + f;
    else
    if (c == name and e == idDepth and d == idScope)
      return convertType(b) + f;
  }
  return "Error";
}

template <typename TypeOne, typename TypeTwo>
string convertToString(TypeOne arg1) {
	stringstream ssBuffer;

    string result;
	ssBuffer << arg1;
	ssBuffer >> result;

	return result;
}

template <typename TypeOne, typename TypeTwo>
void convert(TypeOne arg1, TypeTwo &arg2) {
	stringstream ssBuffer;

	ssBuffer << arg1;
	ssBuffer >> arg2;
}

void addToMap(int line, string type, string id, int scopeId, int scopeDepth, string value = ""){
  auto t = make_tuple(line, type, id, scopeId, scopeDepth, value);
  initMapping.insert(t);
  currMapping.insert(t);
}

void addToCurr(int line, string type, string id, int scopeId, int scopeDepth, string value = ""){
  auto t = make_tuple(line, type, id, scopeId, scopeDepth, value);
  currMapping.insert(t);
}

void addToObj(int line, string type, string id, int scopeId, int scopeDepth, string value = ""){
  auto t = make_tuple(line, type, id, scopeId, scopeDepth, value);
  objMapping.insert(t);
}

vector<string> splitString(string text, string tokken){
	vector <string> split;
  vector <string> result;
	
	string *aux;
	aux = new string;
	for (auto it : text) {
		bool ok = false;
		for (auto t : tokken){
			if (t == it) {
				split.push_back(*aux);
				delete aux;
				aux = new string;
				ok = true;
				break;
			}
		}
		if (not ok) {
			aux->push_back(it);
		}
	}
	split.push_back(*aux);

	for (auto it : split) {
		if (it.size())
			result.push_back(it);
	}

    return result;
}


#line 275 "y.tab.c" /* yacc.c:339  */

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
    TIP_INTRERUPATOR = 258,
    TIP_INTREG = 259,
    TIP_RATIONAL = 260,
    TIP_TEXT = 261,
    TIP_CARACTER = 262,
    TIP_VECTOR = 263,
    TIP_OBIECT = 264,
    TIP_FUNCTIE = 265,
    NR_INTREG = 266,
    NR_RATIONAL = 267,
    TEXT = 268,
    CARACTER = 269,
    SAU = 270,
    SI = 271,
    NEGAT = 272,
    STINS = 273,
    APRINS = 274,
    EGAL = 275,
    DIFERIT = 276,
    MAI_MARE_EGAL = 277,
    MAI_MIC_EGAL = 278,
    DACA = 279,
    ALTFEL = 280,
    PENTRU = 281,
    CAT_TIMP = 282,
    PANA_CAND = 283,
    EXECUTA = 284,
    INCEPE = 285,
    TERMINA = 286,
    APARTINE = 287,
    IN = 288,
    PAS = 289,
    INSPECTEAZA = 290,
    AFISEAZA = 291,
    PRINCIPAL = 292,
    CITESTE = 293,
    EVAL = 294,
    RETURNEAZA = 295,
    IDENTIFICATOR = 296
  };
#endif
/* Tokens.  */
#define TIP_INTRERUPATOR 258
#define TIP_INTREG 259
#define TIP_RATIONAL 260
#define TIP_TEXT 261
#define TIP_CARACTER 262
#define TIP_VECTOR 263
#define TIP_OBIECT 264
#define TIP_FUNCTIE 265
#define NR_INTREG 266
#define NR_RATIONAL 267
#define TEXT 268
#define CARACTER 269
#define SAU 270
#define SI 271
#define NEGAT 272
#define STINS 273
#define APRINS 274
#define EGAL 275
#define DIFERIT 276
#define MAI_MARE_EGAL 277
#define MAI_MIC_EGAL 278
#define DACA 279
#define ALTFEL 280
#define PENTRU 281
#define CAT_TIMP 282
#define PANA_CAND 283
#define EXECUTA 284
#define INCEPE 285
#define TERMINA 286
#define APARTINE 287
#define IN 288
#define PAS 289
#define INSPECTEAZA 290
#define AFISEAZA 291
#define PRINCIPAL 292
#define CITESTE 293
#define EVAL 294
#define RETURNEAZA 295
#define IDENTIFICATOR 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 210 "a.y" /* yacc.c:355  */

  char* strval;

#line 401 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 418 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   429

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  289

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    50,     2,    46,     2,     2,
      56,    57,    47,    44,    58,    45,    59,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    51,    42,     2,    60,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   283,   283,   287,   290,   291,   295,   325,   354,   396,
     438,   476,   514,   560,   606,   658,   659,   662,   663,   665,
     666,   668,   669,   672,   673,   676,   706,   735,   777,   819,
     857,   895,   941,   988,   989,   991,   995,   996,   997,   998,
     999,  1019,  1080,  1133,  1186,  1247,  1289,  1342,  1350,  1358,
    1367,  1376,  1414,  1417,  1420,  1423,  1428,  1570,  1679,  1680,
    1683,  1684,  1688,  1900,  1908,  1937,  1966,  2025,  2084,  2143,
    2202,  2203,  2229,  2255,  2269,  2274,  2279,  2319,  2322,  2323,
    2396,  2470,  2687,  2698,  2915,  2926,  2927,  2939,  2951,  2969,
    3035,  3110,  3111,  3115,  3116,  3117,  3118,  3121,  3124,  3127,
    3128
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIP_INTRERUPATOR", "TIP_INTREG",
  "TIP_RATIONAL", "TIP_TEXT", "TIP_CARACTER", "TIP_VECTOR", "TIP_OBIECT",
  "TIP_FUNCTIE", "NR_INTREG", "NR_RATIONAL", "TEXT", "CARACTER", "SAU",
  "SI", "NEGAT", "STINS", "APRINS", "EGAL", "DIFERIT", "MAI_MARE_EGAL",
  "MAI_MIC_EGAL", "DACA", "ALTFEL", "PENTRU", "CAT_TIMP", "PANA_CAND",
  "EXECUTA", "INCEPE", "TERMINA", "APARTINE", "IN", "PAS", "INSPECTEAZA",
  "AFISEAZA", "PRINCIPAL", "CITESTE", "EVAL", "RETURNEAZA",
  "IDENTIFICATOR", "'>'", "'<'", "'+'", "'-'", "'%'", "'*'", "'/'", "'^'",
  "'#'", "'='", "'{'", "'}'", "'['", "']'", "'('", "')'", "','", "'.'",
  "'@'", "$accept", "program", "preMain", "declarari", "declarare",
  "declarariParam", "declarareParam", "declarariMembri", "declarareMembru",
  "corpFunctie", "tipSimplu", "expresie", "apelVector", "apelFunctie",
  "listaApel", "argumente", "apelObiect", "expresieLogica", "main",
  "comanda", "comenzi", "stareControl", "varPentru", "continutPentru",
  "altfel", YY_NULLPTR
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
     295,   296,    62,    60,    43,    45,    37,    42,    47,    94,
      35,    61,   123,   125,    91,    93,    40,    41,    44,    46,
      64
};
# endif

#define YYPACT_NINF -229

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-229)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -46,   289,    20,  -229,   -10,   -46,   -18,  -229,  -229,  -229,
    -229,   -22,     0,    -6,    34,  -229,    54,  -229,  -229,    58,
     313,    72,   320,    67,     2,    60,    73,    78,    74,    79,
      83,    85,    69,    76,    84,    86,    98,   161,  -229,     2,
     112,  -229,  -229,  -229,  -229,  -229,    60,  -229,  -229,   -12,
      60,   107,   230,  -229,  -229,  -229,    -2,   108,  -229,   109,
     297,   125,    79,   116,   117,    69,   210,    60,   121,    60,
       2,   126,   128,   122,   129,   -14,   135,  -229,  -229,  -229,
      69,    69,   131,   132,    -7,  -229,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    60,    60,
     119,   133,   160,   152,   153,   178,  -229,  -229,   164,   165,
     146,    -4,   189,   169,     9,   196,   187,    60,  -229,    69,
      60,   201,    60,   236,    59,   172,  -229,   190,  -229,  -229,
     210,   210,   210,   210,   210,   210,    66,    75,    45,    51,
     194,  -229,  -229,   229,   237,   257,   219,   327,   334,   220,
     238,   238,   239,   232,   259,   260,   293,   271,   188,    19,
     168,   230,    -2,   284,   230,    -2,  -229,    69,  -229,    69,
     287,   294,    60,   234,   303,   306,   307,    69,   305,   301,
     238,   304,     2,    69,     2,     2,   308,  -229,  -229,  -229,
    -229,    60,  -229,   309,  -229,  -229,    -2,   321,   322,   324,
     326,   210,   328,   316,   318,   330,   342,  -229,   342,   343,
     210,   315,   344,   345,    60,   230,    -2,  -229,   323,   325,
     329,   331,  -229,   341,   348,  -229,     2,  -229,  -229,   353,
      69,  -229,  -229,    82,   369,   370,   238,   238,   333,   335,
     336,   337,   351,   352,  -229,   338,  -229,   339,   340,   346,
     347,   355,   356,   357,   358,    60,     2,   349,  -229,  -229,
     342,   342,   354,   359,   350,   360,   218,    -9,   361,   363,
    -229,  -229,   373,   389,   238,   238,  -229,  -229,  -229,    69,
     362,   364,   365,   366,  -229,  -229,  -229,  -229,  -229
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     2,     0,     5,     0,    36,    37,    38,
      39,     0,     0,     0,     0,     1,     0,     3,     4,     7,
       0,    40,     0,     6,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    92,
       0,    85,    47,    48,    49,    50,     0,    75,    74,    51,
       0,     0,     0,    54,    52,    53,     8,     0,    40,     0,
       0,     0,    24,     0,     0,     0,     9,     0,     0,     0,
      92,     0,     0,     0,     0,     0,     0,    91,    77,    73,
       0,    58,     0,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,     0,     0,    60,     0,    59,    62,    55,    70,
      64,    65,    66,    67,    68,    69,    41,    42,    45,    43,
      44,    46,    72,    71,     0,     0,    26,     0,     0,    25,
      16,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,     0,    82,    84,    56,     0,    57,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,    92,     0,    92,    92,     0,    89,    86,    87,
      88,     0,    61,     0,    10,    11,    27,     0,     0,     0,
       0,    28,     0,     0,     0,     0,    33,    15,    33,     0,
      97,     0,     0,     0,     0,    81,    83,    63,     0,     0,
       0,     0,    18,     0,     0,    17,    92,    13,    12,   100,
       0,    96,    94,     0,     0,     0,    16,    16,     0,     0,
       0,     0,     0,     0,    93,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,    30,    29,
      33,    33,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    31,     0,     0,    16,    16,    34,    35,    99,     0,
       0,     0,     0,     0,    98,    20,    19,    22,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -229,  -229,  -229,   396,    16,  -141,  -229,   367,  -229,  -191,
     -17,   -32,   368,  -229,   233,   240,  -229,   -31,  -229,  -229,
     -38,  -229,  -228,  -229,  -229
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    38,   179,   180,    61,    62,   227,
      14,    52,    53,    54,   125,   126,    55,    56,    17,    39,
      40,    41,   211,   113,   244
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      66,    77,   245,    28,     1,    31,    98,    99,    98,    99,
     181,    98,    99,    98,    99,    79,     5,   228,    83,    84,
      15,     5,   277,    19,    98,    99,    33,    16,    34,    35,
      20,    36,   115,   110,    98,    99,   111,   120,   114,   207,
      80,    21,    80,   105,    81,   121,    22,    82,   123,   124,
     129,   284,    37,   152,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   155,   142,   143,   270,
     271,    42,    43,    44,    45,    23,   189,    46,    47,    48,
      42,    43,    44,    45,    24,   158,   159,   160,   161,   162,
     164,   165,    95,    96,    97,   249,   250,    98,    99,    96,
      97,    49,    29,    92,    93,    94,    95,    96,    97,    25,
      49,    93,    94,    95,    96,    97,    50,   167,    32,    58,
      51,    94,    95,    96,    97,    65,    57,    59,    70,    60,
     174,   176,    67,   282,   283,   124,    63,   124,    64,   246,
      68,   196,    69,    78,   209,   201,   212,   213,    85,   100,
     101,   210,    86,    87,    88,    89,   106,   108,   109,   215,
     216,   205,   112,   118,     6,     7,     8,     9,    10,    11,
      12,    13,   127,   144,    90,    91,    92,    93,    94,    95,
      96,    97,   116,   233,   117,   119,   122,   145,   242,   128,
      92,    93,    94,    95,    96,    97,    71,    72,   210,    73,
      74,   146,    75,   128,   147,   148,   239,   241,    86,    87,
      88,    89,    92,    93,    94,    95,    96,    97,   268,   149,
     150,   151,   153,   266,   267,   190,   154,   156,   157,   168,
      90,    91,    92,    93,    94,    95,    96,    97,    86,    87,
      88,    89,   163,    97,    98,   188,   169,   210,   170,   276,
      86,    87,    88,    89,    92,    93,    94,    95,    96,    97,
      90,    91,    92,    93,    94,    95,    96,    97,   171,   182,
     172,   177,    90,    91,    92,    93,    94,    95,    96,    97,
      92,    93,    94,    95,    96,    97,   183,   197,   178,   184,
     185,   166,     6,     7,     8,     9,    10,    11,    12,    13,
     102,     7,     8,     9,    10,   103,    27,   104,   202,     7,
       8,     9,    10,   203,    27,   204,    26,     7,     8,     9,
      10,   186,    27,    30,     7,     8,     9,    10,   187,    27,
     173,     7,     8,     9,    10,   191,    27,   175,     7,     8,
       9,    10,   194,    27,   238,     7,     8,     9,    10,   195,
      27,   240,     7,     8,     9,    10,   198,    27,   206,   199,
     200,   208,   218,   219,   214,   220,   217,   221,   223,   222,
     224,   225,   226,   230,   229,   231,   232,   234,   243,   235,
     247,   248,   256,   269,   280,   236,   251,   237,   252,   253,
     254,   255,   278,   257,   258,   259,   262,   263,   264,   265,
     281,    18,   193,   260,   261,    76,   274,   192,   272,     0,
       0,     0,     0,   273,   279,     0,   275,   285,     0,   286,
       0,     0,   287,   288,     0,     0,     0,     0,     0,   107
};

static const yytype_int16 yycheck[] =
{
      32,    39,   230,    20,    50,    22,    15,    16,    15,    16,
     151,    15,    16,    15,    16,    46,     0,   208,    50,    50,
       0,     5,    31,    41,    15,    16,    24,    37,    26,    27,
      52,    29,    70,    65,    15,    16,    67,    51,    69,   180,
      54,    41,    54,    60,    56,    59,    52,    59,    80,    81,
      57,   279,    50,    57,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    57,    98,    99,   260,
     261,    11,    12,    13,    14,    41,    57,    17,    18,    19,
      11,    12,    13,    14,    30,   117,   117,   119,   120,   120,
     122,   122,    47,    48,    49,   236,   237,    15,    16,    48,
      49,    41,    30,    44,    45,    46,    47,    48,    49,    51,
      41,    45,    46,    47,    48,    49,    56,    58,    51,    41,
      60,    46,    47,    48,    49,    56,    53,    53,    30,    50,
     147,   148,    56,   274,   275,   167,    53,   169,    53,    57,
      56,   172,    56,    31,   182,   177,   184,   185,    41,    41,
      41,   183,    20,    21,    22,    23,    31,    41,    41,   191,
     191,   178,    41,    41,     3,     4,     5,     6,     7,     8,
       9,    10,    41,    54,    42,    43,    44,    45,    46,    47,
      48,    49,    56,   214,    56,    56,    51,    54,   226,    57,
      44,    45,    46,    47,    48,    49,    35,    36,   230,    38,
      39,    41,    41,    57,    52,    52,   223,   224,    20,    21,
      22,    23,    44,    45,    46,    47,    48,    49,   256,    41,
      56,    56,    33,   255,   255,    57,    57,    31,    41,    57,
      42,    43,    44,    45,    46,    47,    48,    49,    20,    21,
      22,    23,    41,    49,    15,    57,    56,   279,    11,    31,
      20,    21,    22,    23,    44,    45,    46,    47,    48,    49,
      42,    43,    44,    45,    46,    47,    48,    49,    11,    30,
      51,    51,    42,    43,    44,    45,    46,    47,    48,    49,
      44,    45,    46,    47,    48,    49,    54,    53,    50,    30,
      30,    55,     3,     4,     5,     6,     7,     8,     9,    10,
       3,     4,     5,     6,     7,     8,     9,    10,     3,     4,
       5,     6,     7,     8,     9,    10,     3,     4,     5,     6,
       7,    28,     9,     3,     4,     5,     6,     7,    57,     9,
       3,     4,     5,     6,     7,    51,     9,     3,     4,     5,
       6,     7,    55,     9,     3,     4,     5,     6,     7,    55,
       9,     3,     4,     5,     6,     7,    53,     9,    57,    53,
      53,    57,    41,    41,    56,    41,    57,    41,    52,    41,
      52,    41,    30,    58,    31,    31,    31,    54,    25,    54,
      11,    11,    30,    34,    11,    56,    53,    56,    53,    53,
      53,    40,    31,    55,    55,    55,    41,    41,    41,    41,
      11,     5,   169,    57,    57,    37,    56,   167,    54,    -1,
      -1,    -1,    -1,    54,    51,    -1,    56,    55,    -1,    55,
      -1,    -1,    57,    57,    -1,    -1,    -1,    -1,    -1,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    62,    63,    64,    65,     3,     4,     5,     6,
       7,     8,     9,    10,    71,     0,    37,    79,    64,    41,
      52,    41,    52,    41,    30,    51,     3,     9,    71,    30,
       3,    71,    51,    24,    26,    27,    29,    50,    65,    80,
      81,    82,    11,    12,    13,    14,    17,    18,    19,    41,
      56,    60,    72,    73,    74,    77,    78,    53,    41,    53,
      50,    68,    69,    53,    53,    56,    72,    56,    56,    56,
      30,    35,    36,    38,    39,    41,    73,    81,    31,    78,
      54,    56,    59,    72,    78,    41,    20,    21,    22,    23,
      42,    43,    44,    45,    46,    47,    48,    49,    15,    16,
      41,    41,     3,     8,    10,    71,    31,    68,    41,    41,
      72,    78,    41,    84,    78,    81,    56,    56,    41,    56,
      51,    59,    51,    72,    72,    75,    76,    41,    57,    57,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    78,    78,    54,    54,    41,    52,    52,    41,
      56,    56,    57,    33,    57,    57,    31,    41,    72,    78,
      72,    72,    78,    41,    72,    78,    55,    58,    57,    56,
      11,    11,    51,     3,    71,     3,    71,    51,    50,    66,
      67,    66,    30,    54,    30,    30,    28,    57,    57,    57,
      57,    51,    76,    75,    55,    55,    78,    53,    53,    53,
      53,    72,     3,     8,    10,    71,    57,    66,    57,    81,
      72,    83,    81,    81,    56,    72,    78,    57,    41,    41,
      41,    41,    41,    52,    52,    41,    30,    70,    70,    31,
      58,    31,    31,    78,    54,    54,    56,    56,     3,    71,
       3,    71,    81,    25,    85,    83,    57,    11,    11,    66,
      66,    53,    53,    53,    53,    40,    30,    55,    55,    55,
      57,    57,    41,    41,    41,    41,    72,    78,    81,    34,
      70,    70,    54,    54,    56,    56,    31,    31,    31,    51,
      11,    11,    66,    66,    83,    55,    55,    57,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    70,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    82,    82,    82,    82,    83,    84,    85,
      85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     3,     3,     5,     5,
       9,     9,    10,    10,     6,     2,     0,     3,     3,     9,
       9,     9,     9,     2,     1,     3,     3,     5,     5,     9,
       9,    10,    10,     0,     5,     5,     1,     1,     1,     1,
       2,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     4,     0,     1,
       1,     3,     3,     6,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     2,     4,     1,     4,
       4,     6,     4,     6,     4,     1,     5,     5,     5,     5,
       3,     2,     0,     8,     7,     8,     7,     1,    10,     4,
       0
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
#line 283 "a.y" /* yacc.c:1646  */
    {printf("Programul este bine definit!\n");}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 295 "a.y" /* yacc.c:1646  */
    {
              char* type = (yyvsp[-1].strval);
              char* varId = (yyvsp[0].strval);
              
              string s = varId;
              vector <string> split = splitString(s, " ");
              char* line = new char[split[0].size() + 5];
              char* varName = new char[split[1].size() + 5];
              strcpy(line, split[0].c_str());
              strcpy(varName, split[1].c_str());

              int curLine;

              stringstream ss;
              ss << line;
              ss >> curLine;

              curLine --;

              auto p = wordScope[curLine][0];
              int idScope = p.first;
              int idDepth = p.second;
              if (checkDeclare(varName, idScope, idDepth))
                addToMap(curLine, type, varName, idScope, idDepth);
              else{
                cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                return -1;
              }
            }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 325 "a.y" /* yacc.c:1646  */
    {
              char* type = (yyvsp[-1].strval);
              char* varId = (yyvsp[0].strval);
              
              string s = varId;
              vector <string> split = splitString(s, " ");
              char* line = new char[split[0].size() + 5];
              char* varName = new char[split[1].size() + 5];
              strcpy(line, split[0].c_str());
              strcpy(varName, split[1].c_str());

              int curLine;

              stringstream ss;
              ss << line;
              ss >> curLine;

              curLine --;

              auto p = wordScope[curLine][0];
              int idScope = p.first;
              int idDepth = p.second;
              if (checkDeclare(varName, idScope, idDepth))
                addToMap(curLine, type, varName, idScope, idDepth);
              else{
                cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                return -1;
              }
            }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 354 "a.y" /* yacc.c:1646  */
    {
              char* type = (yyvsp[-3].strval);
              char* varId = (yyvsp[-2].strval);
              
              string s = varId;
              vector <string> split = splitString(s, " ");
              char* line = new char[split[0].size() + 5];
              char* varName = new char[split[1].size() + 5];
              strcpy(line, split[0].c_str());
              strcpy(varName, split[1].c_str());

              int curLine;

              char* evalResult = (yyvsp[0].strval);

              if (strlen(evalResult) == 2){
                cout << "Eroare: Atribuire vida la linia: " << line << "\n";
                return -1;
              }

              if (evalResult[0] != convertType(type)[0]){
                cout << "Eroare: Atribuire invalida la linia: " << line << "\n";
                return -1; 
              }

              stringstream ss;
              ss << line;
              ss >> curLine;
              
              curLine --;

              auto p = wordScope[curLine][0];
              int idScope = p.first;
              int idDepth = p.second;
              if (checkDeclare(varName, idScope, idDepth))
                addToMap(curLine, type, varName, idScope, idDepth, evalResult+2);
              else{
                cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                return -1;
              }
            }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 396 "a.y" /* yacc.c:1646  */
    {
              char* type = (yyvsp[-3].strval);
              char* varId = (yyvsp[-2].strval);
              
              string s = varId;
              vector <string> split = splitString(s, " ");
              char* line = new char[split[0].size() + 5];
              char* varName = new char[split[1].size() + 5];
              strcpy(line, split[0].c_str());
              strcpy(varName, split[1].c_str());

              int curLine;

              char* evalResult = (yyvsp[0].strval);

              if (strlen(evalResult) == 2){
                cout << "Eroare: Atribuire vida la linia: " << line << "\n";
                return -1;
              }

              if (evalResult[0] != convertType(type)[0]){
                cout << "Eroare: Atribuire invalida la linia: " << line << "\n";
                return -1; 
              }

              stringstream ss;
              ss << line;
              ss >> curLine;
              
              curLine --;

              auto p = wordScope[curLine][0];
              int idScope = p.first;
              int idDepth = p.second;
              if (checkDeclare(varName, idScope, idDepth))
                addToMap(curLine, type, varName, idScope, idDepth, evalResult+2);
              else{
                cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                return -1;
              }
            }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 438 "a.y" /* yacc.c:1646  */
    {
              char* type = (yyvsp[-5].strval);
              char* quantity = (yyvsp[-1].strval);
              string s_type = "vector_{";
              s_type += type;
              s_type += "}_[";
              s_type += quantity;
              s_type +=  + "]";
              
              char* varId = (yyvsp[-3].strval);
              
              string s = varId;
              vector <string> split = splitString(s, " ");
              char* line = new char[split[0].size() + 5];
              char* varName = new char[split[1].size() + 5];
              strcpy(line, split[0].c_str());
              strcpy(varName, split[1].c_str());

              int curLine;

              stringstream ss;
              ss << line;
              ss >> curLine;

              curLine --;
              
              auto p = wordScope[curLine][0];
              int idScope = p.first;
              int idDepth = p.second;
              
              if (checkDeclare(varName, idScope, idDepth))
                addToMap(curLine, s_type, varName, idScope, idDepth);
              else{
                cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                return -1;
              }
            }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 476 "a.y" /* yacc.c:1646  */
    {
              char* type = (yyvsp[-5].strval);
              char* quantity = (yyvsp[-1].strval);
              string s_type = "vector_{";
              s_type += type;
              s_type += "}_[";
              s_type += quantity;
              s_type +=  + "]";
              
              char* varId = (yyvsp[-3].strval);
              
              string s = varId;
              vector <string> split = splitString(s, " ");
              char* line = new char[split[0].size() + 5];
              char* varName = new char[split[1].size() + 5];
              strcpy(line, split[0].c_str());
              strcpy(varName, split[1].c_str());

              int curLine;

              stringstream ss;
              ss << line;
              ss >> curLine;

              curLine --;
              
              auto p = wordScope[curLine][0];
              int idScope = p.first;
              int idDepth = p.second;
              
              if (checkDeclare(varName, idScope, idDepth))
                addToMap(curLine, s_type, varName, idScope, idDepth);
              else{
                cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                return -1;
              }
            }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 514 "a.y" /* yacc.c:1646  */
    {
              char* returnType = (yyvsp[-6].strval);
              
              char* varId = (yyvsp[-4].strval);
              
              string s = varId;
              vector <string> split = splitString(s, " ");
              char* line = new char[split[0].size() + 5];
              char* varName = new char[split[1].size() + 5];
              strcpy(line, split[0].c_str());
              strcpy(varName, split[1].c_str());

              int curLine;

              stringstream ss;
              ss << line;
              ss >> curLine;

              curLine --;

              string s_type = "functie_{";
              s_type += returnType;
              s_type += "}";

              char* bodyFunction = (yyvsp[0].strval);

              if (bodyFunction[0] == 'a'){
                s_type += "_Complet_Definita";
              }
              else
              if (bodyFunction[0] == 'b'){
                s_type += "_Incomplet_Definita";
              }
  
              auto p = wordScope[curLine][0];
              int idScope = p.first;
              int idDepth = p.second;

              if (checkDeclare(varName, idScope, idDepth))
                addToMap(curLine, s_type, varName, idScope, idDepth);
              else{
                cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                return -1;
              }
            }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 560 "a.y" /* yacc.c:1646  */
    {
              char* returnType = (yyvsp[-6].strval);
              
              char* varId = (yyvsp[-4].strval);
              
              string s = varId;
              vector <string> split = splitString(s, " ");
              char* line = new char[split[0].size() + 5];
              char* varName = new char[split[1].size() + 5];
              strcpy(line, split[0].c_str());
              strcpy(varName, split[1].c_str());

              int curLine;

              stringstream ss;
              ss << line;
              ss >> curLine;

              curLine --;

              string s_type = "functie_{";
              s_type += returnType;
              s_type += "}";

              char* bodyFunction = (yyvsp[0].strval);

              if (bodyFunction[0] == 'a'){
                s_type += "_Complet_Definita";
              }
              else
              if (bodyFunction[0] == 'b'){
                s_type += "_Incomplet_Definita";
              }
  
              auto p = wordScope[curLine][0];
              int idScope = p.first;
              int idDepth = p.second;

              if (checkDeclare(varName, idScope, idDepth))
                addToMap(curLine, s_type, varName, idScope, idDepth);
              else{
                cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                return -1;
              }
            }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 606 "a.y" /* yacc.c:1646  */
    {
              
              string type = "obiect";
              
              char* varId = (yyvsp[-3].strval);
              
              string s = varId;
              vector <string> split = splitString(s, " ");
              char* line = new char[split[0].size() + 5];
              char* varName = new char[split[1].size() + 5];
              strcpy(line, split[0].c_str());
              strcpy(varName, split[1].c_str());

              int curLine;

              stringstream ss;
              ss << line;
              ss >> curLine;

              curLine --;

              for (auto it : objMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;
                tie(a, b, c, d, e, f) = it;

                string typeInner;
                typeInner = varName;
                typeInner += "->";
                typeInner += b;
                addToMap(a, typeInner, c, d, e, f);
              }

              objMapping.clear();

              auto p = wordScope[curLine][0];
              int idScope = p.first;
              int idDepth = p.second;

              if (checkDeclare(varName, idScope, idDepth))
                addToMap(curLine, type, varName, idScope, idDepth);
              else{
                cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                return -1;
              }
            }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 676 "a.y" /* yacc.c:1646  */
    {
                    char* type = (yyvsp[-1].strval);
                    char* varId = (yyvsp[0].strval);
                    
                    string s = varId;
                    vector <string> split = splitString(s, " ");
                    char* line = new char[split[0].size() + 5];
                    char* varName = new char[split[1].size() + 5];
                    strcpy(line, split[0].c_str());
                    strcpy(varName, split[1].c_str());

                    int curLine;

                    stringstream ss;
                    ss << line;
                    ss >> curLine;

                    curLine --;

                    auto p = wordScope[curLine][0];
                    int idScope = p.first;
                    int idDepth = p.second;
                    if (checkDeclareObj(varName, idScope, idDepth))
                      addToObj(curLine, type, varName, idScope, idDepth);
                    else{
                      cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                      return -1;
                    }
                  }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 706 "a.y" /* yacc.c:1646  */
    {
                    char* type = (yyvsp[-1].strval);
                    char* varId = (yyvsp[0].strval);
                    
                    string s = varId;
                    vector <string> split = splitString(s, " ");
                    char* line = new char[split[0].size() + 5];
                    char* varName = new char[split[1].size() + 5];
                    strcpy(line, split[0].c_str());
                    strcpy(varName, split[1].c_str());

                    int curLine;

                    stringstream ss;
                    ss << line;
                    ss >> curLine;

                    curLine --;

                    auto p = wordScope[curLine][0];
                    int idScope = p.first;
                    int idDepth = p.second;
                    if (checkDeclareObj(varName, idScope, idDepth))
                      addToObj(curLine, type, varName, idScope, idDepth);
                    else{
                      cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                      return -1;
                    }
                  }
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 735 "a.y" /* yacc.c:1646  */
    {
                    char* type = (yyvsp[-3].strval);
                    char* varId = (yyvsp[-2].strval);
                    
                    string s = varId;
                    vector <string> split = splitString(s, " ");
                    char* line = new char[split[0].size() + 5];
                    char* varName = new char[split[1].size() + 5];
                    strcpy(line, split[0].c_str());
                    strcpy(varName, split[1].c_str());

                    int curLine;

                    char* evalResult = (yyvsp[0].strval);

                    if (strlen(evalResult) == 2){
                      cout << "Eroare: Atribuire vida la linia: " << line << "\n";
                      return -1;
                    }

                    if (evalResult[0] != convertType(type)[0]){
                      cout << "Eroare: Atribuire invalida la linia: " << line << "\n";
                      return -1; 
                    }

                    stringstream ss;
                    ss << line;
                    ss >> curLine;
                    
                    curLine --;

                    auto p = wordScope[curLine][0];
                    int idScope = p.first;
                    int idDepth = p.second;
                    if (checkDeclareObj(varName, idScope, idDepth))
                      addToObj(curLine, type, varName, idScope, idDepth, evalResult+2);
                    else{
                      cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                      return -1;
                    }
                  }
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 777 "a.y" /* yacc.c:1646  */
    {
                    char* type = (yyvsp[-3].strval);
                    char* varId = (yyvsp[-2].strval);
                    
                    string s = varId;
                    vector <string> split = splitString(s, " ");
                    char* line = new char[split[0].size() + 5];
                    char* varName = new char[split[1].size() + 5];
                    strcpy(line, split[0].c_str());
                    strcpy(varName, split[1].c_str());

                    int curLine;

                    stringstream ss;
                    ss << line;
                    ss >> curLine;

                    curLine --;

                    char* evalResult = (yyvsp[0].strval);

                    if (strlen(evalResult) == 2){
                      cout << "Eroare: Atribuire vida la linia: " << line << "\n";
                      return -1;
                    }

                    if (evalResult[0] != convertType(type)[0]){
                      cout << "Eroare: Atribuire invalida la linia: " << line << "\n";
                      return -1; 
                    }

                    auto p = wordScope[curLine][0];
                    int idScope = p.first;
                    int idDepth = p.second;
                    if (checkDeclareObj(varName, idScope, idDepth))
                      addToObj(curLine, type, varName, idScope, idDepth, evalResult+2);
                    else{
                      cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                      return -1;
                    }
                  }
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 819 "a.y" /* yacc.c:1646  */
    {
                    char* type = (yyvsp[-5].strval);
                    char* quantity = (yyvsp[-1].strval);
                    string s_type = "vector_{";
                    s_type += type;
                    s_type += "}_[";
                    s_type += quantity;
                    s_type +=  + "]";
                    
                    char* varId = (yyvsp[-3].strval);
                    
                    string s = varId;
                    vector <string> split = splitString(s, " ");
                    char* line = new char[split[0].size() + 5];
                    char* varName = new char[split[1].size() + 5];
                    strcpy(line, split[0].c_str());
                    strcpy(varName, split[1].c_str());

                    int curLine;

                    stringstream ss;
                    ss << line;
                    ss >> curLine;

                    curLine --;
                    
                    auto p = wordScope[curLine][0];
                    int idScope = p.first;
                    int idDepth = p.second;
                    
                    if (checkDeclareObj(varName, idScope, idDepth))
                      addToObj(curLine, s_type, varName, idScope, idDepth);
                    else{
                      cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                      return -1;
                    }
                  }
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 857 "a.y" /* yacc.c:1646  */
    {
                    char* type = (yyvsp[-5].strval);
                    char* quantity = (yyvsp[-1].strval);
                    string s_type = "vector_{";
                    s_type += type;
                    s_type += "}_[";
                    s_type += quantity;
                    s_type +=  + "]";
                    
                    char* varId = (yyvsp[-3].strval);
                    
                    string s = varId;
                    vector <string> split = splitString(s, " ");
                    char* line = new char[split[0].size() + 5];
                    char* varName = new char[split[1].size() + 5];
                    strcpy(line, split[0].c_str());
                    strcpy(varName, split[1].c_str());

                    int curLine;

                    stringstream ss;
                    ss << line;
                    ss >> curLine;

                    curLine --;
                    
                    auto p = wordScope[curLine][0];
                    int idScope = p.first;
                    int idDepth = p.second;
                    
                    if (checkDeclareObj(varName, idScope, idDepth))
                      addToObj(curLine, s_type, varName, idScope, idDepth);
                    else{
                      cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                      return -1;
                    }
                  }
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 895 "a.y" /* yacc.c:1646  */
    {
                    char* returnType = (yyvsp[-6].strval);
                    
                    char* varId = (yyvsp[-4].strval);
                    
                    string s = varId;
                    vector <string> split = splitString(s, " ");
                    char* line = new char[split[0].size() + 5];
                    char* varName = new char[split[1].size() + 5];
                    strcpy(line, split[0].c_str());
                    strcpy(varName, split[1].c_str());

                    int curLine;

                    stringstream ss;
                    ss << line;
                    ss >> curLine;

                    curLine --;

                    string s_type = "functie_{";
                    s_type += returnType;
                    s_type += "}";

                    char* bodyFunction = (yyvsp[0].strval);

                    if (bodyFunction[0] == 'a'){
                      s_type += "_Complet_Definita";
                    }
                    else
                    if (bodyFunction[0] == 'b'){
                      s_type += "_Incomplet_Definita";
                    }
        
                    auto p = wordScope[curLine][0];
                    int idScope = p.first;
                    int idDepth = p.second;

                    if (checkDeclareObj(varName, idScope, idDepth))
                      addToObj(curLine, s_type, varName, idScope, idDepth);
                    else{
                      cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                      return -1;
                    }
                  }
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 941 "a.y" /* yacc.c:1646  */
    {
                    char* returnType = (yyvsp[-6].strval);
                    
                    char* varId = (yyvsp[-4].strval);
                    
                    string s = varId;
                    vector <string> split = splitString(s, " ");
                    char* line = new char[split[0].size() + 5];
                    char* varName = new char[split[1].size() + 5];
                    strcpy(line, split[0].c_str());
                    strcpy(varName, split[1].c_str());

                    int curLine;

                    stringstream ss;
                    ss << line;
                    ss >> curLine;

                    curLine --;

                    string s_type = "functie_{";
                    s_type += returnType;
                    s_type += "}";

                    char* bodyFunction = (yyvsp[0].strval);

                    if (bodyFunction[0] == 'a'){
                      s_type += "_Complet_Definita";
                    }
                    else
                    if (bodyFunction[0] == 'b'){
                      s_type += "_Incomplet_Definita";
                    }
        
                    auto p = wordScope[curLine][0];
                    int idScope = p.first;
                    int idDepth = p.second;

                    if (checkDeclareObj(varName, idScope, idDepth))
                      addToObj(curLine, s_type, varName, idScope, idDepth);
                    else{
                      cout << "Eroare: Redefinire de variabila la linia " << curLine+1 << "\n";
                      return -1;
                    }
                  }
#line 2451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 988 "a.y" /* yacc.c:1646  */
    {char* s = new char[10]; strcpy(s, "b");(yyval.strval) = s;}
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 990 "a.y" /* yacc.c:1646  */
    {char* s = new char[10]; strcpy(s, "a");(yyval.strval) = s;}
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 992 "a.y" /* yacc.c:1646  */
    {char* s = new char[10]; strcpy(s, "a");(yyval.strval) = s;}
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 995 "a.y" /* yacc.c:1646  */
    {(yyval.strval) = (yyvsp[0].strval);}
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 996 "a.y" /* yacc.c:1646  */
    {(yyval.strval) = (yyvsp[0].strval);}
#line 2481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 997 "a.y" /* yacc.c:1646  */
    {(yyval.strval) = (yyvsp[0].strval);}
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 998 "a.y" /* yacc.c:1646  */
    {(yyval.strval) = (yyvsp[0].strval);}
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 999 "a.y" /* yacc.c:1646  */
    { 
              string s1 = "obiect"; 
              
              char* varId = (yyvsp[0].strval);
              
              string sId = varId;
              vector <string> split = splitString(sId, " ");
              char* varName = new char[split[1].size() + 5];
              strcpy(varName, split[1].c_str());

              char* sr = new char[s1.size() +strlen(varName) + 5];
              string s = s1;
              s += "_";
              s += varName;
              strcpy(sr, s.c_str());
              (yyval.strval) = sr;
            }
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1019 "a.y" /* yacc.c:1646  */
    {
            string l = (yyvsp[-2].strval);
            string r = (yyvsp[0].strval);
            if (l[0] != r[0]){
              cout << "Eroare: Tipuri diferite la linia" << yylineno << "\n";
              cout << "Eroare: Adunare intre tipuri" << "\n";
              cout << l[0] << " " << r[0] << "\n";
              return -1;
            }

            string valLeft;
            for (int i = 2; i < l.size(); i++)
              valLeft.push_back(l[i]);

            string valRight;
            for (int i = 2; i < r.size(); i++)
              valRight.push_back(r[i]);

            if (l[0] == '0'){
              int i_left;
              int i_right;
              convert(valLeft, i_left);
              convert(valRight, i_right);
              int i_res = i_left + i_right;
              string s_res;
              convert(i_res, s_res);
              s_res = "0$" + s_res;
              
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              (yyval.strval) = c_res;
            }
            else
            if (l[0] == '1'){
              float f_left;
              float f_right;
              convert(valLeft, f_left);
              convert(valRight, f_right);
              float f_res = f_left + f_right;
              string s_res;
              convert(f_res, s_res);
              s_res = "1$" + s_res;
              
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              (yyval.strval) = c_res;
            }
            else
            if (l[0] == '2'){
              string s_res = valLeft + valRight;
              s_res = "2$" + s_res;
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              (yyval.strval) = c_res;
            }
            else{
              cout << "Adunare incompatibila pentru tipurile " << l[0] << "\n";
              cout << "Eroare la linia " << yylineno << "\n";
              return -1;
            }
          }
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1080 "a.y" /* yacc.c:1646  */
    {
            string l = (yyvsp[-2].strval);
            string r = (yyvsp[0].strval);
            if (l[0] != r[0]){
              cout << "Eroare: Tipuri diferite la linia" << yylineno << "\n";
              cout << "Eroare: Scadere intre tipuri" << "\n";
              cout << l[0] << " " << r[0] << "\n";
              return -1;
            }

            string valLeft;
            for (int i = 2; i < l.size(); i++)
              valLeft.push_back(l[i]);

            string valRight;
            for (int i = 2; i < r.size(); i++)
              valRight.push_back(r[i]);

            if (l[0] == '0'){
              int i_left;
              int i_right;
              convert(valLeft, i_left);
              convert(valRight, i_right);
              int i_res = i_left - i_right;
              string s_res;
              convert(i_res, s_res);
              s_res = "0$" + s_res;
              
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              (yyval.strval) = c_res;
            }
            else
            if (l[0] == '1'){
              float f_left;
              float f_right;
              convert(valLeft, f_left);
              convert(valRight, f_right);
              float f_res = f_left - f_right;
              string s_res;
              convert(f_res, s_res);
              s_res = "1$" + s_res;
              
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              (yyval.strval) = c_res;
            }
            else{
              cout << "Scadere incompatibila pentru tipurile " << l[0] << "\n";
              cout << "Eroare la linia " << yylineno << "\n";
              return -1;
            }
          }
#line 2639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1133 "a.y" /* yacc.c:1646  */
    {
            string l = (yyvsp[-2].strval);
            string r = (yyvsp[0].strval);
            if (l[0] != r[0]){
              cout << "Eroare: Tipuri diferite la linia" << yylineno << "\n";
              cout << "Eroare: Inmultire intre tipuri" << "\n";
              cout << l[0] << " " << r[0] << "\n";
              return -1;
            }

            string valLeft;
            for (int i = 2; i < l.size(); i++)
              valLeft.push_back(l[i]);

            string valRight;
            for (int i = 2; i < r.size(); i++)
              valRight.push_back(r[i]);

            if (l[0] == '0'){
              int i_left;
              int i_right;
              convert(valLeft, i_left);
              convert(valRight, i_right);
              int i_res = i_left * i_right;
              string s_res;
              convert(i_res, s_res);
              s_res = "0$" + s_res;
              
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              (yyval.strval) = c_res;
            }
            else
            if (l[0] == '1'){
              float f_left;
              float f_right;
              convert(valLeft, f_left);
              convert(valRight, f_right);
              float f_res = f_left * f_right;
              string s_res;
              convert(f_res, s_res);
              s_res = "1$" + s_res;
              
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              (yyval.strval) = c_res;
            }
            else{
              cout << "Inmultire incompatibila pentru tipurile " << l[0] << "\n";
              cout << "Eroare la linia " << yylineno << "\n";
              return -1;
            }
          }
#line 2697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1186 "a.y" /* yacc.c:1646  */
    {
            string l = (yyvsp[-2].strval);
            string r = (yyvsp[0].strval);
            if (l[0] != r[0]){
              cout << "Eroare: Tipuri diferite la linia" << yylineno << "\n";
              cout << "Eroare: Impartire intre tipuri" << "\n";
              cout << l[0] << " " << r[0] << "\n";
              return -1;
            }

            string valLeft;
            for (int i = 2; i < l.size(); i++)
              valLeft.push_back(l[i]);

            string valRight;
            for (int i = 2; i < r.size(); i++)
              valRight.push_back(r[i]);

            if (l[0] == '0'){
              int i_left;
              int i_right;
              convert(valLeft, i_left);
              convert(valRight, i_right);
              if (i_right == 0){
                cout << "Eroare: Impartire la 0 la linia " << yylineno << "\n";
                return -1;
              }
              int i_res = i_left / i_right;
              string s_res;
              convert(i_res, s_res);
              s_res = "0$" + s_res;
              
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              (yyval.strval) = c_res;
            }
            else
            if (l[0] == '1'){
              float f_left;
              float f_right;
              convert(valLeft, f_left);
              convert(valRight, f_right);
              if (f_right == 0){
                cout << "Eroare: Impartire la 0 la linia " << yylineno << "\n";
                return -1;
              }
              float f_res = f_left / f_right;
              string s_res;
              convert(f_res, s_res);
              s_res = "1$" + s_res;
              
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              (yyval.strval) = c_res;
            }
            else{
              cout << "Impartire incompatibila pentru tipurile " << l[0] << "\n";
              cout << "Eroare la linia " << yylineno << "\n";
              return -1;
            }
          }
#line 2763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1247 "a.y" /* yacc.c:1646  */
    {
            string l = (yyvsp[-2].strval);
            string r = (yyvsp[0].strval);
            if (l[0] != r[0]){
              cout << "Eroare: Tipuri diferite la linia" << yylineno << "\n";
              cout << "Eroare: Modulo intre tipuri" << "\n";
              cout << l[0] << " " << r[0] << "\n";
              return -1;
            }

            string valLeft;
            for (int i = 2; i < l.size(); i++)
              valLeft.push_back(l[i]);

            string valRight;
            for (int i = 2; i < r.size(); i++)
              valRight.push_back(r[i]);

            if (l[0] == '0'){
              int i_left;
              int i_right;
              convert(valLeft, i_left);
              convert(valRight, i_right);
              if (i_right == 0){
                cout << "Eroare: Modulo 0 la linia " << yylineno << "\n";
                return -1;
              }
              int i_res = i_left % i_right;
              string s_res;
              convert(i_res, s_res);
              s_res = "0$" + s_res;
              
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              (yyval.strval) = c_res;
            }
            else{
              cout << "Modulo incompatibila pentru tipurile " << l[0] << "\n";
              cout << "Eroare la linia " << yylineno << "\n";
              return -1;
            }
          }
#line 2810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1289 "a.y" /* yacc.c:1646  */
    {
            string l = (yyvsp[-2].strval);
            string r = (yyvsp[0].strval);
            if (l[0] != r[0]){
              cout << "Eroare: Tipuri diferite la linia" << yylineno << "\n";
              cout << "Eroare: Ridicare la putere intre tipuri" << "\n";
              cout << l[0] << " " << r[0] << "\n";
              return -1;
            }

            string valLeft;
            for (int i = 2; i < l.size(); i++)
              valLeft.push_back(l[i]);

            string valRight;
            for (int i = 2; i < r.size(); i++)
              valRight.push_back(r[i]);

            if (l[0] == '0'){
              int i_left;
              int i_right;
              convert(valLeft, i_left);
              convert(valRight, i_right);
              int i_res = pow(i_left, i_right);
              string s_res;
              convert(i_res, s_res);
              s_res = "0$" + s_res;
              
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              (yyval.strval) = c_res;
            }
            else
            if (l[0] == '1'){
              float f_left;
              float f_right;
              convert(valLeft, f_left);
              convert(valRight, f_right);
              float f_res = powl(f_left, f_right);
              string s_res;
              convert(f_res, s_res);
              s_res = "1$" + s_res;
              
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              (yyval.strval) = c_res;
            }
            else{
              cout << "Ridicare la putere incompatibila pentru tipurile " << l[0] << "\n";
              cout << "Eroare la linia " << yylineno << "\n";
              return -1;
            }
          }
#line 2868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1342 "a.y" /* yacc.c:1646  */
    {
            char* type = new char[5];
            strcpy(type, "0$");
            char* val = new char[strlen((yyvsp[0].strval)) + 10];
            strcpy(val, type);
            strcat(val, (yyvsp[0].strval));
            (yyval.strval) = val;
          }
#line 2881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1350 "a.y" /* yacc.c:1646  */
    {
            char* type = new char[5];
            strcpy(type, "1$");
            char* val = new char[strlen((yyvsp[0].strval)) + 10];
            strcpy(val, type);
            strcat(val, (yyvsp[0].strval));
            (yyval.strval) = val;
          }
#line 2894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1358 "a.y" /* yacc.c:1646  */
    {
            char* type = new char[5];
            strcpy(type, "2$");
            char* val = new char[strlen((yyvsp[0].strval)) + 10];
            strcpy(val, type);
            strcat(val, (yyvsp[0].strval) + 1);
            val[strlen(val)-1] = '\0';
            (yyval.strval) = val;
          }
#line 2908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1367 "a.y" /* yacc.c:1646  */
    {
            char* type = new char[5];
            strcpy(type, "3$");
            char* val = new char[strlen((yyvsp[0].strval)) + 10];
            strcpy(val, type);
            strcat(val, (yyvsp[0].strval) + 1);
            val[strlen(val)-1] = '\0';
            (yyval.strval) = val;
          }
#line 2922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1376 "a.y" /* yacc.c:1646  */
    {
            char* varInfo = (yyvsp[0].strval);
            string s = varInfo;
            vector<string> split = splitString(s, " ");
            string nameVar = split[1];
            string line = split[0];
            
            stringstream ss;
            ss << line;

            int curLine;
            ss >> curLine;
            curLine--;

            auto p = wordScope[curLine][0];
            
            int idScope = p.first;
            int idDepth = p.second;

            string res = checkVarExistence(nameVar, idScope, idDepth);
            if (res != "Error"){
              if (res.size() < 3){
                cout << "Eroare la linia: " << line << "\n";
                cout << "Accesare variabila neinitializata!\n";
                return -1;
              }

              char* final = new char[res.size()+5];
              strcpy(final, res.c_str());
              (yyval.strval) = final;
            }
            else{
              cout << "Eroare variabila nedeclarata folosita in expresie la linia: " << line << "\n";
              cout << "Nume variabila: " << nameVar << "\n";
              return -1;
            }

          }
#line 2965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1414 "a.y" /* yacc.c:1646  */
    {
            (yyval.strval) = (yyvsp[0].strval);
          }
#line 2973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1417 "a.y" /* yacc.c:1646  */
    {
            (yyval.strval) = (yyvsp[0].strval);
          }
#line 2981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1420 "a.y" /* yacc.c:1646  */
    {
            (yyval.strval) = (yyvsp[0].strval);
          }
#line 2989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1423 "a.y" /* yacc.c:1646  */
    {
           (yyval.strval) = (yyvsp[-1].strval);
         }
#line 2997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1428 "a.y" /* yacc.c:1646  */
    {
              char* varInfo = (yyvsp[-3].strval);
              string s = varInfo;
              vector<string> split = splitString(s, " ");
              string nameVar = split[1];
              string line = split[0];
              
              stringstream ss;
              ss << line;

              int curLine;
              ss >> curLine;
              curLine--;

              auto p = wordScope[curLine][0];
              
              int idScope = p.first;
              int idDepth = p.second;

              bool found = false;

              tuple <int, string, string, int, int, string> myFunc;
              for (auto it : currMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                if (c == nameVar and e < idDepth){
                  myFunc = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and e == idDepth and d == idScope){
                  myFunc = it;
                  found = true;
                  break;
                }
              }
              for (auto it : objMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                if (c == nameVar and e < idDepth){
                  myFunc = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and e == idDepth and d == idScope){
                  myFunc = it;
                  found = true;
                  break;
                }
              }

              if (not found){
                cout << "Eroare Identificator vector inexistent la linia ";
                cout << line << "\n";
                return -1;
              }

              int a;
              string b;
              string c;
              int d;
              int e;
              string f;

              tie(a,b,c,d,e,f) = myFunc;
              split = splitString(b, "{}");
              if (split.size() < 3){
                cout << "Eroare la linia " << line << "\n";
                cout << "Vector inexistent\n";
                return -1;
              }

              string typeFunc = split[1];

              split = splitString(b, "[]");
              if (split.size() < 2){
                cout << "Eroare la linia " << line << "\n";
                cout << "Vector inexistent\n";
                return -1;
              }

              string s_vecSize = split[1];
              int i_vecSize;
              convert(s_vecSize, i_vecSize);

              char* c_vecAcces = (yyvsp[-1].strval);
              if (c_vecAcces[0] != '0'){
                cout << "Eroare la linia " << line << "\n";
                cout << "Tip accesare invalid\n";
                return -1;
              }


              string s_vecAcces = c_vecAcces+2;
              int i_vecAcces;
              convert(s_vecAcces, i_vecAcces);


              if (i_vecAcces >= i_vecSize or i_vecAcces < 0){
                cout << "Eroare la linia " << line << "\n";
                cout << "Accesare zona memorie invalida\n";
                return -1;
              }

              char* res = new char[10];
              if (typeFunc == "intreg"){
                strcpy(res, "0$0");
              }
              if (typeFunc == "rational"){
                strcpy(res, "1$0");
              }
              if (typeFunc == "text"){
                strcpy(res, "2$ ");
              }
              if (typeFunc == "char"){
                strcpy(res, "3$ ");
              }
              if (typeFunc == "intrerupator"){
                strcpy(res, "4$1");
              }

              (yyval.strval) = res;

            }
#line 3140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1570 "a.y" /* yacc.c:1646  */
    {
                char* varInfo = (yyvsp[-3].strval);
                string s = varInfo;
                vector<string> split = splitString(s, " ");
                string nameVar = split[1];
                string line = split[0];
                
                stringstream ss;
                ss << line;

                int curLine;
                ss >> curLine;
                curLine--;

                auto p = wordScope[curLine][0];
                
                int idScope = p.first;
                int idDepth = p.second;

                bool found = false;

                tuple <int, string, string, int, int, string> myFunc;
                for (auto it : currMapping){
                  int a;
                  string b;
                  string c;
                  int d;
                  int e;
                  string f;

                  tie(a,b,c,d,e,f) = it;
                  if (c == nameVar and e < idDepth){
                    myFunc = it;
                    found = true;
                    break;
                  }
                  else
                  if (c == nameVar and e == idDepth and d == idScope){
                    myFunc = it;
                    found = true;
                    break;
                  }
                }
                for (auto it : objMapping){
                  int a;
                  string b;
                  string c;
                  int d;
                  int e;
                  string f;

                  tie(a,b,c,d,e,f) = it;
                  if (c == nameVar and e < idDepth){
                    myFunc = it;
                    found = true;
                    break;
                  }
                  else
                  if (c == nameVar and e == idDepth and d == idScope){
                    myFunc = it;
                    found = true;
                    break;
                  }
                }

                if (not found){
                  cout << "Eroare Identificator functie inexistent la linia ";
                  cout << line << "\n";
                  return -1;
                }

                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = myFunc;
                split = splitString(b, "{}");
                if (split.size() < 2){
                  cout << "Eraore la linia " << line << "\n";
                  cout << "Functie inexistenta\n";
                  return -1;
                }

                char* res = new char[10];
                string typeFunc = split[1];
                if (typeFunc == "intreg"){
                  strcpy(res, "0$0");
                }
                if (typeFunc == "rational"){
                  strcpy(res, "1$0");
                }
                if (typeFunc == "text"){
                  strcpy(res, "2$ ");
                }
                if (typeFunc == "char"){
                  strcpy(res, "3$ ");
                }
                if (typeFunc == "intrerupator"){
                  strcpy(res, "4$1");
                }

                (yyval.strval) = res;

              }
#line 3252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1688 "a.y" /* yacc.c:1646  */
    {
              
              char* varInfo = (yyvsp[-2].strval);
              string s = varInfo;
              vector<string> split = splitString(s, " ");
              string nameVar = split[1];
              string line = split[0];
              
              stringstream ss;
              ss << line;

              int curLine;
              ss >> curLine;
              curLine--;

              auto p = wordScope[curLine][0];
              
              int idScope = p.first;
              int idDepth = p.second;

              bool found = false;

              tuple <int, string, string, int, int, string> myFunc;
              for (auto it : currMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                vector<string> typeSplit = splitString(b, "_");

                if(typeSplit.size() < 2 or typeSplit[0] != "obiect") continue;

                if (c == nameVar and e < idDepth){
                  myFunc = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and e == idDepth and d == idScope){
                  myFunc = it;
                  found = true;
                  break;
                }
              }
              for (auto it : objMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;

                vector<string> typeSplit = splitString(b, "_");

                if(typeSplit.size() < 2 or typeSplit[0] != "obiect") continue;

                if (c == nameVar and e < idDepth){
                  myFunc = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and e == idDepth and d == idScope){
                  myFunc = it;
                  found = true;
                  break;
                }
              }

              if (not found){
                cout << "Eroare tip inexistent la linia ";
                cout << line << "\n";
                return -1;
              }

              int a;
              string b;
              string c;
              int d;
              int e;
              string f;

              tie(a,b,c,d,e,f) = myFunc;
              idScope = d;
              idDepth = e;

              split = splitString(b, "_");
              if (split.size() < 2){
                cout << "Eroare la linia " << line << "\n";
                cout << "Identificator obiect inexistent\n";
                return -1;
              }

              string objectType = split[1];

              found = false;
              tuple <int, string, string, int, int, string> myObj;
              for (auto it : currMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                if (b == "obiect" and c == objectType and e < idDepth){
                  myObj = it;
                  found = true;
                  break;
                }
                else
                if (b == "obiect" and c == objectType and e == idDepth and d == idScope){
                  myObj = it;
                  found = true;
                  break;
                }
              }

              if (not found){
                cout << "Eroare la linia " << line << "\n";
                cout << "Tip variabila inexistent\n";
                return -1;
              }

              char* fieldId = (yyvsp[0].strval);
              split = splitString(fieldId, " ");
              nameVar = split[1];

              found = false;

              tuple <int, string, string, int, int, string> myField;
              for (auto it : currMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                if (c == nameVar and splitString(b, "->")[0] == objectType){
                  myField = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and splitString(b, "->")[0] == objectType){
                  myField = it;
                  found = true;
                  break;
                }
              }
              for (auto it : objMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                if (c == nameVar and splitString(b, "->")[0] == objectType){
                  myField = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and splitString(b, "->")[0] == objectType){
                  myField = it;
                  found = true;
                  break;
                }
              }

            if(!found){
              cout<<"Eroare la linia "<< line << "\n";
              cout<<"Campul nu a fost gasit\n";
              return -1;
            }

            tie(a,b,c,d,e,f) = myField;

            split = splitString(b, "->");

            char* res = new char[10];
              if (split[1] == "intreg"){
                strcpy(res, "0$0");
              }
              if (split[1] == "rational"){
                strcpy(res, "1$0");
              }
              if (split[1] == "text"){
                strcpy(res, "2$ ");
              }
              if (split[1] == "char"){
                strcpy(res, "3$ ");
              }
              if (split[1] == "intrerupator"){
                strcpy(res, "4$1");
              }

              (yyval.strval) = res;


           }
#line 3469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1900 "a.y" /* yacc.c:1646  */
    {
             char* res = new char[10];
             strcpy(res, "0$0");
             (yyval.strval) = res;
           }
#line 3479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1908 "a.y" /* yacc.c:1646  */
    {
                  string l = (yyvsp[-2].strval);
                  string r = (yyvsp[0].strval);
                  if (l[0] != r[0]){
                    cout << "Eroare: Tipuri diferite la linia " << yylineno << "\n";
                    cout << "Eroare: Comparare intre tipuri" << "\n";
                    cout << l[0] << " " << r[0] << "\n";
                    return -1;
                  }

                  string valLeft;
                  for (int i = 2; i < l.size(); i++)
                    valLeft.push_back(l[i]);

                  string valRight;
                  for (int i = 2; i < r.size(); i++)
                    valRight.push_back(r[i]);

                  if (valLeft == valRight){
                    char* result = new char[10];
                    strcpy(result, "4$1");
                    (yyval.strval) = result;
                  }
                  else{
                    char* result = new char[10];
                    strcpy(result, "4$0");
                    (yyval.strval) = result;
                  }
                }
#line 3513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1937 "a.y" /* yacc.c:1646  */
    {
                  string l = (yyvsp[-2].strval);
                  string r = (yyvsp[0].strval);
                  if (l[0] != r[0]){
                    cout << "Eroare: Tipuri diferite la linia" << yylineno << "\n";
                    cout << "Eroare: Comparare intre tipuri" << "\n";
                    cout << l[0] << " " << r[0] << "\n";
                    return -1;
                  }

                  string valLeft;
                  for (int i = 2; i < l.size(); i++)
                    valLeft.push_back(l[i]);

                  string valRight;
                  for (int i = 2; i < r.size(); i++)
                    valRight.push_back(r[i]);

                  if (valLeft != valRight){
                    char* result = new char[10];
                    strcpy(result, "4$1");
                    (yyval.strval) = result;
                  }
                  else{
                    char* result = new char[10];
                    strcpy(result, "4$0");
                    (yyval.strval) = result;
                  }
                }
#line 3547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1966 "a.y" /* yacc.c:1646  */
    {
                  string l = (yyvsp[-2].strval);
                  string r = (yyvsp[0].strval);
                  if (l[0] != r[0]){
                    cout << "Eroare: Tipuri diferite la linia" << yylineno << "\n";
                    cout << "Eroare: Comparare intre tipuri" << "\n";
                    cout << l[0] << " " << r[0] << "\n";
                    return -1;
                  }

                  string valLeft;
                  for (int i = 2; i < l.size(); i++)
                    valLeft.push_back(l[i]);

                  string valRight;
                  for (int i = 2; i < r.size(); i++)
                    valRight.push_back(r[i]);

                  if (l[0] == '0'){
                    int i_left;
                    int i_right;
                    convert(valLeft, i_left);
                    convert(valRight, i_right);
                    
                    if (i_left >= i_right){
                      char* result = new char[10];
                      strcpy(result, "4$1");
                      (yyval.strval) = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      (yyval.strval) = result;
                    }
                  }
                  else
                  if (l[0] == '1'){
                    float f_left;
                    float f_right;
                    convert(valLeft, f_left);
                    convert(valRight, f_right);
                    
                    if (f_left >= f_right){
                      char* result = new char[10];
                      strcpy(result, "4$1");
                      (yyval.strval) = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      (yyval.strval) = result;
                    }
                  }
                  else{
                    cout << "Comparare incompatibila pentru tipurile " << l[0] << "\n";
                    cout << "Eroare la linia " << yylineno << "\n";
                    return -1;
                  }
                }
#line 3611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 2025 "a.y" /* yacc.c:1646  */
    {
                  string l = (yyvsp[-2].strval);
                  string r = (yyvsp[0].strval);
                  if (l[0] != r[0]){
                    cout << "Eroare: Tipuri diferite la linia" << yylineno << "\n";
                    cout << "Eroare: Comparare intre tipuri" << "\n";
                    cout << l[0] << " " << r[0] << "\n";
                    return -1;
                  }

                  string valLeft;
                  for (int i = 2; i < l.size(); i++)
                    valLeft.push_back(l[i]);

                  string valRight;
                  for (int i = 2; i < r.size(); i++)
                    valRight.push_back(r[i]);

                  if (l[0] == '0'){
                    int i_left;
                    int i_right;
                    convert(valLeft, i_left);
                    convert(valRight, i_right);
                    
                    if (i_left <= i_right){
                      char* result = new char[10];
                      strcpy(result, "4$1");
                      (yyval.strval) = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      (yyval.strval) = result;
                    }
                  }
                  else
                  if (l[0] == '1'){
                    float f_left;
                    float f_right;
                    convert(valLeft, f_left);
                    convert(valRight, f_right);
                    
                    if (f_left <= f_right){
                      char* result = new char[10];
                      strcpy(result, "4$1");
                      (yyval.strval) = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      (yyval.strval) = result;
                    }
                  }
                  else{
                    cout << "Comparare incompatibila pentru tipurile " << l[0] << "\n";
                    cout << "Eroare la linia " << yylineno << "\n";
                    return -1;
                  }
                }
#line 3675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 2084 "a.y" /* yacc.c:1646  */
    {
                  string l = (yyvsp[-2].strval);
                  string r = (yyvsp[0].strval);
                  if (l[0] != r[0]){
                    cout << "Eroare: Tipuri diferite la linia" << yylineno << "\n";
                    cout << "Eroare: Comparare intre tipuri" << "\n";
                    cout << l[0] << " " << r[0] << "\n";
                    return -1;
                  }

                  string valLeft;
                  for (int i = 2; i < l.size(); i++)
                    valLeft.push_back(l[i]);

                  string valRight;
                  for (int i = 2; i < r.size(); i++)
                    valRight.push_back(r[i]);

                  if (l[0] == '0'){
                    int i_left;
                    int i_right;
                    convert(valLeft, i_left);
                    convert(valRight, i_right);
                    
                    if (i_left > i_right){
                      char* result = new char[10];
                      strcpy(result, "4$1");
                      (yyval.strval) = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      (yyval.strval) = result;
                    }
                  }
                  else
                  if (l[0] == '1'){
                    float f_left;
                    float f_right;
                    convert(valLeft, f_left);
                    convert(valRight, f_right);
                    
                    if (f_left > f_right){
                      char* result = new char[10];
                      strcpy(result, "4$1");
                      (yyval.strval) = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      (yyval.strval) = result;
                    }
                  }
                  else{
                    cout << "Comparare incompatibila pentru tipurile " << l[0] << "\n";
                    cout << "Eroare la linia " << yylineno << "\n";
                    return -1;
                  }
                }
#line 3739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 2143 "a.y" /* yacc.c:1646  */
    {
                  string l = (yyvsp[-2].strval);
                  string r = (yyvsp[0].strval);
                  if (l[0] != r[0]){
                    cout << "Eroare: Tipuri diferite la linia" << yylineno << "\n";
                    cout << "Eroare: Comparare intre tipuri" << "\n";
                    cout << l[0] << " " << r[0] << "\n";
                    return -1;
                  }

                  string valLeft;
                  for (int i = 2; i < l.size(); i++)
                    valLeft.push_back(l[i]);

                  string valRight;
                  for (int i = 2; i < r.size(); i++)
                    valRight.push_back(r[i]);

                  if (l[0] == '0'){
                    int i_left;
                    int i_right;
                    convert(valLeft, i_left);
                    convert(valRight, i_right);
                    
                    if (i_left < i_right){
                      char* result = new char[10];
                      strcpy(result, "4$1");
                      (yyval.strval) = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      (yyval.strval) = result;
                    }
                  }
                  else
                  if (l[0] == '1'){
                    float f_left;
                    float f_right;
                    convert(valLeft, f_left);
                    convert(valRight, f_right);
                    
                    if (f_left < f_right){
                      char* result = new char[10];
                      strcpy(result, "4$1");
                      (yyval.strval) = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      (yyval.strval) = result;
                    }
                  }
                  else{
                    cout << "Comparare incompatibila pentru tipurile " << l[0] << "\n";
                    cout << "Eroare la linia " << yylineno << "\n";
                    return -1;
                  }
                }
#line 3803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 2202 "a.y" /* yacc.c:1646  */
    {(yyval.strval) = (yyvsp[-1].strval);}
#line 3809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 2203 "a.y" /* yacc.c:1646  */
    {
                  char *l = (yyvsp[-2].strval);
                  char *r = (yyvsp[0].strval);

                  char c_l = l[2];
                  char c_r = r[2];

                  int i_l;
                  int i_r;
                  convert(c_l, i_l);
                  convert(c_r, i_r);

                  bool b_l = i_l;
                  bool b_r = i_r;

                  if (b_l and b_r){
                    char* result = new char[10];
                    strcpy(result, "4$1");
                    (yyval.strval) = result;
                  }
                  else{
                    char* result = new char[10];
                    strcpy(result, "4$0");
                    (yyval.strval) = result;
                  }
               }
#line 3840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 2229 "a.y" /* yacc.c:1646  */
    {
                  char *l = (yyvsp[-2].strval);
                  char *r = (yyvsp[0].strval);

                  char c_l = l[2];
                  char c_r = r[2];

                  int i_l;
                  int i_r;
                  convert(c_l, i_l);
                  convert(c_r, i_r);

                  bool b_l = i_l;
                  bool b_r = i_r;

                  if (b_l or b_r){
                    char* result = new char[10];
                    strcpy(result, "4$1");
                    (yyval.strval) = result;
                  }
                  else{
                    char* result = new char[10];
                    strcpy(result, "4$0");
                    (yyval.strval) = result;
                  }
                }
#line 3871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 2255 "a.y" /* yacc.c:1646  */
    {
                  char *expr = (yyvsp[0].strval);
                  char c_value = expr[2];
                  int i_value;
                  convert(c_value, i_value);
                  i_value = !i_value;
                  convert(i_value, c_value);
                  
                  char *result = new char[10];
                  strcpy(result, "4$D");
                  result[2] = c_value;

                  (yyval.strval) = result;
                }
#line 3890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 2269 "a.y" /* yacc.c:1646  */
    {
                  char* result = new char[10];
                  strcpy(result, "4$1");
                  (yyval.strval) = result;
                }
#line 3900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 2274 "a.y" /* yacc.c:1646  */
    {
                  char* result = new char[10];
                  strcpy(result, "4$0");
                  (yyval.strval) = result;
                }
#line 3910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 2279 "a.y" /* yacc.c:1646  */
    {
                  char* varInfo = (yyvsp[0].strval);
                  string s = varInfo;
                  vector<string> split = splitString(s, " ");
                  string nameVar = split[1];
                  string line = split[0];
                  
                  stringstream ss;
                  ss << line;

                  int curLine;
                  ss >> curLine;
                  curLine--;

                  auto p = wordScope[curLine][0];
                  
                  int idScope = p.first;
                  int idDepth = p.second;

                  string res = checkVarExistence(nameVar, idScope, idDepth);
                  if (res != "Error"){
                    if (res[0] != '4'){
                      cout << "Eroare: Identificator care nu este intrerupator la linia " << line << "\n";
                      return -1;
                    }
                    char* final = new char[res.size()+5];
                    strcpy(final, res.c_str());
                    (yyval.strval) = final;
                  }
                  else{
                    cout << "Eroare: variabila nedeclarata folosita in expresie la linia: " << line << "\n";
                    cout << "Nume variabila: " << nameVar << "\n";
                    return -1;
                  }

                  
                }
#line 3952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 2323 "a.y" /* yacc.c:1646  */
    {
            char* varId = (yyvsp[-2].strval);
            
            string s = varId;
            vector <string> split = splitString(s, " ");
            char* line = new char[split[0].size() + 5];
            char* varName = new char[split[1].size() + 5];
            strcpy(line, split[0].c_str());
            strcpy(varName, split[1].c_str());

            int curLine;

            stringstream ss;
            ss << line;
            ss >> curLine;
            curLine --;

            auto p = wordScope[curLine][0];
            int idScope = p.first;
            int idDepth = p.second;

            string check = checkVarExistence(varName, idScope, idDepth);
            if (check == "Error"){
              cout << "Eroare: Variabila inexistenta la linia " << line << "\n";
              return -1;
            }

            char* evalResult = (yyvsp[0].strval);

            if (strlen(evalResult) == 2){
              cout << "Eroare: Atribuire vida la linia: " << line << "\n";
              return -1;
            }

            if (evalResult[0] != check[0]){
              cout << "Eroare: Atribuire invalida la linia: " << line << "\n";
              return -1; 
            }

            string type;
            if (check[0] == '0')
              type = "intreg";
            else
            if (check[0] == '1')
              type = "rational";
            else
            if (check[0] == '2')
              type = "text";
            else
            if (check[0] == '3')
              type = "caracter";
            else
            if (check[0] == '4')
              type = "intrerupator";
            else
              type = "necunoscut";

          
            tuple <int, string, string, int, int, string> arg;
            if (deleteFromMap(varName, idScope, idDepth, arg) == 1){
              int a;
              string b;
              string c;
              int d;
              int e;
              string f;

              tie (a,b,c,d,e,f) = arg;

              addToCurr(a, b, varName, d, e, evalResult+2);
            }
          }
#line 4029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 2396 "a.y" /* yacc.c:1646  */
    {
            char* varId = (yyvsp[-2].strval);
            
            string s = varId;
            vector <string> split = splitString(s, " ");
            char* line = new char[split[0].size() + 5];
            char* varName = new char[split[1].size() + 5];
            strcpy(line, split[0].c_str());
            strcpy(varName, split[1].c_str());

            int curLine;

            stringstream ss;
            ss << line;
            ss >> curLine;
            curLine --;

            auto p = wordScope[curLine][0];
            int idScope = p.first;
            int idDepth = p.second;

            string check = checkVarExistence(varName, idScope, idDepth);
            if (check == "Error"){
              cout << "Eroare: Variabila inexistenta la linia " << line << "\n";
              return -1;
            }

            char* evalResult = (yyvsp[0].strval);

            if (strlen(evalResult) == 2){
              cout << "Eroare: Atribuire vida la linia: " << line << "\n";
              return -1;
            }

            if (evalResult[0] != check[0]){
              cout << "Eroare: Atribuire invalida la linia: " << line << "\n";
              return -1; 
            }

            string type;
            if (check[0] == '0')
              type = "intreg";
            else
            if (check[0] == '1')
              type = "rational";
            else
            if (check[0] == '2')
              type = "text";
            else
            if (check[0] == '3')
              type = "caracter";
            else
            if (check[0] == '4')
              type = "intrerupator";
            else
              type = "necunoscut";

            
            tuple <int, string, string, int, int, string> arg;
            if (deleteFromMap(varName, idScope, idDepth, arg) == 1){
              int a;
              string b;
              string c;
              int d;
              int e;
              string f;

              tie (a,b,c,d,e,f) = arg;

              addToCurr(a, b, varName, d, e, evalResult+2);
            }
            
          }
#line 4107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 2470 "a.y" /* yacc.c:1646  */
    {
              
              char* varInfo = (yyvsp[-4].strval);
              string s = varInfo;
              vector<string> split = splitString(s, " ");
              string nameVar = split[1];
              string line = split[0];
              
              stringstream ss;
              ss << line;

              int curLine;
              ss >> curLine;
              curLine--;

              auto p = wordScope[curLine][0];
              
              int idScope = p.first;
              int idDepth = p.second;

              bool found = false;

              tuple <int, string, string, int, int, string> myFunc;
              for (auto it : currMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                vector<string> typeSplit = splitString(b, "_");

                if(typeSplit.size() < 2 or typeSplit[0] != "obiect") continue;

                if (c == nameVar and e < idDepth){
                  myFunc = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and e == idDepth and d == idScope){
                  myFunc = it;
                  found = true;
                  break;
                }
              }
              for (auto it : objMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;

                vector<string> typeSplit = splitString(b, "_");

                if(typeSplit.size() < 2 or typeSplit[0] != "obiect") continue;

                if (c == nameVar and e < idDepth){
                  myFunc = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and e == idDepth and d == idScope){
                  myFunc = it;
                  found = true;
                  break;
                }
              }

              if (not found){
                cout << "Eroare tip inexistent la linia ";
                cout << line << "\n";
                return -1;
              }

              int a;
              string b;
              string c;
              int d;
              int e;
              string f;

              tie(a,b,c,d,e,f) = myFunc;
              idScope = d;
              idDepth = e;

              split = splitString(b, "_");
              if (split.size() < 2){
                cout << "Eroare la linia " << line << "\n";
                cout << "Identificator obiect inexistent\n";
                return -1;
              }

              string objectType = split[1];

              found = false;
              tuple <int, string, string, int, int, string> myObj;
              for (auto it : currMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                if (b == "obiect" and c == objectType and e < idDepth){
                  myObj = it;
                  found = true;
                  break;
                }
                else
                if (b == "obiect" and c == objectType and e == idDepth and d == idScope){
                  myObj = it;
                  found = true;
                  break;
                }
              }

              if (not found){
                cout << "Eroare la linia " << line << "\n";
                cout << "Tip variabila inexistent\n";
                return -1;
              }

              char* fieldId = (yyvsp[-2].strval);
              split = splitString(fieldId, " ");
              nameVar = split[1];

              found = false;

              tuple <int, string, string, int, int, string> myField;
              for (auto it : currMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                if (c == nameVar and splitString(b, "->")[0] == objectType){
                  myField = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and splitString(b, "->")[0] == objectType){
                  myField = it;
                  found = true;
                  break;
                }
              }
              for (auto it : objMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                if (c == nameVar and splitString(b, "->")[0] == objectType){
                  myField = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and splitString(b, "->")[0] == objectType){
                  myField = it;
                  found = true;
                  break;
                }
              }

            if(!found){
              cout<<"Eroare la linia "<< line << "\n";
              cout<<"Campul nu a fost gasit\n";
              return -1;
            }

            tie(a,b,c,d,e,f) = myField;

            split = splitString(b, "->");

            char* res = new char[10];
            if (split[1] == "intreg"){
              strcpy(res, "0$0");
            }
            if (split[1] == "rational"){
              strcpy(res, "1$0");
            }
            if (split[1] == "text"){
              strcpy(res, "2$ ");
            }
            if (split[1] == "char"){
              strcpy(res, "3$ ");
            }
            if (split[1] == "intrerupator"){
              strcpy(res, "4$1");
            }

            char* expresie = (yyvsp[0].strval);

            if(expresie[0] != res[0]){
              cout<<"Eroare la linia " << line << '\n';
              cout<<"Atribuire intre tipuri incompatibile"<<"\n";
              return -1;
            }

           }
#line 4329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 2687 "a.y" /* yacc.c:1646  */
    {
          char* valLeft = (yyvsp[-2].strval);
          char* valExpr = (yyvsp[0].strval);

          if (valLeft[0] != valExpr[0]){
            cout << "Eroare la linia " << yylineno;
            cout << "\nTipuri invalide\n";
            return -1;
          }
        }
#line 4344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 2698 "a.y" /* yacc.c:1646  */
    {
              
              char* varInfo = (yyvsp[-4].strval);
              string s = varInfo;
              vector<string> split = splitString(s, " ");
              string nameVar = split[1];
              string line = split[0];
              
              stringstream ss;
              ss << line;

              int curLine;
              ss >> curLine;
              curLine--;

              auto p = wordScope[curLine][0];
              
              int idScope = p.first;
              int idDepth = p.second;

              bool found = false;

              tuple <int, string, string, int, int, string> myFunc;
              for (auto it : currMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                vector<string> typeSplit = splitString(b, "_");

                if(typeSplit.size() < 2 or typeSplit[0] != "obiect") continue;

                if (c == nameVar and e < idDepth){
                  myFunc = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and e == idDepth and d == idScope){
                  myFunc = it;
                  found = true;
                  break;
                }
              }
              for (auto it : objMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;

                vector<string> typeSplit = splitString(b, "_");

                if(typeSplit.size() < 2 or typeSplit[0] != "obiect") continue;

                if (c == nameVar and e < idDepth){
                  myFunc = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and e == idDepth and d == idScope){
                  myFunc = it;
                  found = true;
                  break;
                }
              }

              if (not found){
                cout << "Eroare tip inexistent la linia ";
                cout << line << "\n";
                return -1;
              }

              int a;
              string b;
              string c;
              int d;
              int e;
              string f;

              tie(a,b,c,d,e,f) = myFunc;
              idScope = d;
              idDepth = e;

              split = splitString(b, "_");
              if (split.size() < 2){
                cout << "Eroare la linia " << line << "\n";
                cout << "Identificator obiect inexistent\n";
                return -1;
              }

              string objectType = split[1];

              found = false;
              tuple <int, string, string, int, int, string> myObj;
              for (auto it : currMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                if (b == "obiect" and c == objectType and e < idDepth){
                  myObj = it;
                  found = true;
                  break;
                }
                else
                if (b == "obiect" and c == objectType and e == idDepth and d == idScope){
                  myObj = it;
                  found = true;
                  break;
                }
              }

              if (not found){
                cout << "Eroare la linia " << line << "\n";
                cout << "Tip variabila inexistent\n";
                return -1;
              }

              char* fieldId = (yyvsp[-2].strval);
              split = splitString(fieldId, " ");
              nameVar = split[1];

              found = false;

              tuple <int, string, string, int, int, string> myField;
              for (auto it : currMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                if (c == nameVar and splitString(b, "->")[0] == objectType){
                  myField = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and splitString(b, "->")[0] == objectType){
                  myField = it;
                  found = true;
                  break;
                }
              }
              for (auto it : objMapping){
                int a;
                string b;
                string c;
                int d;
                int e;
                string f;

                tie(a,b,c,d,e,f) = it;
                if (c == nameVar and splitString(b, "->")[0] == objectType){
                  myField = it;
                  found = true;
                  break;
                }
                else
                if (c == nameVar and splitString(b, "->")[0] == objectType){
                  myField = it;
                  found = true;
                  break;
                }
              }

            if(!found){
              cout<<"Eroare la linia "<< line << "\n";
              cout<<"Campul nu a fost gasit\n";
              return -1;
            }

            tie(a,b,c,d,e,f) = myField;

            split = splitString(b, "->");

            char* res = new char[10];
            if (split[1] == "intreg"){
              strcpy(res, "0$0");
            }
            if (split[1] == "rational"){
              strcpy(res, "1$0");
            }
            if (split[1] == "text"){
              strcpy(res, "2$ ");
            }
            if (split[1] == "char"){
              strcpy(res, "3$ ");
            }
            if (split[1] == "intrerupator"){
              strcpy(res, "4$1");
            }

            char* expresie = (yyvsp[0].strval);

            if(expresie[0] != res[0]){
              cout<<"Eroare la linia " << line << '\n';
              cout<<"Atribuire intre tipuri incompatibile"<<"\n";
              return -1;
            }

           }
#line 4566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 2915 "a.y" /* yacc.c:1646  */
    {
          char* valLeft = (yyvsp[-2].strval);
          char* valExpr = (yyvsp[0].strval);

          if (valLeft[0] != valExpr[0]){
            cout << "Eroare la linia " << yylineno;
            cout << "\nTipuri invalide\n";
            return -1;
          }
        }
#line 4581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 2927 "a.y" /* yacc.c:1646  */
    {
            char* result = (yyvsp[-1].strval);
            string value;
            for (int i = 2; i < strlen(result); i++){
              value += result[i];  
            }
            if (value.size() == 0){
              cout << "Eroare: Expresie vida la linia: " << yylineno << "\n";
              return -1;
            }
            cout << value << "\n";
          }
#line 4598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 2939 "a.y" /* yacc.c:1646  */
    {
            char* result = (yyvsp[-1].strval);
            string value;
            for (int i = 2; i < strlen(result); i++){
              value += result[i];  
            }
            if (value.size() == 0){
              cout << "Eroare: Expresie vida la linia: " << yylineno << "\n";
              return -1;
            }
            cout << value << "\n";
          }
#line 4615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 2951 "a.y" /* yacc.c:1646  */
    {
            char* result = (yyvsp[-1].strval);
            if (result[0] != '0'){
              cout << "Eroare la linia " << yylineno << "\n";
              cout << "Functia EVAL apelata pe o expresie cu rezultat neintreg" << "\n";
              return -1;
            }

            string value;
            for (int i = 2; i < strlen(result); i++){
              value += result[i];  
            }
            if (value.size() == 0){
              cout << "Eroare: Expresie vida la linia: " << yylineno << "\n";
              return -1;
            }
            cout << value << "\n";
          }
#line 4638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 2969 "a.y" /* yacc.c:1646  */
    {
            char* result = (yyvsp[-1].strval);
            vector <string> split = splitString(result, " ");
            string line = split[0];
            string nameVar = split[1];

            stringstream ss;
            ss << line;

            int curLine;
            ss >> curLine;
            curLine--;

            auto p = wordScope[curLine][0];
            
            int idScope = p.first;
            int idDepth = p.second;

            string res = checkVarExistence(nameVar, idScope, idDepth);
            if (res == "Error"){
              cout << "Eroare variabila nedeclarata folosita in inspectare la linia: " << line << "\n";
              cout << "Nume variabila: " << nameVar << "\n";
              return -1;
            }

            tuple <int, string, string, int, int, string> toFind;
            int found = 0;
            for (auto it : currMapping){
              int a;
              string b;
              string c;
              int d;
              int e;
              string f;

              tie(a,b,c,d,e,f) = it;
              if (c == nameVar and e < idDepth){
                toFind = it;
                found += 1;
                break;
              }
              else
              if (c == nameVar and e == idDepth and d == idScope){
                toFind = it;
                found += 1;
                break;
              }
            }

            int a;
            string b;
            string c;
            int d;
            int e;
            string f;

            tie(a, b, c, d, e, f) = toFind;
            a++;

            cout << "Linia (declarare): "  << a << " | ";
            cout << "Tipul : "             << b << " | ";
            cout << "Numele: "             << c << " | ";
            cout << "ScopeID: "            << d << " | ";
            cout << "ScopeDepth: "         << e << " | ";
            cout << "Valoare: "            << f << " \n";
          }
#line 4709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 3035 "a.y" /* yacc.c:1646  */
    {
            char* varId = (yyvsp[0].strval);
            
            string s = varId;
            vector <string> split = splitString(s, " ");
            char* line = new char[split[0].size() + 5];
            char* varName = new char[split[1].size() + 5];
            strcpy(line, split[0].c_str());
            strcpy(varName, split[1].c_str());

            int curLine;

            stringstream ss;
            ss << line;
            ss >> curLine;
            curLine --;

            auto p = wordScope[curLine][0];
            int idScope = p.first;
            int idDepth = p.second;

            string check = checkVarExistence(varName, idScope, idDepth);
            if (check == "Error"){
              cout << "Eroare: Variabila inexistenta la linia " << line << "\n";
              return -1;
            }

            char* evalResult = new char[1000];
            cin.get(evalResult, 1000);
            cin.get();

            if (strlen(evalResult) < 3){
              cout << "Eroare: citire vida la linia: " << line << "\n";
              return -1;
            }

            bool ok = false;
            for (auto l : "01234"){
              if (l == evalResult[0]){
                ok = true;
                break;
              }
            }

            if (!ok){
              cout << "Eroare: tip invalid la linia " << line << "\n";
              return -1;
            }

            if (evalResult[1] != '$'){
              cout << "Eroare: Sintaxa citire invalida la linia" << line << "\n";
              return -1;
            }

            if (evalResult[0] != check[0]){
              cout << "Eroare: Atribuire invalida la linia: " << line << "\n";
              return -1; 
            }
          
            tuple <int, string, string, int, int, string> arg;
            if (deleteFromMap(varName, idScope, idDepth, arg) == 1){
              int a;
              string b;
              string c;
              int d;
              int e;
              string f;

              tie (a,b,c,d,e,f) = arg;

              addToCurr(a, b, varName, d, e, evalResult+2);
            }
          }
#line 4787 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4791 "y.tab.c" /* yacc.c:1646  */
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
#line 3130 "a.y" /* yacc.c:1906  */


int yyerror(char * s){
  printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
  yyin = fopen(argv[1],"r");

  stack <int> scopeChecker;
  ifstream fin(argv[1]);

  string line;
  while (getline(fin, line)){
    fileContent.push_back(line);
  }

  int i = 1;
  for (auto line : fileContent){
    vector <string> split = splitString(line, " ");
    for (auto word : split){
      if (word == "incepe"){
        scopeChecker.push(1);
      }
      else
      if (word == "termina" and scopeChecker.size() == 0){
        cout << "Programul are scope-urile rau definite\n";
        cout << "Eroare linia: " << i << "\n";
        return 0;
      }
      else
      if (word == "termina" and scopeChecker.top() != 1){
        cout << "Programul are scope-urile rau definite\n";
        cout << "Eroare linia: " << i << "\n";
        return 0;
      }
      else
      if (word == "termina"){
        scopeChecker.pop();
      }
      /*
      for (auto l : word){
        if (l == '{'){
          scopeChecker.push(2);
        }
        else
        if (l == '}' and scopeChecker.size() == 0){
          cout << "Programul are scope-urile rau definite\n";
          cout << "Eroare linia: " << i << "\n";
          return 0;
        }
        else
        if (l == '}' and scopeChecker.top() != 2){
          cout << "Programul are scope-urile rau definite\n";
          cout << "Eroare linia: " << i << "\n";
          return 0;
        }
        else
        if (l == '}'){
          scopeChecker.pop();
        }
      }
      */
    }
    i++;
  }

  if (scopeChecker.size() == 0){
    cout << "Programul are scope-urile bine definite\n";
  }
  else{
    cout << "Programul are scope-urile rau definite\n";
    return 0;
  }

  int scopeId[1000];
  for (int i = 0; i < 1000; i++)
    scopeId[i] = -1;
  int scopeDepth = 0;
  scopeId[0] = 0;

  int l = 0;
  for (auto line : fileContent){
    wordScope.push_back(vector <pair<int, int>>());

    vector <string> split = splitString(line, " ");
    for (int i = 0; i < split.size(); i++){
      wordScope[l].push_back(pair <int, int>());

      auto word = split[i];
      if (word == "incepe"){
        scopeDepth++;
        scopeId[scopeDepth]++;
      }
      else
      if (word == "termina"){
        scopeDepth--;
      }
      /*
      for (auto l : word){
        if (l == '{'){
          scopeDepth++;
          scopeId[scopeDepth]++;
        }
        else
        if (l == '}')
          scopeDepth--;
      }
      */

      wordScope[l][i].first = scopeId[scopeDepth];
      wordScope[l][i].second = scopeDepth;
    }

    l++;
  }

  /*
  cout << wordScope[46][0].first << " ";
  cout << wordScope[46][0].second << "\n";

  cout << wordScope[49][0].first << " ";
  cout << wordScope[49][0].second << "\n";
  */
  int myInt;
  char myChar;
  char *myText;
  float myFloat;

  /*
  cout << typeid(myInt).name() << "\n";
  cout << typeid(myChar).name() << "\n";
  cout << typeid(myText).name() << "\n";
  cout << typeid(myFloat).name() << "\n";
  */

  yyparse();

  ofstream fout ("tableInit.out");
  for (auto it : initMapping){
    int curLine;
    string type;
    string varName;
    int idScope;
    int idDepth;
    string value;
    tie(curLine, type, varName, idScope, idDepth, value) = it;
    fout << curLine+1 << " " << type << " " << varName << " ";
    fout << idScope << " " << idDepth << " " << value << "\n"; 
  }
  fout.close();

  ofstream gout ("tableCurr.out");
  for (auto it : currMapping){
    int curLine;
    string type;
    string varName;
    int idScope;
    int idDepth;
    string value;
    tie(curLine, type, varName, idScope, idDepth, value) = it;
    gout << curLine+1 << " " << type << " " << varName << " ";
    gout << idScope << " " << idDepth << " " << value << "\n"; 
  }
  gout.close();
} 
