#include "EnemyA.h"
#include "EnemyB.h"
#include "Player.h"

const char kWindowTitle[] = "GC1C_03_イトウシュンヤ";

bool Enemy::IsAlive_ = true;
bool Player::IsAlive_ = true;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Scene scene = TITLE;
	Enemy* enemy[2];
	enemy[0] = new EnemyA();
	enemy[1] = new EnemyB();
	Player* player = new Player;
	
	int clearImg = Novice::LoadTexture("./GAMECLEAR.png");
	int overImg = Novice::LoadTexture("./GAMEOVER.png");
	int titleImg = Novice::LoadTexture("./TITLE.png");
	

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理と描画処理はここから
		///
		
		switch (scene) {
		case TITLE:

			Novice::DrawSprite(0, 0, titleImg, 1.0f, 1.0f, 0.0f, WHITE);

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				for (int i = 0; i < 2; i++) {
					scene = GAME;
					enemy[i]->Initialize();
					player->Initialize();
				}
			}

			break;

		case GAME:

			Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);

			for (int i = 0; i < 2; i++) {
				enemy[i]->Update();
				player->Update(keys, preKeys);
				enemy[i]->Draw();
				player->Draw();
				player->GetBullet()->IsHit(enemy[i]->GetPos(), enemy[i]->GetRadius());
				enemy[i]->ResPawnTimer(scene);
				player->IsDamage(scene,enemy[i]->GetPos(), enemy[i]->GetRadius());
			}

			if (!player->GetBullet()->GetIsShot()) {
				player->GetBullet()->SetPos((int)player->GetPos().x, (int)player->GetPos().y);
			}
			player->GetBullet()->Draw();
			player->GetBullet()->Move();


			break;
			

		case GAMECLEAR:

			Novice::DrawSprite(0, 0, clearImg, 1.0f, 1.0f, 0.0f, WHITE);

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {

				scene = TITLE;
				player->SetIsAlive(true);
				player->SetPos({ 640,650 });
				enemy[0]->SetAliveNum(0);
				enemy[1]->SetAliveNum(0);
				
			}

			break;

		case GAMEOVER:

			Novice::DrawSprite(0, 0, overImg, 1.0f, 1.0f, 0.0f, WHITE);

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = GAME;
				player->SetIsAlive(true);
				player->SetPos({ 640,650 });
			}

		break;
		}	

		///
		/// ↑更新処理と描画処理はここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete enemy[0],enemy[1], player;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
