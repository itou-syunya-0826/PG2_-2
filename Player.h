#pragma once
#include "mystruct.h"
#include "Bullet.h"
#include "Collision.h"

class Player
{
private:

	VectorInt2 Pos_;
	int R_;
	int Speed_;
	Bullet* bullet_;
	Collision* collision_;

public:

	static bool IsAlive_;

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(char* keys, char* preKeys);
	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();


	Bullet* GetBullet() { return bullet_; };
	VectorInt2 GetPos() { return Pos_; };

	void IsDamage(Scene&scene, VectorInt2 pos, int radius);

	void SetIsAlive(bool IsAlive);

	void SetPos(VectorInt2 Pos);


};

