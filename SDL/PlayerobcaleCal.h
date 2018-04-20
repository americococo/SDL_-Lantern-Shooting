#pragma once
#include "GameObject.h"


#include <map>
#include <queue>
class Bullet;
class State;
class BulletPattern;
enum eBulletPattern;
class PlayerObcaleCal : public GameObject
{

public:
	PlayerObcaleCal();
	~PlayerObcaleCal();

	void Init(const char * name);

	void DeInit();
	void Render();
	void Update(int deltaTime);

	//АјАн
private:
	std::queue<Bullet*> _bulletList;

	



public:
	void changeState(eStateType type);	

};
