// fxRefClass - a simple class that counts its instances

//---------------------------------------------------------------------------
#ifndef fxRefClassH
#define fxRefClassH
//---------------------------------------------------------------------------

#include "../insanefx.h"

class INSANEFX_API fxRefClass
	{
	protected:

	public:

	int _RefCount;	

	fxRefClass()
		{
		_RefCount = 1;
		}

	void AddRef(void)
		{
		_RefCount++;
		}

       void Release(void)
		{
		_RefCount--;
		}
	};
#endif
