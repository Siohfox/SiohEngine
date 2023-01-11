#pragma once

#include <iostream>
#include "SiohEngine/SiohEngine.h"

using namespace SiohEngine;

#define shared std::shared_ptr
#define weak std::weak_ptr
#define transform GetEntity()->GetTransform()
#define input GetEntity()->GetCore()->GetInput()


struct GameManager : Component
{

	void Start()
	{
		score = 65756;
		collectableCount = 0;

		std::cout << "My name is: " << GetEntity()->GetName() << std::endl;

		srand(static_cast<unsigned int>(time(0)));
	}

	void OnTick()
	{
		if (collectableCount <= 5)
		{
			collectableCount += 1;
			std::cout << "Rand num = " << rand() << std::endl;
			
			std::shared_ptr<Entity> potato = GetEntity()->GetCore()->AddEntity();
			potato->AddComponent<ModelRenderer>();
			potato->GetComponent<ModelRenderer>()->SetModel(GetEntity()->GetCore()->GetCache()->load<ModelLoad>("../resources/models/maxwell/Maxwell.obj"));
			potato->GetComponent<ModelRenderer>()->SetTexture(GetEntity()->GetCore()->GetCache()->load<TextureLoad>("../resources/models/maxwell/Maxwell_Diffuse.bmp"));
			potato->GetComponent<Transform>()->SetPosition(vec3(rand() % 10 + 1, 0.0f, rand() % 10 + 1));
			potato->GetComponent<Transform>()->SetScale(vec3(0.1f));
			potato->GetComponent<Transform>()->SetRotation(transform->GetRotation());
			
		}
	}

	int ReturnScore() { return score; }
	
private:
	int score;
	int collectableCount;

};