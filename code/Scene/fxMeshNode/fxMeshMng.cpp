//---------------------------------------------------------------------------
#include "fxMeshMng.h"
#include "3D Studio 3DS/3DSimport.h"
#include <string.h>
#include <stdio.h>
//---------------------------------------------------------------------------

int fxMeshMng::_FindMesh(char * name)
{
for (int i=0; i < MeshList.Count; i++)
	{
	fxMesh * m = (fxMesh*)MeshList.Get(i);
	if (strcmp(m->name,name)==0) return i;
	}
return -1;
}

fxMesh * fxMeshMng::FindMesh(char * name)
{
for (int i=0; i < MeshList.Count; i++)
	{
	fxMesh * m = (fxMesh*)MeshList.Get(i);
	if (strcmp(m->name,name)==0) return m;
	}
return NULL;
}

void fxMeshMng::LoadFile(char * name)
{
FILE * f;
f = fopen(name, "rb");
import3DS(f, this);
fclose(f);
}
