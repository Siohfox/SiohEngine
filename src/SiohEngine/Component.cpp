#include "Component.h"


namespace SiohEngine
{
	void SiohEngine::Component::OnTick()
	{

	}

	void SiohEngine::Component::OnDisplay()
	{

	}

	void SiohEngine::Component::Tick()
	{
		OnTick();
	}

	void SiohEngine::Component::Display()
	{
		OnDisplay();
	}
}
