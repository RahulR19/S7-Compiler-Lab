%{ 
#include <stdio.h>
%} 

%%                                            
exit\n                      return 0;
.*[Rr]+[Aa]+[Hh]+[Uu].*\n   return 1;       
.*\n                        return 2;       
%% 

int yywrap(){}

int main()       
{               
    int rep;
    do
    {	printf("\nEnter the word : ");
        rep = yylex();
        if(rep==1) printf("%scontains rahu as substring\n", yytext);
        else if(rep==2) printf("%sdoes not contain rahu as substring\n", yytext);
    } while(rep);
}


