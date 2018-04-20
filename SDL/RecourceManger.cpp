#include "RecourceManger.h"
#include "GameSystem.h"

#include <string>

#include <stdio.h>
#include <SDL_image.h>

RecourceManger * RecourceManger::instance =NULL;

RecourceManger::RecourceManger(){}

RecourceManger* RecourceManger::GetInstance()
{
	if (NULL == instance)
		instance = new RecourceManger();

	return  instance;
}


RecourceManger::~RecourceManger()
{
	std::map<std::string , SDL_Texture*>::iterator it;
	for (it = _TextureMap.begin(); it != _TextureMap.end(); it++)
	{
		delete it->second;
	}

	_TextureMap.clear();//싹다 지움 
}


SDL_Texture * RecourceManger::FindTexture(std::string fileName)
{
	//탐색
	std::map<std::string, SDL_Texture*>::iterator it = _TextureMap.find(fileName);//반복자를 돌리면서 fileName  fnf
	if (it != _TextureMap.end())//맨마지막에 도달하면 못찾았다 마지막 값은 NULL
	{
		return it->second;
	}

	SDL_Texture * _texture = IMG_LoadTexture(GameSystem::Getinstance()->GetRender(), fileName.c_str());

	_TextureMap[fileName] = _texture;

	return _texture;
}