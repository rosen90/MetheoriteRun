/*
 * Background.cpp
 *
 *  Created on: May 11, 2016
 *      Author: default
 */

#include "Background.h"
#include "../Managers/DrawManager.h"
#include "Character.h"

namespace GameObjects {

Background::Background()
	:BaseGameObject(0, 0, Managers::DrawManager::SCREEN_WIDTH,
			Managers::DrawManager::SCREEN_HEIGHT, INFINITY, 1, "Data/Images/background.png")
{
	SetSource(0, 0, Managers::DrawManager::SCREEN_WIDTH * 2, Managers::DrawManager::SCREEN_HEIGHT);
}

Background::~Background() {
	// TODO Auto-generated destructor stub
}

bool Background::CheckCollision(IColidable* other) {

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

void Background::Draw(SDL_Renderer* renderer) {
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

void Background::Collide(IColidable* other) {
	Character* charecter = dynamic_cast<Character*>(other);
	if(charecter != NULL)
	{
		SetX(GetX() - charecter->GetInitialVX());
		charecter->Stop();
		return;
	}
	BaseGameObject::Collide(other);
}

} /* namespace GameObjects */
