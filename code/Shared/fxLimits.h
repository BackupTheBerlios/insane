#ifndef fxLimitsH
#define fxLimitsH

// size of all strings
#define MAX_STRING	128

// number of supported texture units (in these days only the NVIDIA GeoForge has 4 texture units)
#define MAX_UNITS	4

// limits of the renderers vertex cache (these limits influence the performance -> you should
// adjust them for your application

#define MAX_VERTEXES	1024    	// number of vertexes to cache
#define MAX_ELEMS	4*MAX_VERTEXES	// number of elements to cache

// limits for fxMaterial and fxLayer
#define MAX_LAYERS  8		// number of layers per material
#define MAX_MAPS	16		// number of frames per layer

#define MAX_SURFACES	10000
#define MAX_MATERIALS	512
#define MAX_TEXTURES	512

#endif
