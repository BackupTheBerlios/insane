#include "fxMath.h"

/*
void QuaternionFromAngles( const fxVector angles, fxQuaternion& quaternion )
{
float		angle;
float		sr, sp, sy, cr, cp, cy;

angle = angles[2] * 0.5;
sy = sin(angle);
cy = cos(angle);
angle = angles[1] * 0.5;
sp = sin(angle);
cp = cos(angle);
angle = angles[0] * 0.5;
sr = sin(angle);
cr = cos(angle);

quaternion[0] = sr*cp*cy-cr*sp*sy; // X
quaternion[1] = cr*sp*cy+sr*cp*sy; // Y
quaternion[2] = cr*cp*sy-sr*sp*cy; // Z
quaternion[3] = cr*cp*cy+sr*sp*sy; // W
}


void QuaternionToMatrix( const fxQuaternion quaternion, fxMatrix& matrix )
{
matrix[0][0] = 1.0 - 2.0 * quaternion[1] * quaternion[1] - 2.0 * quaternion[2] * quaternion[2];
matrix[1][0] = 2.0 * quaternion[0] * quaternion[1] + 2.0 * quaternion[3] * quaternion[2];
matrix[2][0] = 2.0 * quaternion[0] * quaternion[2] - 2.0 * quaternion[3] * quaternion[1];

matrix[0][1] = 2.0 * quaternion[0] * quaternion[1] - 2.0 * quaternion[3] * quaternion[2];
matrix[1][1] = 1.0 - 2.0 * quaternion[0] * quaternion[0] - 2.0 * quaternion[2] * quaternion[2];
matrix[2][1] = 2.0 * quaternion[1] * quaternion[2] + 2.0 * quaternion[3] * quaternion[0];

matrix[0][2] = 2.0 * quaternion[0] * quaternion[2] + 2.0 * quaternion[3] * quaternion[1];
matrix[1][2] = 2.0 * quaternion[1] * quaternion[2] - 2.0 * quaternion[3] * quaternion[0];
matrix[2][2] = 1.0 - 2.0 * quaternion[0] * quaternion[0] - 2.0 * quaternion[1] * quaternion[1];
}

void QuaternionSlerp( const fxQuaternion p, fxQuaternion q, float t, fxQuaternion& qt)
{
int i;
float omega, cosom, sinom, sclp, sclq;

// decide if one of the quaternions is backwards
float a = 0;
float b = 0;
for (i = 0; i < 4; i++)
  {
  a += (p[i]-q[i])*(p[i]-q[i]);
  b += (p[i]+q[i])*(p[i]+q[i]);
  }
if (a > b)
  {
  for (i = 0; i < 4; i++)
    {
    q[i] = -q[i];
    }
  }

cosom = p[0]*q[0] + p[1]*q[1] + p[2]*q[2] + p[3]*q[3];

if ((1.0 + cosom) > 0.00000001)
  {
  if ((1.0 - cosom) > 0.00000001)
    {
    omega = acos( cosom );
    sinom = sin( omega );
    sclp = sin( (1.0 - t)*omega) / sinom;
    sclq = sin( t*omega ) / sinom;
    }
  else
    {
    sclp = 1.0 - t;
    sclq = t;
    }
  for (i = 0; i < 4; i++)
    {
    qt[i] = sclp * p[i] + sclq * q[i];
    }
  }
else
  {
  qt[0] = -p[1];
  qt[1] = p[0];
  qt[2] = -p[3];
  qt[3] = p[2];
  sclp = sin( (1.0 - t) * 0.5 * PI);
  sclq = sin( t * 0.5 * PI);
  for (i = 0; i < 3; i++)
    {
    qt[i] = sclp * p[i] + sclq * qt[i];
    }
  }
}

*/
