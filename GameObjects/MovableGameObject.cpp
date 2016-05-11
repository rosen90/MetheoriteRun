#include "MovableGameObject.h"
#include "World.h"

namespace GameObjects {

	MovableGameObject::MovableGameObject(World* world, int x, int y, int w, int h, int vX, int vY, int health, int power, std::string path)
		: Contracts::IMovable(), BaseGameObject(world, x, y, w, h, health, power, path), velocityX(vX), velocityY(vY)
	{
		currentDir = eNone;
		if(world)
			world->GetManager<Contracts::IMovable*>()->AddClient(this);
	}

	MovableGameObject::~MovableGameObject()
	{
		World::GetInstance()->GetManager<Contracts::IMovable*>()->RemoveClient(this);
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

	Direction MovableGameObject::GetDirection() {
		return currentDir;
	}
}
