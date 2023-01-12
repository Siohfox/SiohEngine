#pragma once

#include <iostream>
#include "SiohEngine/SiohEngine.h"

using namespace SiohEngine;



struct Collectables : Component
{
	Collectables();

	~Collectables();

	void OnTick();
};