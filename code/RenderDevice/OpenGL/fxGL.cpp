//---------------------------------------------------------------------------
#include <stdio.h>

#include "fxGL.h"
#include "../../shared/fxConst.h"
#include "../../Scene/fxScene.h"

#include "../../kernel/fxTimer.h"
#include "../../kernel/fxVars.h"
#include "../../kernel/fxClass.h"
#include "../../kernel/fxConsole.h"

// funktion pointers to extension funktions...
PFNGLLOCKARRAYSEXTPROC	      	        glLockArraysEXT;
PFNGLUNLOCKARRAYSEXTPROC                glUnlockArraysEXT;

PFNGLACTIVETEXTUREARBPROC      	        glActiveTextureARB;
PFNGLCLIENTACTIVETEXTUREARBPROC	        glClientActiveTextureARB;

PFNWGLSWAPINTERVALPROC	      	        wglSwapIntervalEXT;
PFNWGLGETSWAPINTERVALPROC      	        wglGetSwapIntervalEXT;


//---------------------------------------------------------------------------

void fxGL::Resize(int x, int y, int width, int height, int windowwidth, int windowheight)
{
if (cCamera==NULL) return;

float MaxDim, Ratio;

MaxDim=(float)windowwidth;
if (windowheight > MaxDim) MaxDim=(float)windowheight;

Ratio=(float)(2*width+2*x-windowwidth)/windowwidth;
cCamera->rightplane=(float)Ratio*windowwidth/(2*MaxDim);

Ratio=(float)(windowwidth-2*x)/windowwidth;
cCamera->leftplane=(float)-Ratio*windowwidth/(2*MaxDim);

Ratio=(float)(2*height+2*y-windowheight)/windowheight;
cCamera->topplane=(float)Ratio*windowheight/(2*MaxDim);

Ratio=(float)(windowheight-2*y)/windowheight;
cCamera->bottomplane=(float)-Ratio*windowheight/(2*MaxDim);

cCamera->nearplane=(float)0.2;
cCamera->farplane=cCamera->nearplane+cCamera->DepthOfView;

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(cCamera->leftplane,cCamera->rightplane,cCamera->bottomplane,cCamera->topplane,cCamera->nearplane,cCamera->farplane);
glViewport(x,y,windowwidth,windowheight);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}


void fxGL::flush(void)
{
if(vcache.numelems==0 || cMaterial->numlayers==0) return;

/*
// set culling:
if(cMaterial->CullMode!=cCullMode){
	if(cMaterial->CullMode != GL_NONE){
		glEnable(GL_CULL_FACE);
		if(cMaterial->CullMode==GL_FRONT) glCullFace(GL_FRONT);
		else glCullFace(GL_BACK);
	}
	else {
		glDisable(GL_CULL_FACE);
	}
	cCullMode=cMaterial->CullMode;
	}
*/
// select render path
if (ext_compiled_vertex_array)
	{
	if (ext_multitexture)
		{
		flushMtxCVA();
		}
		else
		{
		flushGenericCVA();
		}
	}
	else
        {
	if (ext_multitexture)
		{
		flushMtx();
		}
		else
		{
		flushGeneric();
		}
	}

// clear buffer state:
vcache.numelems=0;
vcache.numverts=0;
};


void fxGL::DrawBuffer(fxVertex * VertexList, int VertexCount, int * IndexList, int IndexCount)
{
if(VertexCount>MAX_VERTEXES) return;
if(IndexCount>MAX_ELEMS) return;

if(IndexCount==0 || VertexCount==0) return;

	// test array bounds
	if( vcache.numelems + IndexCount >= MAX_ELEMS ||
            vcache.numverts + VertexCount >= MAX_VERTEXES )
            	{
		flush();
		}
	// copy elems
	for(int i=0; i < IndexCount; i++)
        	{
		vcache.elems[vcache.numelems] = vcache.numverts + *IndexList;
		vcache.numelems++;
		IndexList++;
		}

	// copy vertex positions
        for (i=0; i < VertexCount; i++)
		{
                memcpy(vcache.position[vcache.numverts + i],VertexList[i].position, sizeof(fxVectorData));
		}

	// copy vertex normals
	for (i=0; i < VertexCount; i++)
		{
		memcpy(vcache.normal[vcache.numverts + i],VertexList[i].normal, sizeof(fxVectorData));
		}
	// copy texture coordinates
	for (i=0; i < VertexCount; i++)
		{
		for (int j=0; j < MAX_UNITS; j++)
			{
			memcpy(vcache.tc[j][vcache.numverts + i],VertexList[i].tc[j],  sizeof(fxPointData));
			}
		}
	// copy vertex colors
	for (i=0; i < VertexCount; i++)
		{
		memcpy(vcache.color[vcache.numverts + i],VertexList[i].color, sizeof(fxColorRGBA));
		}

	vcache.numverts+=VertexCount;
};

