#include "draw.h"
#include "globals.h"

#include "raylib.h"

void draw::DrawText(text::Text text)
{
	DrawTextEx(text.font, text.text.c_str(), { (text.posX * externs::screenWidth / 100.0f) - (MeasureText(text.text.c_str(), text.fonstSize)) / 2.4f, (text.posY * externs::screenHeight / 100.0f) - (text.fonstSize / 2) }, static_cast<float>(text.fonstSize), static_cast<float>(text.spacing), text.color);
}
