#ifndef SIOHENGINE_MODEL_H
#define SIOHENGINE_MODEL_H

#include <iostream>
#include "Component.h"
#include "Cache.h"

namespace SiohEngine
{
	struct Model : Cache
	{
		void OnLoad();
	};
}
#endif