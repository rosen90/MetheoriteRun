#include <iostream>
#include "../Managers/BossManager.h"
#include "../Managers/DrawManager.h"
#include "../Managers/EventManager.h"
#include "../Managers/MovableManager.h"
#include "../GameObjects/BaseGameObject.h"
#include "../GameObjects/Character.h"
#include "../GameObjects/FallingObject.h"

using namespace std;
using namespace Managers;
using namespace GameObjects;


int main()
{
	BossManager* man = BossManager::GetInstance();
	man->AddClient(new MovableManager());
	man->AddClient(new EventManager());
	man->AddClient(new DrawManager());

	BaseGameObject background(0, 0, DrawManager::SCREEN_WIDTH, DrawManager::SCREEN_HEIGHT, "Data/Images/background.png");

	Character player(10, 450, 10);
	FallingObject obj = FallingObject(200, 10, 10);
	FallingObject obj1 = FallingObject(150, 5, 12);
	FallingObject obj2 = FallingObject(700, -4, 10);

	while(man->Process())
	{
	}

	return 0;
}
