//---------------------------------------------------------------------------
#include "fxSceneGraph.h"
#include "../kernel/fxConsole.h"
//---------------------------------------------------------------------------

void fxSceneGraph::Clear(void)
{
for (int i=0; i < MeshNodes.Count; i++)
	{
    fxSGNode * sgnode = (fxSGNode*)MeshNodes.Get(i);
	delete sgnode;
	}
MeshNodes.Clear();

for (i=0; i < LightNodes.Count; i++)
	{
	}
LightNodes.Clear();
}

void fxSceneGraph::SetMaterial(fxMaterial * material)
{
cMaterial = material;
}

void fxSceneGraph::SetTransform(fxMatrix * matrix)
{
cMatrix = matrix;
}

fxSGNode * fxSceneGraph::AddMeshNode(void)
{
fxSGNode * node;
node = new fxSGNode;
node->material = cMaterial;
node->position = cMatrix;
MeshNodes.Add(node);
return node;
}

void fxSceneGraph::Render(fxRenderDevice * rd)
{
rd->BeginFrame();

for (int i=0; i < MeshNodes.Count; i++)
	{
	fxSGNode * node = (fxSGNode*)MeshNodes.Get(i);
	rd->SetMaterial(node->material);
	rd->DrawBuffer(node->mesh->Vertex, node->mesh->VertexCount, node->mesh->Index, node->mesh->IndexCount);
	}

rd->EndFrame();
}

