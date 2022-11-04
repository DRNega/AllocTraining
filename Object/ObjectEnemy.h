#pragma once

#include "Vec2.h"

class SceneMain;

class ObjectEnemy
{
public:
	ObjectEnemy();
	virtual ~ObjectEnemy();

	virtual void init();
	virtual void end();

	virtual void update();
	virtual void draw();

	void setHandle(int handle) { m_hGraph = handle; }
	// 開始位置決定に使用する
	void setPos(Vec2 pos) { m_pos = pos; }

	// 存在確認
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

protected:
	// グラフィックハンドル
	int		m_hGraph;

	// 回転角度
	float	m_rotation;
	// 回転速度
	float	m_rotateSpeed;

	// 存在するか
	bool	m_isExist;
	// 左上座標
	Vec2	m_pos;
};