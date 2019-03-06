#include "SpriteRenderer.h"

void SpriteRenderer::Initialize(String path, float width, float height, Vector2f position)
{
	_rectangle = RectangleShape(Vector2f(width, height));
	_rectangle.setPosition(position);

	_texture.loadFromFile(path);
	_rectangle.setTexture(&_texture);
}

void SpriteRenderer::Update(Time deltaTime)
{
	//printf("mu: %ld \n", deltaTime.asMicroseconds());
}

void SpriteRenderer::Draw(RenderWindow &window)
{
	window.draw(_rectangle);
}