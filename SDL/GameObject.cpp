#include "GameObject.h"
#include "Sprite.h"
#include "GameObjectManger.h"
#include <stdio.h>
#include "BulletPattern.h"
#include "GameSystem.h"
GameObject::GameObject() 
{
	_state = nullptr;
}
GameObject::~GameObject() {}

void GameObject::Init(const char * name)
{
	_sprite = new Sprite(name, true);
	_ObjectId = 1;

	_hp = 5;
	_isLive = true;

	_objectType = eObjectType::Object;

	_moveX = 0;
	_moveY = 0;

	_speed = 2;
}

void GameObject::DeInit()
{
	if (_sprite != nullptr)
	{
		delete _sprite;
		_sprite = nullptr;
	}
}

void GameObject::Render()
{
	_sprite->Render();

	SetPostion(_x,_y);
}
void GameObject::Update(int deltaTime)
{
	_sprite->Update(deltaTime);
}

void GameObject::MoveVector(int moveX, int moveY)
{
	_moveX = moveX;
	_moveY = moveY;
}

void GameObject::SetPostion(int x, int y)
{
	_x = x;
	_y = y;

	_sprite->SetPostion(x, y);

	_minX = _x - _sprite->GetSpriteRangeX() / 2;
	_maxX = _x + _sprite->GetSpriteRangeX() / 2;

	_minY = _y - _sprite->GetSpriteRangeY() / 2;
	_maxY = _y + _sprite->GetSpriteRangeY() / 2;


	if (_x >= (GameSystem::Getinstance()->GetWindowW()))
		_x = GameSystem::Getinstance()->GetWindowW();

	if (_y >= (GameSystem::Getinstance()->GetWindowH()))
		_y = GameSystem::Getinstance()->GetWindowH();

	if (_x <= 0)
		_y = 0;

	if (_y <= 0)
		_y = 0;

}

void GameObject::changeState(eStateType type)
{
	if (_state != nullptr)
	{
		_state->Stop();
		_state = nullptr;
	}

	_state = _stateMap[type];
	_state->Start();
}
void GameObject::Damage()
{
	_hp -= 1;
	printf("%d\n", _hp);

	if (0 == _hp)
	{
		_isLive = false;
	}

}
void GameObject::ChangePattern(eBulletPattern patternType)
{
	_pattern = _bulletPatternList[patternType];
}