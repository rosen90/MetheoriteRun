/*
 * FallingObject.cpp
 *
 *  Created on: May 10, 2016
 *      Author: default
 */

#include "FallingObject.h"

namespace GameObjects
{

const std::string FallingObject::LOAD_PATH = "Data/Images/fallingObjects.png";

FallingObject::FallingObject(int posX, int velX, int velY)
	: MovableGameObject(posX, 0, CLIP_SIZE, CLIP_SIZE, velX, velY, LOAD_PATH)
{
	m_currentSprite = 0;
}

FallingObject::~FallingObject() {
	// TODO Auto-generated destructor stub
}


void FallingObject::Move()
{
	if(m_currentSprite < MAX_SPRITE_COUNT - 1)
		m_currentSprite++;

	MovableGameObject::Move();
}


void FallingObject::Draw(SDL_Renderer* renderer)
{
	SetSource(
		(m_currentSprite % SPRITE_PER_LINE) * CLIP_SIZE,
		(m_currentSprite / SPRITE_PER_LINE ) * CLIP_SIZE,
		CLIP_SIZE,
		CLIP_SIZE
	);

	MovableGameObject::Draw(renderer);
}

}
