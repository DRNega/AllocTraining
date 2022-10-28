#include "DxLib.h"
#include "game.h"
#include "SceneTest.h"

namespace
{
	const char* const kPlayerFilename = "Data/player.bmp";
	const char* const kEnemyFilename = "Data/enemy.bmp";

	// “¯Žž‚É“oê‚·‚é“G‚ÌÅ‘å”
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
		delete pEnemy;
		pEnemy = nullptr;
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
		pEnemy->update();
	}

	m_enemyInterval++;
	if (m_enemyInterval >= kEnemyInterval)
	{
		// Žg—p‚³‚ê‚Ä‚¢‚È‚¢“G‚ð’T‚µ‚Ä‚»‚ê‚ðŽg‚¤
		for (auto& pEnemy : m_pEnemy)
		{
			if (pEnemy->isExist())	continue;

			pEnemy->setExist(true);
			Vec2 pos{Game::kScreenWidth+16, static_cast<float>(GetRand(Game::kScreenHeight))};
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
		pEnemy->draw();
	}
}

