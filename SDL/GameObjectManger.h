#pragma once
class GameObject;
#include <map>
class GameObjectManger
{

public:
	GameObjectManger();
	~GameObjectManger();


	int objectId;

public:
	std::map<int, GameObject*> _ObjectList;
public:
	void PushObjaceMap(GameObject * object);

	std::map<int, GameObject*>::iterator GetBegin();
	std::map<int, GameObject*>::iterator GetEnd() {return _ObjectList.end(); }


	GameObject * FindObject(int ID);

	void Update(int deltaTime);
	void Render();

	void DeInit();

};
