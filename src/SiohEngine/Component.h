#ifndef SIOHENGINE_COMPONENT_H
#define SIOHENGINE_COMPONENT_H

namespace SiohEngine
{
	struct Entity;

	struct Component
	{
	public:
		int counter = 0;

	private:
		friend struct Entity;

		virtual void OnTick();
		virtual void OnDisplay();

		void Tick();
		void Display();

		
	};
}

#endif