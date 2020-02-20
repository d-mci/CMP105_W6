#pragma once
#include "Framework/GameObject.h"
class Ball : public GameObject
{
public:
	Ball();
	~Ball();
	void handleInput(float dt) override;
	void setHandled(bool state);
	void toggleMode(bool state);
	void Update(float dt);
private:
	sf::Vector2f stepVelocity;
	sf::Vector2f gravity;
	bool handled;
	float scale;

};

