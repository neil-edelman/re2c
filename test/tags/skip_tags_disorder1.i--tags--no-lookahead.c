/* Generated by re2c */

{
	YYCTYPE yych;
	yyt1 = NULL;
	yyt2 = YYCURSOR;
	goto yy0;
yy1:
yy0:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':
		++YYCURSOR;
		goto yy3;
	default:	goto yy2;
	}
yy2:
	a = yyt1;
	{}
yy3:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR++;
	yyt1 = yyt2;
	yyt2 = YYCURSOR;
	goto yy1;
}

tags/skip_tags_disorder1.i--tags--no-lookahead.re:3:14: warning: rule matches empty string [-Wmatch-empty-string]
tags/skip_tags_disorder1.i--tags--no-lookahead.re:3:14: warning: tag 'a' has 2nd degree of nondeterminism [-Wnondeterministic-tags]