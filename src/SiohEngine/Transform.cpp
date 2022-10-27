#include "Transform.h"

namespace SiohEngine
{
	Transform::Transform()
	{
		m_position = glm::vec3(0);
		m_rotation = glm::vec3(0);
		m_scale = glm::vec3(1.0f,1.0f,1.0f);
	}
}

