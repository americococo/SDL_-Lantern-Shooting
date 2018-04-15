#pragma once
#include "GameObject.h"
#include <map>
class BulletPattern;
enum eBulletPattern;


class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();


	void Init(const char * name);
	void DeInit();
	void Render();
	void Update(int deltaTime);

public:
	void Attack();

	void ChangePattern(eBulletPattern patternType);
private:
	BulletPattern * _pattern;
	std::map<eBulletPattern, BulletPattern *> _bulletPatternList;
};

