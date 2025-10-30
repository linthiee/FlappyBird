#include "player.h"
#include "globals.h"

namespace variables
{
	static float velocity = 500.0f;
}

void player::Initialization(Bird& bird)
{
	bird.textureID = 0;

	bird.position = { static_cast<float>(externs::screenWidth) / 6.0f, static_cast<float>(externs::screenHeight) / 2.0f };

	bird.velocity = 0.0f;
}

void player::Update(Bird& bird)
{
	//bird.velocity -= globals::acceleration * externs::deltaT;

	//if (player::IsPlayerMoving())
	//{
	//	bird.velocity = variables::velocity;
	//}

	//bird.position.y -= bird.velocity * externs::deltaT;

	if (player::IsPlayerMovingUp())
	{
		bird.velocity = -variables::velocity;
	}
	else if (player::IsPlayerMovingDown())
	{
		bird.velocity = variables::velocity;
	}

	bird.position.y += bird.velocity * externs::deltaT;

}

void player::Draw(Bird bird)
{
	DrawCircleV(bird.position, 30.0f, BLUE);
}

bool player::IsPlayerMovingUp()
{
	return IsKeyPressed(KEY_UP);
}

bool player::IsPlayerMovingDown()
{
	return IsKeyPressed(KEY_DOWN);
}
