%{
#include "y.tab.h"
%}

%%
a {return A;}
b {return B;}
\n {return NL;}
[\t]; 
 

%%

int yywrap()
{
  return 1;
}


