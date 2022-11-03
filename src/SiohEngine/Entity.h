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
		Entity();
		Entity(std::string name);


		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_self = rtn;
			rtn->m_entity = m_self;

			m_components.push_back(rtn);

			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> GetComponent()
		{
			for (std::list<Shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
			{
				if (rtn)
				{
					return rtn;
				}
			}

			std::cout << "No component found while getting component" << "\n";
		}

		std::shared_ptr<Transform> GetTransform();

		bool IsAlive() { return m_alive; };
		void Kill();

	private:
		friend struct Core;

		std::list<std::shared_ptr<Component>> m_components;

		void Tick();
		void Display();

		bool m_alive = true;
		std::string m_name;

		std::weak_ptr<Transform> m_transform;

		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;
	};
	
}

