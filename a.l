%{
#include <stdio.h>
#include "y.tab.h"
#include <bits/stdc++.h>

using namespace std;

//extern int yylval;
%}
option noyywrap

tipIntrer "intrerupator"
tipIntreg "intreg"
tipRational "rational"
tipText "text"
tipCaracter "caracter"
tipVector "vector"
tipObiect "obiect"
tipFunctie "functie"

nrIntreg ([1-9][0-9]*)|[0-9]
nrRational {nrIntreg}"."[0-9]+
text \"[a-zA-Z0-9 _]+\"
caracter \'[a-zA-Z0-9 _]\'

identificator [a-zA-Z_][a-zA-Z0-9_]*

%%

{tipIntrer}     {yylval.strval = strdup(yytext); return TIP_INTRERUPATOR;}
{tipIntreg}     {yylval.strval = strdup(yytext); return TIP_INTREG;}
{tipRational}   {yylval.strval = strdup(yytext); return TIP_RATIONAL;}
{tipText}       {yylval.strval = strdup(yytext); return TIP_TEXT;}
{tipCaracter}   {yylval.strval = strdup(yytext); return TIP_CARACTER;}
{tipVector}     {yylval.strval = strdup(yytext); return TIP_VECTOR;}
{tipObiect}     {
                    char* s; 
                    s = new char[100]; 
                    stringstream ss; 
                    ss << yylineno; 
                    string aux;
                    ss >> aux; 
                    strcpy(s, aux.c_str()); 
                    yylval.strval = strdup(s); 
                    return TIP_OBIECT;
                }

{tipFunctie}    {
                    char* s; 
                    s = new char[100]; 
                    stringstream ss; 
                    ss << yylineno; 
                    string aux;
                    ss >> aux; 
                    strcpy(s, aux.c_str()); 
                    yylval.strval = strdup(s);
                    return TIP_FUNCTIE;
                }

{nrIntreg}      {yylval.strval = strdup(yytext); return NR_INTREG;}
{nrRational}    {yylval.strval = strdup(yytext); return NR_RATIONAL;}
{text}          {yylval.strval = strdup(yytext); return TEXT;}
{caracter}      {yylval.strval = strdup(yytext); return CARACTER;}

"sau"           {yylval.strval = strdup(yytext); return SAU;}
"si"            {yylval.strval = strdup(yytext); return SI;}
"nu"            {yylval.strval = strdup(yytext); return NEGAT;}
"aprins"        {yylval.strval = strdup(yytext); return APRINS;}
"stins"         {yylval.strval = strdup(yytext); return STINS;}

"=="            {yylval.strval = strdup(yytext); return EGAL;}
"!="            {yylval.strval = strdup(yytext); return DIFERIT;}
">="            {yylval.strval = strdup(yytext); return MAI_MARE_EGAL;}
"<="            {yylval.strval = strdup(yytext); return MAI_MIC_EGAL;}

"daca"          {yylval.strval = strdup(yytext); return DACA;}
"altfel"        {yylval.strval = strdup(yytext); return ALTFEL;}
"pentru"        {yylval.strval = strdup(yytext); return PENTRU;}
"cat_timp"      {yylval.strval = strdup(yytext); return CAT_TIMP;}
"pana_cand"     {yylval.strval = strdup(yytext); return PANA_CAND;}
"executa"       {yylval.strval = strdup(yytext); return EXECUTA;}
"incepe"        {yylval.strval = strdup(yytext); return INCEPE;}
"termina"       {yylval.strval = strdup(yytext); return TERMINA;}
"apartine"      {yylval.strval = strdup(yytext); return APARTINE;}
"in"            {yylval.strval = strdup(yytext); return IN;}
"pas"           {yylval.strval = strdup(yytext); return PAS;}

"inspecteaza"   {yylval.strval = strdup(yytext); return INSPECTEAZA;}
"afiseaza"      {yylval.strval = strdup(yytext); return AFISEAZA;}
"principal"     {yylval.strval = strdup(yytext); return PRINCIPAL;}
"citeste"       {yylval.strval = strdup(yytext); return CITESTE;}
"eval"          {yylval.strval = strdup(yytext); return EVAL;}

"returneaza"    {yylval.strval = strdup(yytext); return RETURNEAZA;}

{identificator} {
                    char* s; 
                    s = new char[100 + strlen(yytext)]; 
                    stringstream ss; 
                    ss << yylineno; 
                    string aux;
                    ss >> aux;
                    aux += " ";
                    strcpy(s, aux.c_str()); 
                    strcat(s, yytext);
                    yylval.strval = strdup(s);
                    return IDENTIFICATOR;
                }

[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
