//---------------------------------------------------------------------------
#ifndef fxSGNodeH
#define fxSGNodeH
//---------------------------------------------------------------------------

#include "../insanefx.h"
#include "../materials/fxMaterial.h"
#include "../math/fxMatrix.h"
#include "../Scene/fxMeshNode/fxMesh.h"

class INSANEFX_API fxSGNode
	{
	protected:


	public:

		fxMaterial 	* material;
		fxMatrix 	* position;	

		fxMesh 		* mesh;
	};

#endif
