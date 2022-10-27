#include "Component.h"
#include <vector>
#include <rend/rend.h>

namespace SiohEngine
{
	struct Transform : Component
	{
		Transform::Transform();

	private:
		glm::vec3 m_position;
		glm::vec3 m_rotation;
		glm::vec3 m_scale;
	};
}
