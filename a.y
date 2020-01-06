%{
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

%}

%union{
  char* strval;
}


%start program

%token<strval> TIP_INTRERUPATOR
%token<strval> TIP_INTREG
%token<strval> TIP_RATIONAL
%token<strval> TIP_TEXT
%token<strval> TIP_CARACTER
%token<strval> TIP_VECTOR
%token<strval> TIP_OBIECT
%token<strval> TIP_FUNCTIE

%token<strval> NR_INTREG
%token<strval> NR_RATIONAL
%token<strval> TEXT
%token<strval> CARACTER

%token<strval> SAU
%token<strval> SI
%token<strval> NEGAT
%token<strval> STINS
%token<strval> APRINS
%token<strval> EGAL
%token<strval> DIFERIT
%token<strval> MAI_MARE_EGAL
%token<strval> MAI_MIC_EGAL

%token<strval> DACA
%token<strval> ALTFEL
%token<strval> PENTRU
%token<strval> CAT_TIMP
%token<strval> PANA_CAND
%token<strval> EXECUTA
%token<strval> INCEPE
%token<strval> TERMINA
%token<strval> APARTINE
%token<strval> IN
%token<strval> PAS

%token<strval> INSPECTEAZA
%token<strval> AFISEAZA
%token<strval> PRINCIPAL
%token<strval> CITESTE
%token<strval> EVAL

%token<strval> RETURNEAZA

%token<strval> IDENTIFICATOR

%left EGAL
%left DIFERIT
%left '>'
%left MAI_MARE_EGAL
%left '<'
%left MAI_MIC_EGAL

%left SI
%left SAU
%left NEGAT

%left '+'
%left '-'
%left '%'
%left '*'
%left '/'
%left '^'

%%
/*Start*/
program : preMain {printf("Programul este bine definit!\n");}
        ;

/*PreMain*/
preMain : declarari main
        ;

declarari : declarare declarari
          | /*epsilon*/
          ;

