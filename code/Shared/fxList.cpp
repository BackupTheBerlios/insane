//---------------------------------------------------------------------------
#include "fxList.h"
#include <assert.h>
//---------------------------------------------------------------------------

void fxList::Clear(void)
{
if (PointerArray != NULL) free(PointerArray);
PointerArray = NULL;
Count = 0;
}

void fxList::Add(void * pointer)
{
Count++;
PointerArray = realloc(PointerArray, 4 * Count);
assert(PointerArray);

int * tp = (int*)PointerArray;
tp += Count-1;
*tp = (int)pointer;
}

void fxList::Remove(int index)
{
for (int i=index; i < Count - 1; i++)
	{
	int * tp1 = (int*)PointerArray;
	tp1 += i;
	int * tp2 = (int*)PointerArray;
	tp2 += i+1;
	*tp1 = *tp2;
	}
Count--;
PointerArray = realloc(PointerArray, Count * 4);
assert(PointerArray);
}

void fxList::Delete(void * pointer)
{
int index = GetIndex(pointer);
if (index == -1) return;
Remove(index);
}

int fxList::GetIndex(void * pointer)
{
for (int i=0; i < Count; i++)
	{
	int * tp = (int*)PointerArray;
	tp += i;
	if (*tp == (int)pointer) return i;
	}
return -1;
}

void * fxList::Get(int index)
{
int * tp = (int*)PointerArray;
tp += index;
return (void*)*tp;
}
