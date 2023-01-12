#pragma once

#include <iostream>
#include "SiohEngine/SiohEngine.h"

using namespace SiohEngine;

struct MainCam : Component
{
	MainCam() {}

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