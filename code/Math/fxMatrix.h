//---------------------------------------------------------------------------
#ifndef fxMatrixH
#define fxMatrixH
//---------------------------------------------------------------------------

#include "../insanefx.h"

class fxVector;

typedef float fxMatrixData[4][4];

class INSANEFX_API fxMatrix
	{
	public:

        // the actual 4x4 matrix data
	fxMatrixData data;

	// creates a new fxMatrix object containing the same data
	fxMatrix * Clone(void);

	// copies the data into another matrix object
    void Copy(fxMatrix * matrix);

	// clears all fields to 0
	void Clear(void);

	// resets to identity matrix
	void Identity(void);

	// multiplies the matrix by a translation matrix
	void Translate(float x, float y, float z);
    void Translate(fxVector * vector);

	// multiplies the matrix by a rotation matrix
	void Rotate(float x, float y, float z, float angle);
    void Rotate(fxVector * axis, float angle); 

	// rotate about local coordinate axis
	void RotateLocalX(float v);
	void RotateLocalY(float v);
	void RotateLocalZ(float v);

	// rotate about global coordinate axis
	void RotateGlobalX(float v);
	void RotateGlobalY(float v);
	void RotateGlobalZ(float v);

	// multiplies the matrix by a scale matrix
	void Scale(float x, float y, float z);

	// multiplies the matrix by an arbitrary matrix
	void Multiply(fxMatrix * matrix);

	// invert whole matrix
	fxMatrix * Invert(void);

	// invert rotation part of matrix
	fxMatrix * InvertRotation(void);

	};

#endif
