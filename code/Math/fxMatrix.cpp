//---------------------------------------------------------------------------
#include "fxMatrix.h"
#include "fxVector.h"
#include <math.h>
#include <memory.h>
//---------------------------------------------------------------------------

fxMatrix * fxMatrix::Clone(void)
{
fxMatrix * temp;
temp = new fxMatrix;
Copy(temp);
return temp;
}

void fxMatrix::Copy(fxMatrix * matrix)
{
memcpy(matrix->data, data, sizeof(fxMatrixData));
}


void fxMatrix::Clear(void)
{
for (int i=0; i<4; i++)
	{
	for (int j=0; j<4; j++)
		{
		data[i][j] = 0;
		}
	}
}

void fxMatrix::Identity(void)
{
Clear();
data[0][0] = 1;
data[1][1] = 1;
data[2][2] = 1;
data[3][3] = 1;
}

void fxMatrix::Translate(float x, float y, float z)
{
fxMatrix temp;
temp.Identity();
temp.data[0][3] = x;
temp.data[1][3] = y;
temp.data[2][3] = z;
Multiply(&temp);
}

void fxMatrix::Translate(fxVector * vector)
{
fxMatrix temp;
temp.Identity();
temp.data[0][3] = vector->data[0];
temp.data[1][3] = vector->data[1];
temp.data[2][3] = vector->data[2];
Multiply(&temp);
}

void fxMatrix::Rotate(float x, float y, float z, float angle)
{
float sine = (float)sin(angle);
float cosine = (float)cos(angle);
float one_minus_cosine=1-cosine;

fxVector Axis(x,y,z); 

if (Axis.Normalize()==0) return;

fxMatrix temp;
temp.Identity();

temp.data[0][0]=(one_minus_cosine*(Axis.data[0]*Axis.data[0]))+cosine;
temp.data[0][1]=(one_minus_cosine*Axis.data[0]*Axis.data[1])-(Axis.data[2]*sine);
temp.data[0][2]=(one_minus_cosine*Axis.data[2]*Axis.data[0])+(Axis.data[1]*sine);
temp.data[0][3]=0;

temp.data[1][0]=(one_minus_cosine*Axis.data[0]*Axis.data[1])+(Axis.data[2]*sine);
temp.data[1][1]=(one_minus_cosine*(Axis.data[1]*Axis.data[1]))+cosine;
temp.data[1][2]=(one_minus_cosine*Axis.data[1]*Axis.data[2])-(Axis.data[0]*sine);
temp.data[1][3]=0;

temp.data[2][0]=(one_minus_cosine*Axis.data[2]*Axis.data[0])-(Axis.data[1]*sine);
temp.data[2][1]=(one_minus_cosine*Axis.data[1]*Axis.data[2])+(Axis.data[0]*sine);
temp.data[2][2]=(one_minus_cosine*(Axis.data[2]*Axis.data[2]))+cosine;
temp.data[2][3]=0;

temp.data[3][0]=0;
temp.data[3][1]=0;
temp.data[3][2]=0;
temp.data[3][3]=1;
}

void fxMatrix::Rotate(fxVector * axis, float angle)
{
float sine = (float)sin(angle);
float cosine = (float)cos(angle);
float one_minus_cosine=1-cosine;

fxVector Axis(axis->data);

if (Axis.Normalize()==0) return;

fxMatrix temp;
temp.Identity();

temp.data[0][0]=(one_minus_cosine*(Axis.data[0]*Axis.data[0]))+cosine;
temp.data[0][1]=(one_minus_cosine*Axis.data[0]*Axis.data[1])-(Axis.data[2]*sine);
temp.data[0][2]=(one_minus_cosine*Axis.data[2]*Axis.data[0])+(Axis.data[1]*sine);
temp.data[0][3]=0;

temp.data[1][0]=(one_minus_cosine*Axis.data[0]*Axis.data[1])+(Axis.data[2]*sine);
temp.data[1][1]=(one_minus_cosine*(Axis.data[1]*Axis.data[1]))+cosine;
temp.data[1][2]=(one_minus_cosine*Axis.data[1]*Axis.data[2])-(Axis.data[0]*sine);
temp.data[1][3]=0;

temp.data[2][0]=(one_minus_cosine*Axis.data[2]*Axis.data[0])-(Axis.data[1]*sine);
temp.data[2][1]=(one_minus_cosine*Axis.data[1]*Axis.data[2])+(Axis.data[0]*sine);
temp.data[2][2]=(one_minus_cosine*(Axis.data[2]*Axis.data[2]))+cosine;
temp.data[2][3]=0;

temp.data[3][0]=0;
temp.data[3][1]=0;
temp.data[3][2]=0;
temp.data[3][3]=1;
}

void fxMatrix::RotateLocalX(float v)
{
fxMatrix temp;
temp.Identity();
float sine = (float)sin(v);
float cosine = (float)cos(v);

temp.data[0][0] = 1.0;
temp.data[0][1] = 0.0;
temp.data[0][2] = 0.0;

temp.data[1][0] = 0.0;
temp.data[1][1] = cosine;
temp.data[1][2] = -sine;

temp.data[2][0] = 0.0;
temp.data[2][1] = sine;
temp.data[2][2] = cosine;

Multiply(&temp);
}

