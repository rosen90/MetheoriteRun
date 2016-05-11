#include "MovableGameObject.h"
#include "../Managers/BossManager.h"

namespace GameObjects {

	MovableGameObject::MovableGameObject(int x, int y, int w, int h, int vX, int vY, std::string path)
		: Contracts::IMovable(), BaseGameObject(x, y, w, h, path), velocityX(vX), velocityY(vY)
	{
		Managers::BossManager::GetManager<Contracts::IMovable*>()->AddClient(this);
	}

	MovableGameObject::~MovableGameObject()
	{
	}

	void MovableGameObject::Move()
	{
		SetX(GetX() + GetVelocityX());
		SetY(GetY() + GetVelocityY());
	}

	int MovableGameObject::GetVelocityX()
	{
		return velocityX;
	}

	int MovableGameObject::GetVelocityY()
	{
		return velocityY;
	}

	void MovableGameObject::SetVelocityX(int velocityX)
	{
		this->velocityX = velocityX;
	}

	void MovableGameObject::SetVelocityY(int velocityY)
	{
		this->velocityY = velocityY;
	}
}
