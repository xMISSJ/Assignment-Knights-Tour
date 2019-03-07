#include "ChessBoard.h";

/*
 *	This ChessBoard.cpp file handles the tiling of the board.
 *  Includes adjusting tile colours.
 */

 /*!
		 \param &window: the window to show the board and knight on. 
		 \param boardSize: int which defines the boardSize (e.g. 5 x 5).
		 \param startPosX: the start position of the x-coordinate which the user has chosen.
		 \param startPosY: the start position of the y-coordinate which the user has chosen.
 */
ChessBoard::ChessBoard(RenderWindow &window, int boardSize, int startPosX, int startPosY)
{
	this->boardSize = boardSize;

	float width = window.getSize().x / boardSize, height = window.getSize().y / boardSize;
	_knightRenderer.Initialize(startPosX, startPosY, boardSize, width, height);

	_sprites.emplace_back(&_knightRenderer);

	InitializeTiles(width, height);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color(255, 255, 255, 255));
		Update();
		Draw(window);
		window.display();
	}
}

/*!
		\param width: the width of the board.
		\param height: the height of the board.
*/
void ChessBoard::InitializeTiles(int width, int height)
{

	if (boardSize < this->MIN_SIZE || boardSize > this->MIN_SIZE) {
		cout << "Invalid input. Please pick a number between 5 and 7.";
	}

	for (int y = 0; y < boardSize; y++)
	{	
		for (int x = 0; x < boardSize; x++)
		{
			RectangleShape tile(Vector2f(width, height));
			tile.setPosition(x * width, y * height);
			Color c = ((x + y) % 2) == 0 ? Color(255, 236, 251, 255) : Color(252, 146, 182, 255);
			tile.setFillColor(c);

			_tiles.emplace_back(tile);
		}
	}
}

void ChessBoard::Update()
{
	Time deltatime = _deltaClock.restart();
	for (vector<SpriteRenderer*>::iterator it = _sprites.begin();
		it < _sprites.end(); ++it)
	{
		(*it)->Update(deltatime);
	}
}

void ChessBoard::Draw(RenderWindow &window)
{
	for (vector<RectangleShape>::iterator it = _tiles.begin();
		it != _tiles.end(); ++it)
	{
		window.draw(*it);
	}

	for (vector<SpriteRenderer*>::iterator it = _sprites.begin();
		it != _sprites.end(); ++it)
	{
		(*it)->Draw(window);
	}
	DrawChessBoard(window);
}

void ChessBoard::DrawChessBoard(RenderWindow &window)
{

}

ChessBoard::~ChessBoard()
{
	// Deletes everything on the heap.
}