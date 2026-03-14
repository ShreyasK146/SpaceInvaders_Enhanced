#include "mysteryship.h"

MysteryShip::MysteryShip()
{
	image = LoadTexture("Images/mystery.png");
	alive = false;
}

MysteryShip::~MysteryShip()
{
	UnloadTexture(image);
}
//spawning mystery ship at top left or right side
void MysteryShip::Spawn()
{
	position.y = 90;
	int side = GetRandomValue(0, 1);

	if (side == 0)
	{
		position.x = 25;
		speed = 3;
	}
	else
	{
		position.x = GetScreenWidth() - image.width -25;
		speed = -3;
	}
	alive = true;
}

// move the mystery ship horizontally
void MysteryShip::Update()
{
	if (alive)
	{
		position.x += speed;
		if (position.x > GetScreenWidth() - image.width-25 || position.x < 25) // kill it when it goes out of bounds no points though
			alive = false;
	}
		
}

void MysteryShip::Draw()
{
	if (alive)
	{
		DrawTextureV(image, position, WHITE);
	}
}
// same logic as obstacle to draw rect around mystery ship for colliision detection
Rectangle MysteryShip::getRect()
{
	if (alive)
		return { position.x,position.y,float(image.width),float(image.height) };
	else
		return { position.x,position.y,0,0 };
}