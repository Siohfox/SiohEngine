#ifndef SIOHENGINE_ENTITY_H
#define SIOHENGINE_ENTITY_H
#include <memory>
#include <vector>
#include <rend/rend.h>
#include <iostream>
#include <list>

namespace SiohEngine
{
	struct Component;
	struct Core;
	struct Transform;

	struct Entity
	{
		/**
		 * @brief Default constructor for entity
		*/
		Entity();

		/**
		 * @brief Constructor for entity with a given name
		 * @param name The name of the entity
		*/
		Entity(std::string name);

		/**
		 * @brief A method to add components to the entity
		 * @tparam T 
		 * @return A pointer to the component
		*/
		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_self = rtn;
			rtn->m_entity = m_self;

			m_components.push_back(rtn);

			return rtn;
		}

		/**
		 * @brief A method to get a component attached to the entity.
		 * If there is no component found, throw an error.
		 * @tparam T 
		 * @return A pointer to the component attached to the entity
		*/
		template <typename T>
		std::shared_ptr<T> GetComponent()
		{
			for (std::list<std::shared_ptr<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
			{
				
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);

				if (rtn)
				{
					return rtn;
				}
			}

			std::cout << "No component found while getting component" << "\n";
			throw std::runtime_error("Specified component not found");
		}


		/**
		 * @brief A getter to get the transform of the entity
		 * @return A pointer to the transform component of the entity
		*/
		std::shared_ptr<Transform> GetTransform();

		/**
		 * @brief A getter to get the name of the entity
		 * @return The name of the entity as a string
		*/
		std::string GetName();

		/**
		 * @brief A getter to get the core
		 * @return A pointer to the core
		*/
		std::shared_ptr<Core> GetCore();

		/**
		 * @brief A method to see if the entity is still alive
		 * @return The status of the entity (dead or alive)
		*/
		bool IsAlive() { return m_alive; };

		/**
		 * @brief A method to kill the entity.
		 * (Sets the entities alive bool to false)
		*/
		void Kill();

	private:
		friend struct Core;

		std::list<std::shared_ptr<Component>> m_components;

		/**
		 * @brief A method to call each component's tick
		*/
		void Tick();

		/**
		 * @brief A method to call each component's display
		*/
		void Display();

		/**
		 * @brief A method to call each component's start
		*/
		void Start();

		bool m_alive = true; ///< A bool to see if the entity is destroyed or not
		std::string m_name; ///< The given name of the entity

		std::weak_ptr<Transform> m_transform; ///< A pointer to the entities' transform
		std::weak_ptr<Core> m_core; ///< A pointer to the main core
		std::weak_ptr<Entity> m_self; ///< A pointer to itself
	};
	
}
#endif