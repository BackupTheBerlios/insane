//---------------------------------------------------------------------------
//
// classes:
//      fxGL - this class does all the rendering
//
//---------------------------------------------------------------------------
#ifndef fxGLH
#define fxGLH

#ifdef _WIN32
#include <windows.h>
#endif

#include <gl/gl.h>
#include <gl/glu.h>
#include "glext.h"

#include "../../insanefx.h"

#include "../fxRenderDevice.h"

#include "../../Materials/fxMaterialMng.h"

#include "../../Shared/fxLimits.h"
#include "../../Math/fxVertex.h"
#include "../../Math/fxPoint.h"

class fxKernel;
class fxMaterialMng;
class fxMaterial;
class fxLayer;
class fxTextureMng;
class fxTexture;
class fxSceneGraph;
class fxCamera;

typedef struct {
    int				numelems;
    int				elems[MAX_ELEMS];

    int				numverts;
    fxVectorData 	position[MAX_VERTEXES];
    fxVectorData	normal[MAX_VERTEXES];

    fxPointData		tc[MAX_UNITS][MAX_VERTEXES];
    int				numtc[MAX_UNITS];

    fxColorRGBA		color[MAX_VERTEXES];
}VertexCache;

class INSANEFX_API fxGL : public fxRenderDevice {

	#ifdef _WIN32
	#include "fxGL_win.h"
	#else
	// linux opengl<->window binding goes here...
	#endif

	private:

		void SetInitialState(void);

		bool initialized;		

		/* Determine if an extension is supported, must be called after a valid context has been created */
		bool CheckExtension(char *extName) 
			{
			char *extensions = (char *)glGetString(GL_EXTENSIONS);
			if (strstr(extensions, extName)) return true;
			return false;
			};
		
		bool ext_compiled_vertex_array;
		bool ext_multitexture;

		VertexCache  vcache;

		void flush(void);
		void flushGeneric(void);
		void flushGenericCVA(void);
		void flushMtx(void);
		void flushMtxCVA(void);


		void stripmine(int numelems, int *elems);

		void BindLayer(fxLayer *l, int TexUnit = 0);
		void SetState(fxLayer* l);

		void TransformVertexes(void);
		void TransformVertexColors(void);
		void TransformTextureCoordinates(int TexUnit = 0);

		fxCamera *      cCamera;
		fxMaterial *	cMaterial;

		// the current OpenGL render states
		int				cPass;
        int				cCullMode;
		int				cBlendMode;
        unsigned int	cTexture[MAX_UNITS];

	public:

		fxGL() { initialized = false; };
			
		~fxGL(void) {};
			
		virtual void OpenWindow(void);
		virtual void CloseWindow(void);

		virtual void Resize(int x, int y, int width, int height, int windowwidth, int windowheight);

		virtual void BeginFrame(void);
		virtual void EndFrame(void);

		virtual void DrawBuffer(fxVertex * VertexList, int VertexCount, int * IndexList, int IndexCount);

		virtual void RegisterTexture(fxTexture * t);
		virtual void UnregisterTexture(fxTexture * t);

		virtual void SetCamera (fxCamera* cam);

                virtual void SetMaterial (fxMaterial * m);
        };

//---------------------------------------------------------------------------
#endif
