#include <iostream>
#include <SiohEngine/SiohEngine.h>

using namespace SiohEngine;

#define shared std::shared_ptr
#define weak std::weak_ptr

int main(int argc, char* argv[])
{
	// Initialise Engine
	shared<Core> core = Core::Init();

	return 0;
}