//---------------------------------------------------------------------------
#ifndef fxInterpreterH
#define fxInterpreterH
//---------------------------------------------------------------------------

#include "kernel/fxClass.h"

class fxInterpreter : public fxClass
	{
	protected:

	public:

	fxInterpreter()
		{
                ClassName = "fxInterpreter";
		RegisterObject(this, ClassName);
		}

	~fxInterpreter(void)
		{
                UnregisterObject(ClassName);
		}

	};

#endif
