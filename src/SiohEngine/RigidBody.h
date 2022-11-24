#include <iostream>
#include "Component.h"

namespace SiohEngine
{
	struct RigidBody : Component
	{
		void OnTick();
	};
}