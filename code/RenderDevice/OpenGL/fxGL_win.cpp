#ifdef _WIN32

#include "fxGL.h"
#include "../../kernel/fxConsole.h"
#include "../fxRenderWindow_win.h"
#include <stdio.h>

// funktion pointers to extension funktions...
extern PFNGLLOCKARRAYSEXTPROC	      	        glLockArraysEXT;
extern PFNGLUNLOCKARRAYSEXTPROC                glUnlockArraysEXT;

extern PFNGLACTIVETEXTUREARBPROC      	        glActiveTextureARB;
extern PFNGLCLIENTACTIVETEXTUREARBPROC	        glClientActiveTextureARB;

extern PFNWGLSWAPINTERVALPROC	      	        wglSwapIntervalEXT;
extern PFNWGLGETSWAPINTERVALPROC      	        wglGetSwapIntervalEXT;

// load opengl and bind Opengl to a window
void fxGL::Init(HWND window_handle)
	{
	initialized = true;
	if (Vars==NULL) Vars = (fxVars*)FindObject("fxVars");
	fxConsole * Console = (fxConsole*)FindObject("fxConsole");

	if (Console != NULL)
		{
		Console->DisplayString("");
		Console->DisplayString("initializing OpenGL");
		}
	int rgb_bits = 16;
	int z_bits = 32;

	if (Vars != NULL)
		{
		// Display bit depth
		Vars->StdIntValue = 16;
		rgb_bits = Vars->GetIntValue("gl_rgb_bits");

		// zbuffer bit depth
		Vars->StdIntValue = 32;
		z_bits = Vars->GetIntValue("gl_z_bits");
		}

	gl_dc = GetDC(window_handle);
	SetupPixelFormat(rgb_bits, z_bits);

	if (Vars != NULL)
		{
		Vars->NewStringVar("gl_vendor", (char *)glGetString(GL_VENDOR),0);
		Vars->NewStringVar("gl_renderer", (char *)glGetString(GL_RENDERER),0);
		Vars->NewStringVar("gl_version", (char *)glGetString(GL_VERSION),0);
		}
	if (Console != NULL)
		{
		char * vendor_string, *render_string, *version_string;
		vendor_string = (char*)malloc(255);
		render_string = (char*)malloc(255);
		version_string = (char*)malloc(255);
		sprintf(vendor_string, ".gl_vendor: %s",(char*)glGetString(GL_VENDOR));
		sprintf(render_string, ".gl_render: %s",(char*)glGetString(GL_RENDERER));
		sprintf(version_string,".gl_version: %s",(char*)glGetString(GL_VERSION));

		Console->DisplayString(vendor_string);
		Console->DisplayString(render_string);
		Console->DisplayString(version_string);
		}

	ext_compiled_vertex_array = false;
	ext_multitexture = false;

	if (Console != NULL)
		{
		Console->DisplayString("");
		Console->DisplayString(".checking extensions");
		}

	if(CheckExtension("GL_EXT_compiled_vertex_array")){
		glLockArraysEXT = (PFNGLLOCKARRAYSEXTPROC) wglGetProcAddress("glLockArraysEXT");
		glUnlockArraysEXT = (PFNGLUNLOCKARRAYSEXTPROC) wglGetProcAddress("glUnlockArraysEXT");
		if (Vars != NULL) Vars->NewIntVar("gl_compiled_vertex_array_ext", 1, 0);
		ext_compiled_vertex_array = true;
	}
	else if (Vars != NULL) Vars->NewIntVar("gl_compiled_vertex_array_ext", 0, 0);

	int swapinterval = 1;
	if(CheckExtension("WGL_EXT_swap_control")){
		wglSwapIntervalEXT    = (PFNWGLSWAPINTERVALPROC) wglGetProcAddress("wglSwapIntervalEXT");
		wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALPROC) wglGetProcAddress("wglGetSwapIntervalEXT");
		if (Vars != NULL)
			{
			Vars->NewIntVar("gl_swapInterval_ext",1,0);
			Vars->StdIntValue = 1;
			swapinterval = Vars->GetIntValue("gl_swapinterval");
			}
		if(swapinterval==0) wglSwapIntervalEXT(0);
			else wglSwapIntervalEXT(1);
	}
	else if (Vars != NULL) Vars->NewIntVar("gl_swapinterval_ext",0,0);

	int maxtextureunits;
	if(CheckExtension("GL_ARB_multitexture")){
		if (Vars != NULL) Vars->NewIntVar("gl_multitexture_ext", 1, 0);
		glActiveTextureARB	 = (PFNGLACTIVETEXTUREARBPROC) wglGetProcAddress("glActiveTextureARB");
		glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC) wglGetProcAddress("glClientActiveTextureARB");
		glGetIntegerv(GL_MAX_TEXTURE_UNITS_ARB, &maxtextureunits);
		if (Vars != NULL) Vars->NewIntVar("gl_maxtextureunits",maxtextureunits,0);
		ext_multitexture = true;
	}
	else {
		if (Vars != NULL) Vars->NewIntVar("gl_multitexture_ext", 0, 0);
		if (Vars != NULL) Vars->NewIntVar("gl_maxtextureunits",1,0);
	}

	int maxtexturesize;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxtexturesize);
	if (Vars != NULL) Vars->NewIntVar("gl_maxtexturesize",maxtexturesize,0);

	if (Console != NULL)
		{
		if(ext_compiled_vertex_array) Console->DisplayString("..compiled vertex array extension enabled");
		if (swapinterval == 1) Console->DisplayString("..swap control extension enabled");
		if (ext_multitexture)
			{
			char * s;
			s = (char*)malloc(64);
			sprintf(s,"...using %i texture units", maxtextureunits);
			Console->DisplayString("..multitexture extension enabled");
			Console->DisplayString(s);
			}
		char * s;
		s = (char*)malloc(64);
		sprintf(s, "..max texture size: %i", maxtexturesize);
		Console->DisplayString("");
		Console->DisplayString(s);
		Console->DisplayString("");
		}


	// set initial OpenGL states
	SetInitialState();
	cCamera = NULL;

};

