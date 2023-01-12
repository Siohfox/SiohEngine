#ifndef SIOHENGINE_SHADERLOAD_H
#define SIOHENGINE_SHADERLOAD_H

#include "Cache.h"
#include <iostream>
#include "Component.h"

namespace SiohEngine
{
	struct ShaderLoad : Resource
	{
		/**
		 * @brief A getter for the stored shader
		 * @return The stored shader (m_shader)
		*/
		rend::Shader* GetShader() { return m_shader; }

		/**
		 * @brief A function to load a shader onto the cache. Appends to m_shader.
		 * @param _path The file path to search for the shader
		*/
		void LoadShader(const std::string& _path);

		/**
		 * @brief A function that calls LoadShader using given path.
		*/
		void OnLoad();

	private:
		rend::Shader* m_shader; ///< A pointer to the stored shader
	};
}
#endif