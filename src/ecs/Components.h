#pragma once

#include <string>
//SDL
/*
#include <SDL.h>
#include <SDL_image.h>
*/

#include "../utils/MathUtils.h"

class Component
{
	//TODO: Define logic for automatically assigning a new binSignature when a component is created for the first time
public:
	uint32_t binSignature{};
};
/*
class CSprite : public Component
{
public:

	CSprite(const SDL_Rect& p_spriteFrame, SDL_Texture* p_tex)
		: spriteFrame(p_spriteFrame)
		, tex(p_tex)
	{
	}
	// spriteFrame is the frame within the texture file that will be used. e.g. an entire 32x32 at 0,0 is x=0 y=0 w=32 h=32
	SDL_Rect spriteFrame;
	// the pointer to the texture file in mem that is to be rendered
	SDL_Texture* tex;
};
*/


class CTranslate : public Component
// vel, accel, angular vel, angular accel
// used by translate system to change location
{
public:

	CTranslate(const Vec2& p_vel, const Vec2& p_accel)
		: vel(p_vel)
		, accel(p_accel)
	{}
	Vec2 vel = { 0,0 };
	Vec2 accel = { 0,0 };
};

class CTransform : public Component
// Position, rotation, and scale
{
public:

	CTransform(const Vec2 p_pos, const Vec2 p_scale, float p_angle)
		: pos(p_pos)
		, scale(p_scale)
		, angle(p_angle)
	{}

	CTransform(const Vec2 p_pos)
		: pos(p_pos)
	{}

	Vec2 pos = { 0,0 };
	Vec2 scale = { 1,1 };
	float angle = 0;
};

class CShape : public Component
{
	//shape that would be rendered in sfdsldfm
	//will have to look into SDL version
};

class CName : public Component
{
public:
	std::string name;
};

class CScore : public Component
{
public:
	int score = 0;
	CScore(int p_s)
		: score(p_s)
	{}
};

class CBBox : public Component
{

};

class CCircleCollider : public Component
{
	float radius = 0;
	CCircleCollider(float p_r)
		: radius(p_r)
	{}
};

class CLifespan : public Component
{
public:
	int remaining	= 0;
	int total		= 0;
	CLifespan(int p_total)
		: remaining(p_total)
		, total(p_total)
	{}
};

class CInput : public Component
{
public:
	bool up = false;
	bool left = false;
	bool right = false;
	bool down = false;
	bool shoot = false;

	CInput() {}
};