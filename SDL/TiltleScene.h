#pragma once
#include "Scene.h"

class Sprite;

class TitleScene:public Scene
{
public:
	TitleScene();
	~TitleScene();

	void Init();
	void DeInit();
	void Render();
	void Update(int deltaTime);


private:
	Sprite * _backGround;
};

