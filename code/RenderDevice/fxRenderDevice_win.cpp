//---------------------------------------------------------------------------
#include "fxRenderDevice.h"
#include "fxRenderWindow_win.h"

#include <assert.h>
//---------------------------------------------------------------------------

#ifdef _WIN32

void fxRenderDevice::OpenWindow(void)
{
wnd = new fxRenderWindow_win;
wnd->rd = this;

fxVars * vars = (fxVars*)FindObject("fxVars");
//if (vars != NULL) vars->NewIntVar("hwnd",*(int*)wnd->hwnd,0);
}

#endif