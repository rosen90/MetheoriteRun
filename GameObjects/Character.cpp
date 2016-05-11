#include "Character.h"
#include <SDL2/SDL_events.h>
#include <iostream>
#include <SDL2/SDL_timer.h>

const int Character::CHARACTER_ANIMATION = 8;
const int Character::CLIP_HEIGHT = 140;
const int Character::CLIP_WIDTH = 108;

const std::string Character::LOAD_PATH = "Data/Images/playerSprite.png";

Character::Character(int initialPosX, int initialPosY, int velX, int velY)
	: ControlableGameObject( initialPosX, initialPosY, CLIP_WIDTH, CLIP_HEIGHT , velX, velY, 100, 1, LOAD_PATH)
{
	m_currentSprite = 0;
	jumpFrame = 0;
	SetVelocityX(0);
	SetVelocityY(0);

	currentFrame = 0;
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

void Character::Draw(SDL_Renderer* renderer)
{
	if(SDL_GetTicks() - 1000/FPS >= currentFrame)
	{
		switch (currentDir) {
			case eLeft:
				m_currentSprite += (m_currentSprite != 0 ? -1 : CHARACTER_ANIMATION - 1);
				break;
			case eRight:
				m_currentSprite += (m_currentSprite != CHARACTER_ANIMATION - 1 ? 1 : -(CHARACTER_ANIMATION-1));
				break;
			default:
				break;
		}

		currentFrame = SDL_GetTicks();
	}

	if(currentDir != eNone && currentDir != eUp)
	{
		SetSource(m_currentSprite * CLIP_WIDTH, currentDir * CLIP_HEIGHT, CLIP_WIDTH, CLIP_HEIGHT);
	}

	ControlableGameObject::Draw(renderer);
}


void Character::Move(){
	ControlableGameObject::Move();
}
