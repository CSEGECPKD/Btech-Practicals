%{
#include "y.tab.h"
%}

%%
"int"|"float"   {return type;}
[a-zA-Z_][a-zA-Z0-9_]*   { yylval=strdup(yytext);return ID; }
"("           { return '('; }
")"             { return ')'; }
[ \t]+        { /* ignore spaces */ }
\n              {return NL;}
.               { printf("Unknown character: %s\n", yytext); }
%%

int yywrap() { return 1; }
