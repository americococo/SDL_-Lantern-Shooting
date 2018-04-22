#include "GameObjectManger.h"
#include "GameObject.h"
#include <stdio.h>
GameObjectManger::GameObjectManger()
{
	_ObjectList.clear();
}

GameObjectManger::~GameObjectManger()
{
}

std::map<std::wstring, GameObject*>::iterator  GameObjectManger::GetBegin()
{
	return _ObjectList.begin();
}

void GameObjectManger::PushObjaceMap(GameObject * object,std::wstring name)
{
	_ObjectList[name] = object;
	object->SetName(name);
	printf("Position: %d ", object->GetPostionY());
}

GameObject * GameObjectManger::FindObject(std::wstring name)
{
	return _ObjectList[name];
}
void GameObjectManger::Update(int deltaTime)
{

	std::map<std::wstring, GameObject *>::iterator itr;

	for (itr = _ObjectList.begin(); itr != _ObjectList.end(); itr++)
	{
		if (false == itr->second->GetObjectLive())
		{
			GameObject * monoD = itr->second;
			itr=_ObjectList.erase(itr);
			monoD->DeInit();
			delete monoD;

			if (itr == _ObjectList.end())
				break;
		}
		itr->second->Update(deltaTime);
	}

}
void GameObjectManger::Render()
{
	std::map<std::wstring, GameObject *>::iterator itr;

	for (itr = _ObjectList.begin(); itr != _ObjectList.end(); itr++)
	{
		itr->second->Render();
	}
}
void GameObjectManger::DeInit()
{
	std::map<std::wstring, GameObject *>::iterator itr;

	for (itr = _ObjectList.begin(); itr != _ObjectList.end(); itr++)
	{
		itr->second->DeInit();
	}
	_ObjectList.clear();
}