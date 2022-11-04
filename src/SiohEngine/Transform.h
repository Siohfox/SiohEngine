#include "Component.h"
#include <vector>
#include <rend/rend.h>
#include "SiohMath.h"

namespace SiohEngine
{
	struct Transform : Component
	{
		Transform::Transform();

		void SetPosition(vec3 pos) { m_position = pos; }


		mat4 GetModel();

		

	private:
		vec3 m_position;
		vec3 m_rotation;
		vec3 m_scale;

		int m_angle;

		void OnTick();
	};
}
