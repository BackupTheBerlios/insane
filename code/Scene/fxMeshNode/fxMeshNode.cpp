//---------------------------------------------------------------------------
#include "fxMeshNode.h"
#include "../../SceneGraph/fxSGNode.h"
//---------------------------------------------------------------------------

fxMeshNode::fxMeshNode()
{
Mesh = NULL;
}

fxMeshNode::~fxMeshNode(void)
{
Mesh->Release();
}

void fxMeshNode::CreateNode(fxSceneGraph * sg)
{
fxSGNode * node = sg->AddMeshNode();
node->mesh = Mesh;
}
