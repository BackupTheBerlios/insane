//---------------------------------------------------------------------------
#ifndef fxClassH
#define fxClassH
//---------------------------------------------------------------------------

#include "../insanefx.h"
#include "../shared/fxList.h"

class INSANEFX_API fxClass
	{
	protected:

	char * ClassName;

	private:

	static fxList ObjectList;

	public:

	void * FindObject(char * ObjectName);

	void RegisterObject(void * ObjectPointer, char * ObjectName);
	void UnregisterObject(char * ObjectName);
	};

#endif
