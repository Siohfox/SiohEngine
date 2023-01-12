#include "ModelRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"

namespace SiohEngine
{
	ModelRenderer::ModelRenderer() :
		m_modelRenderer(1920, 1080),
		m_shader("../resources/shaders/basic.vert", "../resources/shaders/basic.frag")
	{
		//m_model = new rend::Model("../resources/models/maxwell/Maxwell.obj");
	}

	void ModelRenderer::SetTexture(std::shared_ptr<Texture> texturePath)
	{
		m_texture = texturePath;
	}

	void ModelRenderer::SetModel(std::shared_ptr<Model> modelPath)
	{
		m_model = modelPath;
	}

	void ModelRenderer::OnDisplay()
	{
		if (!m_texture) return;

		mat4 model = m_entity.lock()->GetTransform()->GetModel();
		m_modelRenderer.shader(&m_shader);

		m_modelRenderer.projection(Camera::GetMainCam()->GetProjection());
		m_modelRenderer.view(Camera::GetMainCam()->GetView());

		((rend::Renderer*)(&m_modelRenderer))->model(model);
		m_modelRenderer.model(m_model->m_model.get());

		m_modelRenderer.depthTest(true);
		m_modelRenderer.backfaceCull(true);
		m_modelRenderer.blend(true);

		m_modelRenderer.texture(m_texture->m_texture.get());

		m_modelRenderer.render(); // This should be the final thing that runs here
	}
}