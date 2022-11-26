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
		* A constructor for the Time struct.
		*/
		Time();

		/**
		* A getter for delta time
		*
		* \return (float) The interval in seconds from the last frame to the current one 
		* This value varies depending on the frames per second (FPS) rate at which your game is running.
		*/
		static double DeltaTime();

		

	private:
		friend struct Core;

		void Update();

		static double m_deltaTime;
		double m_lastTime;
		double m_currentTime;
		double m_frameRate;
		double m_diff;
	};
}
#endif