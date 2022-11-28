#ifndef SIOHENGINE_RIGIDBODY_H
#define SIOHENGINE_RIGIDBODY_H

#include <iostream>
#include "Component.h"

namespace SiohEngine
{
	struct RigidBody : Component
	{
		/**
		* @brief A function for ticking each frame.
		*/
		void OnTick();
	};
}
#endif