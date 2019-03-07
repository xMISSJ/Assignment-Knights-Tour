#ifndef _KNIGHT_ // This header file should only be defined once.
#define _KNIGHT_
#include "SpriteRenderer.h";
#include <iostream>

using namespace std;
using namespace sf;

	// If not public, the inheriting of SpriteRenderer would make this Update function inaccessible.
	// For further information, see https://bit.ly/2OGCENo and https://bit.ly/2GcOk9S.
	class Knight : public SpriteRenderer
	{
	private:
		int					startPosX;
		int					startPosY;
		int					startCoordX;
		int					startCoordY;
		int					boardSize;
		int					boardScale;
		int					board[7][7];
		int					counter = 1;
		bool				visualisation;
		float				visualisationSpeed = 1.1f;

		Clock				timer;
		int					turn = 0;

		void				mark(int &);
		void				unmark(int &);
		bool				unvisited(int &);
		bool				canMove(int, int);
		bool				backtrack(int, int);
		void ChangeColor(int value);

	public:
		//override the Update function from SpriteRenderer.
		void Initialize(int startPosX, int startPosY, int boardSize, int width, int height);
		void Update(Time deltaTime);
	};
#endif