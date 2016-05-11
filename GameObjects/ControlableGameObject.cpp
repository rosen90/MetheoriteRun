#include "ControlableGameObject.h"
#include "../Managers/BossManager.h"

namespace GameObjects {
	ControlableGameObject::ControlableGameObject(int x, int y, int w, int h, int vX, int vY, std::string path)
		: Contracts::IControlable(), MovableGameObject(x, y, w, h, vY, vY, path)
		, initialVX(vX), initialVY(vY)
	{
		moveAllowed = false;
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
			moveAllowed = true;
			break;
		case SDLK_LEFT:
			moveAllowed = true;
			SetVelocityX(-initialVX);
			break;
		case SDLK_RIGHT:
			moveAllowed = true;
			SetVelocityX(initialVX);
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
