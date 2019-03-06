#include "Knight.h";
#include <windows.h>

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
	case 8:
		// 8 x boardScale
		this->boardSize = 64;
		break;
	}
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
		this->visualisation = true;
		timer.restart();
	};
}

void Knight::Update(Time deltaTime)
{
	//call the base class's Update function
	SpriteRenderer::Update(deltaTime);
	//update the knight's position
	if (this->visualisation) {
		if (this->timer.getElapsedTime() >= sf::seconds(this->visualisationSpeed)) { // Speed of the visualisation
			this->turn++;
			int i, j;
			for (i = 0; i <= this->boardSize - 1; i++)
				for (j = 0; j <= this->boardSize - 1; j++) {
					if (this->turn == board[i][j]) {
						cout << "[Turn: " << turn << "] X: " << i << " Y: " << j << endl;
						SpriteRenderer::_rectangle.setPosition(((i + 1) * this->boardScale) - this->boardScale, ((j + 1) * this->boardScale) - this->boardScale);
					}
				}
			this->timer.restart();
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

/**
 * Backtracken is een recursieve methode om de Knight te bewegen op het bord.
 */

 /*!
		 \param x the x-coordinate of the Knight.
		 \param y the y-coordinate of the Knight.
 */
bool Knight::backtrack(int x, int y) {

	// Als we bijvoorbeeld een 5x5 bord hebben. Kunnen we maximaal 25 stappen.
	// Als we eenmaal 25 stappen hebben zijn we klaar en returnen wij gelijk true.
	if (counter > (this->boardSize * this->boardSize))
		return true;

	if (unvisited(board[x][y]))
	{
		mark(board[x][y]);
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