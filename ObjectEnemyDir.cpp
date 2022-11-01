#include "ObjectEnemyDir.h"

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

}

