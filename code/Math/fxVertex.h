//---------------------------------------------------------------------------
#ifndef fxVertexH
#define fxVertexH
//---------------------------------------------------------------------------

#include "../shared/fxLimits.h"
#include "fxVector.h"
#include "fxPoint.h"
#include "fxColor.h"

struct fxVertex
	{
	fxVectorData	position;
	fxVectorData	normal;
	fxPointData	tc[MAX_UNITS];
	fxColorRGBA	color;
	};

#endif
