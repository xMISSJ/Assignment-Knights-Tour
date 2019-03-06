#ifndef _KNIGHT_ //make sure that this header file is only defined once
#define _KNIGHT_
#include "SpriteRenderer.h";
#include <iostream>

using namespace std;

	//if not public, the inheriting of SpriteRenderer would make this Update function inaccessible
	//for further information, see https://bit.ly/2OGCENo and https://bit.ly/2GcOk9S
	class Knight : public SpriteRenderer
	{
	private:
		int startPosX;
		int startPosY;
		int startCoordX;
		int startCoordY;
		int boardSize;
		int boardScale;
		int board[8][8];
		int counter = 1;
		bool visualisation;
		float visualisationSpeed = 1.5f;

		sf::Clock timer;
		int turn = 0;

		void mark(int &);
		void unmark(int &);
		bool unvisited(int &);
		bool canMove(int, int);
		bool backtrack(int, int);

	public:
		//override the Update function from SpriteRenderer
		void Initialize(int startPosX, int startPosY, int boardSize, int width, int height);
		void Update(Time deltaTime);
	};
#endif