#include "Array.h"

struct SDL_Renderer;
struct SDL_Texture;

class Texture;

//애니메이션 srp
class Sprite
{
private:
	//SDL_Texture * _mTexture;
	
	Array<Texture*>* _mTextureFram;
	SDL_Renderer * _mRender;

	int _framMaxCount;
	
	int _frame;
	int _frameDuration;
	//int _updateDuration;
	int _aniSpeed;
	int _x, _y;

public:
	Sprite(const char * fileName,bool isloop);

public:
	void Update(int deltaTime);
public:
	~Sprite();

	void SetPostion(int x, int y);

	void Render();

private:
	bool _isplay;
	bool _isloop;

public:
	void play();


public:
	int GetSpriteRangeX();
	int GetSpriteRangeY();

};