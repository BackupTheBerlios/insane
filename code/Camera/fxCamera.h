//---------------------------------------------------------------------------
#ifndef fxCameraH
#define fxCameraH
//---------------------------------------------------------------------------

#include "../insanefx.h"
#include "../math/fxMath.h"
#include "../math/fxVector.h"

class INSANEFX_API fxCamera
	{
	public:
		fxCamera();

		fxVector	position;
		fxVector	direction;
		float		DepthOfView;

		// frustum clipping planes
		float		leftplane, rightplane, topplane, bottomplane, nearplane, farplane;
	};

#endif
