#pragma once

namespace Contracts
{
	class IColidable
	{
	public:
		virtual int GetX() = 0;
		virtual int GetY() = 0;
		virtual void SetX(int) = 0;
		virtual void SetY(int) = 0;

		virtual int GetW() = 0;
		virtual int GetH() = 0;
		virtual void SetW(int) = 0;
		virtual void SetH(int) = 0;

		virtual int GetPower() = 0;
		virtual void SetPower(int p) = 0;
		virtual int GetHealth() = 0;
		virtual void SetHealth(int h) = 0;
		virtual void OnDestroy() = 0;

		virtual void Collide(IColidable* obj) = 0;
		virtual bool CheckCollision(IColidable* other) = 0;
	};
}
