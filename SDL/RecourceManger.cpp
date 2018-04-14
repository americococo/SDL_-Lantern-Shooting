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

	_TextureMap.clear();//�ϴ� ���� 
}


SDL_Texture * RecourceManger::FindTexture(std::string fileName)
{
	//Ž��
	std::map<std::string, SDL_Texture*>::iterator it = _TextureMap.find(fileName);//�ݺ��ڸ� �����鼭 fileName  fnf
	if (it != _TextureMap.end())//�Ǹ������� �����ϸ� ��ã�Ҵ� ������ ���� NULL
	{
		return it->second;
	}

	SDL_Texture * _texture = IMG_LoadTexture(GameSystem::Getinstance()->GetRender(), fileName.c_str());

	_TextureMap[fileName] = _texture;

	return _texture;
}