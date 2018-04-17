#pragma once
#include <string>
class Sprite;

enum eObjectType
{
	Player,
	Monster,
	Object,
};
class BulletPattern;
enum eBulletPattern;
#include <map>
class GameObject
{
public:
	GameObject();
	~GameObject();

protected:
	GameObject * _enemy;

public:
	GameObject * GetEnemy() { return _enemy; }

protected:
	int _minX;
	int _minY;
	int _maxX;
	int _maxY;

	int _x;
	int _y;
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

	void SetPostion(int x,int  y);
	

protected:
	
public:

	int GetPostionX() { return _x; }
	int GetPostionY() { return _y; }


protected:
	int _ObjectId;

public:
	int GetObjectId() { return _ObjectId; }
	void SetObjectId(int ObjectId) { _ObjectId = ObjectId; }

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
	virtual void ChangePattern(eBulletPattern patternType);


protected:
	BulletPattern * _pattern;
	std::map<eBulletPattern, BulletPattern *> _bulletPatternList;
};
