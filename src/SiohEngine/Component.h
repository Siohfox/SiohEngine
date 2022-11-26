#ifndef SIOHENGINE_COMPONENT_H
#define SIOHENGINE_COMPONENT_H

#include "SiohMath.h"
#include <memory>

namespace SiohEngine
{
	struct Entity;

	/**
	* Component class for Entity to allow object manipulation
	*/
	struct Component
	{
	public:

		/**
		 * @brief A getter for the entity this component is attached to
		 * @return The entity this component is attached to
		*/
		std::shared_ptr<Entity>  GetEntity() const;


	private:
		friend struct Entity;

		/**
		* @brief A virtual function for ticking each frame.
		*/
		virtual void OnTick();

		/**
		* @brief A virtual function for displaying each frame.
		*/
		virtual void OnDisplay();

		/**
		* @brief A function for ticking each frame.
		*/
		void Tick();

		/**
		* @brief A function for displaying each frame.
		*/
		void Display();

		/**
		* @brief A function which will set the alive status of the component to false
		*/
		void Kill();

		

		bool m_alive = true; ///< A bool to store alive status.

	protected:
		std::weak_ptr<Entity> m_entity;  ///< A weak pointer to the entity attached
		std::weak_ptr<Component> m_self; ///< A weak pointer to the component's self
	};
}
#endif