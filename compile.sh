yacc -d a.y &&
lex a.l &&
g++ lex.yy.c y.tab.c -ll -ly -w &&
./a.out ex.ro