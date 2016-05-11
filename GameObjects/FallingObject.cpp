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

FallingObject::FallingObject(World* world, int posX, int velX, int velY)
	: MovableGameObject(world, posX, 0, CLIP_SIZE, CLIP_SIZE, velX, velY, 1, 1, LOAD_PATH)
{
	dying = false;
	m_currentSprite = 0;
	m_currentFrame = 0;
}

FallingObject::~FallingObject() {
	// TODO Auto-generated destructor stub
}

void FallingObject::Draw(SDL_Renderer* renderer)
{
	if(SDL_GetTicks() - 1000/60 >= m_currentFrame)
	{
		m_currentSprite++;

		if(!dying)
		{
			if( m_currentSprite == 15)
			{
				m_currentSprite = 5;
			}
		}
		else
		{
			if( m_currentSprite == 25)
			{
				delete this;
				return;
			}
		}

		m_currentFrame = SDL_GetTicks();
	}

	SetSource(
		(m_currentSprite % SPRITE_PER_LINE) * CLIP_SIZE,
		(m_currentSprite / SPRITE_PER_LINE ) * CLIP_SIZE,
		CLIP_SIZE,
		CLIP_SIZE
	);

	MovableGameObject::Draw(renderer);
}

void FallingObject::OnDestroy() {
	dying = true;
	SetPower(0);
	SetVelocityX(0);
	SetVelocityY(0);
}

}
