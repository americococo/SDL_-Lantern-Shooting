#pragma once

#include <iostream>
#include <map>
#include <string>

struct SDL_Texture;

class RecourceManger
{
private:
	static RecourceManger* instance;

	RecourceManger();
public:
	~RecourceManger();

public:
	static RecourceManger*  GetInstance();


private:
	std::map<std::string, SDL_Texture *> _TextureMap; //stl���ӽ����̽��� map�� ��� (char * Ű���� ����� SDL_Texture�� ����(������))	

public:
	SDL_Texture * FindTexture(std::string fileName);
};