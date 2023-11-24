%{
#include <stdio.h>
%}

%%
^xxa*bb$    { printf("Cadena válida: %s\n", yytext); }
.           { printf("Cadena no válida: %s\n", yytext); }

%%
int main(void) {
    yylex();
    return 0;
}