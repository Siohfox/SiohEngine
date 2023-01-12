#pragma once

#include <iostream>
#include "SiohEngine/SiohEngine.h"

using namespace SiohEngine;




struct GameManager : Component
{
	
	void Start()
	{
		score = 65756;
		collectableCount = 0;
		spawnRangeMin = -20;
		spawnRangeMax = 20;
		maxCollectableCount = 5;

		std::cout << "My name is: " << GetEntity()->GetName() << std::endl;

		srand(static_cast<unsigned int>(time(0)));
	}

	void OnTick()
	{
		if (collectableCount <= maxCollectableCount)
		{
			collectableCount += 1;
			std::cout << "Rand num = " << rand() << std::endl;
			
			std::shared_ptr<Entity> potato = GetEntity()->GetCore()->AddEntity();
			potato->AddComponent<ModelRenderer>();
			potato->GetComponent<ModelRenderer>()->SetModel(GetEntity()->GetCore()->GetCache()->load<ModelLoad>("../resources/models/maxwell/Maxwell.obj"));
			potato->GetComponent<ModelRenderer>()->SetTexture(GetEntity()->GetCore()->GetCache()->load<TextureLoad>("../resources/models/maxwell/Maxwell_Diffuse.bmp"));
			potato->GetComponent<Transform>()->SetPosition(vec3(((float(rand()) / float(RAND_MAX)) * (spawnRangeMax - spawnRangeMin)) + spawnRangeMin, 0.0f, ((float(rand()) / float(RAND_MAX)) * (spawnRangeMax - spawnRangeMin)) + spawnRangeMin));
			potato->GetComponent<Transform>()->SetScale(vec3(0.1f));
			potato->GetComponent<Transform>()->SetRotation(transform->GetRotation());
			potato->AddComponent<BoxCollider>();
		}
	}

	int ReturnScore() { return score; }
	
private:
	int score;
	int collectableCount;
	int maxCollectableCount;
	int spawnRangeMin;
	int spawnRangeMax;

};