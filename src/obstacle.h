#pragma once
#include "raylib.h"

namespace obstacle
{
	struct Obstacle
	{
		int textureID;

		Vector2 position;

		float velocity;

		float width;
		float height;
	};

	void Initialization(Obstacle& obstacle);
	void Update(Obstacle& obstacle);
	void Draw(Obstacle obstacle);

	void CheckOutOfBounds(Obstacle& obstacle);
}