void fxGL::flushGeneric(void)
{
TransformVertexes();

for(cPass=0; cPass<cMaterial->numlayers; cPass++)
	{
	fxLayer *l=cMaterial->Layer[cPass];

	TransformTextureCoordinates(0);
	TransformVertexColors();

	BindLayer(l, 0);
	SetState(l);
	stripmine(vcache.numelems, vcache.elems);
	}
};

void fxGL::flushGenericCVA(void)
{
TransformVertexes();

glDisableClientState(GL_TEXTURE_COORD_ARRAY);	// dont allow to cache this!
glDisableClientState(GL_COLOR_ARRAY);
glLockArraysEXT(0, vcache.numverts);
glEnableClientState(GL_TEXTURE_COORD_ARRAY);
glEnableClientState(GL_COLOR_ARRAY);

for(cPass=0; cPass<cMaterial->numlayers; cPass++)
	{
	fxLayer *l=cMaterial->Layer[cPass];

	TransformTextureCoordinates(0);
	TransformVertexColors();

	BindLayer(l, 0);
	SetState(l);
	glDrawElements( GL_TRIANGLES, vcache.numelems, GL_UNSIGNED_INT, vcache.elems);
	}
glUnlockArraysEXT();
};

void fxGL::flushMtx(void)
{
TransformVertexes();

for(cPass=0; cPass<cMaterial->numlayers; cPass++)
	{
	fxLayer *l=cMaterial->Layer[cPass];

	TransformTextureCoordinates(0);
	TransformVertexColors();

	BindLayer(l, 0);
	SetState(l);

	stripmine(vcache.numelems, vcache.elems);
	}
};

void fxGL::flushMtxCVA(void)
{
TransformVertexes();

glDisableClientState(GL_TEXTURE_COORD_ARRAY);	// dont allow to cache this!
glDisableClientState(GL_COLOR_ARRAY);
glLockArraysEXT(0, vcache.numverts);
glEnableClientState(GL_TEXTURE_COORD_ARRAY);
glEnableClientState(GL_COLOR_ARRAY);

for(cPass=0; cPass<cMaterial->numlayers; cPass++)
	{
	fxLayer *l=cMaterial->Layer[cPass];

	TransformTextureCoordinates(0);
	TransformVertexColors();

	BindLayer(l, 0);
	SetState(l);
	glDrawElements( GL_TRIANGLES, vcache.numelems, GL_UNSIGNED_INT, vcache.elems);
	}
glUnlockArraysEXT();
};


// that have been taken from aftershock:	(FIXME: can I use it?)
void fxGL::stripmine(int numelems, int *elems)
{
int toggle;
int a, b, elem;

/* Vertexes are in tristrip order where possible.  If we can't lock
 * the vertex arrays (glLockArraysEXT), then it's better to send
 * tristrips instead of triangles (less transformations).
 * This function looks for and sends tristrips.
 */

/* Tristrip order elems look like this:
 *  0 1 2 2 1 3 2 3 4 4 3 5 4 5 7 7 5 6  <-- elems
 *    b a a b b a b a a b b a b a a b b  <-- ab pattern
 *    \ 1 / \ 2 / \ 3 / \ 4 / \ 5 /      <-- baa/bba groups
 */

elem = 0;
while (elem < numelems){
	toggle = 1;
	glBegin(GL_TRIANGLE_STRIP);

	glArrayElement(elems[elem++]);
	b = elems[elem++];
	glArrayElement(b);
	a = elems[elem++];
	glArrayElement(a);

	while (elem < numelems){
		if (a != elems[elem] || b != elems[elem+1]) break;
		if (toggle) {
			b = elems[elem+2];
			glArrayElement(b);
		}
		else {
			a = elems[elem+2];
			glArrayElement(a);
		}
		elem += 3;
		toggle = !toggle;
	}
	glEnd();
}
};

