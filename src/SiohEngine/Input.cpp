#include "Input.h"

namespace SiohEngine 
{
	std::list<SDL_KeyCode> keys = {};
	std::list<SDL_Keycode> keyDown = {};
	std::list<SDL_Keycode> keyUp = {};

	bool GetKeyDown(SDL_Keycode code)
	{
		for (auto it = keyDown.begin(); it != keyDown.end(); it++)
		{
			if ((*it) == code)
			{
				return true;
			}
		}
		return false;
	}

	bool GetKeyUp(SDL_Keycode code)
	{
		for (auto it = keyUp.begin(); it != keyUp.end(); it++)
		{
			if ((*it) == code)
			{
				return true;
			}
		}
		return false;
	}

	bool GetKey(SDL_Keycode code)
	{
		for (auto it = keys.begin(); it != keys.end(); it++)
		{
			if ((*it) == code)
			{
				return true;
			}
		}
		return false;
	}
}

