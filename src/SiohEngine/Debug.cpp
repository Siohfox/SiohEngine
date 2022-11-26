#include "Debug.h"

namespace SiohEngine
{
	void Debug::Log(std::string message)
	{
		std::cout << "Debug: " << message << std::endl;
	}

	void Debug::LogWarning(std::string message)
	{
		std::cout << "Warning: " << message << std::endl;
	}

	void Debug::LogError(std::string message)
	{
		std::cout << "Error: " << message << std::endl;
	}
}
