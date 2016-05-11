#include <iostream>
#include "../GameObjects/Character.h"
#include "../GameObjects/FallingObject.h"
#include "../GameObjects/World.h"

using namespace std;
using namespace GameObjects;

int main()
{
	World* world = World::GetInstance();

	vector<void*> obj;
	obj.push_back(new Character(world, 10, 600, 5));
	obj.push_back(new FallingObject(world, 200, 1, 2));
	obj.push_back(new FallingObject(world, 300, 2, 3));
	obj.push_back(new FallingObject(world, 700, -4, 10));

	while(world->Process())
	{
	}

	return 0;
}
