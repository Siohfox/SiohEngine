#include "Shader.h"

namespace SiohEngine
{
	void Shader::LoadShader(const std::string& _path)
	{
		m_shader = std::make_shared<rend::Shader>(std::string(_path + ".vert").c_str(), std::string(_path + ".frag").c_str());
	}

	void Shader::OnLoad()
	{
		LoadShader(GetPath());
	}
}
