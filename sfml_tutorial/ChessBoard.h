#ifndef _CHESSBOARD_
#define _CHESSBOARD_

#include <SFML\Graphics.hpp>
#include "Knight.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace sf;
using namespace std;
using std::vector;

class ChessBoard
{
private:
	int                              sizeInput;
	int                              maxSize;
	int                              minSize;
	Vector2f                         position;
	vector<RectangleShape>           _tiles;
	vector<SpriteRenderer*>          _sprites;
	Knight                           _knightRenderer;
	Clock                            _deltaClock;

	void Update();
	void InitializeTiles(int w, int h);
	void Draw(RenderWindow &window);
	void DrawChessBoard(RenderWindow &window);

public:
	ChessBoard(RenderWindow &window, int sizeInput, int maxSize, int minSize, Vector2f position);        // Constructor.
	~ChessBoard();                                                                                       // Destructor.
};

#endif