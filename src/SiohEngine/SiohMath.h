#ifndef SIOHENGINE_SIOHMATH_H
#define SIOHENGINE_SIOHMATH_H

#include "rend/rend.h"

namespace SiohEngine
{
	using namespace glm;

#define shared std::shared_ptr
#define weak std::weak_ptr
#define transform GetEntity()->GetTransform()
#define input GetEntity()->GetCore()->GetInput()

	struct Math
	{
		static float Lerp(float a, float b, float t) { return (1 - t) * a + t * b; }	
	};
}

#endif