#ifndef SIOHENGINE_CORE_H
#define SIOHENGINE_CORE_H

#include "Entity.h"
#include <memory>
#include <list>
#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <vector>

#define INITIAL_WIDTH 640
#define INITIAL_HEIGHT 480

namespace SiohEngine
{
	struct Entity;
	struct Time;
	struct Component;
	struct Cache;
	struct Input;

	struct Core
	{
		/**
		* The destructor for Core
		*/
		~Core();

		/**
		 * @brief Initialiser for the core.
		 * Initialises SDL and Audio
		 * @return A pointer to itself
		*/
		static std::shared_ptr<Core> Init();

		/**
		 * @brief A function to add new entities to the hierarchy
		 * @return A pointer to the new entity
		*/
		std::shared_ptr<Entity> AddEntity();

		/**
		 * @brief A function to start the engine and game loop
		*/
		void Start();

		/**
		* @brief Stops the engine
		*/
		void Stop();

		/**
		 * @brief Returns the component of Type <type> if 
		 * the entity has one attached.
		 * @tparam T 
		 * @param _out A component
		*/
		template <typename T>
		void Find(std::vector<std::shared_ptr<T>> &_out)
		{
			// Go through each Entity in Core.
			for (std::list<std::shared_ptr<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
			{
				std::shared_ptr<Entity> e = *it;
				// Go through each Component in Entity.
				for (std::list<std::shared_ptr<Component>>::iterator itt = e->m_components.begin(); itt != e->m_components.end(); ++itt)
				{
					std::shared_ptr<Component> c = *itt;
					// Try to dynamic cast the Component to a T.
					std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);
					// If succeeds then add it to the output array.
					if (t)
					{
						_out.push_back(t);
					}
				}
			}
		}
		

		std::shared_ptr<Cache> GetCache();


	private:
		bool m_running;

		std::shared_ptr<Input> m_input;

		ALCdevice* m_audioDevice;
		ALCcontext* m_audioContext;
		std::shared_ptr<Cache> m_cache;

		std::weak_ptr<Core> m_self;
		SDL_Window* m_window;
		SDL_GLContext m_context;
		std::list<std::shared_ptr<Entity>> m_entities;
		std::shared_ptr<Time> m_time;
	};
}
#endif