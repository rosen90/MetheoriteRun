#include "Character.h"

const int Character::CHARACTER_ANIMATION = 8;
const int Character::CLIP_HEIGHT = 140;
const int Character::CLIP_WIDTH = 108;
const std::string Character::LOAD_PATH = "Data/Images/playerSprite.png";

Character::Character(int initialPosX, int initialPosY, int velX)
	: ControlableGameObject( initialPosX, initialPosY, CLIP_WIDTH, CLIP_HEIGHT , velX, 0, LOAD_PATH)
{
	m_currentSprite = 0;
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

void Character::Draw(SDL_Renderer* renderer)
{

	if(currentDir != eUp)
	{
		SetSource(m_currentSprite * CLIP_WIDTH,
			currentDir * CLIP_HEIGHT,
			CLIP_WIDTH,
			CLIP_HEIGHT
		);
	}

	ControlableGameObject::Draw(renderer);
}


void Character::Move()
{
	if(moveAllowed)
	{
		switch (currentDir) {
			case eUp:
				moveAllowed = true;
				break;
			case eRight:
					m_currentSprite += (m_currentSprite != CHARACTER_ANIMATION - 1 ? 1 : -(CHARACTER_ANIMATION-1));
					ControlableGameObject::Move();
				break;
			case eLeft:
					m_currentSprite += (m_currentSprite != 0 ? -1 : CHARACTER_ANIMATION - 1);
					ControlableGameObject::Move();
				break;
			default:
				break;
		}
	}
}
