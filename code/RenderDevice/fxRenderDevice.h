//---------------------------------------------------------------------------
#ifndef fxRenderDeviceH
#define fxRenderDeviceH
//---------------------------------------------------------------------------

#include "../insanefx.h"

#include "../kernel/fxClass.h"
#include "../kernel/fxTimer.h"
#include "../kernel/fxVars.h"

#include "../Math/fxVertex.h"
#include "../Camera/fxCamera.h"

#include "../materials/fxTexture.h"
#include "../materials/fxMaterial.h"

#ifdef _WIN32
#include "fxRenderWindow.h"
#endif

class INSANEFX_API fxRenderDevice : public fxClass
	{
	protected:

		fxVars * Vars;
		fxTimer * Timer;

		fxRenderWindow * wnd;

	public:

		fxRenderDevice()
			{
			ClassName = "fxRenderDevice";
			RegisterObject(this, ClassName);

			Vars = NULL;
			Timer = NULL;
			}

		virtual ~fxRenderDevice(void)
			{
			UnregisterObject("RenderDevice");
			}

		// open and close render window
		virtual void OpenWindow(void);
		virtual void CloseWindow(void);

		// resize window or viewport
		virtual void Resize(int x, int y, int width, int height, int windowwidth, int windowheight){};

		// start drawing a frame
		virtual void BeginFrame(void){};
		// end drawing a frame
		virtual void EndFrame(void){};

		// draws triangle lists
		virtual void DrawBuffer(fxVertex * VertexList, int VertexCount, int * IndexList, int IndexCount){};

		// uploads the texture data to the video hardware
		virtual void RegisterTexture(fxTexture * t){};
		// deletes an uploaded texture
		virtual void UnregisterTexture(fxTexture * t){};

		// set current camera
		virtual void SetCamera (fxCamera* cam){};

		// set current material
		virtual void SetMaterial (fxMaterial * m){};
	};
#endif
