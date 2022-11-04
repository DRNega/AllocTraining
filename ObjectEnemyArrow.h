#pragma once
#include "ObjectEnemy.h"
#include "Vec2.h"

// 指定した方向に飛んでいく敵
class ObjectEnemyArrow : public ObjectEnemy
{
public:
	ObjectEnemyArrow();
	virtual ~ObjectEnemyArrow();

	virtual void update();

	// 飛んでいく方向を指定する(左方向を0度として時計回りの角度を指定する)
	void setDir(float degree);
private:
	// 飛んでいく方向
	Vec2 m_vec;
};