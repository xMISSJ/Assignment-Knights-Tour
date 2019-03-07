#include <SFML\Graphics.hpp>;
#include "ChessBoard.h";
#include <windows.h>

/*
 *	This is the main.cpp file for Knight's Tour. 	
 *	Developed for the Knight's Tour school assignment. 
 *	This .cpp file fetches and stores user input data. It also prints text for the user in the console.
 */

using namespace sf;

/*
 * 1. Blue         6. Yellow (Dark)        11. Bright Cyan
 * 2. Green        7. Default White        12. Bright Red
 * 3. Cyan         8. Grey                 13. Magenta
 * 4. Red          9. Bright Blue          14. Yellow
 * 5. Purple       10. Bright Green        15. Bright White
 * Numbers after '15' are background colours/
 */
void SetColor(int value) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

int main()
{
	int                           sizeInput;
	int                           minPosition = 1;
	int										  			startPosX;
	int														startPosY;
	bool                          intro = false;
	static const string           PROGRAM_NAME = "Knight's Tour";
	static const string           PROGRAM_INTRO = "Welcome to ";
	static const string           PROGRAM_INTRO2 = "\nPlease insert a number in the range of 5 to 7. \n";
	static const string           PROGRAM_ERROR = "\nInvalid number. Please pick a number from 5 to 7.";
	static const string           PROGRAM_INPUTX = "\nPlease enter the Knight's x start position min: 1 max: ";
	static const string           PROGRAM_INPUTY = "\nNext. Enter the Knight's y start position min: 1 max: ";
	static const string           PROGRAM_ERRORX = "\nInvalid input. Please pick an x-axis from 1 to ";
	static const string           PROGRAM_ERRORY = "\nInvalid input. Please pick an y-axis from 1 to ";

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

		if (sizeInput < ChessBoard::MIN_SIZE || sizeInput > ChessBoard::MAX_SIZE) {
			cout << PROGRAM_ERROR << endl;
		}
	} while (sizeInput < ChessBoard::MIN_SIZE || sizeInput > ChessBoard::MAX_SIZE);

	// Program shows error, so long there is no valid position (minPosition-sizeInput).
	do {
		cout << PROGRAM_INPUTX << sizeInput << ".\n";
		cin >> startPosX;

		if (startPosX < minPosition || startPosX > sizeInput) {
			cout << PROGRAM_ERRORX << sizeInput << "." << endl;
		}
	} while (startPosX < minPosition || startPosX > sizeInput);

	// Program shows error, so long there is no valid position (minPosition-sizeInput).
	do {
		cout << PROGRAM_INPUTY << sizeInput << ".\n";
		cin >> startPosY;

		if (startPosY < minPosition || startPosY > sizeInput) {
			cout << PROGRAM_ERRORY << sizeInput << "." << endl;
		}
	} while (startPosY < minPosition || startPosY > sizeInput);

	// Renders application window.
	RenderWindow window(VideoMode(512, 512), "Project Game Technology: Knight's Tour", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);

	ChessBoard board(window, sizeInput, startPosX, startPosY);
	return 0;
}