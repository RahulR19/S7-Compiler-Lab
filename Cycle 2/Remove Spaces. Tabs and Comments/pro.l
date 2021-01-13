%{ 
%} 


%% 			
[ \t]+   		    ;
"//".*\n 			;			
"/*"[^*/]*"*/"\n    ;	
%% 

int yywrap(){} //End of processing of Input 

int main() 
{ 

	// yyin and yyout are pointers of File type 
	extern FILE *yyin, *yyout; 

	// yyin points to the file input.c and opens it in read mode
	yyin = fopen("input.c", "r"); 

	// yyout points to the file output.c and opens it in write mode
	yyout = fopen("output.c", "w"); 

	yylex(); // main of lex
	return 0; 
} 


