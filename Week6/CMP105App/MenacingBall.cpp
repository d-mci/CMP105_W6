#include "MenacingBall.h"
#include "Ball.h"
#include <iostream>
#include "Framework/Vector.h"



MenacingBall::MenacingBall() {
	scale = 200.f;
	speed = 100;
	//target = (sf::Vector2f(0,0));
	
}
MenacingBall::~MenacingBall() {

}

void MenacingBall::chase(float dt) {
	target = (sf::Vector2f(input->getMouseX(), input->getMouseY()));
	direction = Vector::normalise(target - getPosition());
	velocity = (direction * speed);
	setPosition(getPosition() + (velocity * dt));
	//if the obj is x distance away from target
	if (Vector::magnitude(target - getPosition()) < 10.f) {
		setPosition(target);
	}
}

void MenacingBall::Update(float dt) {
	chase(dt);
}