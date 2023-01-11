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
	}

	void OnTick()
	{
		std::cout << score;
	}

	
private:
	int score;

};