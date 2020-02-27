#include "..\SDK\Includes.h"

bool Console::Open( ) {
	if ( !AllocConsole( ) )
		return false;

	freopen_s( ( FILE** )stdin, "CONIN$", "r", stdin );
	freopen_s( ( FILE** )stdout, "CONOUT$", "w", stdout );
	SetConsoleTitle( "Debug Console" );

	return true;
}

bool Console::Close( ) {
	fclose( ( FILE* )stdin );
	fclose( ( FILE* )stdout );
	if ( !FreeConsole( ) )
		return false;

	return true;
}

void Console::Print( std::string Message ) {
	printf_s( "%s\n", Message.c_str( ) );
}