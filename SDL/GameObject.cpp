#include "GameObject.h"
#include "Sprite.h"
#include "GameObjectManger.h"
#include "BulletPattern.h"
#include "GameSystem.h"
#include "BulletPattern.h"
#include <string.h>
#include <stdio.h>
GameObject::GameObject() 
{
	_state = nullptr;
}
GameObject::~GameObject() {}

void GameObject::Init(const char * name)
{
	char filePath[256];
	sprintf(filePath, "../Resource/%s", name);
	FILE *fp = fopen(filePath, "r");
	if (NULL == fp)
	{
		printf("파일없음:%s\n", name);

	}

	char buffer[1024];

	char * SpriteFile;

	char * record = fgets(buffer, sizeof(buffer), fp);

	while (true)
	{
		record = fgets(buffer, sizeof(buffer), fp);
		if (NULL == record)
			break;
		{//append 해줄부분
			char * token = strtok(record, ",");
			SpriteFile = token;
			token = strtok(NULL, ",");
			_hp = atoi(token);
		}
	}
	fclose(fp);

	_sprite = new Sprite(SpriteFile, true);
	_isLive = true;

	_objectType = eObjectType::Object;

	_moveX = 0;
	_moveY = 0;

	_x = 0;
	_y = 0;

	_speed = 2;
}
GameObject * GameObject::GetEnemy()
{
	if (_enemy.size() <= 0)
		return nullptr;
	return _enemy[rand() % _enemy.size()];
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
void GameObject::SetColider(int size)
{
	_size = size;
	_minX = _x - size;
	_maxX = _x + size;

	_minY = _y - size;
	_maxY = _y + size;
}
void GameObject::SetPostion(float x, float y)
{
	_sprite->SetPostion(x, y);

	_x = x;
	_y = y;

	_minX = x - _size;
	_maxX = x + _size;

	_minY = y - _size;
	_maxY = y + _size;

	if (_x >= (GameSystem::Getinstance()->GetGameScreenRight()))
		_x = GameSystem::Getinstance()->GetGameScreenRight();

	if (_y >= (GameSystem::Getinstance()->GetGameScreenBottom()))
		_y = GameSystem::Getinstance()->GetGameScreenBottom();

	if (_x <= GameSystem::Getinstance()->GetGameScreenLeft())
		_x = GameSystem::Getinstance()->GetGameScreenLeft();

	if (_y <= GameSystem::Getinstance()->GetGameScreenTop())
		_y = GameSystem::Getinstance()->GetGameScreenTop();


	

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
void GameObject::ChangePattern(int sol)
{
	_pattern = _bulletPatternList[sol];
}
void GameObject::InitBulletParttern(BulletPattern * pattern,int sol)
{
	pattern->Init(this);
	_bulletPatternList[sol] = pattern;
}