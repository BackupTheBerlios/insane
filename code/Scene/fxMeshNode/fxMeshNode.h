//---------------------------------------------------------------------------
#ifndef fxMeshNodeH
#define fxMeshNodeH
//---------------------------------------------------------------------------

#include "../../insanefx.h"
#include "../fxSceneNode.h"

class INSANEFX_API fxMeshNode : public fxSceneNode
	{
	public:

		fxMeshNode();
		~fxMeshNode(void);

		fxMesh * Mesh;

		virtual void Advance(float seconds) {};
		virtual void CreateNode(fxSceneGraph * sg);
		virtual void Render(void) {};
	};

#endif
