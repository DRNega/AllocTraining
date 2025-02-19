#pragma once

#include "ObjectEnemy.h"
#include "Vec2.h"

// 指定した方向に飛んでいく敵
class ObjectEnemyThrow : public ObjectEnemy
{
public:
	ObjectEnemyThrow();
	virtual ~ObjectEnemyThrow();

	virtual void update();

private:
	// 飛んでいく方向
	Vec2 m_vec;
};