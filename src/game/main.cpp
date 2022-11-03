#include <iostream>
#include <SiohEngine/SiohEngine.h>

using namespace SiohEngine;

#define shared std::shared_ptr
#define weak std::weak_ptr

struct Player : Component
{
	void OnTick()
	{
		//std::cout << "Ticking "  << counter << std::endl;
		counter++;
	}

	void OnDisplay()
	{
		
	}
};

int main(int argc, char* argv[])
{
	// Initialise Engine
	shared<Core> core = Core::Init();

	std::shared_ptr<Entity> e = core->AddEntity();

	e->AddComponent<Player>();
	e->AddComponent<TriangleRenderer>();

	

	std::cout << e->IsAlive();

	core->Start();

	return 0;
}