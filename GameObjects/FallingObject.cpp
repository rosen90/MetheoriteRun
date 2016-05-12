/*
 * FallingObject.cpp
 *
 *  Created on: May 10, 2016
 *      Author: default
 */

#include "FallingObject.h"
#include <iostream>
#include <SDL2/SDL_timer.h>
#include "World.h"

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

	if( m_currentSprite == 24)
	{
		SetX(rand() % World::GetScreenWidth());
		SetY(0);
		SetVelocityY(5 + rand() % 10);
		SetVelocityX(-4);
		SetPower(1);
		SetHealth(1);
		dying = false;
		m_currentSprite = 5;
	}
}

void FallingObject::Collide(IColidable* colide)
{
	FallingObject* temp = dynamic_cast<FallingObject*>(colide);

	/*if(temp != NULL)
	{
		SetVelocityX(-GetVelocityX());
		temp->SetVelocityX(-temp->GetVelocityX());
	}
	else*/ if(temp == NULL)
	{
		MovableGameObject::Collide(colide);
	}
}

}
