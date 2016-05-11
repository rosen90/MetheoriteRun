/*
 * Background.cpp
 *
 *  Created on: May 11, 2016
 *      Author: default
 */

#include "World.h"

#include "Character.h"
#include "../Managers/DrawManager.h"
#include "../Contracts/IManager.h"
#include "../Managers/DrawManager.h"
#include "../Managers/EventManager.h"
#include "../Managers/MovableManager.h"
#include "../Managers/CollisionManager.h"
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_events.h>

using namespace Managers;

namespace GameObjects {

World* World::Instance = 0;

World::World()
	: ControlableGameObject(NULL, 0, 0, Managers::DrawManager::SCREEN_WIDTH,
			Managers::DrawManager::SCREEN_HEIGHT, 0, 0, INFINITY, 1, "Data/Images/background.png")
	, ContractImplementations::GenericManager<Contracts::IManager*>()
{
	SetSource(0, 0, Managers::DrawManager::SCREEN_WIDTH * 2, Managers::DrawManager::SCREEN_HEIGHT);
	currentFrame = SDL_GetTicks();
	AddClient<Contracts::IControlable*>(new EventManager());
	AddClient<Contracts::IDrawable*>(new DrawManager());
	AddClient<Contracts::IColidable*>(new CollisionManager());
	AddClient<Contracts::IMovable*>(new MovableManager());
	quit = false;
}

World::~World() {
	Instance = 0;
}

bool World::CheckCollision(IColidable* other) {

	int left1 = GetX();
	int right1 = GetX() + GetW();
	int top1 = GetY();
	int bottom1 = GetY() + GetH();

	// Find edges of rect2
	int left2 = other->GetX();
	int right2 = other->GetX() + other->GetW();
	int top2 = other->GetY();
	int bottom2 = other->GetY() + other->GetH();

	Character* charecter = dynamic_cast<Character*>(other);
	if(charecter != NULL)
	{
		return (right2 >= GetW() / 2 && charecter->GetDirection() == eRight);
	}

	// Check edges
	if ( left2 >= left1 && right2 <= right1 && bottom2 <= bottom1 && top2 >= top1 ) // Bottom 1 is above top 2
		return false; // No collision

	return true;
}

void World::Draw(SDL_Renderer* renderer) {
	if(GetX() <= -GetW())
	{
		SetX(0);
	}
	int currentX = GetX();
	BaseGameObject::Draw(renderer);
	SetX(currentX + GetW());
	BaseGameObject::Draw(renderer);
	SetX(currentX);
}

void World::Collide(IColidable* other) {
	Character* charecter = dynamic_cast<Character*>(other);
	if(charecter != NULL)
	{
		SetX(GetX() - charecter->GetInitialVX());
		charecter->Stop();
		return;
	}
	BaseGameObject::Collide(other);
}

bool World::Process()
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

World * World::GetInstance()
{
	if (Instance == 0)
	{
		Instance = new World();
	}

	return Instance;
}

void World::HandleKey(SDL_Event* e) {

}

} /* namespace GameObjects */
