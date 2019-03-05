#ifndef _CHESSBOARD_
#define _CHESSBOARD_

#include <SFML\Graphics.hpp>
#include "Knight.h"
#include <iostream>
#include <string>

using namespace sf;
using namespace std;
using std::vector;

	class ChessBoard
	{
	private:
		int														userInput;
		int														maxSize;
		int														minSize;
		vector<RectangleShape>				_tiles;
		vector<SpriteRenderer*>				_sprites;
		Knight												_knightRenderer;
		Clock													_deltaClock;

		void Update();
		void InitializeTiles(int w, int h);
		void Draw(RenderWindow &window);
		void DrawChessBoard(RenderWindow &window);

	public:
		ChessBoard(RenderWindow &window, int userInput, int maxSize, int minSize);		// Constructor.
		~ChessBoard();																																// Destructor.
	};

#endif