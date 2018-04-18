#include "GameObjectManger.h"
#include "GameObject.h"
#include <stdio.h>
GameObjectManger::GameObjectManger()
{
	_ObjectList.clear();
	objectId = 0;
}

GameObjectManger::~GameObjectManger()
{
}

std::map<int, GameObject*>::iterator  GameObjectManger::GetBegin()
{
	return _ObjectList.begin();
}

void GameObjectManger::PushObjaceMap(GameObject * object)
{
	object->SetObjectId(objectId);
	_ObjectList[objectId] = object;
	printf("Position: %d ",object->GetPostionY());
	objectId++;
}

GameObject * GameObjectManger::FindObject(int ID)
{
	return _ObjectList[ID];
}
void GameObjectManger::Update(int deltaTime)
{

	std::map<int, GameObject *>::iterator itr;

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
	std::map<int, GameObject *>::iterator itr;

	for (itr = _ObjectList.begin(); itr != _ObjectList.end(); itr++)
	{
		itr->second->Render();
	}
}
void GameObjectManger::DeInit()
{
	std::map<int, GameObject *>::iterator itr;

	for (itr = _ObjectList.begin(); itr != _ObjectList.end(); itr++)
	{
		itr->second->DeInit();
	}
	_ObjectList.clear();
}