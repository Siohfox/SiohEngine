#include "TextureLoad.h"

namespace SiohEngine
{
	void TextureLoad::load_texture(const std::string _path)
	{
		m_texture = new rend::Texture(_path.c_str());
	}

	void TextureLoad::OnLoad()
	{
		load_texture(GetPath());
	}
}
