#include "alien.h"

Texture2D Alien::alienImages[3] = {};

Alien::Alien(int type, Vector2 position)
{
	// load different alien texture 
	this->type = type;
	this->position = position;
	if (alienImages[type - 1].id == 0)
	{
		switch (type)
		{
		case 1:
			alienImages[0] = LoadTexture("Images/alien_1.png");
			break;
		case 2:
			alienImages[1] = LoadTexture("Images/alien_2.png");
			break;
		case 3:
			alienImages[2] = LoadTexture("Images/alien_3.png");
			break;
		default:
			alienImages[0] = LoadTexture("Images/alien_1.png");
			break;
		}
	}
	
}

void Alien::Draw()
{
	//alien type 1,2,3 = aleinimages[0] or 1 or 2
	DrawTextureV(alienImages[type-1], position, WHITE);
}

int Alien::GetType()
{
	return type;
}

void Alien::UnloadImages()
{
	for (int i = 0; i < 3; i++)
	{
		UnloadTexture(alienImages[i]);
	}
}

void Alien::Update(int direction)
{
	position.x += direction*2; // how fast alient moves horizontally
	
}
//Returns a rectangle that perfectly wraps the alien used for collions detection
Rectangle Alien::getRect()
{
	return { position.x,position.y,float(alienImages[type - 1].width), float(alienImages[type - 1].height) };
}