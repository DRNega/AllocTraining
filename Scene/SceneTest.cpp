#include "DxLib.h"
#include "game.h"
#include "SceneTest.h"
#include "ObjectEnemyDir.h"

namespace
{
	const char* const kPlayerFilename = "Data/player.bmp";
	const char* const kEnemyFilename = "Data/enemy.bmp";

	// “¯‚É“oê‚·‚é“G‚ÌÅ‘å”
	constexpr int kEnemyMax = 32;

	// “G‚Ì¶¬ŠÔŠu(ƒtƒŒ[ƒ€”)
	constexpr int kEnemyInterval = 30;
}

SceneTest::SceneTest():
	m_hPlayer(-1),
	m_hEnemy(-1),
	m_pPlayer(nullptr),
	m_pEnemy(kEnemyMax, nullptr),
	m_enemyInterval(0)
{
	m_pPlayer = new ObjectPlayer;
	for (auto& pEnemy : m_pEnemy)
	{
		pEnemy = new ObjectEnemy;
	}
}
SceneTest::~SceneTest()
{
	delete m_pPlayer;
	for (auto& pEnemy : m_pEnemy)
	{
		if (!pEnemy)
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

	m_pPlayer->init();
	m_pPlayer->setHandle(m_hPlayer);
	for (auto& pEnemy : m_pEnemy)
	{
		pEnemy->init();
		pEnemy->setHandle(m_hEnemy);
	}

	m_enemyInterval = 0;
}

void SceneTest::end()
{
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hEnemy);
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
	}

	m_enemyInterval++;
	if (m_enemyInterval >= kEnemyInterval)
	{
		// g—p‚³‚ê‚Ä‚¢‚È‚¢“G‚ğ’T‚µ‚Ä‚»‚ê‚ğg‚¤
		for (auto& pEnemy : m_pEnemy)
		{
			// nullptr‚ğ’T‚µ‚ÄV‚µ‚¢‹…‚ğ¶¬‚·‚é
			if (pEnemy)
			{
				continue;
			}

			pEnemy = new ObjectEnemy;

			pEnemy->init();
			pEnemy->setHandle(m_hEnemy);
			pEnemy->setExist(true);
			//pEnemy->setDir(30.0f);
			Vec2 pos{ Game::kScreenWidth + 16, static_cast<float>(GetRand(Game::kScreenHeight)) };
		//	Vec2 pos{ Game::kScreenWidth / 2, Game::kScreenHeight / 2 };
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
		if (pEnemy)  pEnemy->draw();
	}

	int num = 0;
	for (auto& pEnemy : m_pEnemy)
	{
		if ((pEnemy) && (pEnemy->isExist()))
		{
				num++;
		}

		
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "“G‚Ì”:%d", num);
}

