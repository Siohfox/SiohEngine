#ifndef SIOHENGINE_COMPONENT_H
#define SIOHENGINE_COMPONENT_H

#include "SiohMath.h"
#include <memory>

namespace SiohEngine
{
	struct Entity;

	struct Component
	{
	public:
		int counter = 0;

	private:
		friend struct Entity;

		virtual void OnTick();
		virtual void OnDisplay();

		void Tick();
		void Display();

		void Kill();

		bool m_alive = true;

	protected:
		std::weak_ptr<Entity> m_entity;
		std::weak_ptr<Component> m_self;
	};
}

#endif