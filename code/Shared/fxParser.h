//---------------------------------------------------------------------------
#ifndef fxParserH
#define fxParserH
//---------------------------------------------------------------------------

#include <stdio.h>

#include "../insanefx.h"

class INSANEFX_API fxParser
	{
	protected:

		FILE * stream;
                bool eof;

		char ReadChar(void);

	public:

		fxParser(FILE * f)
			{
                        stream = f;
			eof = false;
			}

		int GetNextToken(char * result);		

	};

#endif
