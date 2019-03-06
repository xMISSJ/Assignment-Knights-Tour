#include "Knight.h";

// e.g. 0 = empty, 1 = filled.
bool Knight::isVisited(bool &value)
{
	return value;
}

// Checks whether the move is inside the chessboard. 
bool Knight::isMovePossible(Knight_Moves nextMove, int inputSize) 
{
	int moveX = nextMove.x;
	int moveY = nextMove.y;

	return (moveX >= 0 && moveX < inputSize) && (moveY >= 0 && moveY < inputSize);
}

// Mark the position which has been visited.
void Knight::mark(int &value, int counter) 
{
	value = counter;
	counter++;
}

// Uses bruteforce backtracking to find path.
bool Knight::findPath(int x, int y)
{
	//if (counter > ())

}

void Knight::Update(Time deltaTime)
{
	//printf("Knight::Update\n");
	// Calls the base class' Update function.
	SpriteRenderer::Update(deltaTime);
	// Update the knight's position.

}