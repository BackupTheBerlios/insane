//---------------------------------------------------------------------------
#include "fxLayer.h"
#include "fxTextureMng.h"
//---------------------------------------------------------------------------
fxLayer::~fxLayer(void)
{
fxTextureMng * tm;
for (int i=0; i<nummaps; i++)
	{
	tm = (fxTextureMng*)maps[i]->TextureMng;
	tm->DeleteTexture(maps[i]);
	}
}

