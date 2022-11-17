#include "Time.h"

namespace SiohEngine
{
    Time::Time()
    {
        m_currentTime = static_cast<double>(SDL_GetTicks());
        m_lastTime = 0.0f;
        m_deltaTime = 0.0f;
        m_maximumDeltaTime = 0.333f;
        m_frameRate = 1.0f / 60.0f; // 60 fps or 0.0166666667
    }

    double Time::DeltaTime()
    {
        // Compute time elapsed since last frame
        m_currentTime = static_cast<double>(SDL_GetTicks());

        // DeltaTime Compution
        m_deltaTime = m_currentTime - m_lastTime;


        // Is deltaTime larger than max delta time? If so cap it to max delta time.
        if (m_deltaTime > m_maximumDeltaTime)
        {
            m_deltaTime = m_maximumDeltaTime;
        }

        // if DeltaTime is less than the framerate, add delay to the game
        if (m_deltaTime < m_frameRate)
        {
            SDL_Delay((Uint32)(m_frameRate - m_deltaTime));
        }

        // Add deltatime to current time so far
        Time::time();

        return m_deltaTime;
    }

    double Time::time()
    {
        if (!m_currentTime >= 0)
        {
            std::cout << "Error, time is not more than 0 for some reason\n";
        }
        return m_currentTime;
    }

    double Time::TimeScale()
    {
        return 0.0f;
    }
}
