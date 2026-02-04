#pragma once
#include "Player.h"
#include "obstacle.h"
#include "alien.h"
#include "mysteryship.h"

class Game {
public:
	Game();
	~Game();
	void Draw();
	void Update();
	void HandleInput();
	bool run;
	int lives;
	int score;
	int highscore;
private:
	void DeleteInactiveLasers();
	std::vector<Obstacle> CreateObstacles();
	std::vector<Alien>CreateAliens();
	void MoveAliens();
	void MoveDownAliens(int distance);
	void AlienShootLaser();
	void CheckForCollisions();
	void GameOver();
	void Reset();
	void InitGame();
	void CheckForHighScore();
	void SaveHighScoreToFile(int highscore);
	int loadHighScoreFromFile();
	Player player;
	std::vector<Obstacle>obstacles;
	std::vector<Alien>aliens;
	int aliensDirection;
	std::vector<Laser> alienLasers;
	constexpr static float alienLaserShootInterval = 0.35;
	float timeLastAlienFired;
	MysteryShip mysteryship;
	float mysteryShipSpawnInterval;
	float timeLastSpawn;
	
};