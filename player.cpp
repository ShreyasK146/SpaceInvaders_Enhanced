#include "player.h"
#include "game.h"
//instantiate player at bottom mid
Player::Player()
{
	image = LoadTexture("Images/spaceship.png");
	position.x = (GetScreenWidth() - image.width) / 2; 
	position.y = GetScreenHeight() - image.height-100;
	lastFireTime = 0.0;
	laserSound = LoadSound("Sounds/laser.ogg");
}

Player::~Player()
{
	UnloadTexture(image);
	UnloadSound(laserSound);
}

void Player::Draw()
{
	DrawTexture(image, position.x, position.y, WHITE);
}
// move left right and clamp so that player cnat go outside bounds
void Player::MoveLeft()
{
	position.x -= 7;
	if (position.x < 25)
		position.x = 25;
}

void Player::MoveRight()
{
	position.x += 7;
	if (position.x > (GetScreenWidth() - image.width- 25))
		position.x = GetScreenWidth() - image.width - 25;
}

void Player::FireLaser()
{
	if (GetTime() - lastFireTime >= 0.35) // fire rate control to stop spamming bullets
	{
		lasers.push_back(Laser({ position.x + image.width / 2 - 2,position.y }, -6));
		/*
		*    position.x + image.width/2  center of the player ship
			-2  slight adjustment to look centered
			-6  laser moves up 6px per frame (negative y = up in raylib)
		*/
		lastFireTime = GetTime();
		PlaySound(laserSound);
	}
	
}

Rectangle Player::getRect()
{
	return { position.x,position.y,float(image.width), float(image.height) };
}
void Player::Reset()
{
	position.x = (GetScreenWidth() - image.width) / 2.0f;
	position.y = GetScreenHeight() - image.height-100;
	lasers.clear();
}
