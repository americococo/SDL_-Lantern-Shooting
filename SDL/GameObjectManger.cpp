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
void GameObjectManger::DeInit()
{
	_ObjectList.clear();
}