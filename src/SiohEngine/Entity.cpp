#include "Entity.h"
#include "Component.h"

namespace SiohEngine
{
	void SiohEngine::Entity::Tick()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = m_components.begin(); it != m_components.end(); ++it)
		{
			(*it)->Tick();
		}

	}

	void SiohEngine::Entity::Display()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = m_components.begin(); it != m_components.end(); ++it)
		{
			(*it)->Display();
		}
	}
}
