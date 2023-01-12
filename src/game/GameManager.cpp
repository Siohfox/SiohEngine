#include "GameManager.h"

void GameManager::Start()
{
	score = 0;
	collectableCount = 0;
	spawnRangeMin = -20;
	spawnRangeMax = 20;
	maxCollectableCount = 5;

	srand(static_cast<unsigned int>(time(0)));
}

void GameManager::OnTick()
{
	if (collectableCount <= maxCollectableCount)
	{
		collectableCount += 1;

		std::shared_ptr<Entity> collectable = GetEntity()->GetCore()->AddEntity();

		collectable->AddComponent<ModelRenderer>();
		collectable->GetComponent<ModelRenderer>()->SetModel(GetEntity()->GetCore()->GetCache()->load<Model>("../resources/models/banana/ripe-banana.obj"));
		collectable->GetComponent<ModelRenderer>()->SetTexture(GetEntity()->GetCore()->GetCache()->load<Texture>("../resources/models/banana/ripe-banana_u1_v1.png"));
		collectable->GetComponent<Transform>()->SetPosition(vec3(((float(rand()) / float(RAND_MAX)) * (spawnRangeMax - spawnRangeMin)) + spawnRangeMin, 0.0f, ((float(rand()) / float(RAND_MAX)) * (spawnRangeMax - spawnRangeMin)) + spawnRangeMin));
		collectable->GetComponent<Transform>()->SetScale(vec3(0.1f));
		collectable->AddComponent<AudioSource>();
		collectable->GetComponent<Transform>()->SetRotation(transform->GetRotation());
		collectable->AddComponent<BoxCollider>();
	}
}