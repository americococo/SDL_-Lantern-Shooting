#pragma once
#include <string>
#include <map>
class Sprite;

#include "State.h"
#include <vector>
enum eObjectType
{
	Player,
	Monster,
	Object,
};

class BulletPattern;
enum eBulletPattern;
class GameObject
{
public:
	GameObject();
	~GameObject();

protected:
	std::vector<GameObject*> _enemy;

public:
	GameObject * GetEnemy();

protected:
	int _minX;
	int _minY;
	int _maxX;
	int _maxY;

	float _x;
	float _y;
public:
	int GetPostionMinX() { return _minX; }
	int GetPostionMaxX() { return _maxX; }

	int GetPostionMinY() { return _minY; }
	int GetPostionMaxY() { return _maxY; }

protected:
	int _speed;

	int _moveX;
	int _moveY;
public:
	void MoveVector(int moveX, int moveY);
	int GetMoveVectorX() { return _moveX; }
	int GetMoveVectorY() { return _moveY; }

	int GetSpeed() { return _speed; }

	void ResetMoveVector() { _moveX = 0; _moveY = 0; }

protected:
	Sprite * _sprite;

public:
	virtual void Init(const char * name);
	virtual void DeInit();
	virtual	void Render();
	virtual	void Update(int deltaTime);

	void SetPostion(float x,float y);
	


//State
protected:
	State * _state;
	std::map<eStateType, State*> _stateMap;
	
public:
	void changeState(eStateType type);

public:

	int GetPostionX() { return _x; }
	int GetPostionY() { return _y; }

protected:
	eObjectType _objectType;
public:
	eObjectType GetObjectType() { return _objectType; }


protected:
	bool _isLive;
	int _hp;
	
public:
	virtual void Damage();
	bool GetObjectLive() { return _isLive; }

public:
	virtual void ChangePattern(int sol);


protected:
	BulletPattern * _pattern;
	std::map<int, BulletPattern *> _bulletPatternList;

public:
	void InitBulletParttern(BulletPattern * pattern,int sol);

	
protected:
	std::wstring _name;
public:
	std::wstring GetName() { return _name; }
	void SetName(std::wstring name) { _name = name; }
};
