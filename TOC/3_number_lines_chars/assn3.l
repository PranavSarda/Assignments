%{
	int nchars = -1, nwords = 0, nlines = 0;	//nchars -1 coz it is probably counting in EOF too
%}

DIGIT [0-9]+
LINE \n
TAB [ \t\n]+

%%

{LINE}		{ nlines++; nwords++; nchars++; }
{TAB}		{ nwords++; nchars++; }
.		{ nchars++; }

%%

int yywrap()
{
	return 1;
}

int main()
{
	yyin = fopen("myfile.txt","r");		//FILE *yyin
	yylex();
	printf("\n\nChars : %d \nWords : %d \nLines : %d \n\n", nchars, nwords, nlines);
	return 0;
}
