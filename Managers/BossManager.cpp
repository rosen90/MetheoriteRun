#include "BossManager.h"

namespace Managers {

	BossManager* BossManager::Instance = 0;

	BossManager::BossManager()
	{
	}

	BossManager::~BossManager()
	{
		Instance = 0;
	}

	bool BossManager::Process()
	{
		for (Contracts::IManager* manager : clients)
		{
			if (!manager->Process())
			{
				return false;
			}
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
