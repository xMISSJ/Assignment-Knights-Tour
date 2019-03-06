#ifndef _CHESSBOARD_
#define _CHESSBOARD_

#include <SFML\Graphics.hpp>
#include "Knight.h"
#include <iostream>

using namespace sf;
using namespace std;
using std::vector;

	class ChessBoard
	{
	private:
		int														boardSize;
		vector<RectangleShape>				_tiles;
		vector<SpriteRenderer*>				_sprites;
		Knight												_knightRenderer;
		Clock													_deltaClock;

		void Update();
		void InitializeTiles(int w, int h);
		void Draw(RenderWindow &window);
		void DrawChessBoard(RenderWindow &window);

	public:
		static const int MIN_SIZE = 5;
		static const int MAX_SIZE = 7;

		ChessBoard(RenderWindow &window, int boardSize, int startPosX, int startPosY); //constructor
		~ChessBoard(); //destructor
	};

#endif