// prepare window for opengl drawing
void fxGL::SetupPixelFormat(int rgb_bits, int z_bits)
	{
	if (Vars==NULL) Vars = (fxVars*)FindObject("fxVars");
	fxConsole * Console = (fxConsole*)FindObject("fxConsole");

	int stencil_bits = 16;

	PIXELFORMATDESCRIPTOR FormatDescriptor = {
		sizeof (PIXELFORMATDESCRIPTOR), 1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA, rgb_bits,
		0,0, 0,0, 0,0, 0,0,     // rgb & shifts
		0, 0,0,0,0,             // accumulation buffer
		z_bits,
		stencil_bits, 0,        // stencil & aux buffers
		PFD_MAIN_PLANE,
		0,                      // reserved
		0,0,0                   // masks
	};
	int FormatIndex = ChoosePixelFormat(gl_dc, &FormatDescriptor);
	SetPixelFormat(gl_dc, FormatIndex, &FormatDescriptor);
	DescribePixelFormat(gl_dc, FormatIndex, sizeof(FormatDescriptor), &FormatDescriptor);
	gl_rc = wglCreateContext(gl_dc);
	wglMakeCurrent(gl_dc, gl_rc);

	if (Console != NULL)
		{
		char *s,* rgb, * z, *stencil;
		s = (char*)malloc(64);
		rgb = (char*)malloc(64);
		z = (char*)malloc(64);
		stencil = (char*)malloc(64);

		sprintf(s,      ".choosing pixelformat %i", FormatIndex);
		sprintf(rgb,    "..color bits: %i",FormatDescriptor.cColorBits);
		sprintf(z,      "..depth bits: %i",FormatDescriptor.cDepthBits);
		sprintf(stencil,"..stencil bits: %i",FormatDescriptor.cStencilBits);
		Console->DisplayString("");
		Console->DisplayString(s);
		Console->DisplayString(rgb);
		Console->DisplayString(z);
		Console->DisplayString(stencil);
		Console->DisplayString("");
		}
};


// unload opengl
void fxGL::Shut(void)
	{
	fxConsole * Console = (fxConsole*)FindObject("fxConsole");
	if (Console != NULL) Console->DisplayString("unloading OpenGL");
	wglMakeCurrent(gl_dc, gl_rc);
    wglDeleteContext(gl_rc);
    ReleaseDC(gl_wnd, gl_dc);
    gl_rc = NULL;
    gl_dc = NULL;
};


// call BEFORE drawing each frame
void fxGL::BeginFrame(void)
{
if (initialized == false) return;
glDepthMask(GL_TRUE);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
vcache.numverts=0;
vcache.numelems=0;
if (cCamera != NULL)
	{
	fxVector up(0,1,0);
	glLoadIdentity();
	gluLookAt(cCamera->position.data[0],cCamera->position.data[1],cCamera->position.data[2],
		  cCamera->position.data[0]+cCamera->direction.data[0],
		  cCamera->position.data[1]+cCamera->direction.data[1],
		  cCamera->position.data[2]+cCamera->direction.data[2],
		  up.data[0],up.data[1],up.data[2]);
	}
};


// call AFTER drawing each frame
void fxGL::EndFrame(void)
{
if (initialized == false) return;
flush();
glFlush();
SwapBuffers(gl_dc);
};

// opens the render window that fxGL renders to
void fxGL::OpenWindow(void)
{
	fxRenderDevice::OpenWindow();
	fxRenderWindow_win* w = (fxRenderWindow_win*) this->wnd;
	Init(w->hwnd);
	wnd->Show();
}

// close the render window
void fxGL::CloseWindow(void)
{
	Shut();
	wnd->Hide();
	fxRenderDevice::CloseWindow();
}


#endif