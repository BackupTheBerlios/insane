//---------------------------------------------------------------------------
#include "fxTimer.h"
//---------------------------------------------------------------------------

#ifdef _WIN32

#include <windows.h>
#include <winbase.h>

fxTimer::fxTimer()
{
ClassName = "fxTimer";
RegisterObject(this, ClassName);

LARGE_INTEGER t;
QueryPerformanceFrequency(&t);

unsigned int lowpart = (unsigned int)t.LowPart;
unsigned int highpart = (unsigned int)t.HighPart;
lowshift = 0;

while (highpart || (lowpart > 2000000.0))
	{
	lowshift++;
	lowpart >>= 1;
	lowpart |= (highpart & 1) << 31;
	highpart >>= 1;
	}
frequency = (double)lowpart;
firstframe = true;
}

float fxTimer::GetTimeDelta(void)
{
LARGE_INTEGER 	t1;
double          t2, t3;
QueryPerformanceCounter(&t1);
unsigned int temp = ((unsigned int)t1.LowPart >> lowshift) | ((unsigned int)t1.HighPart << (32 - lowshift));
t2 = (double) temp / frequency;
t3 = t2 - lasttime;
lasttime = t2;
if (firstframe)
	{
	starttime = t2;
	firstframe = false;
	return 0;
	}
	else return (float)t3;
}

void fxTimer::RestartTimer(void)
{
firstframe = true;
}

float fxTimer::GetTime(void)
{
LARGE_INTEGER 	t1;
double          t2;
QueryPerformanceCounter(&t1);
unsigned int temp = ((unsigned int)t1.LowPart >> lowshift) | ((unsigned int)t1.HighPart << (32 - lowshift));
t2 = (double) temp / frequency;
if (firstframe)
	{
	starttime = t2;
	firstframe = false;
	return 0;
	}
	else return (float)(t2-starttime);
}


#endif