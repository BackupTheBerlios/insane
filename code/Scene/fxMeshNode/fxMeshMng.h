//---------------------------------------------------------------------------
#ifndef fxMeshMngH
#define fxMeshMngH
//---------------------------------------------------------------------------

#include "../../insanefx.h"
#include "../../kernel/fxClass.h" 
#include "../../Scene/fxMeshNode/fxMesh.h"

class INSANEFX_API fxMeshMng : public fxClass
	{
	protected:

	int _FindMesh(char * name);

	public:

	fxMeshMng()
		{
		ClassName = "fxMeshMng";
		RegisterObject(this, ClassName);
		}

	~fxMeshMng(void)
		{
		UnregisterObject(ClassName);
		}

	fxList MeshList;		

	void LoadFile(char * name);

	fxMesh * FindMesh(char * name);

	};

#endif
