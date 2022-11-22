#include <iostream>
#include <SiohEngine/SiohEngine.h>

using namespace SiohEngine;

#define shared std::shared_ptr
#define weak std::weak_ptr

struct Player : Component
{
	Player() : m_angle(0), m_count(0) {}

	void OnTick()
	{
		m_angle += 0.1f;
		++m_count;

		GetEntity()->GetTransform()->SetRotation(rend::vec3(0, m_angle, 0));

		if (m_count > 10)

		{
			//GetEntity()->GetCore()->Stop();
		}
	}


private:
	float m_angle;
	int m_count;
};

int main(int argc, char* argv[])
{
	// Initialise Engine
	shared<Core> core = Core::Init();

	AudioClip clip;

	std::shared_ptr<Entity> entity = core->AddEntity();
	entity->AddComponent<Player>();
	entity->AddComponent<TriangleRenderer>();
	entity->GetTransform()->SetPosition(vec3(-0.5f, -0.5f, -10.0f));
	entity->AddComponent<AudioSource>();
	entity->GetComponent<AudioSource>()->PlaySound(clip, 1.0f);

	/*std::shared_ptr<Entity> entity2 = core->AddEntity();
	entity2->AddComponent<Player>();
	entity2->AddComponent<TriangleRenderer>();
	entity2->GetTransform()->SetPosition(vec3(-0.5f, 0.5f, -10.0f));*/

	//std::cout << entity->IsAlive();

	core->Start();

	return 0;
}