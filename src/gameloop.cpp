#include "gameloop.h"
#include "globals.h"
#include "player.h"
#include "obstacle.h"
#include "text.h"
#include "draw.h"

#include "raylib.h"

namespace essentials
{
	static void GetDeltaTime();
}

namespace game
{
	static bool CheckCollisions(player::Bird bird, obstacle::Obstacle obstacle);
	static void DrawCurrentVer();
}

namespace objects
{
	static player::Bird bird;
	static obstacle::Obstacle obstacle;
}

namespace text
{
	static text::Text version;
}

void game::GameLoop()
{
	InitWindow(externs::screenWidth, externs::screenHeight, "Flappy Bird");
	player::Initialization(objects::bird);
	obstacle::Initialization(objects::obstacle);

	while (!WindowShouldClose())
	{
		essentials::GetDeltaTime();

		player::Update(objects::bird);
		obstacle::Update(objects::obstacle);

		if (game::CheckCollisions(objects::bird, objects::obstacle))
		{
			CloseWindow();

		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		game::DrawCurrentVer();
		player::Draw(objects::bird);
		obstacle::Draw(objects::obstacle);

		EndDrawing();
	}

	CloseWindow();
}

void essentials::GetDeltaTime()
{
	externs::deltaT = GetFrameTime();
}

bool game::CheckCollisions(player::Bird bird, obstacle::Obstacle obstacle)
{
	const float circleRadius = 30.0f; 
	float circleX = bird.position.x;
	float circleY = bird.position.y;

	float rectX = obstacle.position.x;
	float rectY = obstacle.position.y;
	float rectWidth = obstacle.width;
	float rectHeight = obstacle.height;

	float closestX = std::max(rectX, std::min(circleX, rectX + rectWidth));
	float closestY = std::max(rectY, std::min(circleY, rectY + rectHeight));

	float distanceX = circleX - closestX;
	float distanceY = circleY - closestY;

	float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

	if (distanceSquared < (circleRadius * circleRadius))
	{
		return true;
	}
	return false;
}

void game::DrawCurrentVer()
{
	text::version.text = "ver 0.1";
	text::version.posX = 95.0f;
	text::version.posY = 98.0f;
	text::version.color = BLACK;

	draw::DrawText(text::version);
}