%{

    #include<stdio.h>

    int valid=1;

%}

%token digit letter

%%

start : letter s

s :     letter s

      | digit s

      | ;

%%

int yyerror()

{

    printf("\nInvalid String\n");

    valid=0;

    return 0;

}

int main()

{

    printf("\nEnter the string : ");

    yyparse();

    if(valid)

    {

        printf("\nValid String\n");

    }

}
