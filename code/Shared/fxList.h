// class fxList - a generic dynamic growing list of pointers

//---------------------------------------------------------------------------
#ifndef fxListH
#define fxListH
//---------------------------------------------------------------------------

#include <stdlib.h>
#include <malloc.h>

#include "../insanefx.h"

class INSANEFX_API fxList
	{
	protected:

	// pointer to an array of pointers
	void *	PointerArray;

	public:

	fxList()
		{
		Count = 0;
		PointerArray = NULL;
		}

	~fxList(void)
		{
		if (PointerArray != NULL) free(PointerArray);
		}

	int Count;

	void Clear(void);
	void Add(void * pointer);
        void Delete(void * pointer);
        void Remove(int index);

	int  GetIndex(void * pointer);

	void * Get(int index);

	};

#endif
