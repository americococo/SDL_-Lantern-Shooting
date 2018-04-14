#include "Sprite.h"
#include "GameSystem.h"
#include "Texture.h"
#include "DLinkedList.h"

#include <stdio.h>
#include <string.h>
#include <SDL_image.h>

Sprite::Sprite(const char * fileName,bool isloop)
{

	DLinkedList<Texture*> DLinked;

	char filePath[256];
	sprintf(filePath, "../Resource/%s", fileName);
	FILE *fp = fopen(filePath, "r");
	if (NULL == fp)
	{
		printf("파일없음:%s\n", fileName);
		
	}

	char buffer[1024];

	char * textureName;
	float scaleWidth;
	float scaleHeight;

	char * record= fgets(buffer, sizeof(buffer), fp);

	while (true)
	{
		record = fgets(buffer, sizeof(buffer), fp);
		if (NULL == record)
			break;
		{//append 해줄부분
			char * token = strtok(record, ",");
			textureName = token;
			token = strtok(NULL, ",");
			scaleWidth = atof(token);
			token = strtok(NULL, ",");
			scaleHeight = atof(token);
		}
		Texture * texture = new Texture(textureName);
		texture->setscale(scaleWidth, scaleHeight);
		DLinked.apend(texture);
	}
	
	fclose(fp);


	 _frame = 0;
	 int frame=0;
	 _framMaxCount = DLinked.Count();


	 _mTextureFram = new Array<Texture*>(_framMaxCount);
	 DLinkedListIterator<Texture*> itr = DLinked.GetIterator();

	 for (itr.start(); itr.valid(); itr.Forth())
	 {
		 _mTextureFram->Set(frame, itr.item());
		 frame++;
	 }

	 

	 _frameDuration = 0;
	 _aniSpeed = 1000/30;


	 _isloop = isloop;

	 if (_isloop)
	 {
		 _isplay = true;
	 }
	 else
	 {
		 _isplay = false;
	 }

}
Sprite::~Sprite()
{

}

void Sprite::SetPostion(int x, int y)
{
	_x = x;
	_y = y;

	Texture * texture = _mTextureFram->Get(_frame);
	texture->setPosition(_x, _y);
}

void Sprite::Update(int deltaTime)
{
	if (false == _isplay)
		return;

	_frameDuration += deltaTime;

	if (_aniSpeed <= _frameDuration)
	{
		_frameDuration = 0;
		_frame = (_frame + 1) % _framMaxCount;

		if (false == _isloop)
		{
			if (0 == _frame)
			{
				_isplay = false;
			}
		}

	}

	Texture *_text = _mTextureFram->Get(_frame);
	_text->Render();
	_text->setPosition(_x, _y);
}

void Sprite::Render()
{
	if (false == _isplay)
		return;

	_mTextureFram->Get(_frame)->Render();
}

void Sprite::play()
{
	_frame = 0;
	_isplay = true;
}
int Sprite::GetSpriteRangeX()
{
	return _mTextureFram->Get(_frame)->getRenderWidth();
}

int Sprite::GetSpriteRangeY()
{
	return _mTextureFram->Get(_frame)->getRenderWidth();
}