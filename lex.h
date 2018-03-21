DIGIT			[0-9]
TEXT_NUMBERS	[a-zA-Z0-9_]
STRING 			[a-zA-Z0-9_ ]
NUM 			{DIGIT}+
DOT				"."
FLOAT 			{NUM}{DOT}{NUM}
BOOLCONST 		"true"|"false"
STRING1 		\"{STRING}*\"
STRING2 		\'{STRING}*\'
ASSIGN 			":"|"="
ARITHMETIC_OP 	SUM_OP|MUL_OP|ASSIGN
SUM_OP 			"+"|"-"
MUL_OP 			"*"|"/"
LOGICAL_OP 		"&"|"|"
UNARY_OP 		"!"|"++"|"--"
RELATIONAL_OP 	">"|"<"|">="|"<="|"=="|"!="
IDENTIFIER 		{ID}|{ARRAY_ID}|{CLASS_ID}
CLASS_ID 		[A-Z]{TEXT_NUMBERS}*
ARRAY_ID 		[a-z]{TEXT_NUMBERS}*"["{NUM}"]"|[a-z{TEXT_NUMBERS}*"["{ID}"]"
ID 				[a-z]{TEXT_NUMBERS}*
KEYWORD 		"int"|"bool"|"string"|"float"|"print"|"read"|"if"|"else"|"while"|"for"
DELIMITER 		"\n"|";"|","|"."
WHITESPACE 		[ \t]
BRACKETS 		"{"|"}"|"["|"]"|"("|")"

%%

{FLOAT}			{ printf("<FLOATCONST,%s>\n", yytext); }
{NUM}			{ printf("<NUMCONST,%s>\n", yytext); }
{STRING2}		{ printf("<STRINGCONST,%s>\n", yytext); }
{STRING1}		{ printf("<STRINGCONST,%s>\n", yytext); }
{BOOLCONST}		{ printf("<BOOLCONST,%s>", yytext); }
{DELIMITER}		{ printf("<DELIMITER,%s>\n", yytext); }
{KEYWORD}		{ printf("<KEYWORD,%s>\n", yytext); }
{CLASS_ID}		{ printf("<CLASS_ID,%s>\n", yytext); }
{ARRAY_ID}		{ printf("<ARRAY_ID,%s>\n", yytext); }
{ID}			{ printf("<IDENTIFIER,%s>\n", yytext); }
{SUM_OP}		{ printf("<OPERATOR,%s>\n", yytext); }
{MUL_OP}		{ printf("<OPERATOR,%s>\n", yytext); }
{ASSIGN}		{ printf("<OPERATOR,%s>\n", yytext); }
{LOGICAL_OP}	{ printf("<OPERATOR,%s>\n", yytext); }
{UNARY_OP}		{ printf("<OPERATOR,%s>\n", yytext); }
{RELATIONAL_OP}	{ printf("<OPERATOR,%s>\n", yytext); }
{BRACKETS}		{ printf("<BRACKETS,%s>\n", yytext); }
{WHITESPACE}	{ printf("<WHITESPACE,%s>\n", yytext); }

%%

int main(int argc, char *argv[]) {
	yylex();
	return 0;
}















