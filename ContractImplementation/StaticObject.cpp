#include "StaticObject.h"
#include "../GameObjects/World.h"
#include "../GameObjects/World.h"

namespace ContractImplementations {

	StaticObject::StaticObject(GameObjects::World* word,
			int x, int y, int width, int height, int h, int p)
		: Contracts::IColidable(), x(x), y(y), width(width), height(height), health(h), power(p)
	{
		if(word)
			word->GetManager<Contracts::IColidable*>()->AddClient(this);
	}

	StaticObject::~StaticObject()
	{
		GameObjects::World::GetInstance()->GetManager<Contracts::IColidable*>()->RemoveClient(this);
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

	void StaticObject::Collide(IColidable* obj) {
		obj->SetHealth(obj->GetHealth() - GetPower());
		this->SetHealth(this->GetHealth() - obj->GetPower());
		if(obj->GetHealth() <= 0)
		{
			obj->OnDestroy();
		}

		if(this->GetHealth() <= 0)
		{
			this->OnDestroy();
		}
	}

	int StaticObject::GetPower() {
		return power;
	}

	void StaticObject::SetPower(int p) {
		power = p;
	}

	int StaticObject::GetHealth() {
		return health;
	}

	void StaticObject::SetHealth(int h) {
		health = h;
	}

	void StaticObject::OnDestroy() {
		delete this;
	}

	bool StaticObject::CheckCollision(Contracts::IColidable* other) {

		// Find edges of rect1
		int left1 = GetX();
		int right1 = GetX() + GetW();
		int top1 = GetY();
		int bottom1 = GetY() + GetH();

		// Find edges of rect2
		int left2 = other->GetX();
		int right2 = other->GetX() + other->GetW();
		int top2 = other->GetY();
		int bottom2 = other->GetY() + other->GetH();

		// Check edges
		if ( left1 > right2 || right1 < left2 || top1 > bottom2 || bottom1 < top2 ) // Bottom 1 is above top 2
			return false; // No collision

		return true;
	}
}
