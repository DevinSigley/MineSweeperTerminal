#include "Menus.h"
#include <iostream>
#include <string>


Menus::Menus()
{
}


Menus::~Menus()
{
}
int Menus::intQuery(std::string prompt, int lowerBound, int upperBound) {
	int input = -1;
	do {
		std::cout << prompt << std::endl;
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	} while (input < lowerBound || input > upperBound);
	return input;
}

char Menus::charQuery(std::string prompt) {
	bool invalidInput = true;
	char input;
	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		if (input == 'y' || input == 'Y' || input == 'n' || input == 'N') {
			return input;
		}
		else {
			std::cout << prompt;
		}
	} while (invalidInput);
}


int Menus::pickSpace(GameBoard& shownBoard, GameBoard& bombBoard, int turn) {
	char input = ' ';
	int x = -1, y = -1;
	int boardSize = shownBoard.getSize();

	shownBoard.printBoard();
	std::cout << "Select a location by entering the corresponding coordinate.\n";

	// Get Column choice
	do {
		std::cout << "Column (from A to " << static_cast<char>(boardSize + 64) << "): ";
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		// checking lowercase input
		if (input >= 97 && input <= 122) {
			// check if selected letter is on board
			if (input - 31 > boardSize + 65) {
				std::cout << "The coordinate chosen is too high.\n";
			}
			else {
				y = input - 97;
			}
		}
		// checking uppercase input
		else if (input >= 65 && input <= 90) {
			// check if selected letter is on board
			if (input > boardSize + 65) {
				std::cout << "The coordinate chosen is too high.\n";
			}
			else {
				y = input - 65;
			}
		}
		else {
			std::cout << "Please enter an alphanumeric character.\n";
		}
	} while (y == -1);

	// Get Row choice
	do {
		std::cout << "Row (from A to " << static_cast<char>(boardSize + 64) << "): ";
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		// checking lowercase input
		if (input >= 97 && input <= 122){
			// check if selected letter is on board
			if (input - 31 > boardSize + 65) {
				std::cout << "The coordinate chosen is too high.\n";
			}
			else {
				x = input - 97;
			}
		}
		// checking uppercase input
		else if (input >= 65 && input <= 90) {
			// check if selected letter is on board
			if (input > boardSize + 65) {
				std::cout << "The coordinate chosen is too high.\n";
			}
			else {
				x = input - 65;
			}
		}
		else {
			std::cout << "Please enter an alphanumeric character.\n";
		}

	} while (x == -1);

	int bombsNear = bombBoard.checkSurrounding(x, y);
	
	// If user selected a bomb
	if (bombsNear == -1) {
		// If it's the first turn, make that space not a bomb, recalculate bombsNear.
		if (turn == 0) {
			bombBoard.setCell(x, y, '0');
			bombsNear = bombBoard.checkSurrounding(x, y);
			shownBoard.setCell(x, y, static_cast<char>(bombsNear + 48));
			return bombsNear;
		}
		// If bomb selected after the first turn, return -1
		else {
			shownBoard.setCell(x, y, 'X');
			return -1;
		}
	}
	// User selected a non-bomb space
	else {
		shownBoard.setCell(x, y, static_cast<char>(bombsNear + 48));
		return bombsNear;
	}
}

int Menus::checkWin(GameBoard& shownBoard, GameBoard& bombBoard) {
	int boardSize = shownBoard.getSize();
	int emptySpaces = 0, correctSpaces = 0;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (bombBoard.getCell(i, j) == '0') {
				emptySpaces++;
				if (shownBoard.getCell(i, j) != '?') {
					correctSpaces++;
				}
			}
		}
	}
	if (correctSpaces == emptySpaces) {
		return 1;
	}
	else {
		return 0;
	}
}
