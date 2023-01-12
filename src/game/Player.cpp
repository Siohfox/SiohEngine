#include "Player.h"
#include "GameManager.h"

void Player::OnTick()
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
		potato->GetComponent<ModelRenderer>()->SetModel(GetEntity()->GetCore()->GetCache()->load<Model>("../resources/models/maxwell/Maxwell.obj"));
		potato->GetComponent<ModelRenderer>()->SetTexture(GetEntity()->GetCore()->GetCache()->load<Texture>("../resources/models/maxwell/Maxwell_Diffuse.bmp"));
		potato->GetComponent<Transform>()->SetPosition(transform->GetPosition());
		potato->GetComponent<Transform>()->SetScale(vec3(0.1f));
		potato->GetComponent<Transform>()->SetRotation(transform->GetRotation());
	}

	if (input->GetKey(Keys::I))
	{
		std::cout << GetEntity()->GetCore()->GetEntityByName("Game Manager")->GetComponent<Transform>()->GetPosition().x;
	}

	if (input->GetKey(Keys::K))
	{
		GetEntity()->Kill();
	}

	if (GetEntity()->GetComponent<RigidBody>()->CheckCollision().isColliding)
	{

		GetEntity()->GetComponent<RigidBody>()->CheckCollision().other.lock()->GetEntity()->Kill();
		
		GetEntity()->GetComponent<RigidBody>()->CheckCollision().other.lock()->GetEntity()->GetComponent<AudioSource>()->PlaySound(GetEntity()->GetCore()->GetCache()->load<AudioClip>("../resources/monch.ogg"), 1.0f);

		GetEntity()->GetCore()->GetEntityByName("Game Manager")->GetComponent<GameManager>()->AddScore(2500);

		GetEntity()->GetCore()->GetEntityByName("Game Manager")->GetComponent<GameManager>()->ModifyCollectableCount(1);

		std::cout << "Score = " << GetEntity()->GetCore()->GetEntityByName("Game Manager")->GetComponent<GameManager>()->ReturnScore() << std::endl;

	}
}