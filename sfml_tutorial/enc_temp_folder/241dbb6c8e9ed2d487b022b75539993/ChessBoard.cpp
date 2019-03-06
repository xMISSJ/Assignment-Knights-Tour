#include "ChessBoard.h";

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

void ChessBoard::InitializeTiles(int width, int height)
{

	if (boardSize < 5 || boardSize > 8) {
		cout << "Invalid input. Please pick a number between 5 and 7.";
	}

	for (int y = 0; y < boardSize; y++)
	{	
		for (int x = 0; x < boardSize; x++)
		{
			RectangleShape tile(Vector2f(width, height));
			tile.setPosition(x * width, y * height);

			Color c = ((x + y) % 2) == 0 ? Color(50, 50, 50, 255) : Color(0, 100, 100, 255);
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
	//delete everything on the heap.
}