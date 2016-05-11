#include "BossManager.h"
#include <SDL2/SDL_timer.h>

namespace Managers {

	BossManager* BossManager::Instance = 0;

	BossManager::BossManager()
	{
		currentFrame = SDL_GetTicks();
	}

	BossManager::~BossManager()
	{
		Instance = 0;
	}

	bool BossManager::Process()
	{
		if(SDL_GetTicks() - 1000/FPS >= currentFrame)
		{
			for (Contracts::IManager* manager : clients)
			{
				if (!manager->Process())
				{
					return false;
				}
			}

			currentFrame = SDL_GetTicks();
		}

		return true;
	}

	BossManager * BossManager::GetInstance()
	{
		if (Instance == 0)
		{
			Instance = new BossManager();
		}

		return Instance;
	}
}
