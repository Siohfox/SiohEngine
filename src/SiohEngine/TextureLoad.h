#ifndef SIOHENGINE_TEXTURELOAD_H
#define SIOHENGINE_TEXTURELOAD_H

#include "Cache.h"
#include "rend/rend.h"

namespace SiohEngine
{
	struct TextureLoad : Resource
	{
		rend::Texture* GetRenderTexture() { return m_texture; }

		void load_texture(const std::string _path); 

		void OnLoad();

	private:
		rend::Texture* m_texture;

	};
}

#endif