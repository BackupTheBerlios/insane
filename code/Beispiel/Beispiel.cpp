#include "stdafx.h"

#include "../insanefx.h"
#include "../kernel/fxConsole.h"
#include "../kernel/fxVars.h"
#include "../kernel/fxTimer.h"
#include "../RenderDevice/OpenGL/fxGL.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow )
{
fxConsole * Console = new fxConsole;
fxVars *	Vars = new fxVars;
fxTimer *	Timer = new fxTimer;

fxRenderDevice * rd = new fxGL;
rd->OpenWindow();

// main message loop, standart windows stuff...
MSG msg;
while( GetMessage(&msg, NULL, 0, 0) ) 
{
	TranslateMessage( &msg );
	DispatchMessage( &msg );
}
rd->CloseWindow();

return msg.wParam;

}



