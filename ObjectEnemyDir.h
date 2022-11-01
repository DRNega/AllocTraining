#pragma once

#include "ObjectEnemy.h"

// Žw’è‚µ‚½•ûŒü‚É”ò‚ñ‚Å‚¢‚­“G
class ObjectEnemyDir : public ObjectEnemy
{
public:
	ObjectEnemyDir();
	virtual ~ObjectEnemyDir();

	virtual void update();

	// ”ò‚ñ‚Å‚¢‚­•ûŒü‚ðŽw’è‚·‚é(Šp“x)
	void setDir(float degree);


private:
	// ”ò‚ñ‚Å‚¢‚­•ûŒü
	Vec2	m_vec;



};
