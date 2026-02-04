#pragma once
#include "Player.h"
#include "obstacle.h"
#include "alien.h"

class Game {
public:
	Game();
	~Game();
	void Draw();
	void Update();
	void HandleInput();
private:
	void DeleteInactiveLasers();
	std::vector<Obstacle> CreateObstacles();
	std::vector<Alien>CreateAliens();
	void MoveAliens();
	void MoveDownAliens(int distance);
	void AlienShootLaser();
	Player player;
	std::vector<Obstacle>obstacles;
	std::vector<Alien>aliens;
	int aliensDirection;
	std::vector<Laser> alienLasers;
	constexpr static float alienLaserShootInterval = 0.35;
	float timeLastAlienFired;
};