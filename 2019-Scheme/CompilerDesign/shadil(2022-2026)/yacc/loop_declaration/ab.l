%{
#include "y.tab.h"
%}

%%
"for"           { return FOR; }
[a-zA-Z_][a-zA-Z0-9_]*   { return ID; }
[0-9]+          { return NUM; }
"++"            { return INC; }
"="             { return '='; }
"<"             { return '<'; }
"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
";"             { return ';'; }
[ \t]+        { /* ignore spaces */ }
\n              {return NL;}
.               { printf("Unknown character: %s\n", yytext); }
%%

int yywrap() { return 1; }
