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
#line 210 "a.y" /* yacc.c:1909  */

  char* strval;

#line 140 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
