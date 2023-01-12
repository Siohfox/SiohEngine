#include "Entity.h"
#include "Component.h"
#include "Core.h"

namespace SiohEngine
{
	Entity::Entity()
	{
		m_name = "GenericObject";
	}

	Entity::Entity(std::string name)
	{
		m_name = name;
	}

	std::shared_ptr<Transform> Entity::GetTransform()
	{
		return m_transform.lock();
	}

	std::string Entity::GetName()
	{
		return m_name;
	}

	std::shared_ptr<Core> Entity::GetCore()
	{
		return m_core.lock();
	}

	void Entity::Kill()
	{
		if (!m_alive) return;

		m_alive = false;

		for (std::list<std::shared_ptr<Component>>::iterator it = m_components.begin(); it != m_components.end(); ++it)
		{
			(*it)->Kill();
		}
	}

	void Entity::Tick()
	{
		for (std::list<std::shared_ptr<Component>>::iterator it = m_components.begin(); it != m_components.end(); ++it)
		{
			(*it)->Tick();
		}

	}

	void Entity::Display()
	{
		for (std::list<std::shared_ptr<Component>>::iterator it = m_components.begin(); it != m_components.end(); ++it)
		{
			(*it)->Display();
		}
	}


	void Entity::Start()
	{
		for (std::list<std::shared_ptr<Component>>::iterator it = m_components.begin(); it != m_components.end(); ++it)
		{
			(*it)->Start();
		}
	}
}
