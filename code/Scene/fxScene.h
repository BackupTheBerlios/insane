//---------------------------------------------------------------------------
#ifndef fxSceneH
#define fxSceneH
//---------------------------------------------------------------------------

#include "../insanefx.h"
#include "../kernel/fxClass.h"

#include "../shared/fxLimits.h"
#include "../camera/fxCamera.h"
#include "../Scene/fxSceneNode.h"
#include "../RenderDevice/fxRenderDevice.h"
#include "../scene/fxMeshNode/fxMeshMng.h"

class INSANEFX_API fxScene : public fxClass
	{
	protected:

	fxRenderDevice * rd;

	void Reset(void);
	void CreateSceneGraph(void);

	public:

	fxMeshMng * MeshMng;
	fxMaterialMng * MaterialMng;
        fxSceneGraph * SceneGraph;

	fxScene();
	~fxScene(void)
		{
		UnregisterObject("fxScene");
		delete Root;
		delete MeshMng;
		delete SceneGraph;
		}

	fxSceneNode * Root;

	void Advance(float seconds);
	void Render(void);
	};

#endif
