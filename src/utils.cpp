#include "utils.h"

#include "globals.h"

float utils::PercentToPixelsX(float percentX)
{
	return (percentX / 100.0f) * externs::screenWidth;
}

float utils::PercentToPixelsY(float percentY)
{
	return (percentY / 100.0f) * externs::screenHeight;
}

float utils::PixelsToPercentX(float px)
{
	return (px / externs::screenWidth) * 100.0f;
}

float utils::PixelsToPercentY(float py)
{
	return (py / externs::screenHeight) * 100.0f;
}