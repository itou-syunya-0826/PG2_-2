#pragma once
#include <Novice.h>

enum Scene {
	TITLE,
	GAME,
	GAMECLEAR,
	GAMEOVER
};

typedef struct Vector2 final {
	float x;
	float y;
}Vector2;

typedef struct VectorInt2 final {
	int x;
	int y;
}VectorInt2;