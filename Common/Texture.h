#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>

#ifndef TEXTURE_H_
#define TEXTURE_H_

class Texture
{
public:

	Texture();
	virtual ~Texture();


	bool loadFromFile(SDL_Renderer* gRenderer, std::string path );

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(SDL_Renderer* gRenderer, SDL_Rect* renderQuad = NULL, SDL_Rect* clip = NULL );
	void ballRender(SDL_Renderer* gRender, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

	bool loadFromRenderedText(SDL_Renderer*, TTF_Font*, std::string, SDL_Color);
	void renderText(SDL_Renderer*, int x, int y);

	int getWidth();
	int getHeight();
	SDL_Texture*& getTexture();
	void setTexture(SDL_Texture*& texture);

private:

	SDL_Texture* mTexture;

	int mWidth;
	int mHeight;
};

#endif /* TEXTURE_H_ */
