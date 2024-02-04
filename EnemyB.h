#pragma once
#include "Enemy.h"

class EnemyB :public Enemy
{

public:

	void Initialize()override;
	void Update()override;
	void Draw()override;

};

