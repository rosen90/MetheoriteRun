#include "Drawable.h"
#include "../Managers/BossManager.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace ContractImplementations {
	Drawable::Drawable(std::string path)
		: Contracts::IDrawable()
	{
		loadPath = path;
		SetSource(0, 0, 0, 0);
		Managers::BossManager::GetManager<Contracts::IDrawable*>()->AddClient(this);
	}

	Drawable::~Drawable()
	{
		Free();
		Managers::BossManager::GetManager<Contracts::IDrawable*>()->RemoveClient(this);
	}

	void Drawable::Draw(SDL_Renderer * renderer)
	{
		SDL_RenderCopy(renderer, texture, &this->source, NULL);
	}

	bool Drawable::Load(SDL_Renderer * renderer)
	{
		texture = NULL;

		SDL_Surface* loadedSurface = IMG_Load(loadPath.c_str());
		if (loadedSurface == NULL)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", "", IMG_GetError());
			return false;
		}

		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", "", SDL_GetError());
			return false;
		}

		SetSource(0, 0, loadedSurface->w, loadedSurface->h);

		SDL_FreeSurface(loadedSurface);
		return true;
	}

	void Drawable::SetSource(int x, int y, int w, int h)
	{
		this->source = {
			x, y, w, h
		};
	}

	void Drawable::Free()
	{
		//Free texture if it exists
		if (texture != NULL)
		{
			SDL_DestroyTexture(texture);
			texture = NULL;
		}
	}
}
