//---------------------------------------------------------------------------
#include "../kernel/fxConsole.h"
#include "fxTextureMng.h"
#include "fxMaterialMng.h"
#include "../renderdevice/fxRenderDevice.h"
//---------------------------------------------------------------------------

int fxTextureMng::GetTextureIndex(fxTexture * m)
{
for (int i=0; i<TextureCount; i++)
	{
	if (strcmpi(TextureList[i]->name,m->name)==0) return i;
	}
return -1;
}

int fxTextureMng::GetTextureIndex(char * name)
{
for (int i=0; i<TextureCount; i++)
	{
	if (strcmpi(TextureList[i]->name,name)==0) return i;
	}
return -1;
}

void fxTextureMng::CreateDefaultTexture(void)
{
fxTexture * t;
t = new fxTexture(this);
t->mipmap=false;
t->name="$whiteimage";
t->width=16;
t->height=16;
t->bpp=3;
t->mem = (unsigned char*) malloc(16*16*3);
memset(t->mem,255,16*16*3);

AddTexture(t);
}

void fxTextureMng::AddTexture(fxTexture * m)
{
int i = GetTextureIndex(m);
if (i==-1)
	{
	// this Texture is not referenced in the scene, so add it
	TextureList[TextureCount] = m;
	TextureCount++;

	fxRenderDevice * rd = (fxRenderDevice*)FindObject("fxRenderDevice");
	if (rd==NULL)
		{
		fxConsole * Console = (fxConsole*)FindObject("fxConsole");
		if (Console != NULL) Console->DisplayError("unable to upload texture, no fxRenderDevice found");
		}

	rd->RegisterTexture(m);
	}
	else
	{
	// Texture already referenced and loaded, so dont load it again
	fxTexture * tex = GetTexture(i);
	tex->AddRef();
	}
}

void fxTextureMng::DeleteTexture(int index)
{
fxTexture * m = GetTexture(index);
if (m==NULL) return;
m->Release();
if (m->_RefCount==0)
	{
	// this Texture is not referenced by any other material and can be deleted
	for (int i=index; i<TextureCount-1; i++) TextureList[i] = TextureList[i+1];
	TextureList[TextureCount]=NULL;
	TextureCount--;

	fxRenderDevice * rd = (fxRenderDevice*)FindObject("fxRenderDevice");
	if (rd==NULL)
		{
		fxConsole * Console = (fxConsole*)FindObject("fxConsole");
		if (Console != NULL) Console->DisplayError("unable to delete texture, no fxRenderDevice found");
		}

	rd->UnregisterTexture(m);
	delete m;
	}
}

void fxTextureMng::DeleteTexture(fxTexture * m)
{
int i = GetTextureIndex(m);
if (i==-1) return;
DeleteTexture(i);
}

fxTexture* fxTextureMng::GetTexture(int index)
{
if (index < 0) return NULL;
if (index > TextureCount-1) return NULL;
return TextureList[index];
}
