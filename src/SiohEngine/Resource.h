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
		/**
		 * @brief A pure virtual function to allow loading
		*/
		virtual void OnLoad() = 0;

		/**
		 * @brief A Getter for the current string path
		 * @return m_path
		*/
		std::string GetPath() const;

	private:
		friend struct Cache;

		std::string m_path; ///< The current file path

		/**
		 * @brief Calls OnLoad()
		*/
		void Load();
	};
}

#endif // !SIOHENGINE_RESOURCES_H
