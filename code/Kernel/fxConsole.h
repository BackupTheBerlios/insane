//---------------------------------------------------------------------------
#ifndef fxConsoleH
#define fxConsoleH
//---------------------------------------------------------------------------

#include "../insanefx.h"

#include "../kernel/fxClass.h"
#include "../shared/fxList.h"
#include "../shared/fxConst.h"

//#include "kernel/fxConsoleWindow.h"

class INSANEFX_API fxConsole : public fxClass
	{
	protected:

	static fxList StringList;

	// very ugly hack, use a borland vcl window for output
//	TfxConsoleForm * Form;

	public:

	fxConsole()
		{
		ClassName = "fxConsole";
		RegisterObject(this, ClassName);

//		Form = new TfxConsoleForm(NULL);

		DisplayString(IFX_VERSION_STRING);
		DisplayString("");
		}

	~fxConsole(void)
		{
		UnregisterObject(ClassName);
		}

	virtual void DisplayString(char * s);
    virtual void DisplayError(char * s);


	};

#endif
