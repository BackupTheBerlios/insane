//---------------------------------------------------------------------------
#include "fxMaterial.h"
#include "fxMaterialMng.h"
#include "fxTextureMng.h"
#include "../shared/fxParser.h"
#include <stdio.h>
//---------------------------------------------------------------------------

bool fxMaterial::LoadMaterial(char * filename)
{
strcpy(this->name,filename);

FILE * f;
strcat(filename,".material");
f = fopen(filename, "rt");
if (f == NULL) return false;

fxParser * p;
p = new fxParser(f);

char * token;
token = (char*)malloc(256);

while (p->GetNextToken(token) == 0)
	{
	// material cull mode
	if (!strcmpi(token,"cullmode"))
		{
		p->GetNextToken(token);
		if (!strcmpi(token,"front")) this->CullMode = IFX_CULL_FRONT;
		if (!strcmpi(token,"back")) this->CullMode = IFX_CULL_BACK;
		if (!strcmpi(token,"none")) this->CullMode = IFX_CULL_NONE;
		}

	if (!strcmpi(token,"layer"))
		{
		// parse one layer
		p->GetNextToken(token);
		if (strcmpi(token,"{")) return false;

		fxLayer * layer = new fxLayer(this);

		while (strcmpi(token,"}"))
			{
			p->GetNextToken(token);

                        // layer blend mode
			if (!strcmpi(token, "blendmode"))
				{
				p->GetNextToken(token);
                if (!strcmpi(token,"replace")) layer->BlendMode = IFX_BLEND_REPLACE;
				if (!strcmpi(token,"modulate")) layer->BlendMode = IFX_BLEND_MODULATE;
				if (!strcmpi(token,"add")) layer->BlendMode = IFX_BLEND_ADD;
				if (!strcmpi(token,"alpha")) layer->BlendMode = IFX_BLEND_ALPHA;
				}

			if (!strcmpi(token,"texture"))
				{
				// parse one texture map
				p->GetNextToken(token);
				if (strcmpi(token,"{")) return false;

				fxMaterialMng * matmng = (fxMaterialMng*)this->MaterialMng;
				fxTextureMng * texmng = (fxTextureMng*)matmng->TextureMng;

				fxTexture * tex = new fxTexture(texmng);

				while (strcmpi(token,"}"))
					{
					p->GetNextToken(token);

					// clamp u direction ?
					if (!strcmpi(token,"clampu"))
						{
						p->GetNextToken(token);
						if (strcmpi(token,"0")) tex->clampu = 0;
						  else tex->clampu = 1;
						}
					// clamp v direction ?
					if (!strcmpi(token,"clampv"))
						{
						p->GetNextToken(token);
						if (strcmpi(token,"0")) tex->clampv = 0;
						  else tex->clampv = 1;
						}
					// texture map
					if (!strcmpi(token,"map"))
						{
						p->GetNextToken(token);
						tex->Load(token);
						}
					// generate mip maps?
					if (!strcmpi(token,"mipmap"))
						{
						p->GetNextToken(token);
						if (strcmpi(token,"0")) tex->mipmap = false;
						  else tex->mipmap = true;
						}
					}

				layer->nummaps++;
				layer->maps[layer->nummaps-1] = tex;
				} // texture parsed

			}

		this->numlayers++;
		this->Layer[numlayers-1] = layer;
		} // layer parsed

	}
free(token);
fclose(f);
return true;
}
