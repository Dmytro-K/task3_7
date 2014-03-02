#include "task3_7_funcs.h"

#include <stdio.h>
#include <stdlib.h>
//#include <memory.h>
#include <string.h>

size_t StrLen( const char* str )
{
	size_t i;
	if( str == NULL ) {
		return 0;
	}
	for( i = 0;; i++ ) {
		if( *str == 0 ) {
			break;
		}
		str++;
	}
	return i;
}

bool IsDigit( char chr )
{
	return chr >= 0x30 && chr <= 0x39;
}

bool IsUpper( char chr )
{
	return chr >= 0x41 && chr <= 0x5A;
}

bool IsLower( char chr )
{
	return chr >= 0x61 && chr <= 0x7A;
}

bool IsAlpha( char chr )
{
	return IsUpper( chr ) || IsLower( chr );
}

bool IsAlnum( char chr )
{
	return IsDigit( chr ) || IsAlpha( chr );
}

void removeWord( char * str, size_t num )
{
	size_t i, len;

	while( !( IsAlnum( *str ) || *str == '_' ) )
	{
		if( *str == 0 )
		{
			goto EXIT;
		}
		str++;
	}

	for( i=1; i < num; i++ )
	{
		while( IsAlnum( *str ) || *str == '_' || *str == '-' )
		{
			str++;
		}
		while( !( IsAlnum( *str ) || *str == '_' || *str == '-' ) )
		{
			if( *str == 0 )
			{
				goto EXIT;
			}
			str++;
		}
	}

	if( *str == 0 )
	{
		goto EXIT;
	}

	len = 0;
	while( IsAlnum( str[len] ) || str[len] == '_' || str[len] == '-' )
	{
		len++;
	}

	if( str[len] == ' ' )
	{
		len++;
	}
	else
	{
		if( str[-1] == ' ' )
		{
			len++;
			str--;
		}
	}
	memmove( str, str + len, StrLen( str + len ) + 1 );
EXIT:
	return;
}

#define BUF_LEN 256

char* Input( void )
{
	char buffer[BUF_LEN];
	char *str = NULL;
	size_t lastLen;

	lastLen = 0;

	for( ;; ) {
		size_t len;
		char *tmp;
		fgets( buffer, BUF_LEN, stdin );
		len = StrLen( buffer );

		if( len == 1 ) {
			break;
		}

		if( buffer[len - 1] == '\n' ) {
			len--;
		}

		tmp = realloc( str, lastLen + len + 1 );
		if( tmp == NULL ) {
			free( str );
			return NULL;
		} else {
			str = tmp;
		}
		memcpy( str + lastLen, buffer, len );
		lastLen += len;
		str[lastLen] = 0;
	}

	return str;
}

#undef BUF_LEN