/*
 * Background.cpp
 *
 *  Created on: May 11, 2016
 *      Author: default
 */

#include "Background.h"
#include "../Managers/DrawManager.h"

namespace GameObjects {

Background::Background()
	:BaseGameObject(0, 0, Managers::DrawManager::SCREEN_WIDTH, Managers::DrawManager::SCREEN_HEIGHT, "Data/Images/background.png")
{
	// TODO Auto-generated constructor stub

}

Background::~Background() {
	// TODO Auto-generated destructor stub
}

bool Background::CheckCollision(IColidable* other) {
	return false;
}

} /* namespace GameObjects */
