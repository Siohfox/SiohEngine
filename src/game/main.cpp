#include <iostream>
#include <SiohEngine/SiohEngine.h>

using namespace SiohEngine;

#define shared std::shared_ptr
#define weak std::weak_ptr
#define transform GetEntity()->GetTransform()
#define input GetEntity()->GetCore()->GetInput()

struct Player : Component
{
	Player() : m_count(0) {}

	void OnTick()
	{
	 m_count += 0.5f * Time::DeltaTime();


		if (input->GetKey(Keys::W))
		{
			transform->AddPosition(vec3(0.0f, 0.0f, -0.1f));
		}

		if (input->GetKey(Keys::S))
		{
			transform->AddPosition(vec3(0.0f, 0.0f, 0.1f));
		}

		if (input->GetKey(Keys::A))
		{
			transform->AddPosition(vec3(-0.1f, 0.0f, 0.0f));
		}

		if (input->GetKey(Keys::D))
		{
			transform->AddPosition(vec3(0.1f, 0.0f, 0.0f));
		}

		GetEntity()->GetTransform()->AddRotation(rend::vec3(0, m_count, 0));

	}


private:
	float m_count;
};

struct Player2 : Component
{
	Player2() : m_count(-2.0) {}

	void OnTick()
	{
		m_count += 0.1 * Time::DeltaTime();;

		//std::cout << m_count << "\n";

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
		m_count += 0.8f * Time::DeltaTime();
		
	}


private:
	float m_count;
};

int main(int argc, char* argv[])
{
	// Initialise Engine
	shared<Core> core = Core::Init();

	//AudioClip clip;
	std::shared_ptr<AudioClip> clip = core->GetCache()->load<AudioClip>("../resources/FreeBirb.ogg");

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
	entity->AddComponent<ModelRenderer>();
	entity->GetComponent<ModelRenderer>()->SetModel("../resources/models/maxwell/Maxwell.obj");
	entity->GetComponent<ModelRenderer>()->SetTexture("../resources/models/maxwell/Maxwell_Diffuse.bmp");
	entity->GetTransform()->SetPosition(vec3(-0.5f, -0.5f, -10.0f));
	entity->GetTransform()->SetScale(vec3(0.1f));
	entity->AddComponent<AudioSource>();
	entity->GetComponent<AudioSource>()->PlaySound(clip, 1.0f);
	entity->AddComponent<BoxCollider>();
	entity->AddComponent<RigidBody>();

	// ent 2
	std::shared_ptr<Entity> entity2 = core->AddEntity();
	entity2->AddComponent<Player2>();
	entity2->AddComponent<ModelRenderer>();
	entity2->GetComponent<ModelRenderer>()->SetModel("../resources/models/banana/ripe-banana.obj");
	entity2->GetComponent<ModelRenderer>()->SetTexture("../resources/models/banana/ripe-banana_u1_v1.png");
	entity2->GetTransform()->SetPosition(vec3(2.0f, -0.5f, -10.0f));
	entity2->AddComponent<BoxCollider>();

	/*std::cout << "Entity x pos: " << entity->GetComponent<Transform>()->GetPosition().x;
	std::cout << "Entity2 x pos: " << entity2->GetComponent<Transform>()->GetPosition().x;*/

	core->Start();

	return 0;
}