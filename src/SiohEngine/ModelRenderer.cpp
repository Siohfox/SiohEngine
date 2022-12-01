#include "ModelRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"

namespace SiohEngine
{
	ModelRenderer::ModelRenderer() :
		m_shader("../resources/shaders/basic.vert", "../resources/shaders/basic.frag")
	{
		m_mesh.loadTriangle();
		m_model = new rend::Model("../models/curuthers/curuthers.obj");
	}

	void ModelRenderer::OnDisplay()
	{
		rend::ModelRenderer mr(640, 480);
		mat4 model = m_entity.lock()->GetTransform()->GetModel();
		mr.shader(&m_shader);
		mr.mesh(&m_mesh);
		mr.projection(Camera::GetMainCam()->GetProjection());
		mr.view(Camera::GetMainCam()->GetView());

		mr.model(m_model);

		mr.render(); // This should be the final thing that runs here
	}
}