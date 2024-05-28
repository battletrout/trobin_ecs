#include "MathUtils.h"

#include <math.h>
#include <ctime>
#include <stdlib.h>

bool Vec2::operator == (const Vec2& rhs) const
{
	return (x == rhs.x && y == rhs.y);
}

Vec2 Vec2::operator + (const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator - (const Vec2& rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 Vec2::operator * (const float rhs) const
{
	return Vec2(x * rhs, y * rhs);
}

void Vec2::operator += (const Vec2* rhs)
{
	x += rhs->x;
	y += rhs->y;
}

float Vec2::dist(const Vec2& rhs) const
{
	float dx = rhs.x - x;
	float dy = rhs.y - y;
	return sqrtf((dx * dx) + (dy * dy));
}

float Vec2::length() const
{
	return sqrtf((x*x) + (y*y));
}

////////////////////////////////////////////////
//Random Generator
////////////////////////////////////////////////

RandomGenerator::RandomGenerator()
{
	srand(std::time(nullptr));
}

int RandomGenerator::randInt(int p_min, int p_max)
{
	return p_min + (rand() % (1 + p_max - p_min));
}
