#include "EnemyB.h"
#include <Novice.h>

void EnemyB::Initialize() {
	pos_.x = 500;
	pos_.y = 200;
	radius_ = 16;
	speed_ = 8;
}

void EnemyB::Update()
{
	pos_.x += speed_;
	if (pos_.x > 1264 ) {
		speed_ *= -1;
	}
	if (pos_.x < 16) {
		speed_ *= -1;
	}
}

void EnemyB::Draw() {
	if (IsAlive_ == true) {
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}