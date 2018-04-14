#pragma once
enum eStateType
{
	IDLE,
	MOVE,
	ATTACK,
};

class GameObject;
class State
{
public:
	State();
	~State();


	void Init(GameObject * object);
	virtual void Start();
 	virtual void Update(int deltaTime);
	virtual void Stop();

protected:
	GameObject * _object;
protected:
	eStateType _thisType;
};
