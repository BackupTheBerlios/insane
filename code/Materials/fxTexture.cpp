//---------------------------------------------------------------------------
#include "fxTexture.h"
//---------------------------------------------------------------------------

#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>

#include "../math/fxMath.h"
#include "fxTextureMng.h"

extern "C"
	{
	#include "libjpeg/jpeglib.h"
	}

namespace {

typedef unsigned char   byte;
typedef unsigned char 	Byte;
typedef unsigned char   BYTE;
typedef unsigned short  word;
typedef unsigned short  WORD;
typedef unsigned long   dword;
typedef unsigned long   DWORD;
typedef int Int;

static Byte id_length;          /* 0 */
static Byte color_map_type;     /* 1 */
static Byte image_type;         /* 2 */
static Int cm_index;            /* 3 4 */
static Int cm_length;           /* 5 6 */
static Byte cm_entry_size;      /* 7 */
static Int image_x_org;         /* 8 9 */
static Int image_y_org;         /* 10 11 */
static Int image_width;         /* 12 13 */
static Int image_height;        /* 14 15 */
static Byte image_depth;        /* 16 */
static Byte image_desc;         /* 17 */

static Byte image_id[256];

static Byte color_palette[256 * 3];

#define BPP 8
#define LR 0x10
#define BT 0x20

#define bread(fp) (Byte)fgetc(fp)

int
wread(FILE * fp)
{
  Byte h, l;

  l = (Byte) fgetc(fp);
  h = (Byte) fgetc(fp);
  return (h << 8) | l;
}


unsigned char *DecodeTGA (FILE * fpin, int * width, int * height, int swap, int * bpp)
{
  int i, rle;
  int a, r, g, b;
//  int right, top;
  unsigned char *data;
  int size;
  unsigned char *result;

  id_length = bread(fpin);
  color_map_type = bread(fpin);
  image_type = bread(fpin);

  if (!(image_type == 2 || image_type == 10))
    {
      printf("Only type 2 or 10 supported\n");
      exit(112);
    }
  cm_index = wread(fpin);
  cm_length = wread(fpin);

  cm_entry_size = bread(fpin);

  image_x_org = wread(fpin);
  image_y_org = wread(fpin);
  image_width = wread(fpin);
  image_height = wread(fpin);

  image_depth = bread(fpin);
  image_desc = bread(fpin);

  *width = image_width;
  *height = image_height;

  result = (Byte *) malloc(image_width * image_height * 4);
  if (result == 0)
    return NULL;
 

//  right = image_desc & LR;
//  top = image_desc & BT;

  fread((char *) image_id, id_length, 1, fpin);
  fread((char *) color_palette, cm_length, cm_entry_size >> 3, fpin);

  data = result;

  size = (int) image_height *(int) image_width;

  if (image_type == 2)
  {
    if (image_depth == 24)
    {
      *bpp = 3;	
      for (i = 0; i < size; i++)
      {
	if (swap)
	{
	  b = fgetc(fpin);
	  g = fgetc(fpin);
	  r = fgetc(fpin);
	  *data++ = r;
	  *data++ = g;
	  *data++ = b;
	}
	else
	{
	  *data++ = fgetc(fpin);
	  *data++ = fgetc(fpin);
	  *data++ = fgetc(fpin);
	}
      }
    }
    else
    {
      // 32 bit
      *bpp = 4;
      for (i = 0; i < size; i++)
      {
	if (swap)
	{
	  b = fgetc(fpin);
	  g = fgetc(fpin);
	  r = fgetc(fpin);
	  a = fgetc(fpin);
	  *data++ = r;
	  *data++ = g;
	  *data++ = b;
	  *data++ = a;
	}
	else
	{
	  *data++ = fgetc(fpin);
	  *data++ = fgetc(fpin);
	  *data++ = fgetc(fpin);
	  *data++ = fgetc(fpin);
	}
      }
    }
  }
  else                          //RLE
  {
    if (image_depth == 24)
    {
      *bpp = 3;
      i = 0;
      while (i < size)
      {

	rle = fgetc(fpin);
	if (rle < 0x80)
	{
	  rle++;
	  while (rle)
	  {
	    if (swap)
	    {
	      b = fgetc(fpin);
	      g = fgetc(fpin);
	      r = fgetc(fpin);
	      *data++ = r;
	      *data++ = g;
	      *data++ = b;
	    }
	    else
	    {
	      *data++ = fgetc(fpin);
	      *data++ = fgetc(fpin);
	      *data++ = fgetc(fpin);
	    }
	    rle--;
	    i++;
	    if (i > size)
	    {
	      exit(113);
	    }
	  }
	}
	else
	{
	  rle -= 127;
	  b = fgetc(fpin);
	  g = fgetc(fpin);
	  r = fgetc(fpin);

	  while (rle)
	  {
	    if (swap)
	    {
	      *data++ = r;
	      *data++ = g;
	      *data++ = b;
	    }
	    else
	    {
	      *data++ = b;
	      *data++ = g;
	      *data++ = r;
	    }
	    i++;
	    if (i > size)
	    {
	      printf("RLE overflow\n");
	      exit(115);
	    }
	    rle--;
	  }
	}

      }
    }
    else                      // 32bit RLE
    {
      *bpp = 4;
      i = 0;
      while (i < size)
      {

	rle = fgetc(fpin);
	if (rle < 0x80)
        {
          rle++;
	  while (rle)
          {
            if (swap)
            {
              b = fgetc(fpin);
              g = fgetc(fpin);
              r = fgetc(fpin);
              a = fgetc(fpin);
              *data++ = r;
              *data++ = g;
              *data++ = b;
              *data++ = a;
            }
            else
            {
              
              *data++ = fgetc(fpin);
              *data++ = fgetc(fpin);
              *data++ = fgetc(fpin);
	      *data++ = fgetc(fpin);
            }
            rle--;
            i++;
            if (i > size)
            {
              printf("RLE overflow\n");
              exit(116);
	    }
            
          }
        }
        else
        {
          rle -= 127;
          b = fgetc(fpin);
          g = fgetc(fpin);
          r = fgetc(fpin);
          a = fgetc(fpin);
          
          while (rle)
          {
            if (swap)
            {
              *data++ = r;
              *data++ = g;
              *data++ = b;
              *data++ = a;
            }
            else
            {
              *data++ = b;
              *data++ = g;
	      *data++ = r;
              *data++ = a;
	    }
	    rle--;
	    i++;
	    if (i > size)
	    {
	      printf("RLE overflow\n");
	      exit(117);
	    }
	  }
	}

      }
    }
  }
  fclose(fpin);

  return result;
}

} // namespace

