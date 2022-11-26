#ifndef SIOHENGINE_DEBUG_H
#define SIOHENGINE_DEBUG_H

#include <string>
#include <iostream>

namespace SiohEngine
{
	struct Debug
	{
	public:
		static void Log(std::string message);
		static void LogWarning(std::string message);
		static void LogError(std::string message);
	};
}

#endif // !SIOHENGINE_DEBUG_H
