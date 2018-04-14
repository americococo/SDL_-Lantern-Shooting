#include "Texture.h"
#include "GameSystem.h"
#include "RecourceManger.h"

#include <SDL_image.h>
#include <stdio.h>

#include <string>

Texture::Texture() {}
Texture::Texture(const char * fileName)
{
	_texture = nullptr;

	char filePaht[256];
	
	sprintf(filePaht, "../Resource/image/%s", fileName);

	_texture = IMG_LoadTexture(GameSystem::Getinstance()->GetRender(), filePaht);

	//_texture = RecourceManger::GetInstance()->FindTexture(filePaht);//╫л╠шео

	SDL_QueryTexture(_texture, NULL, NULL, &_srcRect.w, &_srcRect.h);

	{
		_srcRect.x = 0;
		_srcRect.y = 0;

		_destRect.w = _srcRect.w;
		_destRect.h = _srcRect.h;
	}
}
void Texture::setscale(float _w, float _h)
{
	_destRect.w = _srcRect.w*_w;
	_destRect.h = _srcRect.h*_h;
}
void Texture::setPosition(int x, int y)
{
	_destRect.x = x-getRenderWidth()/2;
	_destRect.y = y-getRenderHeight()/2;	
}
void Texture::Render()
{
	SDL_RenderCopy(GameSystem::Getinstance()->GetRender(), _texture, &_srcRect, &_destRect);
}
Texture::~Texture()
{

}
int Texture::getRenderHeight()
{
	return _destRect.h;
}
int Texture::getRenderWidth()
{
	return _destRect.w;
}
