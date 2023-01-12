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
	std::cout << "Collectable count currently equal to: " << collectableCount << std::endl;
	if (collectableCount <= maxCollectableCount)
	{
		collectableCount += 1;

		std::shared_ptr<Entity> collectable = GetEntity()->GetCore()->AddEntity();

		collectable->AddComponent<ModelRenderer>();
		collectable->GetComponent<ModelRenderer>()->SetModel(GetEntity()->GetCore()->GetCache()->load<ModelLoad>("../resources/models/maxwell/Maxwell.obj"));
		collectable->GetComponent<ModelRenderer>()->SetTexture(GetEntity()->GetCore()->GetCache()->load<TextureLoad>("../resources/models/maxwell/Maxwell_Diffuse.bmp"));
		collectable->GetComponent<Transform>()->SetPosition(vec3(((float(rand()) / float(RAND_MAX)) * (spawnRangeMax - spawnRangeMin)) + spawnRangeMin, 0.0f, ((float(rand()) / float(RAND_MAX)) * (spawnRangeMax - spawnRangeMin)) + spawnRangeMin));
		collectable->GetComponent<Transform>()->SetScale(vec3(0.1f));
		collectable->GetComponent<Transform>()->SetRotation(transform->GetRotation());
		collectable->AddComponent<BoxCollider>();
	}
}