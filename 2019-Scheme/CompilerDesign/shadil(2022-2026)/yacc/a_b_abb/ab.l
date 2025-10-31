%{
#include "y.tab.h"
%}

%%
a   { return 'a'; }
b   { return 'b'; }
\n  { return 0; }   /* End of input */
[ \t] ;
.   { return yytext[0]; }
%%
int yywrap() { return 1; }
