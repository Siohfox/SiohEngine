#include "Component.h"


namespace SiohEngine
{
	void Component::OnTick()
	{

	}

	void Component::OnDisplay()
	{

	}

	void Component::Tick()
	{
		OnTick();
	}

	void Component::Display()
	{
		OnDisplay();
	}
}
