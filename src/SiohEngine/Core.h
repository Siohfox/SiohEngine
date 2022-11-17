#include <memory>
#include <list>
#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alc.h>

#define INITIAL_WIDTH 640
#define INITIAL_HEIGHT 480

namespace SiohEngine
{
	struct Entity;
	struct Time;

	struct Core
	{
		/**
		* The destructor for Core
		*/
		~Core();


		static std::shared_ptr<Core> Init();

		std::shared_ptr<Entity> AddEntity();

		void Start();
		void Stop();

		

	private:
		bool m_running;

		ALCdevice* m_audioDevice;
		ALCcontext* m_audioContext;

		std::weak_ptr<Core> m_self;
		SDL_Window* m_window;
		SDL_GLContext m_context;
		std::list<std::shared_ptr<Entity>> m_entities;
		std::shared_ptr<Time> m_time;
	};
}

