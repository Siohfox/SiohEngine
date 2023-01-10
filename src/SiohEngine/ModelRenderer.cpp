#include "ModelRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"

namespace SiohEngine
{
	ModelRenderer::ModelRenderer() :
		m_modelRenderer(640, 480),
		m_shader("../resources/shaders/basic.vert", "../resources/shaders/basic.frag")
	{
		//m_model = new rend::Model("../resources/models/maxwell/Maxwell.obj");
	}

	void ModelRenderer::SetTexture(std::shared_ptr<TextureLoad> texturePath)
	{
		m_texture = texturePath->GetRenderTexture();
		m_modelRenderer.texture(m_texture);
	}

	void ModelRenderer::SetModel(std::shared_ptr<ModelLoad> modelPath)
	{
		m_model = modelPath->GetRenderModel();
	}

	void ModelRenderer::OnDisplay()
	{
		mat4 model = m_entity.lock()->GetTransform()->GetModel();
		m_modelRenderer.shader(&m_shader);

		m_modelRenderer.projection(Camera::GetMainCam()->GetProjection());
		m_modelRenderer.view(Camera::GetMainCam()->GetView());

		((rend::Renderer*)(&m_modelRenderer))->model(model);
		m_modelRenderer.model(m_model);

		m_modelRenderer.depthTest(true);
		m_modelRenderer.backfaceCull(true);
		m_modelRenderer.blend(true);

		m_modelRenderer.texture(m_texture);

		m_modelRenderer.render(); // This should be the final thing that runs here
	}
}