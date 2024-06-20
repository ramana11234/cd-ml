//lex

%{
#include <stdio.h>
#include "y.tab.h"  // Include yacc generated header file
%}

%%
[0-9]+(\.[0-9]+)? { 
    yylval.dval = atof(yytext);  // Convert matched digits to double
    return DIGIT;
}
\n     { 
    return yytext[0];  // Return newline character
}
.      { 
    return yytext[0];  // Return any other single character
}
%%

int yywrap() {
    return 1;
}

//yacc

%{
#include <stdio.h>
#include <stdlib.h>
%}

%union {
    double dval;
}

%token <dval> DIGIT
%type <dval> expr term factor

%%
line: expr '\n' { 
        printf("%g\n", $1);  // Print evaluated result
     }
     ;

expr: expr '+' term { 
        $$ = $1 + $3;  // Addition operation
     }
    | expr '-' term {
        $$ = $1 - $3;  // Subtraction operation
    }
    | term
    ;

term: term '*' factor { 
        $$ = $1 * $3;  // Multiplication operation
     }
    | term '/' factor {
        if ($3 == 0) {
            yyerror("division by zero");
            exit(1);
        }
        $$ = $1 / $3;  // Division operation
    }
    | factor
    ;

factor: '(' expr ')' { 
          $$ = $2;  // Parenthesized expression
       }
      | DIGIT { 
          $$ = $1;  // Numeric value
       }
      ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    return yyparse();
}
