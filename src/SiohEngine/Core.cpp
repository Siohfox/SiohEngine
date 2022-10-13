#include "Core.h"
#include "Entity.h"

namespace SiohEngine 
{
	std::shared_ptr<Core> Core::Init()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		return rtn;
	}

	void Core::Start()
	{
		m_running = true;

		while (m_running)
		{
			for (std::list<std::shared_ptr<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); ++it)
			{
				(*it)->Tick();
			}
		}
	}

	void Core::Stop()
	{
		m_running = false;
	}

	std::shared_ptr<Entity> Core::AddEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		m_entities.push_back(rtn);

		return rtn;
	}
}
