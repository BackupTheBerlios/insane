//---------------------------------------------------------------------------
#ifndef fxTextureH
#define fxTextureH
//---------------------------------------------------------------------------

#include <malloc.h>
#include <string.h>

#include "../insanefx.h"
#include "../shared/fxLimits.h"
#include "../Kernel/fxVars.h"
#include "../kernel/fxRefClass.h"

class INSANEFX_API fxTexture : public fxRefClass
	{

	friend class fxTextureMng;
	friend class fxLayer;

	protected:

		void * TextureMng;

		char * name;

		bool LoadTGA(char * filename);
		bool LoadBMP(char * filename);
		bool LoadJPG(char * filename);

	public:
		fxTexture(void * texturemng)
			{
			TextureMng = texturemng;
			mem = NULL;
			name =(char*)malloc(MAX_STRING);
			strcpy(name, "default texture");

			clampu=clampv=false;
			mipmap=true;
			}

		~fxTexture()
			{
			if (mem != NULL) free(mem);
			free(name);
			}

		// this is the handle that identifies this texture
		unsigned int handle;
		// this memory holds a copy of the image in 32 bit rgba format
		unsigned char * mem;
		// width of the texture (must be 2^n, n=0,1,2,4,8,16,...)
		int width;
		// height of the texture (must be 2^n, n=0,1,2,4,8,16,...)
		int height;
		// bit depth of the texture (must be 1,2,3 or 4)
		int bpp;

		// clamp flags for u and v directions
		bool clampu;
		bool clampv;

		// generate mipmaps?
		bool mipmap;

		bool Load( char * filename);
	};


#endif
