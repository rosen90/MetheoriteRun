#include "BaseGameObject.h"
#include <SDL2/SDL_render.h>

namespace GameObjects {

	BaseGameObject::BaseGameObject(int x, int y, int w, int h, std::string path)
		: StaticObject(x, y, w, h), Drawable(path)
	{
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
