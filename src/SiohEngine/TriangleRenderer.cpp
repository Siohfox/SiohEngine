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
		r.shader(&m_shader);
		r.mesh(&m_mesh);
		r.projection(rend::perspective(rend::radians(45.0f), 1.0f, 0.1f, 100.0f));
		//r.model(rend::translate(rend::mat4(1.0f), rend::vec3(0, 0, -10)));

		
		r.model(model);
		
		r.render(); // This should be the final thing that runs here
	}
}
