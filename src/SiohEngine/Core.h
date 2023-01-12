#ifndef SIOHENGINE_CORE_H
#define SIOHENGINE_CORE_H

#include "Entity.h"
#include <memory>
#include <list>
#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <vector>

// Definitions for intial window width and height
#define INITIAL_WIDTH 1920
#define INITIAL_HEIGHT 1080

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
		 * @brief A function to add new entities with a name to the hierarchy
		 * @return A pointer to the new entity
		*/
		std::shared_ptr<Entity> AddEntity(std::string name);

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
		
		/**
		 * @brief Gets the cache stored
		 * @return m_cache
		*/
		std::shared_ptr<Cache> GetCache();

		/**
		 * @brief Gets the input
		 * @return m_input
		*/
		std::shared_ptr<Input> GetInput();

		/**
		 * @brief Gets an entity by finding it from a string name
		 * @param name The name of the entity to be searched for
		 * @return The first entity found with the given name
		*/
		std::shared_ptr<Entity> GetEntityByName(std::string name);


	private:
		bool m_running; ///< Whether the engine is running or not

		std::shared_ptr<Input> m_input; ///< A pointer to the input class
		std::shared_ptr<Time> m_time; ///< A pointer to the time class
		std::shared_ptr<Cache> m_cache; ///< A pointer to the stored cache class
		std::list<std::shared_ptr<Entity>> m_entities; ///< A list of pointers to stored entities
		std::weak_ptr<Core> m_self; ///< A weak pointer to the core itself

		// ALC
		ALCdevice* m_audioDevice; ///< Audio device
		ALCcontext* m_audioContext; ///< Audio context

		//SDL
		SDL_Window* m_window; ///< An SDL window pointer
		SDL_GLContext m_context; ///< The GL context	
	};
}
#endif