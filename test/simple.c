
#line 1 "simple.re"
#define	NULL		((char*) 0)
char *scan(char *p){
char *q;
#define	YYCTYPE		char
#define	YYCURSOR	p
#define	YYLIMIT		p
#define	YYMARKER	q
#define	YYFILL(n)

#line 6 "<stdout>"
{
	YYCTYPE yych;
	goto yy0;
	++YYCURSOR;
yy0:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy2;
	default:	goto yy4;
	}
yy2:	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy7;
yy3:
#line 10 "simple.re"
{return YYCURSOR;}
#line 32 "<stdout>"
yy4:	++YYCURSOR;
	goto yy5;
yy5:
#line 11 "simple.re"
{return NULL;}
#line 38 "<stdout>"
yy6:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy7;
yy7:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy6;
	default:	goto yy3;
	}
}
#line 12 "simple.re"

}
