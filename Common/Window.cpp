/*
 * Window.cpp
 *
 *  Created on: May 5, 2016
 *      Author: default
 */

#include "Window.h"

Window::Window()
{
	m_Window = NULL;
	m_Renderer = NULL;
	m_ScreenSurface = NULL;
	background = NULL;

}


bool Window::init() {

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Set texture filtering to linear
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		m_Window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_Window == NULL) {
			printf("Window could not be created! SDL Error: %s\n",SDL_GetError());
			success = false;
		} else {
			//Create renderer for window
			m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);
			if (m_Renderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				success = false;
			} else {
				m_ScreenSurface = SDL_GetWindowSurface( m_Window );
				//Initialize renderer color
				SDL_SetRenderDrawColor(m_Renderer, 206,22,22,0);

			}
		}
	}

	return success;
}


bool Window::loadImages()
{
	//Loading success flag
	bool success = true;

	//Load PNG background texture
	background = loadTexture("Resources/Images/background.png");

	if (background == NULL)
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	return success;

}

SDL_Texture* Window::loadTexture(std::string path)
{
	//The final texture
		SDL_Texture* newTexture = NULL;

		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == NULL) {
			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(),
			IMG_GetError());
		} else {
			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(m_Renderer, loadedSurface);
			if (newTexture == NULL) {
				printf("Unable to create texture from %s! SDL Error: %s\n",
						path.c_str(), SDL_GetError());
			}

			SDL_FreeSurface(loadedSurface);
		}
		return newTexture;
}

SDL_Texture*& Window::getBackground()
{
	return background;
}

void Window::setBackground(SDL_Texture*& background)
{
	this->background = background;
}

SDL_Renderer*& Window::getRenderer()
{
	return m_Renderer;
}

void Window::setRenderer(SDL_Renderer*& renderer)
{
	m_Renderer = renderer;
}

SDL_Surface*& Window::getScreenSurface()
{
	return m_ScreenSurface;
}

void Window::setScreenSurface(SDL_Surface*& screenSurface)
{
	m_ScreenSurface = screenSurface;
}

SDL_Window*& Window::getWindow()
{
	return m_Window;
}

void Window::setWindow(SDL_Window*& window) {
	m_Window = window;
}

void Window::UpdateScreen()
{

	//Clear screen
	SDL_SetRenderDrawColor(MainWidow.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);

	// Clear the entire screen to our selected color.
	SDL_RenderClear(MainWidow.getRenderer());

	SDL_RenderCopy(MainWidow.getRenderer(), MainWidow.getBackground(), NULL, NULL);

	// Up until now everything was drawn behind the scenes.
	// This will show the new, red contents of the window.
//	SDL_RenderPresent(MainWidow.getRenderer());
}

Window::~Window() {
	// TODO Auto-generated destructor stub
}

Window MainWidow;


