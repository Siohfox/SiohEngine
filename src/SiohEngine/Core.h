#include <memory>
#include <list>

namespace SiohEngine
{
	struct Entity;

	struct Core
	{
		static std::shared_ptr<Core> Init();

		std::shared_ptr<Entity> AddEntity();

		void Start();
		void Stop();

	private:
		bool m_running;
		std::list<std::shared_ptr<Entity>> m_entities;
	};
}

