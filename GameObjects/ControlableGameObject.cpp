#include "ControlableGameObject.h"
#include "../Managers/BossManager.h"
#include <SDL2/SDL_events.h>

namespace GameObjects {
	ControlableGameObject::ControlableGameObject(int x, int y, int w, int h, int vX, int vY, int health, int power, std::string path)
		: Contracts::IControlable(), MovableGameObject(x, y, w, h, vY, vY, health, power, path)
		, initialVX(vX), initialVY(vY)
	{
		currentDir = eNone;
		Managers::BossManager::GetManager<Contracts::IControlable*>()->AddClient(this);
	}


	ControlableGameObject::~ControlableGameObject()
	{
		Managers::BossManager::GetManager<Contracts::IControlable*>()->RemoveClient(this);
	}

	void ControlableGameObject::Move(){
		switch (currentDir) {
			case eLeft:
				SetVelocityX(-initialVX);
				break;
			case eRight:
				SetVelocityX(initialVX);
				break;
			case eUp:
				SetVelocityY(-initialVY);
				break;
			default:
				SetVelocityX(0);
				SetVelocityY(0);
				break;
		}

		MovableGameObject::Move();
	}

	void ControlableGameObject::HandleKey(SDL_Event * e)
	{
		currentDir = eNone;
		switch (e->key.keysym.sym)
		{
		case SDLK_UP:
				currentDir = (e->type == SDL_KEYDOWN ? eUp : eNone);
			break;
		case SDLK_LEFT:
				currentDir = (e->type == SDL_KEYDOWN ? eLeft : eNone);
			break;
		case SDLK_RIGHT:
				currentDir = (e->type == SDL_KEYDOWN ? eRight : eNone);
			break;
		default:
			break;
		}
	}
}
