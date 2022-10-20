#include "Component.h"

#include <rend/rend.h>

namespace SiohEngine
{
	struct TriangleRenderer : Component
	{
		TriangleRenderer();

	private:
		rend::Mesh m_mesh;
		rend::Shader m_shader;

		void OnDisplay();
	};
}