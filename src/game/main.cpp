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

	std::shared_ptr<Entity> entity = core->AddEntity();

	entity->AddComponent<Player>();
	entity->AddComponent<TriangleRenderer>();

	entity->GetTransform()->SetPosition(vec3(-0.5f, -0.5f, 0.0f));

	

	std::cout << entity->IsAlive();

	core->Start();

	return 0;
}