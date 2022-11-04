#include "ObjectEnemy.h"
#include "game.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr float kSpeed = 8.0f;
}

ObjectEnemy::ObjectEnemy() :
	m_hGraph(-1),
	m_rotation(0.0f),
	m_rotateSpeed(-0.1f),
	m_isExist(false),
	m_pos()
{

}

ObjectEnemy::~ObjectEnemy()
{

}

void ObjectEnemy::init()
{
	m_isExist = false;
}

void ObjectEnemy::end()
{

}

void ObjectEnemy::update()
{
	if (!m_isExist)	return;
	m_rotation += m_rotateSpeed;
	m_pos.x -= kSpeed;
	if (m_pos.x <= -16.0f)
	{
		m_isExist = false;
	}
}

void ObjectEnemy::draw()
{
	if (!m_isExist)	return;
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_hGraph, true);
}
