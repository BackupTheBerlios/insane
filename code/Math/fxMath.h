#ifndef fxMathH
#define fxMathH

#define	PI 3.14159265358979323846
#define EPSILON 1.19e-07f

#define fxMax(a,b)      (((a) > (b)) ? (a) : (b))
#define fxMin(a,b)      (((a) < (b)) ? (a) : (b))
#define fxAbs(a)        ((a<0.0f) ? (-a) : (a))
#define fxSgn(a)        ((a<0.0f) ? (-1) : (1))

#define DEG2RAD( a ) ( ( (a) * PI ) / 180.0F )
#define RAD2DEG( a ) ( ( (a) * 180.0f ) / PI )

//----------------------------------------------------------------------------
// quaternion functions
//----------------------------------------------------------------------------
/*
void QuaternionFromAngles( const fxVector angles, fxQuaternion& quaternion );
void QuaternionToMatrix( const fxQuaternion quaternion, fxMatrix& matrix );
void QuaternionSlerp( const fxQuaternion p, fxQuaternion q, float t, fxQuaternion& qt);
*/

//---------------------------------------------------------------------------
#endif
