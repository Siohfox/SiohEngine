#ifndef SIOHENGINE_SIOHMATH_H
#define SIOHENGINE_SIOHMATH_H

#include "rend/rend.h"

namespace SiohEngine
{
	using namespace glm;

	struct Math
	{
		static float Lerp(float a, float b, float t) { return (1 - t) * a + t * b; }	
	};
}

#endif