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

	// ���� ĳ���� ������ �ӵ� ����(vx1, vy1)�� ���ϱ�
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
		// �ð� �������� ��ȸ�� ���� ����ġ�� �ش��ϴ� �ӵ� ���� (vx2,vy2)�� ���ϱ�
		float rad = 3.141592 * 2 * _theta;
		float c = cos(rad), s = sin(rad);
		vx2 = c * vx0 - s * vy0;
		vy2 = s * vx0 + c * vy0;

		// ���� ĳ���� ����� ��ȸ ���� ����ġ �� ��� ������ ��ȸ�� �� ���ϱ�
		if (vx0*vx1 + vy0 * vy1 >= vx0 * vx2 + vy0 * vy2) {

			// ���� ĳ���� ������ ��ȸ ������ ���� �ȿ� ���� ���:
			// ���� ĳ���� �������� ��ȸ��
			_MoveVectorX = vx1; _MoveVectorY = vy1;

		}
		else {

			// ���� ĳ���� ������ ��ȸ ������ ���� ���� ���:
			// �� �ð� �������� ��ȸ�� ���� ���� ������ �ش��ϴ� �ӵ� ���� (vx3,vy3)�� ���ϱ�
			vx3 = c * vx0 + s * vy0;
			vy3 = -s * vx0 + c * vy0;

			// �̵� ��ü���� ���� ĳ���ͱ����� ��� ��ġ ���� (px,py)�� ���ϱ�
			float px = tx - _x, py = ty - _y;

			// �ð� �������� ��ȸ�� �� �� �ð� �������� ��ȸ�� �� �����ϱ�
			if (px*vx2 + py * vy2 >= px * vx3 + py * vy3) {
				_MoveVectorX = vx2; _MoveVectorY = vy2;
			}
			else {
				_MoveVectorX = vx3; _MoveVectorY = vy3;
			}
		}

		// ź�� ������
		_x += _MoveVectorX;
		_y += _MoveVectorY;
	}
}
void ChaseBullet::SetTarget(GameObject * object)
{
	_target = object;
}