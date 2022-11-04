#include "ObjectEnemyThrow.h"
#include "game.h"
#include "DxLib.h"

namespace
{
	// ˆÚ“®‘¬“x
	constexpr float kSpeedX = 5.0f;	// XŽ²
	constexpr float kSpeedY = -10.0f;	// YŽ²
	// d—Í
	constexpr float kGravity = 0.5f;
}

ObjectEnemyThrow::ObjectEnemyThrow() :
	m_vec()
{
	m_vec.x = kSpeedX;
	m_vec.y = kSpeedY;
}

ObjectEnemyThrow::~ObjectEnemyThrow()
{

}

void ObjectEnemyThrow::update()
{
	if (!m_isExist)	return;
	m_rotation += m_rotateSpeed;
	m_pos += m_vec;
	m_vec.y += kGravity;
	if (m_pos.x <= -16.0f || m_pos.x >= Game::kScreenWidth + 10.0f ||
		m_pos.y <= -16.0f || m_pos.y >= Game::kScreenHeight + 10.0f)
	{
		m_isExist = false;
	}
}