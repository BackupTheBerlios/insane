//---------------------------------------------------------------------------
#include "fxMaterialMng.h"
#include "assert.h"
//---------------------------------------------------------------------------

int fxMaterialMng::GetMaterialIndex(fxMaterial * m)
{
for (int i=0; i<MaterialCount; i++)
	{
	if (!strcmpi(MaterialList[i]->name,m->name)) return i;
	}
return -1;
}

int fxMaterialMng::GetMaterialIndex(char * name)
{
for (int i=0; i<MaterialCount; i++)
	{
	if (!strcmpi(MaterialList[i]->name,name)) return i;
	}
return -1;
}

void fxMaterialMng::CreateDefaultMaterial(void)
{
fxMaterial * m;
m = new fxMaterial(this);
// the default material MUST exist
assert(m->LoadMaterial("materials/default"));
AddMaterial(m);
}

void fxMaterialMng::AddMaterial(fxMaterial * m)
{
int i = GetMaterialIndex(m);
if (i==-1)
	{
	// this material is not referenced in the scene, so add it
	MaterialList[MaterialCount] = m;
	MaterialCount++;

	// add the textures of the new material to the TextureMng
	for (int j=0; j < m->numlayers; j++)
		{
		for (int t=0; t < m->Layer[j]->nummaps; t++)
			{
			TextureMng->AddTexture(m->Layer[j]->maps[t]);
			}
		}

	}
	else
	{
	// material already referenced and loaded, so dont load it again
        fxMaterial * mat = GetMaterial(i);
	mat->AddRef();
	}
}

void fxMaterialMng::DeleteMaterial(int index)
{
fxMaterial * m = GetMaterial(index);
if (m==NULL) return;
m->Release();
if (m->_RefCount==0)
	{
        // this material is not referenced by any other object and can be deleted
	for (int i=index; i<MaterialCount-1; i++) MaterialList[i] = MaterialList[i+1];
	MaterialList[MaterialCount]=NULL;
	MaterialCount--;
	delete m;
	}
}

void fxMaterialMng::DeleteMaterial(fxMaterial * m)
{
int i = GetMaterialIndex(m);
if (i==-1) return;
DeleteMaterial(i);
}

fxMaterial* fxMaterialMng::GetMaterial(int index)
{
if (index < 0) return NULL;
if (index > MaterialCount-1) return NULL;
return MaterialList[index];
}

void fxMaterialMng::Clear(void)
{
for (int i=0; i<MaterialCount; i++) delete MaterialList[i];
MaterialCount = 0;
}

bool fxMaterialMng::LoadMaterial(char * filename)
{
fxMaterial * m;
m = new fxMaterial(this);
if (m->LoadMaterial(filename))
	{
	this->AddMaterial(m);
	return true;
	}
return false;
}
