#pragma once
#include "SDL2/SDL_keycode.h"

namespace Contracts
{
	class IControlable
	{
	public:
		virtual void HandleKey(SDL_Keycode e) = 0;
	};
}
