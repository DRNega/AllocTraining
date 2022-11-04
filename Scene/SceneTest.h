#pragma once
#include "SceneBase.h"
#include <vector>

#include "ObjectPlayer.h"
#include "ObjectEnemy.h"

class SceneTest : public SceneBase
{
public:
	SceneTest();
	virtual ~SceneTest();


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;

private:
	// グラフィックハンドル
	int			m_hPlayer;
	int			m_hEnemy;
	int			m_hArrow;

	ObjectPlayer* m_pPlayer;
	std::vector<ObjectEnemy*>	m_pEnemy;

	// 敵の生成
	int			m_enemyInterval;
};