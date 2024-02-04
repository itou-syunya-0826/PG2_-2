#pragma once
#include <Novice.h>
#include "Collision.h"
#include "EnemyA.h"
#include "EnemyB.h"

class Bullet
{
private:

	int posX_;
	int posY_;
	int radius_;
	int speed_;
	bool IsShot_;
	Collision* collision_;

public:

	Bullet();
	~Bullet();
	void Draw();
	void Move();
	void SetIsShot(bool IsShot);
	void SetPos(int posX, int posY);
	bool GetIsShot() { return IsShot_; };
	void IsHit(VectorInt2 pos,int radius);
};

