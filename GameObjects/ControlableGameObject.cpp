#include "ControlableGameObject.h"
#include "../Managers/BossManager.h"

namespace GameObjects {
	ControlableGameObject::ControlableGameObject(int x, int y, int w, int h, int vX, int vY, std::string path)
		: Contracts::IControlable(), MovableGameObject(x, y, w, h, vY, vY, path)
		, initialVX(vX), initialVY(vY)
	{
		moveAllowed = false;
		currentDir = eRight;
		Managers::BossManager::GetManager<Contracts::IControlable*>()->AddClient(this);
	}


	ControlableGameObject::~ControlableGameObject()
	{
	}

	void ControlableGameObject::HandleKey(SDL_Keycode e)
	{
		switch (e)
		{
		case SDLK_UP:
			if(!moveAllowed)
			{
				currentDir = eUp;
				moveAllowed = true;
			}
			break;
		case SDLK_LEFT:
			if(!moveAllowed)
			{
				SetVelocityX(-initialVX);
				currentDir = eLeft;
				moveAllowed = true;
			}
			break;
		case SDLK_RIGHT:
			if(!moveAllowed)
			{
				moveAllowed = true;
				currentDir = eRight;
				SetVelocityX(initialVX);
			}
			break;
		default:
			break;
		}
	}

	void ControlableGameObject::Move()
	{
		if (moveAllowed)
			MovableGameObject::Move();

		moveAllowed = false;
	}
}
