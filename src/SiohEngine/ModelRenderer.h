#ifndef SIOHENGINE_MODELRENDERER_H
#define SIOHENGINE_MODELRENDERER_H

#include "Component.h"
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

	private:
		rend::Mesh m_mesh;     ///< A member variable to hold the mesh for the model
		rend::Shader m_shader; ///< A member variable to hold the shader files
		rend::Model* m_model; ///< A member variable to hold the model

		/**
		* @brief Uses the required information to display the model to the screen.
		*/
		void OnDisplay();
	};
}
#endif // !SIOHENGINE_MODELRENDERER_H
