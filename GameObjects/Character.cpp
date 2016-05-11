#include "Character.h"

const int Character::CHARACTER_ANIMATION = 8;
const int Character::CLIP_HEIGHT = 140;
const int Character::CLIP_WIDTH = 108;
const std::string Character::LOAD_PATH = "Data/Images/playerSprite.png";

Character::Character(int initialPosX, int initialPosY, int velX)
	: ControlableGameObject( initialPosX, initialPosY, CLIP_WIDTH, CLIP_HEIGHT , velX, 0, LOAD_PATH)
{
	m_currentSprite = 0;
	m_currentDir = eRight;
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

void Character::Draw(SDL_Renderer* renderer)
{

		SetSource(m_currentSprite * CLIP_WIDTH,
		m_currentDir * CLIP_HEIGHT,
		CLIP_WIDTH,
		CLIP_HEIGHT);

	ControlableGameObject::Draw(renderer);
}


void Character::HandleKey(SDL_Keycode e)
{

	ControlableGameObject::HandleKey(e);

	switch (e)
	{
//	case SDLK_UP:
//		moveAllowed = true;
//		break;
	case SDLK_LEFT:
		m_currentDir = eLeft;
		m_currentSprite += (m_currentSprite != 0 ? -1 : CHARACTER_ANIMATION - 1);
		break;
	case SDLK_RIGHT:
		m_currentDir = eRight;
		m_currentSprite += (m_currentSprite != CHARACTER_ANIMATION - 1 ? 1 : -(CHARACTER_ANIMATION-1));
		break;
	default:
		break;
	}
}
