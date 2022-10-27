#include "TriangleRenderer.h"
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
		r.shader(&m_shader);
		r.mesh(&m_mesh);
		r.render();
	}
}
