#pragma once
#include "Enemy.h"

class EnemyA:public Enemy
{
public:

	void Initialize()override;
	void Update()override;
	void Draw()override;

	
};

