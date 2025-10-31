%{
#include "y.tab.h"
%}

%%

a { return A; }
b { return B; }
c { return C; }
\n { return NL; }
[ \t] ; 
. { printf("Unknown character\n"); }

%%

int yywrap()
{
 return 1;
}