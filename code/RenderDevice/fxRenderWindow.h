//---------------------------------------------------------------------------
#ifndef fxRenderWindowH
#define fxRenderWindowH
//---------------------------------------------------------------------------

#include "../insanefx.h"
#include "../kernel/fxClass.h"

class INSANEFX_API fxRenderWindow : public fxClass
	{

	public:

	// pointer to owning renderdevice
	void * rd;

	fxRenderWindow() {};
	~fxRenderWindow(void) {};

	virtual Show(void) {};
	virtual Hide(void) {};

	};

#endif