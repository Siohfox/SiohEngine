#pragma once

#include <iostream>
#include "SiohEngine/SiohEngine.h"

using namespace SiohEngine;


struct Player : Component
{
	Player() : m_count(0) {}

	void OnTick();


private:
	float m_count;
};