#include "ShaderLoad.h"

namespace SiohEngine
{
	void ShaderLoad::LoadShader(const std::string& _path)
	{
		m_shader = new rend::Shader(std::string(_path + ".vert").c_str(), std::string(_path + ".frag").c_str());
	}

	void ShaderLoad::OnLoad()
	{
		LoadShader(GetPath());
	}
}
