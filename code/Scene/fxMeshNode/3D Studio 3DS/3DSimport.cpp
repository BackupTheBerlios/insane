#include "3DSimport.h"
#include "../fxMeshMng.h"
#include <assert.h>

ChunkHeader chunk;
fxMeshMng * MeshMng;
fxMesh * Mesh;


unsigned char ReadChar (FILE* f)
{
 return (unsigned char)(fgetc (f));
}
/*----------------------------------------------------------------------------*/
unsigned int ReadInt (FILE* f)
{
 unsigned int temp = ReadChar(f);
 return ( temp | (ReadChar(f) << 8));
}
/*----------------------------------------------------------------------------*/
unsigned long ReadLong (FILE* f)
{
 unsigned long temp1,temp2;

 temp1=ReadInt(f);
 temp2=ReadInt(f);

 return (temp1+(temp2*0x10000L));
}
/*----------------------------------------------------------------------------*/
float ReadFloat (FILE* f)
{
float t;
fread(&t,sizeof(float),1,f);
return t;
}
/*----------------------------------------------------------------------------*/
int ReadName (FILE* f, char* name)
{
 unsigned int teller=0;
 unsigned char letter;
 char temp_name[128];

 strcpy (temp_name,"Default name");

 letter=ReadChar (f);
 if (letter==0) return (-1); // dummy object
 temp_name [teller]=letter;
 teller++;

 do
 {
  letter=ReadChar (f);
  temp_name [teller]=letter;
  teller++;
 }
 while ((letter!=0)/* && (teller<12)*/);

 temp_name [teller-1]=0;

 for (unsigned int i=0; i<=strlen(temp_name); i++)
	{
        name[i] = temp_name[i];
	}

 return 0;
}
/*----------------------------------------------------------------------------*/

void ReadChunkHeader(FILE* f)
{
chunk.id = ReadInt(f);
chunk.length = ReadLong(f);
}
/*----------------------------------------------------------------------------*/

