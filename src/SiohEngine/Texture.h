#ifndef SIOHENGINE_TEXTURE_H
#define SIOHENGINE_TEXTURE_H

#include "Cache.h"
#include "rend/rend.h"

namespace SiohEngine
{
	struct Texture : Cache
	{
		void OnLoad();

	private:
		std::shared_ptr<rend::Texture> m_texture;

	};
}

#endif