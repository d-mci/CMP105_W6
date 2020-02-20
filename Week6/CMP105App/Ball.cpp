#include "Ball.h"
#include <iostream>



Ball::Ball() {
	// initialise gravity value
	scale = 200.f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	handled = false;
}
Ball::~Ball() {

}

void Ball::handleInput(float dt){
	if (input->isKeyDown(sf::Keyboard::Space)) {
		velocity = sf::Vector2f(0, -1.f)  ;
		std::cout << "Jump";
		setPosition(getPosition() + velocity);
	}
	
	
}

void Ball::setHandled(bool state) {
	handled = state;
}


void Ball::Update(float dt){
	if (handled) {
		stepVelocity = sf::Vector2f(0, 0);
	}
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut+ 1/2at^2
	stepVelocity +=gravity *dt; 
	setPosition(getPosition() + pos);
	
	// Check for collision with bottom of window
	if(getPosition().y >= 500){
		setPosition(getPosition().x, 500);
		stepVelocity = sf::Vector2f(-(stepVelocity += gravity * dt)/1.2f);
	}

	
}