//---------------------------------------------------------------------------
#ifndef fxSceneGraphH
#define fxSceneGraphH
//---------------------------------------------------------------------------

#include "../insanefx.h"
#include "../shared/fxList.h"
#include "../materials/fxMaterial.h"
#include "../math/fxMatrix.h"
#include "../SceneGraph/fxSGNode.h"
#include "../kernel/fxClass.h"
#include "../RenderDevice/fxRenderDevice.h"

class INSANEFX_API fxSceneGraph : public fxClass
	{
	protected:

		fxList MeshNodes;	// the mesh nodes
		fxList LightNodes;	// the light nodes

		fxMaterial 	* cMaterial;
		fxMatrix 	* cMatrix;

	public:

		fxSceneGraph()
			{
			ClassName = "fxSceneGraph";
			RegisterObject(this, ClassName);

			cMaterial = NULL;
			cMatrix = NULL;
			}

		~fxSceneGraph(void)
			{
			UnregisterObject(ClassName);
			}

		void Clear(void);
		void SetMaterial(fxMaterial * material);
		void SetTransform(fxMatrix * matrix);

		fxSGNode * AddMeshNode(void);

		void Render(fxRenderDevice * rd);
	};

#endif
