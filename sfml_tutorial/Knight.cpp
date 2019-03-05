#include "Knight.h";

Vector2f
Knight::GetPosition() {
	return position;
}

void
Knight::SetPosition(Vector2f p) {
	position = p;
}

void Knight::Update(Time deltaTime)
{
	printf("Knight::Update\n");
	// Calls the base class' Update function.
	SpriteRenderer::Update(deltaTime);
	// Update the knight's position.

}