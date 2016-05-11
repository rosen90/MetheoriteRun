#pragma once
#include "../Contracts/ISizable.h"
namespace ContractImplementations {
	class StaticObject :
		public Contracts::ISizable
	{
	public:
		StaticObject(int = 0, int = 0, int = 0, int = 0);
		virtual ~StaticObject();

		virtual int GetX() override;
		virtual int GetY() override;
		virtual void SetX(int) override;
		virtual void SetY(int) override;

		virtual int GetW() override;
		virtual int GetH() override;
		virtual void SetW(int) override;
		virtual void SetH(int) override;
	protected:
		int x, y, width, height;
	};
}

