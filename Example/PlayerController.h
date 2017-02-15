#pragma once

#include "Base.h"
using namespace base;
class PlayerController
{

public:
	float speed = 700, turnSpeed = 1;

	float shotTimer = 0.0f;
	bool shotRequest = false;

	void poll(base::Transform *T, base::Rigidbody *rb, float dt)
	{
		if (sfw::getKey('W'))
		{
			rb->addForce(vec2{ 0, speed });
		}
		if (sfw::getKey('Q'))
		{
			rb->addForce(vec2{ 0, -speed });
		}
		
		if (sfw::getKey('A'))
			rb->addForce(vec2{ -speed, 0 });

		if (sfw::getKey('D'))
			rb->addForce(vec2{ speed, 0 });

		shotTimer -= dt;
		if (sfw::getKey(' ') && shotTimer < 0)
		{
			shotRequest = true;
			shotTimer = 0.86f;
		}
		else shotRequest = false;
	}

};