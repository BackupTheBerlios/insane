//---------------------------------------------------------------------------
#include "fxSceneNode.h"
//---------------------------------------------------------------------------

fxSceneNode::fxSceneNode()
{
ChildList = new fxList;
parent = NULL;
transform.Identity();
}

fxSceneNode::fxSceneNode(fxSceneNode * Parent)
{
ChildList = new fxList;
parent = Parent;
}

fxSceneNode::~fxSceneNode(void)
{
for (int i=0; i < ChildList->Count; i++)
	{
	fxSceneNode * so = (fxSceneNode*) ChildList->Get(i);
	delete so;
	}
delete ChildList;

if (parent != NULL) parent->ChildList->Delete(this);
}

void fxSceneNode::Advance(float seconds)
{
for (int i=0; i < ChildList->Count; i++)
	{
	fxSceneNode * so = (fxSceneNode*) ChildList->Get(i);
	so->Advance(seconds);
	}
}

void fxSceneNode::UpdateTransform(fxMatrix * NewTransform)
{
NewTransform->Copy(&transform);
for (int i=0; i < ChildList->Count; i++)
	{
	fxSceneNode * so = (fxSceneNode*) ChildList->Get(i);
	so->UpdateTransform(NewTransform);
	}
}

void fxSceneNode::CreateNode(fxSceneGraph * sg)
{
for (int i=0; i < ChildList->Count; i++)
	{
	fxSceneNode * so = (fxSceneNode*) ChildList->Get(i);
	so->CreateNode(sg);
	}
}
