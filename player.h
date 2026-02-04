#pragma once

#include "raylib.h"
#include "laser.h"
#include <vector>

class Player
{

public:
	Player();
	~Player();
	void Draw();
	void MoveLeft();
	void MoveRight();
	void FireLaser();
	Rectangle getRect();
	void Reset();
	std::vector<Laser> lasers;

private:
	Texture2D image;
	Vector2 position;
	double lastFireTime;
	Sound laserSound;
};