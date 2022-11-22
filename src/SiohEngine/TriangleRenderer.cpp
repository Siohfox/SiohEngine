#include "TriangleRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"

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
		r.projection(Camera::GetMainCam()->GetProjection());
		r.view(Camera::GetMainCam()->GetView());
		
		r.model(model);
		
		r.render(); // This should be the final thing that runs here
	}
}
