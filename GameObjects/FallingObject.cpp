/*
 * FallingObject.cpp
 *
 *  Created on: May 10, 2016
 *      Author: default
 */

#include "FallingObject.h"
#include <iostream>
#include <SDL2/SDL_timer.h>

namespace GameObjects
{

const std::string FallingObject::LOAD_PATH = "Data/Images/fallingObjects.png";

FallingObject::FallingObject(int posX, int velX, int velY)
	: MovableGameObject(posX, 0, CLIP_SIZE, CLIP_SIZE, velX, velY, 1, 1, LOAD_PATH)
{

	m_currentSprite = 0;
	m_currentFrame = 0;
}

FallingObject::~FallingObject() {
	// TODO Auto-generated destructor stub
}


void FallingObject::Move()
{
	if(SDL_GetTicks() - 1000/60 >= m_currentFrame)
	{
		m_currentSprite++;

		if(m_currentSprite == 14)
		{
			m_currentSprite = 6;
		}

		m_currentFrame = SDL_GetTicks();

	}

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
