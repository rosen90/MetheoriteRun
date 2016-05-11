#pragma once
struct SDL_Renderer;

namespace Contracts
{
	class IDrawable
	{
	public:
		virtual void Draw(SDL_Renderer*) = 0;
		virtual bool Load(SDL_Renderer*) = 0;
		virtual void SetSource(int, int, int, int) = 0;
	};
}

