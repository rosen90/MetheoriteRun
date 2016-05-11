#include "BaseGameObject.h"
#include <SDL2/SDL_render.h>

namespace GameObjects {

	BaseGameObject::BaseGameObject(int x, int y, int w, int h, std::string path)
		:  ContractImplementations::Drawable(path), ContractImplementations::StaticObject(x, y, w, h)
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
