//---------------------------------------------------------------------------
#ifndef fxTimerH
#define fxTimerH
//---------------------------------------------------------------------------

#include "../kernel/fxClass.h"

#include "../insanefx.h"

class INSANEFX_API fxTimer : public fxClass
	{
	private:
		double	frequency;
		double	lasttime;
		double  starttime;
		int 	lowshift;

		bool	firstframe;

		float GetTime(void);
		// returns the number of seconds that have passed since the last call
		float GetTimeDelta(void);
	public:
		fxTimer();

		void Refresh(void);

		float	timedelta;
		float	time;

		void RestartTimer(void);
	};

#endif
