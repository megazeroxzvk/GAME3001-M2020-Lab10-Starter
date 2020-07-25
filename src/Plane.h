#pragma once
#ifndef __PLANE__
#define __PLANE__

#include "Sprite.h"

enum directions
{
	UP_DIRECTION,
	RIGHT_DIRECTION,
	LEFT_DIRECTION,
	DOWN_DIRECTION,
	NUMBER_OF_DIRECTIONS
};

class Plane final : public Sprite
{
public:
	Plane();
	~Plane();

	// Life Cycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	//Lab10 -- Patrol Mode
	void patrolToggle(bool toggle);
	void setAngle(directions);

private:
	void m_buildAnimations();
	bool m_patrol;
	float m_angle;
	
};

#endif /* defined (__PLANE__) */
