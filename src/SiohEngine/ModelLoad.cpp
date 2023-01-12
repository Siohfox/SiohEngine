#include "ModelLoad.h"

namespace SiohEngine
{
	void ModelLoad::LoadModel(const std::string _path)
	{
		m_model = new rend::Model(_path.c_str());
	}

	void ModelLoad::OnLoad()
	{
		LoadModel(GetPath());
	}
}
