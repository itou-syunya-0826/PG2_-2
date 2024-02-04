#pragma once
#include <mystruct.h>

class Enemy
{
protected:

	VectorInt2 pos_;
	int speed_;
	int radius_;
	int AliveTimer_;
	int AliveNum_;

public:

	static bool IsAlive_;

	Enemy();

	virtual void Initialize();
	virtual void Update();
	virtual void Draw();
	void ResPawnTimer(Scene& scene);

	VectorInt2 GetPos() { return pos_; };
	int GetRadius() { return radius_; };

	void SetAliveNum(int AliveNum);

};

