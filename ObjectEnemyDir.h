#pragma once

#include "ObjectEnemy.h"

// �w�肵�������ɔ��ł����G
class ObjectEnemyDir : public ObjectEnemy
{
public:
	ObjectEnemyDir();
	virtual ~ObjectEnemyDir();

	virtual void update();

	// ���ł����������w�肷��(�p�x)
	void setDir(float degree);


private:
	// ���ł�������
	Vec2	m_vec;



};
