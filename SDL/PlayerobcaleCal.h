#pragma once
#include "GameObject.h"


#include <map>
#include <queue>
class Bullet;
class State;
enum eStateType;
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

	void Attack();


private:
	int _AttackCoolTime;
	int _DuractionTime;
	
public:
	State * _state;

private:
	std::map<eStateType, State*> _stateMap;


public:
	void changeState(eStateType type);	
};
