//---------------------------------------------------------------------------
#ifndef fxTextureMngH
#define fxTextureMngH
//---------------------------------------------------------------------------

#include "../insanefx.h"
#include "../kernel/fxClass.h"
#include "fxTexture.h"

class INSANEFX_API fxTextureMng : public fxClass
	{
	protected:
		fxTexture * TextureList[MAX_MATERIALS];
		int			TextureCount;

		void		CreateDefaultTexture(void);

		void *		MaterialMng;

	public:

		fxTextureMng(void * materialmng)
			{
			ClassName = "fxTextureMng";
			RegisterObject(this, ClassName);
			MaterialMng = materialmng;
			TextureCount = NULL;
			for (int i=0; i<MAX_TEXTURES; i++) TextureList[i] = NULL;
			CreateDefaultTexture();
			}

		~fxTextureMng(void)
			{
                        UnregisterObject(ClassName);
			}

		void AddTexture(fxTexture * m);
                fxTexture * LoadTexture(char * filename); 

		void DeleteTexture(int index);
		void DeleteTexture(fxTexture * m);
		fxTexture * GetTexture(int index);

		int  GetTextureIndex(fxTexture * m);
		int  GetTextureIndex(char * name);

	};

#endif
