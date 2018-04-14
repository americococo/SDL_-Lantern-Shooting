#pragma once
class Scene
{
public:
	Scene();
	~Scene();


	virtual void Init();
	virtual void DeInit();
	virtual void Render();
	virtual void Update(int deltaTime);


};

