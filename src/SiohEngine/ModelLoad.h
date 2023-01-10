#ifndef SIOHENGINE_MODELLOAD_H
#define SIOHENGINE_MODELLOAD_H

#include <iostream>
#include "rend/rend.h"
#include <string>
#include "Component.h"
#include "Cache.h"

namespace SiohEngine
{
	struct ModelLoad : Resource
	{
		rend::Model* GetRenderModel() { return m_model; }

		void load_model(const std::string _path);

		void OnLoad();

	private:
		rend::Model* m_model;
	};

}
#endif