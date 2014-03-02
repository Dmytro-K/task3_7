#include "task3_7_funcs.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main( void )
{
	char *text;
	int num;
	int readed;

	puts( "Enter text:" );
	text = Input();

	for( ;; )
	{
		puts( "Enter number:" );
		readed = scanf( "%d", &num );
		if( readed > 0 && num >0 )
		{
			break;
		}
		else
		{
			puts( "Wrong number" );
		}
	}

	removeWord( text, (size_t)num );

	puts( text );

	return 0;
}