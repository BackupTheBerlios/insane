#include "fxCamera.h"
#include "../math/fxMath.h"
#include "gl/gl.h"
#include "gl/glu.h"

fxCamera::fxCamera()
{
position.Set(0,0,-1);
direction.Set(0,0,1);
DepthOfView = 1000;
}

