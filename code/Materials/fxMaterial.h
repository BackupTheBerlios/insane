//
//	This file contains the class fxMaterial. A material is used to
//	describe how a surface is rendered. It may have a bump map, an
//	environment map and several texture layers.
//

//---------------------------------------------------------------------------
#ifndef fxMaterialH
#define fxMaterialH
//---------------------------------------------------------------------------

#include "../insanefx.h"
#include "../kernel/fxRefClass.h"
#include "../shared/fxLimits.h"
#include "../shared/fxConst.h"
#include "../materials/fxLayer.h"

class INSANEFX_API fxMaterial : public fxRefClass
	{

	friend class fxMaterialMng;

	protected:

                void *	MaterialMng;

	public:
		fxMaterial(void * materialmng)
			{
			MaterialMng = materialmng;
			numlayers = 0;
			bumpmap = NULL;
			envmap = NULL;
			CullMode = IFX_CULL_BACK;
			name = (char*)malloc(MAX_STRING);
			strcpy(name,"default material");
			}

		~fxMaterial(void)
			{
                        for (int i=0; i<numlayers; i++) delete Layer[i];
			free(name);
			}

		bool LoadMaterial(char * filename);			

		// global material flags

		char * name;

		int			CullMode;

        int			numlayers;
        fxLayer	*	Layer[MAX_LAYERS];
		fxTexture *	bumpmap;
		fxTexture * envmap;
        };

#endif
