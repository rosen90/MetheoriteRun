#include "EventManager.h"
#include "../Contracts/IControlable.h"
#include <SDL2/SDL_events.h>

namespace Managers {
	EventManager::EventManager()
		: ContractImplementations::GenericManager<Contracts::IControlable*>()
	{
	}


	EventManager::~EventManager()
	{
	}

	bool EventManager::Process()
	{
		SDL_Event e;

		while (SDL_PollEvent(&e) != NULL)
		{
			if (e.type == SDL_QUIT)
				return false;

			if (e.type == SDL_KEYDOWN)
			{
				for(Contracts::IControlable* controlable : clients)
				{
					controlable->HandleKey(e.key.keysym.sym);
				}
			}
		}

		return true;
	}
}
