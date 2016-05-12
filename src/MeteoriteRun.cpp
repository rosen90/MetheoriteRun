#include <iostream>
#include "../GameObjects/Character.h"
#include "../GameObjects/FallingObject.h"
#include "../GameObjects/World.h"
#include <ctime>
#include <cstdlib>


using namespace std;
using namespace GameObjects;

int main()
{
	World* world = World::GetInstance();

	vector<void*> obj;
	obj.push_back(new Character(world, 10, 600, 15));

	for (int i = 0; i < 100; ++i)
	{

		obj.push_back(new FallingObject(world, rand() % World::GetScreenWidth(), -4, 5 + rand() % 10));
	}

	while(world->Process())
	{
	}

	return 0;
}
