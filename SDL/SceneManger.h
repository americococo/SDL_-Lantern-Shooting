#pragma once

enum eSceneType
{
	TITLE,
	GAME,
};

class Scene;

class SceneManger
{
private:
	SceneManger();
public:
	~SceneManger();

private:
	static SceneManger * instance;
public:
	static SceneManger * Getinstance();

//Scene State
private:
	Scene * _Scene;

public:
	void ChangeScene(eSceneType type);

	void Render();

	void Update(int deltaTime);

public:
	Scene * GetScene() { return _Scene; }
};

