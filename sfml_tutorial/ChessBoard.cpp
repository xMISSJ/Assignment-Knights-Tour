#include "ChessBoard.h";

ChessBoard::ChessBoard(RenderWindow &window, int userInput, int maxSize, int minSize)
{
	this->userInput = userInput;
	this->maxSize = maxSize;
	this->minSize = minSize;

	float width = window.getSize().x / userInput, height = window.getSize().y / userInput;
	_knightRenderer.Initialize("Textures/Knight.png", width, height);

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
	for (int y = 0; y < userInput; y++)
	{	
		for (int x = 0; x < userInput; x++)
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
		//(*it)->Update(deltatime);
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

// Deletes everything on the heap.
ChessBoard::~ChessBoard()
{
}