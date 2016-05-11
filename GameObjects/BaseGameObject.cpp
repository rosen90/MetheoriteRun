#include "BaseGameObject.h"
#include <SDL2/SDL_render.h>

namespace GameObjects {

	BaseGameObject::BaseGameObject(World* world ,int x, int y, int w, int h, int health, int power, std::string path)
		:  ContractImplementations::Drawable(world, path), ContractImplementations::StaticObject(world, x, y, w, h, health, power)
	{
		SetSource(0, 0, w ,h);
	}

	BaseGameObject::~BaseGameObject()
	{
	}

	void BaseGameObject::Draw(SDL_Renderer * renderer)
	{
		SDL_Rect dest = {
			GetX(), GetY(), GetW(), GetH()
		};

		SDL_RenderCopy(renderer, texture, &this->source, &dest);
	}
}
