#include "StaticObject.h"
#include "../Managers/BossManager.h"

namespace ContractImplementations {

	StaticObject::StaticObject(int x, int y, int width, int height)
		: Contracts::ISizable(), x(x), y(y), width(width), height(height)
	{
		//Managers::BossManager::GetManager<Contracts::ISizable*>()->AddClient(this);
	}

	StaticObject::~StaticObject()
	{
	}

	int StaticObject::GetX()
	{
		return x;
	}

	int StaticObject::GetY()
	{
		return y;
	}

	void StaticObject::SetX(int x)
	{
		this->x = x;
	}

	void StaticObject::SetY(int y)
	{
		this->y = y;
	}

	int StaticObject::GetW()
	{
		return width;
	}

	int StaticObject::GetH()
	{
		return height;
	}

	void StaticObject::SetW(int w)
	{
		this->width = w;
	}

	void StaticObject::SetH(int h)
	{
		this->height = h;
	}
}
