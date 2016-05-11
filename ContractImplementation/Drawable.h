#pragma once
#include "../Contracts/IDrawable.h"
#include <string>
#include <SDL2/SDL_rect.h>

struct SDL_Texture;

namespace ContractImplementations {
	class Drawable :
		public Contracts::IDrawable
	{
	public:
		Drawable(std::string path = "");
		virtual ~Drawable();

		// Inherited via IDrawable
		virtual void Draw(SDL_Renderer *) override;
		virtual bool Load(SDL_Renderer *) override;
		virtual void SetSource(int, int, int, int) override;

	protected:
		SDL_Texture* texture;
		SDL_Rect source;
		const std::string loadPath;

		void Free();
	};
}

