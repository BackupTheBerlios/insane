//---------------------------------------------------------------------------
#ifndef fxMaterialMngH
#define fxMaterialMngH
//---------------------------------------------------------------------------

#include "../insanefx.h"
#include "../kernel/fxClass.h"
#include "../shared/fxLimits.h"
#include "../Materials/fxMaterial.h"
#include "../Materials/fxTextureMng.h"

class INSANEFX_API fxMaterialMng : public fxClass
	{
	protected:

		fxMaterial * 	MaterialList[MAX_MATERIALS];
		int		MaterialCount;

		void		CreateDefaultMaterial(void);

	public:

		fxMaterialMng()
			{
			ClassName = "fxMaterialMng";
			RegisterObject(this, ClassName);

			MaterialCount = NULL;
			for (int i=0; i<MAX_MATERIALS; i++) MaterialList[i] = NULL;

			TextureMng = new fxTextureMng(this);

			CreateDefaultMaterial();
			}

		~fxMaterialMng(void)
			{
			UnregisterObject(ClassName);
			Clear();
			delete TextureMng;
			}

		fxTextureMng *	TextureMng;

		void AddMaterial(fxMaterial * m);
		bool LoadMaterial(char * filename);

		void DeleteMaterial(int index);
		void DeleteMaterial(fxMaterial * m);
		fxMaterial * GetMaterial(int index);

		int  GetMaterialIndex(fxMaterial * m);
		int  GetMaterialIndex(char * name);

		void Clear(void);

	};

#endif
