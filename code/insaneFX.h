
// Der folgende ifdef-Block zeigt die Standardlösung zur Erstellung von Makros, die das Exportieren
// aus einer DLL vereinfachen. Alle Dateien in dieser DLL wurden mit dem in der Befehlszeile definierten
// Symbol INSANEFX_EXPORTS kompiliert. Dieses Symbol sollte für kein Projekt definiert werden, das
// diese DLL verwendet. Auf diese Weise betrachtet jedes andere Projekt, dessen Quellcodedateien diese Datei
// einbeziehen, INSANEFX_API-Funktionen als aus einer DLL importiert, während diese DLL mit diesem
// Makro definierte Symbole als exportiert betrachtet.

#ifdef INSANEFX_EXPORTS
	#define INSANEFX_API __declspec(dllexport)
#else
	#define INSANEFX_API __declspec(dllimport)
#endif



#ifdef _WIN32

	// compiling under windows...

	#define WIN32_LEAN_AND_MEAN  // faster windows.h processing
	#include <windows.h>

#else

	// compiling not under windows, assuming linux
	//#define _LINUX
	#ifdef __linux__
	  #ifdef INSANEFX_API
	  #undef INSANEFX_API
	  #endif
	  #define INSANEFX_API
	#endif
	// josef, das ist dein gebiet

#endif
