#pragma once
#include "../Contracts/IMovable.h"
#include "BaseGameObject.h"

namespace GameObjects {
	class MovableGameObject :
		public Contracts::IMovable, public BaseGameObject
	{
	public:
		MovableGameObject(int x = 0, int y = 0, int w = 0, int h = 0, int vX = 0, int vY = 0, std::string path = "");
		virtual ~MovableGameObject();

		virtual void Move() override;

		virtual int GetVelocityX() override;
		virtual int GetVelocityY() override;
		virtual void SetVelocityX(int) override;
		virtual void SetVelocityY(int) override;

	protected:
		int velocityX, velocityY;
	};
}
