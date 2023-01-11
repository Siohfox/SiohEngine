#pragma once

#include <iostream>
#include "SiohEngine/SiohEngine.h"

using namespace SiohEngine;

#define shared std::shared_ptr
#define weak std::weak_ptr
#define transform GetEntity()->GetTransform()
#define input GetEntity()->GetCore()->GetInput()

struct Collectables : Component
{
	Collectables();

	~Collectables();

	void OnTick()
	{
		std::cout << "hi";
	}
};