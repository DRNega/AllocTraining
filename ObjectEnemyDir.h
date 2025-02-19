#pragma once

#include "ObjectEnemy.h"

// 指定した方向に飛んでいく敵
class ObjectEnemyDir : public ObjectEnemy
{
public:
	ObjectEnemyDir();
	virtual ~ObjectEnemyDir();

	virtual void update();

	// 飛んでいく方向を指定する(角度)
	void setDir(float degree);


private:
	// 飛んでいく方向
	Vec2	m_vec;
};
