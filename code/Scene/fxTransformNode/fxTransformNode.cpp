//---------------------------------------------------------------------------
#include "fxTransformNode.h"
//---------------------------------------------------------------------------

void fxTransformNode::Advance(float seconds)
{
fxSceneNode::Advance(seconds);
}

void fxTransformNode::CreateNode(fxSceneGraph * sg)
{
sg->SetTransform(&matrix);
}

void fxTransformNode::UpdateTransform(fxMatrix * NewTransform)
{
fxMatrix result(matrix);
result.Multiply(NewTransform);

result.Copy(&matrix);
result.Copy(&transform);

for (int i=0; i < ChildList->Count; i++)
	{
	fxSceneNode * so = (fxSceneNode*) ChildList->Get(i);
	so->UpdateTransform(&transform);
	}

}
