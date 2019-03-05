#in#include "Knight.h";

Knight::Knight(int posX, int posY) {
	this->posX = posX;
	this->posY = posY;
}

void Knight::Update(Time deltaTime)
{
	printf("Knight::Update\n");
	// Calls the base class' Update function.
	SpriteRenderer::Update(deltaTime);
	// Update the knight's position.
	this->_rectangle.setPosition(100, 0);
}

// Deletes everything on the heap.
Knight::~Knight()
{
}