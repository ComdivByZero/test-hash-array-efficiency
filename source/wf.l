%%
([a-zA-Z_])([a-zA-Z_0-9])*		puts(yytext);
([\t\v\n\f])					;
.								;
%%