#pragma once
#include "raylib.h"

namespace player
{
	struct Bird
	{
		int textureID;

		Vector2 position;

		float velocity;
	};

	void Initialization(Bird& bird);
	void Update(Bird& bird);
	void Draw(Bird bird);

	bool IsPlayerMoving();

	bool IsTouchingCeiling(Bird bird);
	bool HasLost(Bird bird);

	void CheckState(Bird& bird);
}