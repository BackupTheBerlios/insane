//---------------------------------------------------------------------------
#include "fxScene.h"
#include "../kernel/fxConsole.h"
#include "../materials/fxMaterialMng.h"
#include "../SceneGraph/fxSceneGraph.h"
//---------------------------------------------------------------------------

fxScene::fxScene()
{
ClassName = "fxScene";
RegisterObject(this, ClassName);

Root = new fxSceneNode;

rd = (fxRenderDevice*)FindObject("fxRenderDevice");
if (rd==NULL)
	{
	fxConsole * Console = (fxConsole*)FindObject("fxConsole");
	if (Console != NULL) Console->DisplayError("no fxRenderDevice found");
	}

MaterialMng = new fxMaterialMng;

MeshMng = new fxMeshMng;
SceneGraph = new fxSceneGraph;
}

void fxScene::Advance(float seconds)
{
Root->Advance(seconds);
}

void fxScene::Render(void)
{
CreateSceneGraph();
//Root->Render();
}

void fxScene::CreateSceneGraph(void)
{
SceneGraph->Clear();
Root->CreateNode(SceneGraph);
SceneGraph->Render(rd);
}
