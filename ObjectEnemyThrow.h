#pragma once

#include "ObjectEnemy.h"
#include "Vec2.h"

// Žw’è‚µ‚½•ûŒü‚É”ò‚ñ‚Å‚¢‚­“G
class ObjectEnemyThrow : public ObjectEnemy
{
public:
	ObjectEnemyThrow();
	virtual ~ObjectEnemyThrow();

	virtual void update();

private:
	// ”ò‚ñ‚Å‚¢‚­•ûŒü
	Vec2 m_vec;
};