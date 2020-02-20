#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game object
	ball.setInput(input);
	ball.setFillColor(sf::Color::White);
	ball.setSize(sf::Vector2f(50, 50));
	ball.setPosition((window->getSize().x)/2, 20);

	mBall.setInput(input);
	mBall.setFillColor(sf::Color::Red);
	mBall.setSize(sf::Vector2f(50, 50));
	mBall.setPosition((window->getSize().x) / 2, 20);
	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball.handleInput(dt);
	if (input->isMouseLDown()) {
		ball.setPosition(input->getMouseX() - 20, input->getMouseY());
		ball.setHandled(true);
	}
	else {
		ball.setHandled(false);
	}

}

// Update game objects
void Level::update(float dt)
{
	ball.Update(dt);
	mBall.Update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
	window->draw(mBall);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	
	window->display();
}