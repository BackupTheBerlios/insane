//---------------------------------------------------------------------------
#ifndef fxVarsH
#define fxVarsH
//---------------------------------------------------------------------------

#include "../insanefx.h"
#include "../shared/fxList.h"
#include "../kernel/fxClass.h"

class INSANEFX_API fxVars : public fxClass {
        private:

		fxList *IntVars, *FloatVars, *StringVars;

	public:

		fxVars();
		~fxVars(void);

		void NewIntVar( char* name, int value, int flags );
		void NewFloatVar( char* name, float value, int flags );
		void NewStringVar( char* name, char* value, int flags );

		int    GetIntValue ( char* name );
		float  GetFloatValue ( char* name );
		char*  GetStringValue ( char* name );

		bool   VarExists ( char * name);

		// default return values
		int   StdIntValue;
		float StdFloatValue;
		char* StdStringValue;

		void SaveToFile( char * name );
	};

#endif
