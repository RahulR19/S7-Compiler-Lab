%{
    #include<stdio.h>
    #include"y.tab.h"
%}

%%
[0-9]+  { 
            yylval = atoi(yytext);
            return digit;
        }
.       return yytext[0];
\n      return 0;
%%

int yywrap() { return 1; }
