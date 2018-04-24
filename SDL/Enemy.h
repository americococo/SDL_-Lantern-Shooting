#pragma once
#include "GameObject.h"
#include <map>



class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();


	void Init(const char * name);
	void DeInit();
	void Render();
	void Update(int deltaTime);



private:
	float _wayPointX;
	float _wayPointY;

public:
	float GetWayPointX() { return _wayPointX; }
	float GetWayPointY() { return _wayPointY; }
};

