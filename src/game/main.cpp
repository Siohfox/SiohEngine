#include <iostream>
#include <SiohEngine/SiohEngine.h>
#include "game/Player.h"
#include "game/Collectables.h"
#include "game/GameManager.h"
#include "game/MainCam.h"

using namespace SiohEngine;



int main(int argc, char* argv[])
{

	srand(static_cast<unsigned int>(time(0)));

	// Initialise Engine
	shared<Core> core = Core::Init();

	//AudioClip clip;
	std::shared_ptr<AudioClip> clip = core->GetCache()->load<AudioClip>("../resources/FreeBirb.ogg");
	std::shared_ptr<AudioClip> clip2 = core->GetCache()->load<AudioClip>("../resources/terrar.ogg");
	std::shared_ptr<AudioClip> clip3 = core->GetCache()->load<AudioClip>("../resources/monch.ogg");

	//Models
	std::shared_ptr<Model> maxwellModel = core->GetCache()->load<Model>("../resources/models/maxwell/Maxwell.obj");
	std::shared_ptr<Model> floorModel = core->GetCache()->load<Model>("../resources/models/floor/LP_Stone_floor.obj");

	//Textures
	std::shared_ptr<Texture> maxwellTexture = core->GetCache()->load<Texture>("../resources/models/maxwell/Maxwell_Diffuse.bmp");
	std::shared_ptr<Texture> floorTexture = core->GetCache()->load<Texture>("../resources/models/floor/Stone_floor_albedo.png");

	/*************************************************************************
	* Camera set up
	*************************************************************************/
	std::shared_ptr<Entity> camera = core->AddEntity("Camera");
	std::shared_ptr<Camera> mainCam = camera->AddComponent<Camera>();
	mainCam->SetMainCam(mainCam);
	camera->AddComponent<MainCam>();
	camera->GetTransform()->SetPosition(vec3(0.0f, 5.0f, 0.0f));
	camera->GetTransform()->SetRotation(vec3(-20.0f, 0.0f, 0.0f));

	/*************************************************************************
	* Game Manager set up
	*************************************************************************/
	std::shared_ptr<Entity> gameManager = core->AddEntity("Game Manager");
	gameManager->AddComponent<GameManager>();


	/*************************************************************************
	* Entities
	*************************************************************************/
	// ent 1
	std::shared_ptr<Entity> entity = core->AddEntity("Maxwell");
	entity->AddComponent<Player>();
	entity->AddComponent<ModelRenderer>();
	entity->GetComponent<ModelRenderer>()->SetModel(maxwellModel);
	entity->GetComponent<ModelRenderer>()->SetTexture(maxwellTexture);
	entity->GetTransform()->SetPosition(vec3(-0.5f, -0.5f, -10.0f));
	entity->GetTransform()->SetScale(vec3(0.1f));
	entity->AddComponent<AudioSource>();
	entity->GetComponent<AudioSource>()->PlaySound(clip2, 0.5f, true);
	entity->AddComponent<BoxCollider>();
	entity->AddComponent<RigidBody>();

	// ent 2
	std::shared_ptr<Entity> entity2 = core->AddEntity();
	entity2->AddComponent<ModelRenderer>();
	entity2->GetComponent<ModelRenderer>()->SetModel(floorModel);
	entity2->GetComponent<ModelRenderer>()->SetTexture(floorTexture);
	entity->AddComponent<AudioSource>();
	entity2->GetTransform()->SetPosition(vec3(2.0f, -0.5f, -10.0f));
	entity2->GetTransform()->SetScale(vec3(10.0f));

	core->Start(); // Start the engine loop

	return 0;
}

