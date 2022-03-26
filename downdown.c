/************************  
	Downdown.c original
 	https://fukenko.hatenablog.com/entry/2014/09/11/073327

 	Porte Fusion C 
 	Marcelo P Santos
 	26/03/2022

 ************************/

#include <stdio.h>
#include "fusion-c/header/msx_fusion.h"
#include <stdlib.h>

void initscr()
{
	Cls(); 
	Screen(1);
	Width(32); /* width 32 */
}

main()
{
	int a;
	char b, c, d, e;
	a = 0;
	c = 0;
	d = 0;
	initscr();
	c = d + 8;
	do {
	    //vpoke(0x1920 + c, 86);		/* ｼﾞｷ ﾋｮｳｼﾞ */
	    Vpoke(0x1920 + c,86);
	    Locate(d,23);
	    //puts("ﾛﾛﾛﾛ        ﾛﾛﾛﾛ\n");	/* ｶﾍﾞ ﾋｮｳｼﾞ */
	    Print("|_|_|_|        |_|_|_|\n");
	    b=JoystickRead(0);                  
	    c = c + (b == 3 && a > 9) - (b == 7 && a > 9);	/* ｼﾞｷ ｲﾄﾞｳ */
	    //d = d + rnd(7) - 3;
	    d = d+ rand()%6;
	    d = d - (d > 4 ) * 3 + (d < 1) * 3;
	    //e = vpeek(0x1920 + c);		/* ｼｮｳｶﾞｲﾌﾞﾂ ｹﾝｼｭﾂ */
	    e = Vpeek(0x1920 + c);
	    a = a + 1;				/* ｽｺｱ ｶｻﾝ*/
	    } while (e == 32);			/* ｱﾀﾘ ﾊﾝﾃｲ */
	  	//printf("%d", a);			/* ｽｺｱ ﾋｮｳｼﾞ */
	    PrintNumber(a);
}