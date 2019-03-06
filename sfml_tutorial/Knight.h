#ifndef _KNIGHT_ // This header should only be defined once.
#define _KNIGHT_
#include "SpriteRenderer.h";
#include "ChessBoard.h";

using namespace sf;

extern int maxSize;

// Data elements grouped together under one name.
typedef struct Knight_Moves {
	// x-axis and y-axis on the board.
	int x;
	int y;
}Knight_Moves;

// If not public, the inheriting of SpriteRenderer would make this Update function inaccessible.
// For further information, see https://bit.ly/2OGCENo and https://bit.ly/2GcOk9S.
class Knight : public SpriteRenderer
{
private:
	// Array with the 8 possible moves a knight could make from any square.
	Knight_Moves		movesArray[8] = { {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1} };
	int							counter = 1;		
	int							board[ChessBoard::MAX_SIZE][ChessBoard::MAX_SIZE];
	bool						isVisited(bool &value);
	bool						isMovePossible(Knight_Moves nextMoves, int inputSize);
	bool						findPath(int x, int y);
	void						mark(int &value, int counter);

public:
	// Overrides the Update function from SpriteRenderer.
	void Update(Time deltaTime);
};
#endif