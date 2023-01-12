#ifndef SIOHENGINE_MODELRENDERER_H
#define SIOHENGINE_MODELRENDERER_H

#include "Component.h"
#include "ModelLoad.h"
#include "TextureLoad.h"
#include <string>
#include <iostream>
#include <rend/rend.h>

namespace SiohEngine
{
	struct ModelRenderer : Component
	{
	public:
		/**
		 * @brief Constructs model renderer by giving m_shader the shader
		 * files and additionally loading the model using the rend library.
		*/
		ModelRenderer();

		/**
		 * @brief Sets the texture of the model
		 * @param texture The cached texture to load from
		*/
		void SetTexture(std::shared_ptr<TextureLoad> texture);

		/**
		 * @brief Sets the model
		 * @param texture The cached model to load from
		*/
		void SetModel(std::shared_ptr<ModelLoad> model);

	private:
		rend::Mesh m_mesh;     ///< A member variable to hold the mesh for the model
		rend::Shader m_shader; ///< A member variable to hold the shader files
		rend::Model* m_model; ///< A member variable to hold the model
		rend::Texture* m_texture; ///< A member variable to hold the texture of the model
		rend::ModelRenderer m_modelRenderer; ///< A member variable to hold the modelRenderer

		/**
		* @brief Uses the required information to display the model to the screen.
		*/
		void OnDisplay();
	};
}
#endif // !SIOHENGINE_MODELRENDERER_H
