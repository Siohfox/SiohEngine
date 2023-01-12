#include "ShaderLoad.h"

namespace SiohEngine
{
	void ShaderLoad::LoadShader(const std::string _vertPath, const std::string _fragPath)
	{
		m_shader = new rend::Shader(_vertPath.c_str(), _fragPath.c_str());
	}

	void ShaderLoad::OnLoad()
	{
		LoadShader(GetPath(), GetPath());
	}
}
