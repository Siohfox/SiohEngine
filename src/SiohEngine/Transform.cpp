#include "Transform.h"

namespace SiohEngine
{
	Transform::Transform()
	{
		m_position = glm::vec3(0);
		m_rotation = glm::vec3(0);
		m_scale = glm::vec3(1.0f,1.0f,1.0f);
	}

	mat4 Transform::GetModel()
	{
		mat4 rotationMat = mat4(1.0f);
		mat4 translationMat = mat4(1.0f);
		mat4 scaleMat = mat4(1.0f);

		translationMat = glm::translate(translationMat, m_position);
		rotationMat = rotate(rotationMat,  radians(m_rotation.x), vec3(1.0f, 0.0f, 0.0f));
		rotationMat = rotate(rotationMat, radians(m_rotation.y), vec3(0.0f, 1.0f, 0.0f));
		rotationMat = rotate(rotationMat, radians(m_rotation.z), vec3(0.0f, 0.0f, 1.0f));
		scaleMat = glm::scale(scaleMat, m_scale);


		return translationMat * rotationMat * scaleMat;
	}


	void Transform::OnTick()
	{
		m_position += vec3(0.001f, 0.0f, 0.0f);
	}
}

