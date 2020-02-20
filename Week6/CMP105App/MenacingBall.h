#pragma once
#include "Framework/GameObject.h"
class MenacingBall : public GameObject
{
public:
	MenacingBall();
	~MenacingBall();
	void Update(float dt);
	void chase(float dt);
private:
	sf::Vector2f direction;
	sf::Vector2f target;
	sf::Vector2f velocity;
	float speed;
	float scale;
};

