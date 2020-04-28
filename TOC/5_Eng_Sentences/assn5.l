%{	
	#include "y.tab.h"
%}

ARTICLE		the|a|an|The|A\An
NOUN		[A-Za-z]+
PRONOUN		he|she|it|we|I|Me|He|She|It|Me|We
AUXVERB		is|are|am|can|will|eats|drinks
CONJUNCTION	and|or|not
EOS		"."

%%

{AUXVERB}		{ printf("%s\t==>AUX/VERB\n",yytext); return(AUXVERB); }
{ARTICLE}		{ printf("%s\t==>ARTICLE\n",yytext); return(ARTICLE); }
{PRONOUN}		{ printf("%s\t==>PRONOUN\n",yytext); return(PRONOUN); }
{CONJUNCTION}		{ printf("%s\t==>CONJUNCTION\n",yytext); return(CONJUNCTION); }
{NOUN}			{ printf("%s\t==>NOUN\n",yytext); return(NOUN); }
{EOS}			{ printf("%s\t==>EOS(.)\n\n",yytext); return(EOS); }
.			;

%%

int yywrap()
{
	return 1;
}

