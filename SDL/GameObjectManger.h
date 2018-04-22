#pragma once
class GameObject;
#include <map>
#include <string>
class GameObjectManger
{

public:
	GameObjectManger();
	~GameObjectManger();

private:
	std::map<std::wstring, GameObject*> _ObjectList;
public:
	void PushObjaceMap(GameObject * object, std::wstring name);

	std::map<std::wstring, GameObject*>::iterator GetBegin();
	std::map<std::wstring, GameObject*>::iterator GetEnd() {return _ObjectList.end(); }


	GameObject * FindObject(std::wstring name);

	void Update(int deltaTime);
	void Render();

	void DeInit();

};
