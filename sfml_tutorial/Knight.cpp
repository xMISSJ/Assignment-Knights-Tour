#include "Knight.h";

// Checks whether the move is inside the chessboard. 
bool isMovePossible(Knight_Moves nextMove, int inputSize) {
	int moveX = nextMove.x;
	int moveY = nextMove.y;

	return (moveX >= 0 && moveX < inputSize) && (moveY >= 0 && moveY < inputSize);
}

// e.g. 0 = empty, 1 = filled.
bool isVisited(bool value) {
	return value;
}

// Uses backtracking to find path.
bool findPath(int x, int y) {
	// Checks if current tile isn't in use.
	if ()
}

void Knight::Update(Time deltaTime)
{
	//printf("Knight::Update\n");
	// Calls the base class' Update function.
	SpriteRenderer::Update(deltaTime);
	// Update the knight's position.

}