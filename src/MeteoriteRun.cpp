#include <iostream>
#include "../Managers/BossManager.h"
#include "../Managers/DrawManager.h"
#include "../Managers/EventManager.h"
#include "../Managers/MovableManager.h"
#include "../Managers/CollisionManager.h"
#include "../GameObjects/Background.h"
#include "../GameObjects/Character.h"
#include "../GameObjects/FallingObject.h"

using namespace std;
using namespace Managers;
using namespace GameObjects;


int main()
{
	BossManager* man = BossManager::GetInstance();
	man->AddClient(new EventManager());
	man->AddClient(new DrawManager());
	man->AddClient(new CollisionManager());
	man->AddClient(new MovableManager());

	vector<void*> obj;

	obj.push_back(new Background());
	obj.push_back(new Character(10, 600, 5));
	obj.push_back(new FallingObject(200, 1, 2));
	obj.push_back(new FallingObject(300, 2, 3));
	obj.push_back(new FallingObject(700, -4, 10));

	while(man->Process())
	{
	}

	return 0;
}
