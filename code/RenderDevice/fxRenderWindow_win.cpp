#include "fxRenderWindow_win.h"

#include "../kernel/fxvars.h"
#include "../RenderDevice/fxRenderDevice.h"

fxRenderWindow * rdwnd;

LRESULT CALLBACK fxRenderWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	
	switch( message ) 
	{
		case WM_PAINT:
			hdc = BeginPaint (hWnd, &ps);
			fxRenderDevice * rd;
			rd = (fxRenderDevice*) rdwnd->rd;
			rd->BeginFrame();
			rd->EndFrame();
			EndPaint( hWnd, &ps );
			break;
		case WM_DESTROY:
			PostQuitMessage( 0 );
			break;
		default:
			return DefWindowProc( hWnd, message, wParam, lParam );
   }
   return 0;
}


ATOM fxRenderWindow_win::RegisterClassPlease(void)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)fxRenderWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInst;
	wcex.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= "fxRenderWindow";
	wcex.hIconSm		= LoadIcon(NULL, IDI_APPLICATION);

	return RegisterClassEx(&wcex);
}


BOOL fxRenderWindow_win::CreateWindowPlease(void)
{
   hwnd = CreateWindowEx(0,"fxRenderWindow", "fxRenderWindow", WS_OVERLAPPED | WS_SYSMENU,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInst, NULL);

   return TRUE;
}

fxRenderWindow_win::fxRenderWindow_win()
{
rdwnd = this;
fxVars * var = (fxVars*)this->FindObject("fxVars");
hInst = (HINSTANCE)var->GetIntValue("hinstance");
RegisterClassPlease();
CreateWindowPlease();
}

fxRenderWindow_win::~fxRenderWindow_win(void)
{
DestroyWindow(hwnd);
UnregisterClass("fxRenderWindow",hInst);
rdwnd = NULL;
}

fxRenderWindow_win::Show(void)
{
ShowWindow( hwnd, SW_SHOWNORMAL );
UpdateWindow( hwnd );
}

fxRenderWindow_win::Hide(void)
{
ShowWindow( hwnd, SW_HIDE );
UpdateWindow( hwnd ); // need I call this?
}

