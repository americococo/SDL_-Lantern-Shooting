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

	//����
private:
	std::queue<Bullet*> _bulletList;

	



public:
	void changeState(eStateType type);	

private:
	BulletPattern * _pattern;
	std::map<eBulletPattern, BulletPattern *> _bulletPatternList;

public:
	void ChangePattern(eBulletPattern patternType);
};
