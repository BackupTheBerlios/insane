//---------------------------------------------------------------------------
#include "fxPlane.h"
//---------------------------------------------------------------------------

#define Delta     0.00001

fxPlane::fxPlane()
{
}

fxPlane::fxPlane(fxVector normal, float distance)
{
data.Normal = normal;
data.Distance = distance;
}

fxPlane::fxPlane(fxPlaneData Data)
{
data = Data;
}

fxPlane::fxPlane(fxVector * v1,fxVector * v2,fxVector * v3)
{
FromPoints(v1,v2,v3);
}

fxPlane * fxPlane::Clone(void)
{
fxPlane * p;
p = new fxPlane(data);
return p;
}

void fxPlane::Copy(fxPlane * plane)
{
plane->data.Normal = data.Normal;
plane->data.Distance = data.Distance;
}

void fxPlane::FromPoints(fxVector * v1, fxVector * v2, fxVector * v3)
{
fxVector edge1(v1->data), edge2(v1->data);
edge1.Sub(v2);
edge2.Sub(v3);
edge1.Normalize();
edge2.Normalize();

data.Normal = *edge1.CrossProduct(&edge2);
data.Normal.Normalize();

data.Distance = -v1->DotProduct(&data.Normal);
}

int fxPlane::ClassifyPoint(fxVector * vector)
{
float d = Distance(vector);
if (d > Delta) return 1;
if (d < -Delta) return -1;
return 0;
}

float fxPlane::Distance(fxVector * v)
{
return data.Normal.DotProduct(v) + data.Distance;
}
