// insaneFX.cpp : Definiert den Einsprungpunkt f�r die DLL-Anwendung.
//

#include "insaneFX.h"

#ifdef __WIN32

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

#endif