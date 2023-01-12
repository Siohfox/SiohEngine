#include "TextureLoad.h"

namespace SiohEngine
{
	void TextureLoad::LoadTexture(const std::string _path)
	{
		m_texture = std::make_shared<rend::Texture>(_path.c_str());
	}

	void TextureLoad::OnLoad()
	{
		LoadTexture(GetPath());
	}
}