bool fxTexture::LoadTGA(char * filename)
{
FILE * f;
f = fopen(filename,"rb");
if (f == NULL) return false;
mem = DecodeTGA(f, &width, &height, 1, &bpp);
fclose(f);
strcpy(name, filename);
return true;
}

static void error_exit (j_common_ptr pcinfo){
	// Create the message string
	char sz[256];
	(pcinfo->err->format_message) (pcinfo, sz);

//	err->CriticalError(ERROR_FORMAT_NOT_SUPPORTED, "%s\n",sz);
}


static void init_source (j_decompress_ptr cinfo){
}


static boolean fill_input_buffer (j_decompress_ptr cinfo){
	struct jpeg_source_mgr * src = cinfo->src;
	static JOCTET FakeEOI[] = { 0xFF, JPEG_EOI };

	/* Generate warning */
//	err->Log(UNKNOWN_ERROR, "Premature end of file\n");

	/* Insert a fake EOI marker */
	src->next_input_byte = FakeEOI;
	src->bytes_in_buffer = 2;

	return TRUE;
}


static void skip_input_data (j_decompress_ptr cinfo, long num_bytes) {
	struct jpeg_source_mgr * src = cinfo->src;

	if(num_bytes >= (long)src->bytes_in_buffer) {
		fill_input_buffer(cinfo);
		return;
	}

	src->bytes_in_buffer -= num_bytes;
	src->next_input_byte += num_bytes;
}


void term_source (j_decompress_ptr cinfo){
  /* no work necessary here */
}

bool fxTexture::LoadJPG(char * filename)
{
	unsigned char * temp_mem;
	int		size;
	FILE * 		f;

	f=fopen(filename,"rb");
	if (f==NULL) return false;
	fseek(f,0,SEEK_END);
	size=ftell(f);
	fseek(f,0,SEEK_SET);
	temp_mem = (unsigned char*)malloc(size);
	fread(temp_mem,size,1,f);
        fclose(f);

	jpeg_decompress_struct cinfo;	// IJPEG decoder state.
	jpeg_error_mgr         jerr;	// Custom error manager.

	cinfo.err = jpeg_std_error (&jerr);
	jerr.error_exit = error_exit;	// Register custom error manager.

	jpeg_create_decompress (&cinfo);

	
	struct jpeg_source_mgr * src;
	//jpeg_stdio_src(&cinfo, fp);
	
	cinfo.src= (struct jpeg_source_mgr *) (*cinfo.mem->alloc_small) 
		((j_common_ptr) &cinfo, JPOOL_PERMANENT, sizeof(struct jpeg_source_mgr));

	
	src = cinfo.src;

	src->init_source = init_source;
	src->fill_input_buffer = fill_input_buffer;
	src->skip_input_data = skip_input_data;
	src->resync_to_restart = jpeg_resync_to_restart;	// use default method
	src->term_source = term_source;

	// Set up data pointer
	src->bytes_in_buffer = size;
	src->next_input_byte = temp_mem;

	jpeg_read_header (&cinfo, TRUE);

	cinfo.do_fancy_upsampling = FALSE;		// fast decompression

    cinfo.dct_method = JDCT_FLOAT;			// Choose floating point DCT method.



	jpeg_start_decompress(&cinfo);

    width = cinfo.output_width;
    height = cinfo.output_height;

	if (cinfo.out_color_space == JCS_GRAYSCALE){
		/*tex->bpp=1;
		tex->mem = (byte *) malloc(1*tex->width*tex->height);
		if (!tex->mem) {
			tex->mem=NULL;
			return;
		}*/
//		err->CriticalError(UNKNOWN_ERROR,"grayscale not supported!!!");
	}
	else{
		bpp=3;
		mem = (unsigned char *) malloc(3*width*height);
		if (!mem) {
			return false;
		}

		unsigned char *pDst=mem;
		unsigned char **ppDst=&pDst;
		int num_scanlines=0;
		while (cinfo.output_scanline < cinfo.output_height){
			num_scanlines=jpeg_read_scanlines (&cinfo, ppDst, 1);
			*ppDst += num_scanlines * 3 * cinfo.output_width;
		}
	}

	jpeg_finish_decompress(&cinfo);

	jpeg_destroy_decompress (&cinfo);
	return true;
}

bool fxTexture::Load( char * filename)
{
strcpy(name, filename);

fxTextureMng * texmng = (fxTextureMng* )TextureMng;
int texindex = texmng->GetTextureIndex(filename);
if (texindex != -1) return true;

char * ch = strrchr(filename,'.');

if (ch == NULL) return false;

if (!strcmpi(ch,".tga")) return LoadTGA(filename);
if (!strcmpi(ch,".jpg")) return LoadJPG(filename);
if (!strcmpi(ch,".bmp")) return LoadBMP(filename);
return false;
}
