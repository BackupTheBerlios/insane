//---------------------------------------------------------------------------
#include "fxRenderDevice.h"

#include <assert.h>
//---------------------------------------------------------------------------

void fxRenderDevice::CloseWindow(void)
{
assert(wnd);
delete wnd;
wnd = NULL;
}
