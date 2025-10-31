%{
#include "y.tab.h"
%}
%%
a {return 'a';}
b {return 'b';}
c {return 'c';}
d {return 'd';}

\n {return NL;}
[ /t]
.  {printf("unknown characaters");}
%%

int yywrap()
{
    return 1;
}