#ifndef SIOHENGINE_TEXTURE_H
#define SIOHENGINE_TEXTURE_H

#include "Cache.h"
#include "rend/rend.h"

namespace SiohEngine
{
	struct ModelRenderer;

	struct Texture : Resource
	{
		/**
		 * @brief A function to load a model onto the cache. Appends to m_texture.
		 * @param _path The file path to search for the texture
		*/
		void LoadTexture(const std::string& _path); 

		/**
		 * @brief A function that calls LoadTexture using given path.
		*/
		void OnLoad();

	private:
		friend ModelRenderer;

		std::shared_ptr<rend::Texture> m_texture; ///< A pointer to the stored texture

	};
}

#endif