#include "Knight.h";

void Knight::Update(Time deltaTime)
{
	printf("Knight::Update\n");
	// Calls the base class' Update function.
	SpriteRenderer::Update(deltaTime);
	// Update the knight's position.
	this->_rectangle.setPosition(100, 0);
}