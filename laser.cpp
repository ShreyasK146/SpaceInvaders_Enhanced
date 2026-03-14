#include "laser.h"
#include <iostream>

Laser::Laser(Vector2 position, int speed)
{
	this->position = position;
	this->speed = speed;
	active = true;
}

void Laser::Draw()
{
	if(active)
		DrawRectangle(position.x, position.y, 4, 15, { 243,216,63,255 });
}
// get laser rect for collision detection
Rectangle Laser::getRect()
{
	Rectangle rect;
	rect.x = position.x;
	rect.y = position.y;
	rect.width = 4;
	rect.height = 15;
	return rect;
}
void Laser::Update()
{
	position.y += speed; /// move in y axis

	if (active)
	{
		if (position.y > GetScreenHeight()-100|| position.y < 25) // make it inactive  when it goes out of bounds
		{
			active = false;
			
		}
	}
}
