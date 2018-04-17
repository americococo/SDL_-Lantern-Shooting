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
void GameObjectManger:: EraseObject(std::map<int, GameObject*>::iterator itr) 
{
	GameObject *monoD= itr->second;
	_ObjectList.erase(itr); 
	delete monoD;
}
GameObject * GameObjectManger::FindObject(int ID)
{
	return _ObjectList[ID];
}
void GameObjectManger::Update(int deltaTime)
{
	for (int i = 0; i < _ObjectList.size(); i++)
		_ObjectList[i]->Update(deltaTime);
}
void GameObjectManger::Render()
{
	for (int i = 0; i < _ObjectList.size(); i++)
		_ObjectList[i]->Render();
}
void GameObjectManger::DeInit()
{
	for (int i = 0; i < _ObjectList.size(); i++)
		_ObjectList[i]->DeInit();
	_ObjectList.clear();
}