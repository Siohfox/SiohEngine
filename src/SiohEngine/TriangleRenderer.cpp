#include "TriangleRenderer.h"
#include "Entity.h"
#include "Transform.h"

namespace SiohEngine
{
	TriangleRenderer::TriangleRenderer() :
		m_shader("../data/shaders/basic.vert", "../data/shaders/basic.frag") 
	{
		m_mesh.loadTriangle();
	}
	void TriangleRenderer::OnDisplay()
	{
		rend::Renderer r(640, 480);

		mat4 model = m_entity.lock()->GetTransform()->GetModel();
		r.model(model);

		r.shader(&m_shader);
		r.mesh(&m_mesh);
		r.render();
	}
}
