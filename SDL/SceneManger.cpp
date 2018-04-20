#include "SceneManger.h"

#include "GameScene.h"
#include "TiltleScene.h"
#include "Scene.h"

SceneManger::SceneManger()
{
	_Scene = nullptr;
}

SceneManger::~SceneManger()
{
	delete instance;
}



SceneManger* SceneManger::instance = nullptr;

SceneManger* SceneManger::Getinstance()
{
	if (nullptr == instance)
		instance = new SceneManger();

	return instance;
}

void SceneManger::ChangeScene(eSceneType type)
{
	if (_Scene != nullptr)
	{
		_Scene->DeInit();
		delete _Scene;
	}
	switch (type)
	{
	case TITLE:
		_Scene = new TitleScene();
		break;
	case GAME:
		_Scene = new GameScene();
		
		break;
	}
	_Scene->Init();
}
void SceneManger::Render()
{
	_Scene->Render();
}

void SceneManger::Update(int deltaTime)
{
	_Scene->Update(deltaTime);
}

