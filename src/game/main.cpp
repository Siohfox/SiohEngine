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
		m_angle += 1.0f;
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

struct Player2 : Component
{
	Player2() : m_count(-2.0) {}

	void OnTick()
	{
		m_count += 0.1 * Time::DeltaTime();;

		std::cout << m_count << "\n";

		GetEntity()->GetTransform()->SetPosition(vec3(-m_count, -0.5, -10));
	}


private:
	float m_count;
};

struct Camewa : Component
{
	Camewa() : m_count(0) {}

	void OnTick()
	{
		m_count += 5.0f * Time::DeltaTime();

		std::cout << "Current time = " << Time::GetTime() << std::endl;

		//GetEntity()->GetTransform()->SetPosition(vec3(m_count, 0, 0));

	}


private:
	float m_count;
};

int main(int argc, char* argv[])
{
	// Initialise Engine
	shared<Core> core = Core::Init();

	AudioClip clip;

	/*************************************************************************
	* Camera set up
	*************************************************************************/
	std::shared_ptr<Entity> camera = core->AddEntity();
	std::shared_ptr<Camera> mainCam = camera->AddComponent<Camera>();
	mainCam->SetMainCam(mainCam);
	camera->AddComponent<Camewa>();

	/*************************************************************************
	* Entities
	*************************************************************************/
	// ent 1
	std::shared_ptr<Entity> entity = core->AddEntity();
	entity->AddComponent<Player>();
	entity->AddComponent<TriangleRenderer>();
	entity->GetTransform()->SetPosition(vec3(-0.5f, -0.5f, -10.0f));
	entity->AddComponent<AudioSource>();
	entity->GetComponent<AudioSource>()->PlaySound(clip, 1.0f);
	entity->AddComponent<BoxCollider>();
	entity->AddComponent<RigidBody>();

	// ent 2
	std::shared_ptr<Entity> entity2 = core->AddEntity();
	entity2->AddComponent<Player2>();
	entity2->AddComponent<TriangleRenderer>();
	entity2->GetTransform()->SetPosition(vec3(2.0f, -0.5f, -10.0f));
	entity2->AddComponent<BoxCollider>();

	std::cout << "Entity x pos: " << entity->GetComponent<Transform>()->GetPosition().x;
	std::cout << "Entity2 x pos: " << entity2->GetComponent<Transform>()->GetPosition().x;

	core->Start();

	return 0;
}