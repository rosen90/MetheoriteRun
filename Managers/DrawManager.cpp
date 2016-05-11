#include "DrawManager.h"
#include "../Contracts/IDrawable.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace Managers {
	DrawManager::DrawManager()
		: ContractImplementations::GenericManager<Contracts::IDrawable*>()
	{
		renderer = NULL;
		window = NULL;
		InitSDL();
	}

	DrawManager::~DrawManager()
	{
		QuitSDL();
		renderer = NULL;
		window = NULL;
	}

	bool DrawManager::Process()
	{
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		for (Contracts::IDrawable* drawable : clients)
		{
			drawable->Draw(renderer);
		}

		SDL_RenderPresent(renderer);

		return true;
	}
	void DrawManager::AddClient(Contracts::IDrawable * client)
	{
		client->Load(renderer);
		ContractImplementations::GenericManager<Contracts::IDrawable*>::AddClient(client);
	}

	void DrawManager::InitSDL()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}

		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		}

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		}
	}
	void DrawManager::QuitSDL()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);

		IMG_Quit();
		SDL_Quit();
	}
}
