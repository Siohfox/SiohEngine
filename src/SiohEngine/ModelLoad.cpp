#include "ModelLoad.h"

namespace SiohEngine
{
	void ModelLoad::load_model(const std::string _path)
	{
		m_model = new rend::Model(_path.c_str());
	}

	void ModelLoad::OnLoad()
	{
		load_model(GetPath());
	}
}
