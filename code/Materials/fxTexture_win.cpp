#ifdef _WIN32

#include "fxTexture.h"


// load a bitmap using windows api...
bool fxTexture::LoadBMP(char * filename)
{
HBITMAP bmp = (HBITMAP)LoadImage(NULL,filename,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
if (!bmp) return false;
HDC dc = CreateCompatibleDC(NULL);
SelectObject(dc, bmp);
BITMAP bmi;
GetObject(bmp, sizeof(BITMAP),&bmi);
width = bmi.bmWidth;
height = bmi.bmHeight;
bpp = bmi.bmBitsPixel / 8;
mem = (unsigned char*)malloc(width*height*bpp);

BITMAPINFO bmp_info;
bmp_info.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
bmp_info.bmiHeader.biWidth=width;
bmp_info.bmiHeader.biHeight=height;
bmp_info.bmiHeader.biPlanes=1;
bmp_info.bmiHeader.biBitCount=24;
bmp_info.bmiHeader.biCompression=BI_RGB;

GetDIBits(dc, bmp, 0, height, mem, &bmp_info,DIB_RGB_COLORS);

unsigned char * c1 = (unsigned char *) mem;
unsigned char * c3 = (unsigned char *) mem + 2;

for (int i=0; i<width*height; i++)
	{
	unsigned char t;
	t = *c1;
	*c1 = *c3;
	*c3 = t;
	c1+=3;
	c3+=3;
	}
return true;
}

#endif