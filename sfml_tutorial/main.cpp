#include <SFML\Graphics.hpp>;
#include "ChessBoard.h";

using namespace sf;

int main()
{
	int												userInput;
	int												maxSize = 8;
	int												minSize = 5;
	static const string				PROGRAM_INTRO = "Please insert a number from 5 to 8. \n";
	static const string				PROGRAM_ERROR = "Invalid number. Please pick a number from 5 to 8. \n";

	// Program shows error, so long there is no valid number (5-8).
	do {
		cout << PROGRAM_INTRO;
		cin >> userInput;

		if (userInput < minSize || userInput > maxSize) {
			cout << PROGRAM_ERROR << endl;
		}
	} while (userInput < minSize || userInput > maxSize);

	// Renders application window.
	RenderWindow window(VideoMode(512, 512), "Project Game Technology: Knight's Tour", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);

	ChessBoard board(window, userInput, maxSize, minSize);
	return 0;
}
