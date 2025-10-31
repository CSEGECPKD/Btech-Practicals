%{
#include "y.tab.h"
%}
%%
a {return 'a';}
b {return 'b';}

\n {return NL;}
[ /t]
.  {printf("unknown characaters");}
%%

int yywrap()
{
    return 1;
}