void fxGL::TransformVertexes(void)
{
glVertexPointer(3, GL_FLOAT, 0, vcache.position);
};

void fxGL::TransformTextureCoordinates(int TexUnit)
{
//fxLayer *l=cMaterial->Layer[cPass];
/*
glMatrixMode(GL_TEXTURE);
glLoadIdentity();

glTranslatef(0.5,0.5,0);
glRotatef(fxtimer.time*50,0,0,1);
glTranslatef(-0.5,-0.5,0);
*/
glTexCoordPointer(2, GL_FLOAT, 0, vcache.tc[TexUnit]);
};

void fxGL::TransformVertexColors(void)
{
//fxLayer *l=cMaterial->Layer[cPass];

glColorPointer(4, GL_UNSIGNED_BYTE, 0, vcache.color);
};


void fxGL::SetInitialState(void)
{
	if (Vars==NULL)
		{
		Vars = (fxVars*)FindObject("fxVars");
		Vars->StdIntValue = 0;
		}

	// client state:
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// texturing:
	glEnable(GL_TEXTURE_2D);
	cTexture[0]=-1;

	// second texture unit
	if(ext_multitexture){
		glActiveTextureARB(GL_TEXTURE1_ARB);
		glClientActiveTextureARB(GL_TEXTURE1_ARB);
		//glEnable( GL_TEXTURE_2D );
		glDisable( GL_TEXTURE_2D );
		//glEnableClientState( GL_TEXTURE_COORD_ARRAY );
		glActiveTextureARB(GL_TEXTURE0_ARB);
		glClientActiveTextureARB(GL_TEXTURE0_ARB);
		cTexture[1]=-1;
	}

// backface culling:
glEnable(GL_CULL_FACE);
glCullFace(GL_BACK);
glFrontFace(GL_CCW);
cCullMode=IFX_CULL_BACK;

// color:
glEnable(GL_COLOR);
glShadeModel(GL_SMOOTH);

int dither = 0;
if (Vars != NULL) dither = Vars->GetIntValue("gl_dither");

if (dither == 0) glDisable(GL_DITHER);
 else glEnable(GL_DITHER);

glDisable(GL_BLEND);
glBlendFunc(GL_ONE, GL_ZERO);
cBlendMode = IFX_BLEND_REPLACE;

// alpha func
glDisable(GL_ALPHA_TEST);
glAlphaFunc(GL_ALWAYS, 1.0f );

// depth test:
glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LEQUAL);
glDepthMask(GL_TRUE);

//curr_depthFunc=GL_LEQUAL;
//curr_depthWrite=true;

//glEnable(GL_SCISSOR_TEST);

glEnable(GL_POLYGON_OFFSET_FILL);

int wireframe = 0;

if (Vars != NULL) wireframe = Vars->GetIntValue("gl_wireframe");

if(wireframe==1)
	{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDisable(GL_TEXTURE_2D);
	}
	else
	{
	glPolygonMode(GL_FRONT, GL_FILL);
	}

int quality = 2;
if (Vars != NULL) quality = Vars->GetIntValue("gl_quality");

switch(quality)
	{
	case 0:
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
		break;
	case 1:
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_DONT_CARE);
		break;
	case 2:
	default:
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
		break;
	}

glReadBuffer( GL_BACK );
glDrawBuffer( GL_BACK );

// clearing:
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
glClearDepth(1.0f);
}

void fxGL::BindLayer(fxLayer *l, int TexUnit)
{
if (l == NULL) return;
if(cTexture[TexUnit]!=l->maps[0]->handle)
	{
	glBindTexture(GL_TEXTURE_2D, l->maps[0]->handle);
	cTexture[TexUnit]=l->maps[0]->handle;
	}
}

