#include "Enemy.h"

Enemy::Enemy() {
	AliveTimer_ = 120;
	AliveNum_ = 0;
}

void Enemy::Initialize()
{
	
}

void Enemy::Update() {

}

void Enemy::Draw() {

}



void Enemy::ResPawnTimer(Scene & scene)
{

	/*Novice::ScreenPrintf(100, 140, "%d", AliveNum_);*/

	if (IsAlive_ == false) {
		AliveTimer_--;
	}
	if (AliveTimer_ <= 0) {
		IsAlive_ = true;
		AliveTimer_ = 120;
		if (AliveTimer_ == 120) {
			AliveNum_++;
		}
	}

	if (AliveNum_ == 3) {
		scene = GAMECLEAR;
	}
}

void Enemy::SetAliveNum(int AliveNum)
{
	AliveNum_ = AliveNum;

}