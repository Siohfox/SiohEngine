#ifndef SIOHENGINE_DEBUG_H
#define SIOHENGINE_DEBUG_H

#include <string>
#include <iostream>

namespace SiohEngine
{
	struct Debug
	{
	public:
		/**
		 * @brief A function to log debug messages
		 * @param message The message to output
		*/
		static void Log(std::string message);

		/**
		 * @brief A function to log debug warnings
		 * @param message The message to output
		*/
		static void LogWarning(std::string message);

		/**
		 * @brief A function to log debug Errors
		 * @param message The message to output
		*/
		static void LogError(std::string message);
	};
}
#endif // !SIOHENGINE_DEBUG_H
