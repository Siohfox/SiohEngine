#include <memory>

namespace SiohEngine
{
	struct Core
	{
		static std::shared_ptr<Core> Init();

	private:
		int m_dummy;
	};
}

