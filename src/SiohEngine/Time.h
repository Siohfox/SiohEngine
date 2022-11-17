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
		double DeltaTime();

		/**
		* A getter for time elapsed
		*
		* \return (float) The amount of time in seconds since your project started playing.
		*/
		double time();

		double TimeScale();

	private:
		double m_deltaTime;
		double m_maximumDeltaTime; // < The maximum value of Time.deltaTime in any given frame. This is a time in seconds that limits the increase of Time.time between two frames.
		double m_currentTime;
		double m_lastTime;
		double m_frameRate;

	};
}