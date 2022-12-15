#ifndef SIOHENGINE_SHADER_H
#define SIOHENGINE_SHADER_H

#include "Cache.h"
#include <iostream>
#include "Component.h"

namespace SiohEngine
{
	struct Shader : Cache
	{
		void OnLoad();
	};
}
#endif