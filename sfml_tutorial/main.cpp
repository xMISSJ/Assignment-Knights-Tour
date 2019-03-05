#include <SFML\Graphics.hpp>;
#include "ChessBoard.h";

using namespace sf;

/*
1. Blue			6. Yellow (Dark)		11. Bright Cyan
2. Green		7. Default White		12. Bright Red
3. Cyan			8. Grey							13. Magenta
4. Red			9. Bright Blue			14. Yellow
5. Purple		10. Bright Green		15. Bright White

Numbers after '15' are background colours/
*/
void SetColor(int value) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

int main()
{
	int												sizeInput;
	int												inputX;
	int												inputY;
	int												minPosition = 1;
	int												maxSize = 8;
	int												minSize = 5;
	bool											intro = false;
	static const string				PROGRAM_NAME = "Knight's Tour";
	static const string				PROGRAM_INTRO = "Welcome to ";
	static const string				PROGRAM_INTRO2 = "\nPlease insert a number in the range of 5 to 8. \n";
	static const string				PROGRAM_ERROR = "\nInvalid number. Please pick a number from 5 to 8.";
	static const string				PROGRAM_INPUTX = "\nPlease enter the Knight's x start position min: 1 max: ";
	static const string				PROGRAM_INPUTY = "\nNext. Enter the Knight's y start position min: 1 max: ";
	static const string				PROGRAM_ERRORX = "\nInvalid input. Please pick an x-axis from 1 to ";
	static const string				PROGRAM_ERRORY = "\nInvalid input. Please pick an y-axis from 1 to ";

	// Program shows error, so long there is no valid number (minSize-maxSize).
	do {
		if (!intro) {
			cout << PROGRAM_INTRO;
			SetColor(12);
			cout << PROGRAM_NAME;
			SetColor(7);
			cout << "!" << PROGRAM_INTRO2;
			intro = true;
		}
		cin >> sizeInput;

		if (sizeInput < minSize || sizeInput > maxSize) {
			cout << PROGRAM_ERROR << endl;
		}
	} while (sizeInput < minSize || sizeInput > maxSize);

	// Program shows error, so long there is no valid position (minPosition-sizeInput).
	do {
		cout << PROGRAM_INPUTX << sizeInput << ".\n";
		cin >> inputX;

		if (inputX < minPosition || inputX > sizeInput) {
			cout << PROGRAM_ERRORX << sizeInput << "." << endl;
		}
	} while (inputX < minPosition || inputX > sizeInput);

	// Program shows error, so long there is no valid position (minPosition-sizeInput).
	do {
		cout << PROGRAM_INPUTY << sizeInput << ".\n";
		cin >> inputY;

		if (inputY < minPosition || inputY > sizeInput) {
			cout << PROGRAM_ERRORY << sizeInput << "." << endl;
		}
	} while (inputY < minPosition || inputY > sizeInput);

	// Renders application window.
	RenderWindow window(VideoMode(512, 512), "Project Game Technology: Knight's Tour", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);

	ChessBoard board(window, sizeInput, maxSize, minSize);
	return 0;
}