void fxMatrix::RotateLocalY(float v)
{
fxMatrix temp;
temp.Identity();
float sine = (float)sin(v);
float cosine = (float)cos(v);

temp.data[0][0] = cosine;
temp.data[0][1] = 0.0;
temp.data[0][2] = sine;

temp.data[1][0] = 0.0;
temp.data[1][1] = 1.0;
temp.data[1][2] = 0.0;

temp.data[2][0] = -sine;
temp.data[2][1] = 0.0;
temp.data[2][2] = cosine;

Multiply(&temp);
}

void fxMatrix::RotateLocalZ(float v)
{
fxMatrix temp;
temp.Identity();
float sine = (float)sin(v);
float cosine = (float)cos(v);

temp.data[0][0] = cosine;
temp.data[0][1] = -sine;
temp.data[0][2] = 0.0;

temp.data[1][0] = sine;
temp.data[1][1] = cosine;
temp.data[1][2] = 0.0;

temp.data[2][0] = 0.0;
temp.data[2][1] = 0.0;
temp.data[2][2] = 1.0;

Multiply(&temp);
}

void fxMatrix::RotateGlobalX(float v)
{
fxMatrix temp;
temp.Identity();
float sine = (float)sin(v);
float cosine = (float)cos(v);

temp.data[0][0] = 1.0;
temp.data[0][1] = 0.0;
temp.data[0][2] = 0.0;

temp.data[1][0] = 0.0;
temp.data[1][1] = cosine;
temp.data[1][2] = -sine;

temp.data[2][0] = 0.0;
temp.data[2][1] = sine;
temp.data[2][2] = cosine;

Multiply(&temp);
}

void fxMatrix::RotateGlobalY(float v)
{
fxMatrix temp;
temp.Identity();
float sine = (float)sin(v);
float cosine = (float)cos(v);

temp.data[0][0] = cosine;
temp.data[0][1] = 0.0;
temp.data[0][2] = sine;

temp.data[1][0] = 0.0;
temp.data[1][1] = 1.0;
temp.data[1][2] = 0.0;

temp.data[2][0] = -sine;
temp.data[2][1] = 0.0;
temp.data[2][2] = cosine;

Multiply(&temp);
}

void fxMatrix::RotateGlobalZ(float v)
{
fxMatrix temp;
temp.Identity();
float sine = (float)sin(v);
float cosine = (float)cos(v);

temp.data[0][0] = cosine;
temp.data[0][1] = -sine;
temp.data[0][2] = 0.0;

temp.data[1][0] = sine;
temp.data[1][1] = cosine;
temp.data[1][2] = 0.0;

temp.data[2][0] = 0.0;
temp.data[2][1] = 0.0;
temp.data[2][2] = 1.0;

Multiply(&temp);
}

void fxMatrix::Scale(float x, float y, float z)
{
fxMatrix temp;
temp.Identity();
temp.data[0][0] = x;
temp.data[1][1] = y;
temp.data[2][2] = z;
Multiply(&temp);
}

void fxMatrix::Multiply(fxMatrix * matrix)
{
fxMatrix temp;

for (int i = 0; i<=3; i++)
	{
	for (int j = 0; j<=3; j++)
		{
		temp.data[i][j]=matrix->data[i][0]*data[0][j]+
				matrix->data[i][1]*data[1][j]+
				matrix->data[i][2]*data[2][j]+
				matrix->data[i][3]*data[3][j];
		}
	}
temp.Copy(this);
}

fxMatrix * fxMatrix::Invert(void)
{
fxMatrix * temp;
temp = new fxMatrix;
temp->data[0][0] = data[0][0];
temp->data[0][1] = data[1][0];
temp->data[0][2] = data[2][0];
temp->data[0][3] = 0.0;

temp->data[1][0] = data[0][1];
temp->data[1][1] = data[1][1];
temp->data[1][2] = data[2][1];
temp->data[1][3] = 0.0;

temp->data[2][0] = data[0][2];
temp->data[2][1] = data[1][2];
temp->data[2][2] = data[2][2];
temp->data[2][3] = 0.0;

temp->data[3][0] = -( data[3][0] * temp->data[0][0] + data[3][1] * temp->data[1][0] + data[3][2] * temp->data[2][0] );
temp->data[3][1] = -( data[3][0] * temp->data[0][1] + data[3][1] * temp->data[1][1] + data[3][2] * temp->data[2][1] );
temp->data[3][2] = -( data[3][0] * temp->data[0][2] + data[3][1] * temp->data[1][2] + data[3][2] * temp->data[2][2] );
temp->data[3][3] = 1.0f;
return temp;
}

fxMatrix * fxMatrix::InvertRotation(void)
{
fxMatrix * temp;
temp = Clone();

// Swap elements across the diagonal.
temp->data[1][0] = data[0][1];
temp->data[0][1] = data[1][0];

temp->data[2][0] = data[0][2];
temp->data[0][2] = data[2][0];

temp->data[2][1] = data[1][2];
temp->data[1][2] = data[2][1];

return temp;
}

