#include "ModelRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"

namespace SiohEngine
{
	ModelRenderer::ModelRenderer() :
		m_shader("../resources/shaders/basic.vert", "../resources/shaders/basic.frag"),
		//m_texture("../resources/models/curuthers/Whiskers_diffuse.png")
		m_texture("../resources/models/maxwell/Maxwell_Diffuse.bmp")
		//m_texture("../resources/models/banana/ripe-banana_u1_v1.png")
	{
		m_mesh.loadTriangle();
		//m_model = new rend::Model("../resources/models/curuthers/curuthers.obj");
		m_model = new rend::Model("../resources/models/maxwell/Maxwell.obj");
		//m_model = new rend::Model("../resources/models/banana/ripe-banana.obj");
	}

	void ModelRenderer::OnDisplay()
	{
		rend::ModelRenderer mr(640, 480);
		mat4 model = m_entity.lock()->GetTransform()->GetModel();
		mr.shader(&m_shader);

		mr.projection(Camera::GetMainCam()->GetProjection());
		mr.view(Camera::GetMainCam()->GetView());

		((rend::Renderer*)(&mr))->model(model); 
		mr.model(m_model);

		mr.depthTest(true);
		mr.backfaceCull(true);
		mr.blend(true);

		mr.texture(&m_texture);

		mr.render(); // This should be the final thing that runs here
	}
}