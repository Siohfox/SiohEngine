#ifndef SIOHENGINE_CACHE_H
#define SIOHENGINE_CACHE_H

#include "Debug.h"
#include "Resource.h"
#include <memory>
#include <string>
#include <vector>

namespace SiohEngine
{
	struct Cache
	{

	public:
		/**
		 * @brief Loads a resource and adds it to cache
		 * @tparam T Template t
		 * @param _path The string path that it should find to load from
		 * @return A pointer to the resource loaded
		*/
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			for (size_t i = 0; i < m_resources.size(); ++i)
			{
				// Return it if found
				if (m_resources.at(i)->GetPath() == _path)
				{
					return std::dynamic_pointer_cast<T>(m_resources.at(i));
				}
			}
			// Create new instance and add to cache
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_path = _path;
			rtn->Load();
			m_resources.push_back(rtn);
			return rtn;

		}
	private:
		std::vector<std::shared_ptr<Resource>> m_resources; ///< A vector of pointers to resourcesd
	};
}

#endif // !SIOHENGINE_RESOURCES_H
