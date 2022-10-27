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
		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

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

			std::cout << "no component" << "\n";
		}

		std::shared_ptr<Transform> GetTransform();

	private:
		friend struct Core;
		std::list<std::shared_ptr<Component>> m_components;

		void Tick();
		void Display();

		std::weak_ptr<Transform> m_transform;
	};
	
}

