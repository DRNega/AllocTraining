#include "DxLib.h"
#include "game.h"
#include "SceneTest.h"
#include "ObjectEnemyDir.h"
#include "ObjectEnemyThrow.h"
#include "ObjectEnemyArrow.h"

namespace
{
	const char* const kPlayerFilename = "Data/player.bmp";
	const char* const kEnemyFilename = "Data/enemy.bmp";
	const char* const kArrowFilename = "Data/arrow.png";

	// 同時に登場する敵の最大数
	constexpr int kEnemyMax = 32;

	// 敵の生成間隔(フレーム数)
	constexpr int kEnemyInterval = 15;
}

SceneTest::SceneTest() :
	m_hPlayer(-1),
	m_hEnemy(-1),
	m_pPlayer(nullptr),
	m_pEnemy(kEnemyInterval, nullptr),
	m_enemyInterval(0)
{
	m_pPlayer = new ObjectPlayer;
}

SceneTest::~SceneTest()
{
	delete m_pPlayer;
	for (auto& pEnemy : m_pEnemy)
	{
		if (pEnemy)
		{
			delete pEnemy;
			pEnemy = nullptr;
		}
	}
}

void SceneTest::init()
{
	m_hPlayer = LoadGraph(kPlayerFilename);
	m_hEnemy = LoadGraph(kEnemyFilename);
	m_hArrow = LoadGraph(kArrowFilename);

	m_pPlayer->init();
	m_pPlayer->setHandle(m_hPlayer);
	for (auto& pEnemy : m_pEnemy)
	{
		/*pEnemy->init();
		pEnemy->setHandle(m_hEnemy);*/
		pEnemy = nullptr;
	}

	m_enemyInterval = 0;
}

void SceneTest::end()
{
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hEnemy);
	DeleteGraph(m_hArrow);
}

SceneBase* SceneTest::update()
{
	m_pPlayer->update();
	for (auto& pEnemy : m_pEnemy)
	{
		if (!pEnemy)
		{
			continue;
		}
		pEnemy->update();

		if (!pEnemy->isExist())
		{
			delete pEnemy;
			pEnemy = nullptr;
		}
	}

	m_enemyInterval++;
	if (m_enemyInterval >= kEnemyInterval)
	{
		// 使用されていない敵を探してそれを使う
		for (auto& pEnemy : m_pEnemy)
		{
			// nullptrを探して新しい弾を生成する
			if (pEnemy)	continue;
#if false
			switch (GetRand(2))
			{
			case 0:
				pEnemy = new ObjectEnemy;
				break;
			case 1:
				pEnemy = new ObjectEnemyDir;
				break;
			case 2:
			default:
				pEnemy = new ObjectEnemyThrow;
				break;
			}
#else
			pEnemy = new ObjectEnemyArrow;
#endif

			pEnemy->init();
			pEnemy->setHandle(m_hEnemy);
			pEnemy->setExist(true);

			// データに応じた初期化を行う
			ObjectEnemyDir* pTemp = dynamic_cast<ObjectEnemyDir*>(pEnemy);
			if (pTemp)
			{
				pTemp->setDir(GetRand(359));
			}
			ObjectEnemyArrow* pTempArrow = dynamic_cast<ObjectEnemyArrow*>(pEnemy);
			if (pTempArrow)
			{
				pTempArrow->setHandle(m_hArrow);
				pTempArrow->setDir(static_cast<float>(GetRand(359)));
			}


			//	Vec2 pos{ Game::kScreenWidth + 16, static_cast<float>(GetRand(Game::kScreenHeight)) };
			Vec2 pos{ Game::kScreenWidth / 2, Game::kScreenHeight / 2 };
			pEnemy->setPos(pos);
			break;
		}
		m_enemyInterval = 0;
	}
	return this;
}

void SceneTest::draw()
{
	m_pPlayer->draw();
	for (auto& pEnemy : m_pEnemy)
	{
		if (pEnemy)
		{
			pEnemy->draw();
		}
	}

	int num = 0;
	for (auto& pEnemy : m_pEnemy)
	{
		if ((pEnemy) && (pEnemy->isExist()))
		{
			num++;
		}
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "敵の数:%d", num);

}