// set the appropiate state to render the layer
void fxGL::SetState(fxLayer *l)
{
if (l == NULL) return;
if (cBlendMode != l->BlendMode)
	{
	switch (l->BlendMode)
		{
		case IFX_BLEND_ADD:
			{
			glEnable(GL_BLEND);
			glBlendFunc(GL_ONE, GL_ONE);
			break;
			}
		case IFX_BLEND_MODULATE:
			{
			glEnable(GL_BLEND);
			glBlendFunc(GL_DST_COLOR, GL_ZERO);
			break;
			}
		case IFX_BLEND_ALPHA:
			{
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			break;
			}

		default:
		case IFX_BLEND_REPLACE:
			{
			glDisable(GL_BLEND);
			}
		}
	cBlendMode = l->BlendMode;
	}

/*
	if(curr_alphaFunc!=l->alphafunc){
		if(l->alphafunc==GL_ALWAYS) glDisable(GL_ALPHA_TEST);
		else {
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(l->alphafunc, l->alphafuncref);
		}
		curr_alphaFunc=l->alphafunc;
	}
*/
//	if(curr_shader->surface_flags&SF_POLYGONOFFSET) glPolygonOffset(1.0, 1.0);	// FIXME: Quake 3 uses (1,2); why?

/*
	if(curr_depthFunc!=l->depthFunc){
		glDepthFunc(l->depthFunc);
		curr_depthFunc=l->depthFunc;
	}

	if(l->depthWrite!=curr_depthWrite){
		glDepthMask(l->depthWrite);
		curr_depthWrite=l->depthWrite;
	}
*/
};

void fxGL::SetCamera (fxCamera* cam)
{
cCamera = cam;
}

void fxGL::SetMaterial (fxMaterial * m)
{
if (m == NULL) return;
if ((cMaterial != NULL) && (cMaterial != m)) flush();
cMaterial = m;
}

void fxGL::RegisterTexture(fxTexture * t)
{

if (Vars==NULL)
	{
	Vars = (fxVars*)FindObject("fxVars");
	Vars->StdIntValue = 0;
	}

int fform, gl_format, gl_components;

if (Vars != NULL)
	{
	Vars->StdIntValue = 16;
	fform=Vars->GetIntValue("gl_texturebits");
	}

switch(t->bpp)
	{
	case 1:
		gl_format=GL_ALPHA;
		gl_components=GL_ALPHA;
		break;
	case 2:
		gl_format=GL_LUMINANCE_ALPHA;
		gl_components=GL_LUMINANCE_ALPHA;
		break;
	case 3:
		gl_format=GL_RGB;
		switch(fform){
			case 16:
				gl_components=GL_RGB5;
				break;
			case 32:
				gl_components=GL_RGB8;
				break;
			default:
				gl_components=GL_RGB;
			};
		break;
	case 4:
		gl_format=GL_RGBA;
		switch(fform){
			case 16:
				gl_components=GL_RGBA4;
				break;
			case 32:
				gl_components=GL_RGBA8;
				break;
			default:
				gl_components=GL_RGBA;
			};
		break;
	default:
		gl_format = GL_RGB;
		gl_components = GL_RGB;
}

/*
if(newheight>fxVars.GetIntValue("gl_maxTextureSize"))newheight=fxVars.GetIntValue("gl_maxTextureSize");
if(newwidth>fxVars.GetIntValue("gl_maxTextureSize"))newwidth=fxVars.GetIntValue("gl_maxTextureSize");

if(tex->height!=newheight||tex->width!=newwidth){
	mem = (byte *) malloc(newheight*newwidth*tex->bpp);
	gluScaleImage(format,tex->width, tex->height, GL_UNSIGNED_BYTE ,tex->mem, newwidth, newheight, GL_UNSIGNED_BYTE, mem);
}
*/

glGenTextures(1, &t->handle);
glBindTexture(GL_TEXTURE_2D, t->handle);

if(t->mipmap) glTexImage2D(GL_TEXTURE_2D, 0, gl_components, t->width, t->height, 0, gl_format, GL_UNSIGNED_BYTE, t->mem);
  else gluBuild2DMipmaps(GL_TEXTURE_2D, gl_components, t->width, t->height, gl_format, GL_UNSIGNED_BYTE, t->mem);

if(t->clampu) glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  else glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

if(t->clampv) glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
  else glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

int filter = 2;
if (Vars != NULL)
	{
	Vars->StdIntValue = 2;
	filter = Vars->GetIntValue("gl_filter");
	}

switch (filter)
	{
	case 0:
		{
		// nearest point sampling
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		if(t->mipmap) glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		  else glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		break;
		}
	case 1:
		{
		// bilinear point sampling
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		if(t->mipmap) glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		  else glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
		break;
		}
	default:
		{
		// trilinear point sampling
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		if(t->mipmap) glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		  else glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		}
	}

glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

void fxGL::UnregisterTexture(fxTexture * t)
{
glBindTexture(GL_TEXTURE_2D,NULL);
glDeleteTextures(1,&t->handle);
}
