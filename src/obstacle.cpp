#include "obstacle.h"

#include "globals.h"

namespace variables
{
	static float velocity = 500.0f;
}

void obstacle::Initialization(Obstacle& obstacle)
{
	obstacle.textureID = 0;

	obstacle.width = 50.0f;
	obstacle.height = 400.0f;

	obstacle.position = { static_cast<float>(externs::screenWidth) - obstacle.width,  static_cast<float>(externs::screenHeight) - obstacle.height };

	obstacle.velocity = variables::velocity;
}

void obstacle::Update(Obstacle& obstacle)
{
	obstacle.position.x += -obstacle.velocity * externs::deltaT;

	obstacle::CheckOutOfBounds(obstacle);
}

void obstacle::Draw(Obstacle obstacle)
{
	DrawRectangle(static_cast<int>(obstacle.position.x), static_cast<int>(obstacle.position.y), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), RED);
	DrawRectangle(static_cast<int>(obstacle.position.x - static_cast<int>(obstacle.width / 30.0f)), static_cast<int>(obstacle.position.y - static_cast<int>(obstacle.height * 1.5f)), static_cast<int>(obstacle.width), static_cast<int>(obstacle.height), RED);
}

void obstacle::CheckOutOfBounds(Obstacle& obstacle)
{
	if (obstacle.position.x + obstacle.width < 0.0f)
	{
		obstacle.position.x = externs::screenWidth + obstacle.width;
	}
}
