#include "Knight.h";
#include <windows.h>

/*
 * This Knight.cpp file handles the knight sprite. 
 * Consists of an update function, in which the position of the knight is adjusted according to the Bruteforce backtrack algorithm.
 * Backtracking is a recursive method to make the knight move around.
 * Handles the visualisation and positioning of the knight sprite.
 */

void Knight::Initialize(int startPosX, int startPosY, int boardSize, int width, int height) {
	this->startPosX = startPosX;
	this->startPosY = startPosY;
	this->boardSize = boardSize;

	switch (boardSize) {
	case 5:
		// 5 x 5
		this->boardScale = 102;
		break;
	case 6:
		// 6 x 6 
		this->boardScale = 85;
		break;
	case 7:
		// 7 x 7
		this->boardScale = 73;
		break;
	}

	// Calculates the start coordinates.
	this->startCoordX = (this->startPosX * this->boardScale) - this->boardScale;
	this->startCoordY = (this->startPosY * this->boardScale) - this->boardScale;

	SpriteRenderer::Initialize("Textures/Knight.png", width, height);
	SpriteRenderer::_rectangle.setPosition(this->startCoordX, this->startCoordY);

	// Fills the boards with 0's which means a cell is unvisited.
	int i, j;
	for (i = 0; i <= this->boardSize - 1; i++)
		for (j = 0; j <= this->boardSize - 1; j++)
			board[i][j] = 0;

	cout << "Calculating..." << endl;
	if (this->backtrack(this->startPosX - 1, this->startPosY - 1)) {
		cout << "Tour complete!" << endl;
		// Toggles visualisation of the knight and board.
		this->visualisation = true;
		timer.restart();
	};
}

void Knight::Update(Time deltaTime)
{
	// Calls the base class' Update function.
	SpriteRenderer::Update(deltaTime);
	// Updates the knight's position.
	if (this->visualisation) {
		// Visualisation speed.
		if (this->timer.getElapsedTime() >= sf::seconds(this->visualisationSpeed)) { 
			this->turn++;
			int i, j;
			// Simulates a turn with the knight.
			for (int i = 0; i <= this->boardSize - 1; i++) // Loop for x-coordinate.
				for (int j = 0; j <= this->boardSize - 1; j++) { // Loop for y-coordinate.
					if (this->turn == board[i][j]) { // If the turn is in the following x-coordinate and y-coordinate.
						cout << "[Turn " << turn << "] X: " << i << " Y: " << j << endl; // Print out the turn, x-coordinate and y-coordinate.
						SpriteRenderer::_rectangle.setPosition(((i + 1) * this->boardScale) - this->boardScale, ((j + 1) * this->boardScale) - this->boardScale); // Based on the scale of the Board, we apply a formule ((gridPosition + 1) * boardScale) - boardScale.
					}
				}
			this->timer.restart(); // Restart the timer to do the next turn in ... seconds.
		}
	}
}

void Knight::mark(int &val) {
	val = this->counter;
	this->counter++;
}

void Knight::unmark(int &val) {
	val = 0;
	this->counter--;
}

 /*!
		 \param x: the x-coordinate of the knight.
		 \param y: the y-coordinate of the knight.
 */
bool Knight::backtrack(int x, int y) {

	// If we have a 5x5 board, we can have a maximum of 25 steps.
	// If we've reached this amount of steps, the pathfinding is done and it will return true.
	if (counter > (this->boardSize * this->boardSize))
		return true;

	if (unvisited(board[x][y]))
	{
		mark(board[x][y]);

		// The 8 different L moves.
		if (canMove(x - 2, y + 1)) {
			if (backtrack(x - 2, y + 1)) return true;
		}

		if (canMove(x - 2, y - 1)) {
			if (backtrack(x - 2, y - 1)) return true;
		}

		if (canMove(x - 1, y + 2)) {
			if (backtrack(x - 1, y + 2)) return true;
		}

		if (canMove(x - 1, y - 2)) {
			if (backtrack(x - 1, y - 2)) return true;
		}

		if (canMove(x + 2, y + 1)) {
			if (backtrack(x + 2, y + 1)) return true;
		}

		if (canMove(x + 2, y - 1)) {
			if (backtrack(x + 2, y - 1)) return true;
		}

		if (canMove(x + 1, y + 2)) {
			if (backtrack(x + 1, y + 2)) return true;
		}

		if (canMove(x + 1, y - 2)) {
			if (backtrack(x + 1, y - 2)) return true;
		}

		unmark(board[x][y]);
	}
	return false;
}

bool Knight::unvisited(int &val) {
	return val == 0;
}

bool Knight::canMove(int moveX, int moveY) {
	return(moveX >= 0) && (moveX < this->boardSize) && (moveY >= 0) && (moveY < this->boardSize);
}