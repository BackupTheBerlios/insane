//---------------------------------------------------------------------------
#include "fxMesh.h"
#include "3D Studio 3ds/3DSimport.h"
//---------------------------------------------------------------------------

fxMesh::fxMesh()
{
VertexCount = 0;
Vertex = NULL;

IndexCount = 0;
Index = NULL;
}

fxMesh::~fxMesh(void)
{
Vertex = (fxVertex*) realloc(Vertex,0);
Index = (int*)realloc(Index,0);
}

int fxMesh::FindVertex(fxVertex * v)
{
fxVertex * temppointer = Vertex;
for (int i=0; i < VertexCount; i++)
	{
	if (memcmp(v, temppointer, sizeof(fxVertex)) == 0) return i;
	temppointer++;
	}
return -1;
}

int fxMesh::AddVertex(fxVertex * v)
{
int index = FindVertex(v);
if (index != -1) return index;

VertexCount++;
Vertex = (fxVertex*)realloc(Vertex, sizeof(fxVertex) * VertexCount);
Vertex[VertexCount-1] = *v;
return VertexCount-1; // return index of added vertex
}

void fxMesh::AddTriangle(int v1,int v2,int v3)
{
IndexCount+=3;
Index = (int*)realloc(Index, sizeof(int)*IndexCount);
Index[IndexCount-3] = v1;
Index[IndexCount-2] = v2;
Index[IndexCount-1] = v3;
}
/*
int fxMesh::LoadOBJ(char * filename)
{
GLMmodel 	* m;
GLMgroup 	* g;
GLMtriangle 	* t;

int index[3];

fxVertex * v;
v = new fxVertex;

m = glmReadOBJ(filename);

if (m==NULL) return -1;

g = m->groups;
while (g)
	{
	for (unsigned int i=0; i < g->numtriangles; i++)
		{
		t = &m->triangles[g->triangles[i]];
		for (int j = 0; j < 3; j++)
			{
			v->position[0] = m->vertices[3 * t->vindices[j]    ];
			v->position[1] = m->vertices[3 * t->vindices[j] + 1];
			v->position[2] = m->vertices[3 * t->vindices[j] + 2];

			v->color[0] = 1;
			v->color[1] = 1;
			v->color[2] = 1;

			if (m->normals != NULL)
				{
				v->normal[0] = m->normals[3 * t->nindices[j]    ];
				v->normal[1] = m->normals[3 * t->nindices[j] + 1];
				v->normal[2] = m->normals[3 * t->nindices[j] + 2];
				}
			if (m->texcoords != NULL)
				{
				v->tc[0][0] = m->texcoords[2 * t->tindices[j]    ];
				v->tc[0][1] = m->texcoords[2 * t->tindices[j] + 1];
				}
			index[j] = AddVertex(v);
			}
		AddTriangle((short)index[0], (short)index[1], (short)index[2]);
		}
	g = g->next;
	}
return 0;
}
*/
