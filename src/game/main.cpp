#include <iostream>
#include <SiohEngine/SiohEngine.h>
#include "Player.h"

using namespace SiohEngine;

#define shared std::shared_ptr
#define weak std::weak_ptr
#define transform GetEntity()->GetTransform()
#define input GetEntity()->GetCore()->GetInput()


struct Player : Component
{
	Player() : m_count(0) {}

	/*std::shared_ptr<ModelLoad> maxwellModel = GetEntity()->GetCore()->GetCache()->load<ModelLoad>("../resources/models/maxwell/Maxwell.obj");
	std::shared_ptr<TextureLoad> maxwellTexture = GetEntity()->GetCore()->GetCache()->load<TextureLoad>("../resources/models/maxwell/Maxwell_Diffuse.bmp");*/

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

		if (input->GetKey(Keys::LCTRL))
		{
			transform->AddPosition(vec3(0.0f, -0.1f, 0.0f));
		}

		if (input->GetKey(Keys::SPACE))
		{
			transform->AddPosition(vec3(0.0f, 0.1f, 0.0f));
		}

		GetEntity()->GetTransform()->AddRotation(rend::vec3(0, m_count, 0));

		/*std::shared_ptr<Entity> potato = GetEntity()->GetCore()->AddEntity();
		potato->AddComponent<ModelRenderer>();
		potato->GetComponent<ModelRenderer>()->SetModel(maxwellModel);
		potato->GetComponent<ModelRenderer>()->SetTexture(maxwellTexture);
		potato->GetComponent<Transform>()->SetPosition(vec3(0.0f, 0.0f + m_count, 0.0f));*/
	}


private:
	float m_count;
};

struct Floor : Component
{
	Floor() {}

	void OnTick()
	{
		
	}


	

private:
};

struct Camewa : Component
{
	Camewa() {}

	void OnTick()
	{
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
		transform->SetPosition(vec3(transform->GetPosition().x, 5.0f, transform->GetPosition().z));
	}


private:
};

int main(int argc, char* argv[])
{
	// Initialise Engine
	shared<Core> core = Core::Init();

	//AudioClip clip;
	std::shared_ptr<AudioClip> clip = core->GetCache()->load<AudioClip>("../resources/FreeBirb.ogg");

	//Models
	std::shared_ptr<ModelLoad> maxwellModel = core->GetCache()->load<ModelLoad>("../resources/models/maxwell/Maxwell.obj");
	std::shared_ptr<ModelLoad> floorModel = core->GetCache()->load<ModelLoad>("../resources/models/floor/LP_Stone_floor.obj");

	//Textures
	std::shared_ptr<TextureLoad> maxwellTexture = core->GetCache()->load<TextureLoad>("../resources/models/maxwell/Maxwell_Diffuse.bmp");
	std::shared_ptr<TextureLoad> floorTexture = core->GetCache()->load<TextureLoad>("../resources/models/floor/Stone_floor_albedo.png");

	/*************************************************************************
	* Camera set up
	*************************************************************************/
	std::shared_ptr<Entity> camera = core->AddEntity();
	std::shared_ptr<Camera> mainCam = camera->AddComponent<Camera>();
	mainCam->SetMainCam(mainCam);
	camera->AddComponent<Camewa>();
	camera->GetTransform()->SetPosition(vec3(0.0f, 5.0f, 0.0f));
	camera->GetTransform()->SetRotation(vec3(-20.0f, 0.0f, 0.0f));

	/*************************************************************************
	* Entities
	*************************************************************************/
	// ent 1
	std::shared_ptr<Entity> entity = core->AddEntity();
	entity->AddComponent<Player>();
	entity->AddComponent<ModelRenderer>();
	entity->GetComponent<ModelRenderer>()->SetModel(maxwellModel);
	entity->GetComponent<ModelRenderer>()->SetTexture(maxwellTexture);
	entity->GetTransform()->SetPosition(vec3(-0.5f, -0.5f, -10.0f));
	entity->GetTransform()->SetScale(vec3(0.1f));
	entity->AddComponent<AudioSource>();
	entity->GetComponent<AudioSource>()->PlaySound(clip, 1.0f);
	entity->AddComponent<BoxCollider>();
	entity->AddComponent<RigidBody>();

	// ent 2
	std::shared_ptr<Entity> entity2 = core->AddEntity();
	entity2->AddComponent<Floor>();
	entity2->AddComponent<ModelRenderer>();
	entity2->GetComponent<ModelRenderer>()->SetModel(floorModel);
	entity2->GetComponent<ModelRenderer>()->SetTexture(floorTexture);
	entity2->GetTransform()->SetPosition(vec3(2.0f, -0.5f, -10.0f));
	entity2->GetTransform()->SetScale(vec3(10.0f));
	entity2->AddComponent<BoxCollider>();

	core->Start(); // Start the engine loop

	return 0;
}