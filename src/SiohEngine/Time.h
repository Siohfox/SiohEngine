#ifndef SIOHENGINE_TIME_H
#define SIOHENGINE_TIME_H

#include <iostream>
#include <chrono>
#include "SDL2/SDL.h"

namespace SiohEngine
{
	struct Time
	{
		/**
		* @brief A constructor for the Time struct.
		*/
		Time();

		/**
		* @brief A getter for delta time
		*
		* @return (float) The interval in seconds from the last frame to the current one 
		* This value varies depending on the frames per second (FPS) rate at which your game is running.
		*/
		static double DeltaTime();

		/**
		 * @brief Gets the current time in seconds
		 * @return The current time in seconds
		*/
		static double GetTimeSeconds() { return SDL_GetTicks() / 1000; }

		/**
		 * @brief Gets the current time in milliseconds
		 * @return The current time in milliseconds
		*/
		static double GetTimeMilliSeconds() { return SDL_GetTicks(); }

	private:
		friend struct Core;

		void Update();

		static double m_deltaTime; ///< Delta time
		double m_lastTime; ///< The last time recieved
		double m_currentTime; ///< The current given time
		double m_frameRate; ///< The ideal frameRate
		double m_diff; ///< The difference of given time and last time
	};
}
#endif