void ParseUnknownChunk(FILE* f)
{
fseek(f,chunk.length-6,SEEK_CUR);
}
/*----------------------------------------------------------------------------*/
void ParsePlacementChunks(FILE* f, long length)
{
long pos = 0;
float matrix[4][4];
for (int j=0; j<4; j++)
	{
	for (int i=0; i<3; i++)
		{
		matrix[j][i] = ReadFloat(f);
		}
	}
matrix[0][3]=0;
matrix[1][3]=0;
matrix[2][3]=0;
matrix[3][3]=1;
pos+=4*3*sizeof(float);
fseek(f,length-pos,SEEK_CUR);
}
/*----------------------------------------------------------------------------*/
void ParseFaceChunks(FILE* f, long length)
{
long pos = 0;
int numFaces = ReadInt(f);
int a,b,c,EdgeInfo;

for (int i=0; i<numFaces; i++)
	{
	a = ReadInt(f);
	b = ReadInt(f);
	c = ReadInt(f);
	EdgeInfo = ReadInt(f);
	Mesh->AddTriangle(a,b,c);
	}
pos+=numFaces*4*2+2;
fseek(f,length-pos,SEEK_CUR);
}
/*----------------------------------------------------------------------------*/
void ParseVertexChunks(FILE* f, long length)
{
long pos = 0;
int numVertices = ReadInt(f);
fxVertex * v;
v = new fxVertex;

for (int i=0; i<numVertices; i++)
	{
	v->position[0] = ReadFloat(f);
	v->position[2] = ReadFloat(f);
	v->position[1] = ReadFloat(f);
	v->color[0]=255;
	v->color[1]=255;
	v->color[2]=255;
	v->color[3]=255;
	Mesh->AddVertex(v);
	}
pos+=numVertices*3*sizeof(float)+2;
fseek(f,length-pos,SEEK_CUR);
}
/*----------------------------------------------------------------------------*/
void ParseTexVertexChunks(FILE* f, long length)
{
long pos = 0;
int numVertices = ReadInt(f);

for (int i=0; i<numVertices; i++)
	{
	fxVertex vertex = Mesh->Vertex[i];
	vertex.tc[0][0] = ReadFloat(f);
	vertex.tc[0][1] = ReadFloat(f);
	}
pos+=numVertices*2*sizeof(float)+2;
fseek(f,length-pos,SEEK_CUR);
}
/*----------------------------------------------------------------------------*/
void ParseMeshChunks(FILE* f, long length)
{
long pos = 0;
while (pos < length)
	{
	ReadChunkHeader(f);
	pos+=chunk.length;
	switch (chunk.id)
		{
		case TRI_VERTEXL :
			// vertices
			ParseVertexChunks(f, chunk.length-6);
			break;
		case TRI_TEXVERTS :
			// texture coordinates
			ParseTexVertexChunks(f, chunk.length-6);
			break;
		case TRI_FACEL1 :
			// indices
			ParseFaceChunks(f, chunk.length-6);
			break;
		case TRI_LOCAL :
			// object placement matrix
			ParsePlacementChunks(f, chunk.length-6);
			break;
		case TRI_VISIBLE :
			// object visibility flag
			ParseUnknownChunk(f);
			break;
		default:
			ParseUnknownChunk(f);
			break;
		}
	}
}
/*----------------------------------------------------------------------------*/
void ParseObjectChunks(FILE* f, long length)
{
Mesh = new fxMesh;
Mesh->name = (char*)malloc(128);
ReadName(f,Mesh->name);

MeshMng->MeshList.Add(Mesh);

long pos = strlen(Mesh->name)+1;
while (pos < length)
	{
	ReadChunkHeader(f);
	pos+=chunk.length;
	switch (chunk.id)
		{
		case OBJ_TRIMESH :
			ParseMeshChunks(f, chunk.length-6);
			break;
		case OBJ_LIGHT:
			ParseUnknownChunk(f);
			break;
		case OBJ_CAMERA:
			ParseUnknownChunk(f);
			break;
		default:
			ParseUnknownChunk(f);
			break;
		}
	}
}
/*----------------------------------------------------------------------------*/
void ParseMaterialNameChunk(FILE* f, long length)
{
long pos = 0;
char * name;
name = new char[128];
fread(name,length,1,f);
pos+=strlen(name)+1;
delete name;
}
/*----------------------------------------------------------------------------*/
void ParseMaterialChunks(FILE* f, long length)
{
long pos = 0;
while (pos < length)
	{
	ReadChunkHeader(f);
	pos+=chunk.length;
	switch (chunk.id)
		{
		case MAT_NAME01 :
			ParseMaterialNameChunk(f, chunk.length-6);
			break;
		default:
			ParseUnknownChunk(f);
			break;
		}
	}
}
/*----------------------------------------------------------------------------*/
void ParseEditorChunks(FILE* f, long length)
{
long pos = 0;
while (pos < length)
	{
	ReadChunkHeader(f);
	pos+=chunk.length;
	switch (chunk.id)
		{
		case EDIT_MATERIAL :
			ParseMaterialChunks(f, chunk.length-6);
			break;
		case EDIT_OBJECT:
			ParseObjectChunks(f, chunk.length-6);
			break;
		default:
			ParseUnknownChunk(f);
			break;
		}
	}

}
/*----------------------------------------------------------------------------*/
void ParseMainChunks (FILE* f, long length)
{
long pos = 0;
while (pos < length)
	{
	ReadChunkHeader(f);
	pos+=chunk.length;
	switch (chunk.id)
		{
		case KEYF3DS :
			// keyframer chunks - not supported yet
			ParseUnknownChunk(f);
			break;
		case EDIT3DS :
			ParseEditorChunks(f, chunk.length-6);
			break;
		default:
			ParseUnknownChunk(f);
			break;
		}

	}
}

int import3DS(FILE* f,fxMeshMng * m)
	{
	MeshMng = m;
	Mesh = NULL;
	ReadChunkHeader(f);
	ParseMainChunks(f, chunk.length-6);
	return 0;
	}

