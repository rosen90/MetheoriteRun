#pragma once

#include "../ContractImplementation/Drawable.h"
#include "../ContractImplementation/StaticObject.h"

namespace GameObjects {
	class BaseGameObject :
		public ContractImplementations::Drawable,
		public ContractImplementations::StaticObject
	{
	public:
		BaseGameObject(int x = 0, int y = 0, int w = 0, int h = 0, int health = 0, int power = 0, std::string path = "");
		virtual ~BaseGameObject();

		virtual void Draw(SDL_Renderer* renderer) override;
	};
}

