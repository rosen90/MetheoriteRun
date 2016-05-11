#pragma once
#include "../ContractImplementation/GenericManager.h"

namespace Contracts {
	class IDrawable;
}

struct SDL_Window;
struct SDL_Renderer;

namespace Managers {
	class DrawManager :
		public ContractImplementations::GenericManager<Contracts::IDrawable*>
	{
	public:
		DrawManager();
		virtual ~DrawManager();

		virtual bool Process() override;
		virtual void AddClient(Contracts::IDrawable* client) override;

		static const int SCREEN_WIDTH = 1020;
		static const int SCREEN_HEIGHT = 768;
	private:
		void InitSDL();
		void QuitSDL();

	private:
		SDL_Renderer* renderer;
		SDL_Window* window;
	};
}

