#ifndef SIOHENGINE_TEXTURELOAD_H
#define SIOHENGINE_TEXTURELOAD_H

#include "Cache.h"
#include "rend/rend.h"

namespace SiohEngine
{
	struct TextureLoad : Resource
	{
		/**
		 * @brief A getter for the stored texture
		 * @return The stored model (m_texture)
		*/
		rend::Texture* GetRenderTexture() { return m_texture; }

		/**
		 * @brief A function to load a model onto the cache. Appends to m_texture.
		 * @param _path The file path to search for the texture
		*/
		void LoadTexture(const std::string _path); 

		/**
		 * @brief A function that calls LoadTexture using given path.
		*/
		void OnLoad();

	private:
		rend::Texture* m_texture; ///< A pointer to the stored texture

	};
}

#endif