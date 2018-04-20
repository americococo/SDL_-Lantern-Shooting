#pragma once
#include <SDL_image.h>
//struct SDL_Texture;
//struct SDL_Rect;

class Texture
{
protected:
	SDL_Rect _srcRect;
	SDL_Rect _destRect;
	SDL_Texture * _texture;

public:
	Texture();
	Texture(const char * fileName);
	void setscale(float W, float h);
	void setPosition(int x, int y);
	void Render();

	int getRenderWidth();
	int getRenderHeight();
	~Texture();
};