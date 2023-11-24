%{
#include <stdio.h>
%}

%%
^\(?([0-9]{3})\)?-?([0-9]{3})-?([0-9]{4})$   { printf("Número de teléfono válido: %s\n", yytext); }
.                                           { printf("Número de teléfono no válido: %s\n", yytext); }

%%
int main(void) {
    yylex();
    return 0;
}