//---------------------------------------------------------------------------
#ifndef fxRenderWindow_winH
#define fxRenderWindow_winH
//---------------------------------------------------------------------------

#include "../insanefx.h"
#include "fxRenderWindow.h"

class INSANEFX_API fxRenderWindow_win : public fxRenderWindow
	{
protected:

	HINSTANCE	hInst;
	ATOM		WindowClass;
	
	virtual ATOM RegisterClassPlease(void);
	virtual BOOL CreateWindowPlease(void);

	public:

	HWND		hwnd;
		
	fxRenderWindow_win();
	~fxRenderWindow_win(void);

	virtual Show(void);
	virtual Hide(void);

	};

#endif