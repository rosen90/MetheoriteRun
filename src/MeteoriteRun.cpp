#include <iostream>
#include "../Managers/BossManager.h"
#include "../Managers/DrawManager.h"
#include "../Managers/EventManager.h"
#include "../Managers/MovableManager.h"
#include "../GameObjects/BaseGameObject.h"
#include "../GameObjects/Character.h"

using namespace std;
using namespace Managers;
using namespace GameObjects;


int main()
{
	BossManager* man = BossManager::GetInstance();
	man->AddClient(new DrawManager());
	man->AddClient(new EventManager());
	man->AddClient(new MovableManager());

	BaseGameObject background(0, 0, DrawManager::SCREEN_WIDTH, DrawManager::SCREEN_HEIGHT, "Data/Images/background.png");

	Character player(10, 450, 15);

	while(man->Process())
	{
	}

	return 0;
}
