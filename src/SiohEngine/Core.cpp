#include "Core.h"
#include "Transform.h"
#include "Time.h"
#include "Cache.h"
#include <rend/rend.h>
#include <stdexcept>

namespace SiohEngine 
{
	std::shared_ptr<Core> Core::Init()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		rtn->m_self = rtn;
		rtn->m_running = false;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::runtime_error("Failed to initialize SDL");
		}
		if (!(rtn->m_window = SDL_CreateWindow("SDL2 Platform",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, INITIAL_WIDTH, INITIAL_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)))
		{
			SDL_Quit();
			throw std::runtime_error("Failed to create Window");
		}
		if (!(rtn->m_context = SDL_GL_CreateContext(rtn->m_window)))
		{
			SDL_DestroyWindow(rtn->m_window);
			SDL_Quit();
			throw std::runtime_error("Failed to create OpenGL context");
		}

		/*************************************************************************
	    * Initialization
	    *************************************************************************/
		rtn->m_audioDevice = alcOpenDevice(NULL);

		if (!rtn->m_audioDevice)
		{
			throw std::runtime_error("Failed to open audio device");
		}

		rtn->m_audioContext = alcCreateContext(rtn->m_audioDevice, NULL);

		if (!rtn->m_audioContext)
		{
			alcCloseDevice(rtn->m_audioDevice);
			throw std::runtime_error("Failed to create audio context");
		}

		if (!alcMakeContextCurrent(rtn->m_audioContext))
		{
			alcDestroyContext(rtn->m_audioContext);
			alcCloseDevice(rtn->m_audioDevice);
			throw std::runtime_error("Failed to make context current");
		}

		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		//alListener3f(AL_VELOCITY, 0.0f, 0.0f, 0.0f);

		rtn->m_cache = std::make_shared<Cache>();

		//rtn->m_input = std::make_shared<Input>();

		return rtn;
	}

	void Core::Start()
	{
		m_running = true;

		m_time = std::make_shared<Time>();

		glm::vec3 lastCol;
		float timer = 0.0f;

		const glm::vec3 startColor = glm::vec3(1.0f, 0.0f, 0.0f); // red
		const glm::vec3 endColor = glm::vec3(0.0f, 1.0f, 0.0f); // green

		const float startTime = 0.0f;
		const float endTime = 0.1f;
		float t = 0.0f;

		while (m_running)
		{
			m_time->Update();

			SDL_Event evt = { 0 };

			while (SDL_PollEvent(&evt))
			{
				if (evt.type == SDL_QUIT)
				{
					m_running = false;
				}
				if (evt.type == SDL_KEYDOWN)
				{
					if (evt.key.keysym.sym == SDLK_d)
					{
						std::cout << "hi";
					}
				}
			}

			for (std::list<std::shared_ptr<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
			{
				(*it)->Tick();

			}

			rend::Renderer r(640, 480);


			float elapsedTime = Time::GetTimeMilliSeconds() / 1000;

			// Calculate the interpolation factor t
			t = (elapsedTime - startTime) / (endTime - startTime);

			if (Time::GetTimeSeconds() >= 10)
			{		
				lastCol.x = Math::Lerp(startColor.x, endColor.x, (sin(t) + 1) / 2);
				lastCol.y = Math::Lerp(startColor.y, endColor.y, (sin(t) + 1) / 2);
				lastCol.z = Math::Lerp(startColor.z, endColor.z, (sin(t) + 1) / 2);

				r.clearColor(lastCol);
			}
			
			
			r.clear();
			

			for (std::list<std::shared_ptr<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
			{
				(*it)->Display();
			}

			SDL_GL_SwapWindow(m_window);

			for (std::list<std::shared_ptr<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
			{
				if (!(*it)->IsAlive())
				{
					//(*it)->Destroy();
					m_entities.erase(it);
					--it;
				}
			}
		}
	}

	void Core::Stop()
	{
		m_running = false;
	}

	std::shared_ptr<Cache> Core::GetCache()
	{
		return m_cache;
	}

	std::shared_ptr<Entity> Core::AddEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_self = rtn;
		rtn->m_core = m_self;
		rtn->m_transform = rtn->AddComponent<Transform>();

		m_entities.push_back(rtn);

		return rtn;
	}

	Core::~Core()
	{
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}
}
