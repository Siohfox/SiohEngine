#include "Transform.h"

namespace SiohEngine
{
	Transform::Transform()
	{
		m_position = glm::vec3(0);
		m_rotation = glm::vec3(0);
		m_scale = glm::vec3(1.0f,1.0f,1.0f);
		m_angle = 0;
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
		m_scale = vec3(0.5f);
		m_position += vec3(0.002f * 0.5f,(0.03f*sin(m_angle*3.141592f/180.0f)),0.0f);

		m_angle += 5;
		//m_position += vec3(0.001f, 0.0f, 0.0f);

		m_rotation.z += 1.0f;
	}
}

