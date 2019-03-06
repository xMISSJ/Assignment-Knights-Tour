#include <SFML\Graphics.hpp>;
#include "ChessBoard.h";

using namespace sf;

/*
1. Blue         6. Yellow (Dark)        11. Bright Cyan
2. Green        7. Default White        12. Bright Red
3. Cyan         8. Grey                 13. Magenta
4. Red          9. Bright Blue          14. Yellow
5. Purple       10. Bright Green        15. Bright White

Numbers after '15' are background colours/
*/
void SetColor(int value) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

int main()
{
	int                           sizeInput;
	Vector2f                      positionInput;
	int                           minPosition = 1;
	float										  		rePosX;
	float												  rePosY;
	bool                          intro = false;
	static const string           PROGRAM_NAME = "Knight's Tour";
	static const string           PROGRAM_INTRO = "Welcome to ";
	static const string           PROGRAM_INTRO2 = "\nPlease insert a number in the range of 5 to 8. \n";
	static const string           PROGRAM_ERROR = "\nInvalid number. Please pick a number from 5 to 8.";
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
		cin >> positionInput.x;

		if (positionInput.x < minPosition || positionInput.x > sizeInput) {
			cout << PROGRAM_ERRORX << sizeInput << "." << endl;
		}
	} while (positionInput.x < minPosition || positionInput.x > sizeInput);

	// Program shows error, so long there is no valid position (minPosition-sizeInput).
	do {
		cout << PROGRAM_INPUTY << sizeInput << ".\n";
		cin >> positionInput.y;

		if (positionInput.y < minPosition || positionInput.y > sizeInput) {
			cout << PROGRAM_ERRORY << sizeInput << "." << endl;
		}
	} while (positionInput.y < minPosition || positionInput.y > sizeInput);

	// Renders application window.
	RenderWindow window(VideoMode(512, 512), "Project Game Technology: Knight's Tour", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);

	switch (sizeInput) {
	case 5:
		// 5 x 5
		rePosX = (positionInput.x * 102) - 102;
		rePosY = (positionInput.y * 102) - 102;
		break;
	case 6:
		// 6 x 6 
		rePosX = (positionInput.x * 85) - 85;
	  rePosY = (positionInput.y * 85) - 85;
		break;
	case 7:
		// 7 x 7
		rePosX = (positionInput.x * 73) - 73;
		rePosY = (positionInput.y * 73) - 73;
		break;
	case 8:
		// 8 x 8
		rePosX = (positionInput.x * 64) - 64;
		rePosY = (positionInput.y * 64) - 64;
		break;
}


	Vector2f rePosition = { rePosX, rePosY };

	ChessBoard board(window, sizeInput, ChessBoard::MAX_SIZE, ChessBoard::MIN_SIZE, rePosition);
	return 0;
}