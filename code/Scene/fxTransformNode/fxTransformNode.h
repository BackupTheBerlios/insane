//---------------------------------------------------------------------------
#ifndef fxTransformNodeH
#define fxTransformNodeH
//---------------------------------------------------------------------------

#include "scene/fxSceneNode.h"

class fxTransformNode : public fxSceneNode
	{
	protected:

	fxMatrix matrix; 

	public:

	virtual void UpdateTransform(fxMatrix * NewTransform);	

	// animate this node
	virtual void Advance(float seconds);
	// fill out an scene graph node
	virtual void CreateNode(fxSceneGraph * sg);
	// render
	virtual void Render(void) {};
	};

#endif
