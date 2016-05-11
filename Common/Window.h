#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Window
{
public:

	Window();
	virtual ~Window();

	static const int SCREEN_WIDTH = 1191;
	static const int SCREEN_HEIGHT = 670;

	bool init();
	bool loadImages();
	SDL_Texture* loadTexture(std::string);

	SDL_Texture*& getBackground();

	void setBackground(SDL_Texture*& background);

	SDL_Renderer*& getRenderer();

	void setRenderer(SDL_Renderer*& renderer);

	SDL_Surface*& getScreenSurface();

	void setScreenSurface(SDL_Surface*& screenSurface);

	SDL_Window*& getWindow();

	void setWindow(SDL_Window*& window);

	void UpdateScreen();

private:

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	SDL_Surface* m_ScreenSurface;
	SDL_Texture* background;

};

extern Window MainWidow;



#endif
