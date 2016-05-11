#pragma once
#include "../Contracts/IMovable.h"
#include "BaseGameObject.h"

namespace GameObjects {

	enum Direction {
		eRight,
		eLeft,
		eUp,
		eUpLeft,
		eUpRight,
		eNone
	};

	class MovableGameObject :
		public Contracts::IMovable, public BaseGameObject
	{
	public:
		MovableGameObject(World* world = NULL, int x = 0, int y = 0, int w = 0, int h = 0, int vX = 0, int vY = 0, int health = 0, int power = 0, std::string path = "");
		virtual ~MovableGameObject();

		virtual void Move() override;

		virtual int GetVelocityX() override;
		virtual int GetVelocityY() override;
		virtual void SetVelocityX(int) override;
		virtual void SetVelocityY(int) override;
		Direction GetDirection();

	protected:
		int velocityX, velocityY;
		Direction currentDir;
	};
}
