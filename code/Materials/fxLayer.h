//
//	This file contains the class fxLayer, which is used to describe
//	one layer of a material. 
//

//---------------------------------------------------------------------------
#ifndef fxLayerH
#define fxLayerH
//---------------------------------------------------------------------------

#include "../insanefx.h"
#include "../shared/fxConst.h"
#include "../shared/fxLimits.h"
#include "fxTexture.h"

class INSANEFX_API fxLayer
	{
	private:

		void *	Material;

	public:
	fxLayer(void * material)
		{
		Material = material;
		BlendMode = IFX_BLEND_REPLACE;
		nummaps = 0;
		}

	~fxLayer(void);

	int		BlendMode;

	fxTexture *     maps[MAX_MAPS];
	int				nummaps;
	};

#endif
