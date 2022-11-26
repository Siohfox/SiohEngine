#ifndef SIOHENGINE_BOXCOLLIDER_H
#define SIOHENGINE_BOXCOLLIDER_H

#include <iostream>
#include "Component.h"

namespace SiohEngine
{

	struct BoxCollider : Component
	{
		/**
		 * @brief A box collider default constructor
		*/
		BoxCollider();

		/**
		 * @brief A function to detect whether the
		 * collider this object is attached to is
		 * colliding with another given object
		 * @param _other The other collider to compare with
		 * @return Whether a collision happened between the colliders
		*/
		bool Colliding(const BoxCollider& _other);

	private:
		vec3 m_size; ///< The dimensions of the box collider
		vec3 m_offset; ///< The offset of the box collider
	};
}
#endif