//---------------------------------------------------------------------------
#ifndef fxSceneNodeH
#define fxSceneNodeH
//---------------------------------------------------------------------------
#include "../insanefx.h"
#include "../shared/fxList.h"
#include "../camera/fxCamera.h"
#include "../RenderDevice/fxRenderDevice.h"
#include "../SceneGraph/fxSceneGraph.h"

class INSANEFX_API fxSceneNode
	{
	protected:

	// the current transformation matrix, only for internal use
	fxMatrix transform;

	public:

	// constructor and destructor
	fxSceneNode();
	fxSceneNode(fxSceneNode * Parent);

	virtual ~fxSceneNode(void);

	// parent node
	fxSceneNode * parent;

	// child nodes
	fxList * ChildList;


	// update transform matrix and child matrices
	virtual void UpdateTransform(fxMatrix * NewTransform);

	// the following 3 functions are called for each object each frame

	// animate this node
	virtual void Advance(float seconds);
	// fill out an scene graph node
	virtual void CreateNode(fxSceneGraph * sg);
	// render
	virtual void Render(void) {};
	};

#endif
