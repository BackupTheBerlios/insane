//---------------------------------------------------------------------------
#ifndef fxPlaneH
#define fxPlaneH
//---------------------------------------------------------------------------

// fxPlane - this class represents a plane in R3
//	     equation: X*Normal = -Distance  (HESSEsche Normalform)


#include "../insanefx.h"
#include "fxVector.h"

struct INSANEFX_API fxPlaneData
	{
	fxVector Normal;
	float  	 Distance;
	};

class INSANEFX_API fxPlane
	{
	protected:

	fxPlaneData data;

	public:

	fxPlane();
	fxPlane(fxVector normal, float distance);
	fxPlane(fxPlaneData Data);
        fxPlane(fxVector * v1,fxVector * v2,fxVector * v3);

	fxPlane * Clone(void);
	void Copy(fxPlane * plane);

	// constructs a plane from 3 points that lie on the plane
	void FromPoints(fxVector * v1, fxVector * v2, fxVector * v3);

	// returns the distance from the plane
	float Distance(fxVector * v);

	// returns  1 if the point lies in front of the plane
	//         -1 if the point lies behind the plane
	//          0 if the point lies on the plane
	int ClassifyPoint(fxVector * vector);

	};

#endif
