%{
#include "y.tab.h"
%}

%%
[0-9]+ {yyval=atoi(yytext);return NUM;)}
'+' {return PLUS;}
'-' {return MINUS;}
'*' {return MUL;}
'/' {return DIV;}
[ \t] 
. {return yytext[0];}
%%
int yywrap() { return 1; }
