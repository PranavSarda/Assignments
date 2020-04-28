%{
	FILE *yyin;
	int yylex();
	void yyerror(const char *s);
%}

%name parse
%token ARTICLE NOUN PRONOUN AUXVERB CONJUNCTION EOS

%%

start : | simple start | compound start ;

simple : subject AUXVERB object EOS { printf("\nThis is a Simple Sentence.\n"); } ;

compound : subject AUXVERB object CONJUNCTION subject AUXVERB object EOS { printf("\nThis is a Compound Sentence.\n"); } 
	| subject AUXVERB object CONJUNCTION AUXVERB object EOS { printf("\nThis is a Compound Sentence.\n"); } ;

subject : ARTICLE NOUN | ARTICLE PRONOUN | NOUN | PRONOUN ;

object : ARTICLE NOUN | ARTICLE PRONOUN | NOUN | PRONOUN ;

%%

void yyerror(const char *s )
{ 
	fprintf(stderr, "ERROR: %s\n",s);
}

int main()
{
	yyin = fopen("input.txt","r");
	yyparse();
	fclose(yyin);
	
	return 0;
}