/*Declarari*/
declarare : '#' tipSimplu IDENTIFICATOR {
              char* type = $<strval>2;
              char* varId = $<strval>3;
              
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

          | '#' TIP_INTRERUPATOR IDENTIFICATOR {
              char* type = $<strval>2;
              char* varId = $<strval>3;
              
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
          | '#' TIP_INTRERUPATOR IDENTIFICATOR '=' expresieLogica {
              char* type = $<strval>2;
              char* varId = $<strval>3;
              
              string s = varId;
              vector <string> split = splitString(s, " ");
              char* line = new char[split[0].size() + 5];
              char* varName = new char[split[1].size() + 5];
              strcpy(line, split[0].c_str());
              strcpy(varName, split[1].c_str());

              int curLine;

              char* evalResult = $<strval>5;

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

          | '#' tipSimplu IDENTIFICATOR '=' expresie {
              char* type = $<strval>2;
              char* varId = $<strval>3;
              
              string s = varId;
              vector <string> split = splitString(s, " ");
              char* line = new char[split[0].size() + 5];
              char* varName = new char[split[1].size() + 5];
              strcpy(line, split[0].c_str());
              strcpy(varName, split[1].c_str());

              int curLine;

              char* evalResult = $<strval>5;

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

          | '#' TIP_VECTOR '{' TIP_INTRERUPATOR '}' IDENTIFICATOR '[' NR_INTREG ']' {
              char* type = $<strval>4;
              char* quantity = $<strval>8;
              string s_type = "vector_{";
              s_type += type;
              s_type += "}_[";
              s_type += quantity;
              s_type +=  + "]";
              
              char* varId = $<strval>6;
              
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

          | '#' TIP_VECTOR '{' tipSimplu '}' IDENTIFICATOR '[' NR_INTREG ']' {
              char* type = $<strval>4;
              char* quantity = $<strval>8;
              string s_type = "vector_{";
              s_type += type;
              s_type += "}_[";
              s_type += quantity;
              s_type +=  + "]";
              
              char* varId = $<strval>6;
              
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
          
          | '#' TIP_FUNCTIE '{' tipSimplu '}' IDENTIFICATOR '(' declarariParam ')' corpFunctie {
              char* returnType = $<strval>4;
              
              char* varId = $<strval>6;
              
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

              char* bodyFunction = $<strval>10;

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

          | '#' TIP_FUNCTIE '{' TIP_INTRERUPATOR '}' IDENTIFICATOR '(' declarariParam ')' corpFunctie {
              char* returnType = $<strval>4;
              
              char* varId = $<strval>6;
              
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

              char* bodyFunction = $<strval>10;

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
          
          | '#' TIP_OBIECT IDENTIFICATOR INCEPE declarariMembri TERMINA {
              
              string type = "obiect";
              
              char* varId = $<strval>3;
              
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
          ;

declarariParam : declarareParam declarariParam 
               | /*epsilon*/ 
               ;

declarareParam : '#' tipSimplu IDENTIFICATOR 
               | '#' TIP_INTRERUPATOR IDENTIFICATOR

               | '#' TIP_VECTOR '{' tipSimplu '}' IDENTIFICATOR '[' NR_INTREG ']'
               | '#' TIP_VECTOR '{' TIP_INTRERUPATOR '}' IDENTIFICATOR '[' NR_INTREG ']'

               | '#' TIP_FUNCTIE '{' tipSimplu '}' IDENTIFICATOR '(' declarariParam ')'
               | '#' TIP_FUNCTIE '{' TIP_INTRERUPATOR '}' IDENTIFICATOR '(' declarariParam ')'
               ;

declarariMembri : declarareMembru declarariMembri
                | declarareMembru
                ;

declarareMembru : '#' tipSimplu IDENTIFICATOR {
                    char* type = $<strval>2;
                    char* varId = $<strval>3;
                    
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

                | '#' TIP_INTRERUPATOR IDENTIFICATOR {
                    char* type = $<strval>2;
                    char* varId = $<strval>3;
                    
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
                | '#' TIP_INTRERUPATOR IDENTIFICATOR '=' expresieLogica {
                    char* type = $<strval>2;
                    char* varId = $<strval>3;
                    
                    string s = varId;
                    vector <string> split = splitString(s, " ");
                    char* line = new char[split[0].size() + 5];
                    char* varName = new char[split[1].size() + 5];
                    strcpy(line, split[0].c_str());
                    strcpy(varName, split[1].c_str());

                    int curLine;

                    char* evalResult = $<strval>5;

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

                | '#' tipSimplu IDENTIFICATOR '=' expresie {
                    char* type = $<strval>2;
                    char* varId = $<strval>3;
                    
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

                    char* evalResult = $<strval>5;

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

                | '#' TIP_VECTOR '{' tipSimplu '}' IDENTIFICATOR '[' NR_INTREG ']' {
                    char* type = $<strval>4;
                    char* quantity = $<strval>8;
                    string s_type = "vector_{";
                    s_type += type;
                    s_type += "}_[";
                    s_type += quantity;
                    s_type +=  + "]";
                    
                    char* varId = $<strval>6;
                    
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

                  | '#' TIP_VECTOR '{' TIP_INTRERUPATOR '}' IDENTIFICATOR '[' NR_INTREG ']' {
                    char* type = $<strval>4;
                    char* quantity = $<strval>8;
                    string s_type = "vector_{";
                    s_type += type;
                    s_type += "}_[";
                    s_type += quantity;
                    s_type +=  + "]";
                    
                    char* varId = $<strval>6;
                    
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
                
                | '#' TIP_FUNCTIE '{' tipSimplu '}' IDENTIFICATOR '(' declarariParam ')' corpFunctie {
                    char* returnType = $<strval>4;
                    
                    char* varId = $<strval>6;
                    
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

                    char* bodyFunction = $<strval>10;

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

                | '#' TIP_FUNCTIE '{' TIP_INTRERUPATOR '}' IDENTIFICATOR '(' declarariParam ')' corpFunctie {
                    char* returnType = $<strval>4;
                    
                    char* varId = $<strval>6;
                    
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

                    char* bodyFunction = $<strval>10;

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
                ;

corpFunctie : /*epsilon*/ {char* s = new char[10]; strcpy(s, "b");$<strval>$ = s;}
            | INCEPE comenzi RETURNEAZA expresie TERMINA 
              {char* s = new char[10]; strcpy(s, "a");$<strval>$ = s;}
            | INCEPE comenzi RETURNEAZA expresieLogica TERMINA 
              {char* s = new char[10]; strcpy(s, "a");$<strval>$ = s;}
            ;

tipSimplu : TIP_INTREG {$<strval>$ = $<strval>1;}
          | TIP_RATIONAL {$<strval>$ = $<strval>1;}
          | TIP_TEXT {$<strval>$ = $<strval>1;}
          | TIP_CARACTER {$<strval>$ = $<strval>1;}
          | TIP_OBIECT IDENTIFICATOR { 
              string s1 = "obiect"; 
              
              char* varId = $<strval>2;
              
              string sId = varId;
              vector <string> split = splitString(sId, " ");
              char* varName = new char[split[1].size() + 5];
              strcpy(varName, split[1].c_str());

              char* sr = new char[s1.size() +strlen(varName) + 5];
              string s = s1;
              s += "_";
              s += varName;
              strcpy(sr, s.c_str());
              $<strval>$ = sr;
            }
          ;

/*Expresii*/
expresie : expresie '+' expresie /*nr str*/   {
            string l = $<strval>1;
            string r = $<strval>3;
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
              $<strval>$ = c_res;
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
              $<strval>$ = c_res;
            }
            else
            if (l[0] == '2'){
              string s_res = valLeft + valRight;
              s_res = "2$" + s_res;
              char* c_res = new char[s_res.size()+5];
              strcpy(c_res, s_res.c_str());
              $<strval>$ = c_res;
            }
            else{
              cout << "Adunare incompatibila pentru tipurile " << l[0] << "\n";
              cout << "Eroare la linia " << yylineno << "\n";
              return -1;
            }
          }
         | expresie '-' expresie /*nr*/       {
            string l = $<strval>1;
            string r = $<strval>3;
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
              $<strval>$ = c_res;
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
              $<strval>$ = c_res;
            }
            else{
              cout << "Scadere incompatibila pentru tipurile " << l[0] << "\n";
              cout << "Eroare la linia " << yylineno << "\n";
              return -1;
            }
          }
         | expresie '*' expresie /*nr*/       {
            string l = $<strval>1;
            string r = $<strval>3;
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
              $<strval>$ = c_res;
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
              $<strval>$ = c_res;
            }
            else{
              cout << "Inmultire incompatibila pentru tipurile " << l[0] << "\n";
              cout << "Eroare la linia " << yylineno << "\n";
              return -1;
            }
          }
         | expresie '/' expresie /*nr*/       {
            string l = $<strval>1;
            string r = $<strval>3;
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
              $<strval>$ = c_res;
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
              $<strval>$ = c_res;
            }
            else{
              cout << "Impartire incompatibila pentru tipurile " << l[0] << "\n";
              cout << "Eroare la linia " << yylineno << "\n";
              return -1;
            }
          }
         | expresie '%' expresie /*nr*/       {
            string l = $<strval>1;
            string r = $<strval>3;
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
              $<strval>$ = c_res;
            }
            else{
              cout << "Modulo incompatibila pentru tipurile " << l[0] << "\n";
              cout << "Eroare la linia " << yylineno << "\n";
              return -1;
            }
          }
         | expresie '^' expresie /*nr*/       {
            string l = $<strval>1;
            string r = $<strval>3;
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
              $<strval>$ = c_res;
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
              $<strval>$ = c_res;
            }
            else{
              cout << "Ridicare la putere incompatibila pentru tipurile " << l[0] << "\n";
              cout << "Eroare la linia " << yylineno << "\n";
              return -1;
            }
          }
         | NR_INTREG             /*nr*/       {
            char* type = new char[5];
            strcpy(type, "0$");
            char* val = new char[strlen($<strval>1) + 10];
            strcpy(val, type);
            strcat(val, $<strval>1);
            $<strval>$ = val;
          }
         | NR_RATIONAL           /*nr*/       {
            char* type = new char[5];
            strcpy(type, "1$");
            char* val = new char[strlen($<strval>1) + 10];
            strcpy(val, type);
            strcat(val, $<strval>1);
            $<strval>$ = val;
          }
         | TEXT                  /*str*/      {
            char* type = new char[5];
            strcpy(type, "2$");
            char* val = new char[strlen($<strval>1) + 10];
            strcpy(val, type);
            strcat(val, $<strval>1 + 1);
            val[strlen(val)-1] = '\0';
            $<strval>$ = val;
          }
         | CARACTER              /*char*/     {
            char* type = new char[5];
            strcpy(type, "3$");
            char* val = new char[strlen($<strval>1) + 10];
            strcpy(val, type);
            strcat(val, $<strval>1 + 1);
            val[strlen(val)-1] = '\0';
            $<strval>$ = val;
          }
         | IDENTIFICATOR         /*all*/      {
            char* varInfo = $<strval>1;
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
              $<strval>$ = final;
            }
            else{
              cout << "Eroare variabila nedeclarata folosita in expresie la linia: " << line << "\n";
              cout << "Nume variabila: " << nameVar << "\n";
              return -1;
            }

          }
         | apelFunctie           /*all*/      {
            $<strval>$ = $<strval>1;
          }
         | apelObiect            /*all*/      {
            $<strval>$ = $<strval>1;
          }
         | apelVector            /*all*/      {
            $<strval>$ = $<strval>1;
          }
         | '(' expresie ')'      /*nr str*/   {
           $<strval>$ = $<strval>2;
         }
         ;

apelVector : IDENTIFICATOR '[' expresie ']' {
              char* varInfo = $<strval>1;
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

              char* c_vecAcces = $<strval>3;
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

              $<strval>$ = res;

            }
           ;


/*Apel Functie*/
apelFunctie : IDENTIFICATOR '(' listaApel ')' {
                char* varInfo = $<strval>1;
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

                $<strval>$ = res;

              }
            ;

listaApel : /*epsilon*/
          | argumente
          ;

argumente : expresie
          | expresie ',' argumente
          ;

/*Apel Obiect*/
apelObiect : IDENTIFICATOR '.' IDENTIFICATOR {
              
              char* varInfo = $<strval>1;
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

              char* fieldId = $<strval>3;
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

              $<strval>$ = res;


           }
           | IDENTIFICATOR '.' IDENTIFICATOR '(' listaApel ')' {
             char* res = new char[10];
             strcpy(res, "0$0");
             $<strval>$ = res;
           }
           ;

/*Expresie Logica*/
expresieLogica : expresie EGAL expresie {
                  string l = $<strval>1;
                  string r = $<strval>3;
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
                    $<strval>$ = result;
                  }
                  else{
                    char* result = new char[10];
                    strcpy(result, "4$0");
                    $<strval>$ = result;
                  }
                }
               | expresie DIFERIT expresie {
                  string l = $<strval>1;
                  string r = $<strval>3;
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
                    $<strval>$ = result;
                  }
                  else{
                    char* result = new char[10];
                    strcpy(result, "4$0");
                    $<strval>$ = result;
                  }
                }
               | expresie MAI_MARE_EGAL expresie {
                  string l = $<strval>1;
                  string r = $<strval>3;
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
                      $<strval>$ = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      $<strval>$ = result;
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
                      $<strval>$ = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      $<strval>$ = result;
                    }
                  }
                  else{
                    cout << "Comparare incompatibila pentru tipurile " << l[0] << "\n";
                    cout << "Eroare la linia " << yylineno << "\n";
                    return -1;
                  }
                }
               | expresie MAI_MIC_EGAL expresie {
                  string l = $<strval>1;
                  string r = $<strval>3;
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
                      $<strval>$ = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      $<strval>$ = result;
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
                      $<strval>$ = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      $<strval>$ = result;
                    }
                  }
                  else{
                    cout << "Comparare incompatibila pentru tipurile " << l[0] << "\n";
                    cout << "Eroare la linia " << yylineno << "\n";
                    return -1;
                  }
                }
               | expresie '>' expresie {
                  string l = $<strval>1;
                  string r = $<strval>3;
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
                      $<strval>$ = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      $<strval>$ = result;
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
                      $<strval>$ = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      $<strval>$ = result;
                    }
                  }
                  else{
                    cout << "Comparare incompatibila pentru tipurile " << l[0] << "\n";
                    cout << "Eroare la linia " << yylineno << "\n";
                    return -1;
                  }
                }
               | expresie '<' expresie {
                  string l = $<strval>1;
                  string r = $<strval>3;
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
                      $<strval>$ = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      $<strval>$ = result;
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
                      $<strval>$ = result;
                    }
                    else{
                      char* result = new char[10];
                      strcpy(result, "4$0");
                      $<strval>$ = result;
                    }
                  }
                  else{
                    cout << "Comparare incompatibila pentru tipurile " << l[0] << "\n";
                    cout << "Eroare la linia " << yylineno << "\n";
                    return -1;
                  }
                }
               | '(' expresieLogica ')' {$<strval>$ = $<strval>2;}
               | expresieLogica SI expresieLogica {
                  char *l = $<strval>1;
                  char *r = $<strval>3;

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
                    $<strval>$ = result;
                  }
                  else{
                    char* result = new char[10];
                    strcpy(result, "4$0");
                    $<strval>$ = result;
                  }
               }
               | expresieLogica SAU expresieLogica {
                  char *l = $<strval>1;
                  char *r = $<strval>3;

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
                    $<strval>$ = result;
                  }
                  else{
                    char* result = new char[10];
                    strcpy(result, "4$0");
                    $<strval>$ = result;
                  }
                }
               | NEGAT expresieLogica {
                  char *expr = $<strval>2;
                  char c_value = expr[2];
                  int i_value;
                  convert(c_value, i_value);
                  i_value = !i_value;
                  convert(i_value, c_value);
                  
                  char *result = new char[10];
                  strcpy(result, "4$D");
                  result[2] = c_value;

                  $<strval>$ = result;
                }
               | APRINS {
                  char* result = new char[10];
                  strcpy(result, "4$1");
                  $<strval>$ = result;
                }
               | STINS {
                  char* result = new char[10];
                  strcpy(result, "4$0");
                  $<strval>$ = result;
                }
               | '@' IDENTIFICATOR {
                  char* varInfo = $<strval>2;
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
                    $<strval>$ = final;
                  }
                  else{
                    cout << "Eroare: variabila nedeclarata folosita in expresie la linia: " << line << "\n";
                    cout << "Nume variabila: " << nameVar << "\n";
                    return -1;
                  }

                  
                }
               ;

