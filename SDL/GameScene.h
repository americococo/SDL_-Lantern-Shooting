#pragma once
#include "Scene.h"


class PlayerObcaleCal;
class Sprite;
class Enemy;
class GameObjectManger;
class BulletManger;
class GameScene :public Scene
{
public:
	GameScene();
	~GameScene();

	void Init();
	void DeInit();
	void Render();
	void Update(int deltaTime);


private:
	GameObjectManger * _objectManger;
	BulletManger * _bulletManger;
	Sprite * _backGround;


public:
	GameObjectManger * GetObjectManger() { return _objectManger; }
	BulletManger * GetBulletManger() { return _bulletManger; }
};

