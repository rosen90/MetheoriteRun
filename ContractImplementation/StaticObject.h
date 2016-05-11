#pragma once
#include "../Contracts/IColidable.h"
namespace ContractImplementations {
	class StaticObject :
		public Contracts::IColidable
	{
	public:
		StaticObject(int x= 0, int y= 0, int w= 0, int h= 0, int health = 0, int power = 0);
		virtual ~StaticObject();

		virtual int GetX() override;
		virtual int GetY() override;
		virtual void SetX(int) override;
		virtual void SetY(int) override;

		virtual int GetW() override;
		virtual int GetH() override;
		virtual void SetW(int) override;
		virtual void SetH(int) override;

		virtual int GetPower() override;
		virtual void SetPower(int p) override;
		virtual int GetHealth() override;
		virtual void SetHealth(int h) override;
		virtual void OnDestroy() override;

		virtual void Collide(IColidable* obj) override;
		virtual bool CheckCollision(IColidable* other) override;
	protected:
		int x, y, width, height, health, power;
	};
}

