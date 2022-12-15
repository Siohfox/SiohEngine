#ifndef SIOHENGINE_RESOURCES_H
#define SIOHENGINE_RESOURCES_H

#include "Debug.h"
#include <memory>
#include <string>
#include <vector>

namespace SiohEngine
{
	struct Cache;

	struct Resource
	{

		public:
		virtual void OnLoad() = 0;
		std::string GetPath() const;

	private:
		friend struct Cache;

		std::string m_path;
		void Load();
	};
}

#endif // !SIOHENGINE_RESOURCES_H
