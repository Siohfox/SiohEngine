#pragma once

#include <iostream>
#include "SiohEngine/SiohEngine.h"

using namespace SiohEngine;

#define shared std::shared_ptr
#define weak std::weak_ptr
#define transform GetEntity()->GetTransform()
#define input GetEntity()->GetCore()->GetInput()


struct Player : Component
{
	Player() : m_count(0) {}

	void OnTick()
	{
		m_count += 1.0f * Time::DeltaTime();


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

		transform->AddRotation(rend::vec3(0, m_count, 0));

		if (input->GetKey(Keys::L))
		{
			std::shared_ptr<Entity> potato = GetEntity()->GetCore()->AddEntity();
			potato->AddComponent<ModelRenderer>();
			potato->GetComponent<ModelRenderer>()->SetModel(GetEntity()->GetCore()->GetCache()->load<ModelLoad>("../resources/models/maxwell/Maxwell.obj"));
			potato->GetComponent<ModelRenderer>()->SetTexture(GetEntity()->GetCore()->GetCache()->load<TextureLoad>("../resources/models/maxwell/Maxwell_Diffuse.bmp"));
			potato->GetComponent<Transform>()->SetPosition(transform->GetPosition());
			potato->GetComponent<Transform>()->SetScale(vec3(0.1f));
			potato->GetComponent<Transform>()->SetRotation(transform->GetRotation());
		}

		if (input->GetKey(Keys::I))
		{
			std::cout << GetEntity()->GetCore()->GetEntityByName("Game Manager")->GetComponent<Transform>()->GetPosition().x;
		}
	}


private:
	float m_count;
};