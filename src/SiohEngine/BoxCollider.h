#ifndef SIOHENGINE_BOXCOLLIDER_H
#define SIOHENGINE_BOXCOLLIDER_H

#include <iostream>
#include "Component.h"

namespace SiohEngine
{

	struct BoxCollider : Component
	{
		BoxCollider();

		bool Colliding(const BoxCollider& _other);
	private:
		vec3 m_size;
		vec3 m_offset;
	};
}

#endif