#include "Core.h"
#include "Transform.h"
#include "Time.h"
#include "Cache.h"
#include <rend/rend.h>
#include <stdexcept>
#include "Input.h"

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

	std::shared_ptr<Entity> Core::AddEntity(std::string name)
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_self = rtn;
		rtn->m_core = m_self;
		rtn->m_transform = rtn->AddComponent<Transform>();
		rtn->m_name = name;

		m_entities.push_back(rtn);

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

		float idealTime = 1.0f / 60.0f;
		

		// Call every entity's component's intialise methods.
		for (std::list<std::shared_ptr<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
		{
			(*it)->Start();
		}


		while (m_running)
		{
			// Update the time
			m_time->Update();

			SDL_Event event = { 0 }; // Creat event handler

			if (idealTime > Time::DeltaTime())
			{
				SDL_Delay((idealTime - Time::DeltaTime()) * 1000.0f);
			}

			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					m_running = false;
					break;

				case SDL_KEYDOWN:
					if (!m_input->GetKey(event.key.keysym.sym))
					{
						m_input->keyDown.push_back(event.key.keysym.sym);
						m_input->keys.push_back(event.key.keysym.sym);
					}
					break;

				case SDL_KEYUP:
					if (m_input->GetKey(event.key.keysym.sym))
					{
						m_input->keys.remove(event.key.keysym.sym);
						m_input->keyUp.push_back(event.key.keysym.sym);
					}
					break;
				}
			}

			// Tick every entity that exists
			for (std::list<std::shared_ptr<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
			{
				(*it)->Tick();
			}

			rend::Renderer r(640, 480); // Creating a renderer


			double elapsedTime = Time::GetTimeMilliSeconds() / 1000.0f;

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
			
			// Display every entity that exists
			for (std::list<std::shared_ptr<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
			{
				(*it)->Display();
			}

			SDL_GL_SwapWindow(m_window);

			// Erase dead entities
			for (std::list<std::shared_ptr<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
			{
				if (!(*it)->IsAlive())
				{
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

	std::shared_ptr<Input> Core::GetInput()
	{
		return m_input;
	}

	std::shared_ptr<Entity> Core::GetEntityByName(std::string name)
	{
		for (std::list<std::shared_ptr<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
		{
			if ((*it)->GetName() == name)
			{
				return (*it);
			}
		}
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
