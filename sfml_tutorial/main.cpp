#include <SFML\Graphics.hpp>;
#include "ChessBoard.h";

using namespace sf;

int main()
{
	int userInput;
	cin >> userInput;
	RenderWindow window(VideoMode(512, 512), "SFML Tutorial", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);

	ChessBoard board(window, userInput);
	return 0;
}