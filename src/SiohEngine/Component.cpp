#include "Component.h"
#include "Entity.h"

namespace SiohEngine
{
	void Component::OnTick()
	{

	}

	void Component::OnDisplay()
	{

	}

	void Component::Start()
	{

	}

	void Component::Tick()
	{
		OnTick();
	}

	void Component::Display()
	{
		OnDisplay();
	}

	void Component::Kill()
	{
		if (!m_alive) return;

		m_alive = false;
	}

	std::shared_ptr<Entity> Component::GetEntity() const
	{
		return m_entity.lock();
	}
}
