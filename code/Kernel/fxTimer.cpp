#include "fxTimer.h"

// get new time and time-since-last-call
void fxTimer::Refresh(void)
{
timedelta = GetTimeDelta();
time = GetTime();
}
