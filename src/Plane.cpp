#include "Plane.h"
#include "TextureManager.h"

Plane::Plane()
{
	TextureManager::Instance()->loadSpriteSheet(
		"../Assets/sprites/atlas.txt",
		"../Assets/sprites/atlas.png", 
		"spritesheet");

	setSpriteSheet(TextureManager::Instance()->getSpriteSheet("spritesheet"));

	// set frame width
	setWidth(65);

	// set frame height
	setHeight(65);

	getTransform()->position = glm::vec2(400.0f, 200.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLANE);


	m_buildAnimations();
}

Plane::~Plane()
= default;

void Plane::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the plane sprite with simple propeller animation
	TextureManager::Instance()->playAnimation(
		"spritesheet", getAnimation("plane"),
		x, y, 0.5f, m_angle, 255, true);
}

void Plane::update()
{
	//startPatrol();
}

void Plane::clean()
{
}


void Plane::patrolToggle(bool toggle)
{
	m_patrol = toggle;
}

void Plane::m_buildAnimations()
{
	Animation planeAnimation = Animation();

	planeAnimation.name = "plane";
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("plane1"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("plane2"));
	planeAnimation.frames.push_back(getSpriteSheet()->getFrame("plane3"));

	setAnimation(planeAnimation);
}

void Plane::setAngle(directions dir)
{
	switch (dir)
	{
	case UP_DIRECTION:
		m_angle = 0.0f;
		break;

	case RIGHT_DIRECTION:
		m_angle = 90.0f;
		break;

	case LEFT_DIRECTION:
		m_angle = -90.0f;
		break;

	case DOWN_DIRECTION:
		m_angle = 180.0f;
		break;

	default:
		m_angle = 0.0f;
		break;
	}
}
