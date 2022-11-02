#include "ObjectEnemyDir.h"
#include "DxLib.h"

ObjectEnemyDir::ObjectEnemyDir():
	m_vec()
{

}

ObjectEnemyDir::~ObjectEnemyDir()
{

}

void ObjectEnemyDir::update()
{
	if (!m_isExist) return;
	m_pos += m_vec;
}

void ObjectEnemyDir::setDir(float degree)
{
	float rad = degree * DX_PI_F / 180.0f;

	m_vec.x = cosf(rad);
	m_vec.y = sinf(rad);
	m_vec *= 5.0f;

}

