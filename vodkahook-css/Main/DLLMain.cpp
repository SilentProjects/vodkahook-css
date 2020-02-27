#include "..\SDK\Includes.h"

unsigned long __stdcall Setup( _In_ LPVOID Reserved ) {
	Console::Open( );
	Console::Print( "Test!" );

	while ( !GetAsyncKeyState( VK_DELETE ) )
		Sleep( 50 ); // ((((VERY TEMPORARY))))

	Console::Close( );

	FreeLibraryAndExitThread( ( HMODULE )Reserved, 0 );
}

BOOL WINAPI DllMain( _In_ HINSTANCE Instance, _In_ DWORD Reason, _In_ LPVOID Reserved  ) {
	if ( Reason == DLL_PROCESS_ATTACH ) {
		auto ThreadHandle = CreateThread( NULL, NULL, Setup, Instance, NULL, NULL );

		CloseHandle( ThreadHandle ); // IMAGINE LEAKING UPON INJECTION COULDNT BE ME
	}
	return TRUE;
}