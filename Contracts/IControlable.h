#pragma once

union SDL_Event;

namespace Contracts
{
	class IControlable
	{
	public:
		virtual void HandleKey(SDL_Event * e) = 0;
	};
}
