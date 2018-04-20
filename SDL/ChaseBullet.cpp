#include "ChaseBullet.h"
#include "GameObject.h"
#include "GameObjectManger.h"
#include "GameScene.h"
#include "Scene.h"
#include "SceneManger.h"
#include "GameObject.h"

#include <math.h>
#include <map>
ChaseBullet::ChaseBullet()
{
}
void ChaseBullet::Init(const char * name)
{
	Bullet::Init(name);
	_theta = 0.002;
	_MoveVectorX = 0;
	_MoveVectorY = 0;
}
ChaseBullet::~ChaseBullet()
{

}
void ChaseBullet::Update(int deltaTime)
{
	if (_isLive == false)
		return;

	Bullet::Update(deltaTime);

}

void ChaseBullet::MoveBullet()
{
	float vx0 = _MoveVectorX, vy0 = _MoveVectorY, vx1, vy1, vx2, vy2, vx3, vy3;
	float tx = _target->GetPostionX();
	float ty = _target->GetPostionY();

	// 메인 캐릭터 방향의 속도 벡터(vx1, vy1)를 구하기
	vx1 = tx - _x; vy1 = ty - _y;

	float d = sqrt(vx1*vx1 + vy1 * vy1);
	if (d) {
		vx1 *= _speed / d;
		vy1 *= _speed / d;
	}
	else {
		vx1 = 0;
		vy1 = 0;
	}


	{
		// 시계 방향으로 선회할 때의 상한치에 해당하는 속도 벡터 (vx2,vy2)를 구하기
		float rad = 3.141592 * 2 * _theta;
		float c = cos(rad), s = sin(rad);
		vx2 = c * vx0 - s * vy0;
		vy2 = s * vx0 + c * vy0;

		// 메인 캐릭터 방향과 선회 각도 상한치 중 어느 쪽으로 선회할 지 정하기
		if (vx0*vx1 + vy0 * vy1 >= vx0 * vx2 + vy0 * vy2) {

			// 메인 캐릭터 방향이 선회 가능한 범위 안에 있을 경우:
			// 메인 캐릭터 방향으로 선회함
			_MoveVectorX = vx1; _MoveVectorY = vy1;

		}
		else {

			// 메인 캐릭터 방향이 선회 가능한 범위 밖일 경우:
			// 반 시계 방향으로 선회할 때의 제한 각도에 해당하는 속도 벡터 (vx3,vy3)를 구하기
			vx3 = c * vx0 + s * vy0;
			vy3 = -s * vx0 + c * vy0;

			// 이동 물체에서 메인 캐릭터까지의 상대 위치 벡터 (px,py)를 구하기
			float px = tx - _x, py = ty - _y;

			// 시계 방향으로 선회할 지 반 시계 방향으로 선회할 지 결정하기
			if (px*vx2 + py * vy2 >= px * vx3 + py * vy3) {
				_MoveVectorX = vx2; _MoveVectorY = vy2;
			}
			else {
				_MoveVectorX = vx3; _MoveVectorY = vy3;
			}
		}

		// 탄을 움직임
		_x += _MoveVectorX;
		_y += _MoveVectorY;
	}
}
void ChaseBullet::SetTarget(GameObject * object)
{
	_target = object;
}