//---------------------------------------------------------------------------
#ifndef fxMeshH
#define fxMeshH
//---------------------------------------------------------------------------

#include "../../insanefx.h"
#include "../../kernel/fxRefClass.h"
#include "../../math/fxVertex.h"

class INSANEFX_API fxMesh : public fxRefClass
	{
	public:
		char * name;

		int  FindVertex(fxVertex * v);
		int  AddVertex(fxVertex * v);
		void AddTriangle(int v1,int v2,int v3);

		fxMesh();
		~fxMesh(void);

		fxVertex 	* Vertex;
		int		  VertexCount;

		int       * Index;
		int		  IndexCount;
	};

#endif