/*MAIN*/
main : PRINCIPAL INCEPE comenzi TERMINA
     ;

comanda : declarare
        | '#' IDENTIFICATOR '=' expresie {
            char* varId = $<strval>2;
            
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

            char* evalResult = $<strval>4;

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

        | '#' IDENTIFICATOR '=' expresieLogica {
            char* varId = $<strval>2;
            
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

            char* evalResult = $<strval>4;

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

        | '#' IDENTIFICATOR '.' IDENTIFICATOR '=' expresie {
              
              char* varInfo = $<strval>2;
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

              char* fieldId = $<strval>4;
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

            char* expresie = $<strval>6;

            if(expresie[0] != res[0]){
              cout<<"Eroare la linia " << line << '\n';
              cout<<"Atribuire intre tipuri incompatibile"<<"\n";
              return -1;
            }

           }
        | '#' apelVector '=' expresie {
          char* valLeft = $<strval>2;
          char* valExpr = $<strval>4;

          if (valLeft[0] != valExpr[0]){
            cout << "Eroare la linia " << yylineno;
            cout << "\nTipuri invalide\n";
            return -1;
          }
        }

        | '#' IDENTIFICATOR '.' IDENTIFICATOR '=' expresieLogica{
              
              char* varInfo = $<strval>2;
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

              char* fieldId = $<strval>4;
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

            char* expresie = $<strval>6;

            if(expresie[0] != res[0]){
              cout<<"Eroare la linia " << line << '\n';
              cout<<"Atribuire intre tipuri incompatibile"<<"\n";
              return -1;
            }

           }
        | '#' apelVector '=' expresieLogica {
          char* valLeft = $<strval>2;
          char* valExpr = $<strval>4;

          if (valLeft[0] != valExpr[0]){
            cout << "Eroare la linia " << yylineno;
            cout << "\nTipuri invalide\n";
            return -1;
          }
        }

        | stareControl
        | '#' AFISEAZA '(' expresie ')' {
            char* result = $<strval>4;
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
        | '#' AFISEAZA '(' expresieLogica ')' {
            char* result = $<strval>4;
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
        | '#' EVAL '(' expresie ')' {
            char* result = $<strval>4;
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
        | '#' INSPECTEAZA '(' IDENTIFICATOR ')' {
            char* result = $<strval>4;
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
        | '#' CITESTE IDENTIFICATOR {
            char* varId = $<strval>3;
            
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
        ;
    
comenzi : comanda comenzi
        | /*epsilon*/
        ;

/*StareControl*/
stareControl : DACA '(' expresieLogica ')' INCEPE comenzi TERMINA altfel
             | CAT_TIMP '(' expresieLogica ')' INCEPE comenzi TERMINA
             | EXECUTA INCEPE comenzi TERMINA PANA_CAND '(' expresieLogica ')'
             | PENTRU '(' continutPentru ')' INCEPE comenzi TERMINA
             ;

varPentru : expresie
          ;

continutPentru : IDENTIFICATOR IN '[' varPentru ',' varPentru ']' PAS '=' varPentru
               ;

altfel : ALTFEL INCEPE comenzi TERMINA
       | /*epsilon*/
       ;
%%

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