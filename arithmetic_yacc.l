//lex

%{
#include "y.tab.h"
%}

%%
[a-zA-Z_][a-zA-Z_0-9]*   return id;    // Match identifiers (letters, underscores, followed by alphanumeric)
[0-9]+(\.[0-9]*)?         return num;   // Match numbers (integer or decimal)
[+/*]                     return op;    // Match arithmetic operators (+, *, /)
.                         return yytext[0];  // Match any other single character
\n                        return 0;     // Match newline
%%

int yywrap() {
    return 1;  // Indicates end of input
}

//yacc

%{
#include <stdio.h>
int valid = 1;
%}

%token num id op

%%
start : id '=' s ';' {
            // Code after parsing the rule
        }
s : id x
  | num x
  | '-' num x
  | '(' s ')' x
  ;

x : op s
  | '-' s
  | /* empty */
  ;
%%

int yyerror() {
    valid = 0;
    printf("\nInvalid expression!\n");
    return 0;
}

int main() {
    printf("\nEnter the expression:\n");
    yyparse();
    if (valid) {
        printf("\nValid expression!\n");
    }
    return 0;
}
