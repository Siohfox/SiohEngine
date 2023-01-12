#pragma once

#include <iostream>
#include "SiohEngine/SiohEngine.h"

using namespace SiohEngine;

struct GameManager : Component
{
	
	void Start();

	void OnTick();

	int ReturnScore() { return score; }
	int ReturnCollectableCount() { return collectableCount; }


	void AddScore(int scoreAmount) { score += scoreAmount; }
	void ModifyCollectableCount(int _collectableCount) { collectableCount -= _collectableCount; }
	
private:
	int score;
	int collectableCount;
	int maxCollectableCount;
	int spawnRangeMin;
	int spawnRangeMax;

};