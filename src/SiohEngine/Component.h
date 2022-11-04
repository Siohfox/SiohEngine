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
		int counter = 0;

	private:
		friend struct Entity;

		/**
		* A virtual function for ticking each frame.
		*/
		virtual void OnTick();

		/**
		* A virtual function for displaying each frame.
		*/
		virtual void OnDisplay();

		/**
		* A function for ticking each frame.
		*/
		void Tick();

		/**
		* A function for displaying each frame.
		*/
		void Display();

		/**
		* A function which will set the alive status of the component to false
		*/
		void Kill();

		bool m_alive = true; ///< A bool to store alive status.

	protected:
		std::weak_ptr<Entity> m_entity;  ///< A weak pointer to the entity attached
		std::weak_ptr<Component> m_self; ///< A weak pointer to the component's self
	};
}

#endif