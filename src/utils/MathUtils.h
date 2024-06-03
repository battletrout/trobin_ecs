#pragma once

class Vec2
{
public:
	Vec2()
		: x(0)
		, y(0)
	{}

	Vec2(float p_x, float p_y)
		: x(p_x)
		, y(p_y)
	{}

	bool operator == (const Vec2& rhs) const;
	Vec2 operator + (const Vec2& rhs) const;
	Vec2 operator - (const Vec2& rhs) const;
	Vec2 operator * (const float rhs) const;
	void operator += (const Vec2* rhs);

	float dist(const Vec2& rhs) const;
	float length() const;

	float x, y;
};

class RandomGenerator
{
public:
	RandomGenerator();
	int randInt(int p_min, int p_max);
};