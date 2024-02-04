#include "Player.h"

void Player::Initialize() {
	Pos_.x = 640;
	Pos_.y = 650;
	R_ = 32;
	Speed_ = 4;
	bullet_ = new Bullet;
}

void Player::Update(char* keys, char* preKeys)
{
	if (keys[DIK_A]) {
		Pos_.x -= Speed_;
	}
	if (keys[DIK_D]) {
		Pos_.x += Speed_;
	}
	if (keys[DIK_W]) {
		Pos_.y -= Speed_;
	}
	if (keys[DIK_S]) {
		Pos_.y += Speed_;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		bullet_->SetIsShot(true);
	}

}

void Player::Draw()
{
	if (IsAlive_ == true) {
		Novice::DrawEllipse(Pos_.x, Pos_.y, R_, R_, 0.0f, GREEN, kFillModeSolid);
	}
}

void Player::IsDamage(Scene&scene,VectorInt2 pos, int radius)
{
	if (collision_->Box(pos.x, pos.y, radius, Pos_.x, Pos_.y, R_)) {
		Player::IsAlive_ = false;
	}

	if (Player::IsAlive_ == false) {
		scene = GAMEOVER;
	}

}

void Player::SetIsAlive(bool IsAlive)
{
	IsAlive_ = IsAlive;
}

void Player::SetPos(VectorInt2 Pos) {

	Pos_.x = Pos.x;
	Pos_.y = Pos.y;
}


