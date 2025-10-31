%{
#include "y.tab.h"
%}

%%
"int"|"float"   {return type;}
[a-zA-Z_][a-zA-Z0-9_]*   { yyval=strdup(yytext);return ID; }
[0-9]+          { return NUM; }
"="             { return '='; }

[ \t]+        { /* ignore spaces */ }
\n              {return NL;}
.               { printf("Unknown character: %s\n", yytext); }
%%

int yywrap() { return 1; }
