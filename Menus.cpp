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
	} while (input < lowerBound || input > upperBound);
	return input;
}

int Menus::pickSpace(GameBoard& shownBoard, GameBoard& bombBoard) {
	char input = ' ';
	int x = -1, y = -1;
	int boardSize = shownBoard.getSize();

	shownBoard.printBoard();
	std::cout << "Select a location by entering the corresponding coordinate.\n";

	// Get Row choice
	do {
		std::cout << "Column (from A to " << static_cast<char>(boardSize + 65) << "): ";
		std::cin >> input;

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

	// Get Column choice
	do {
		std::cout << "Row (from A to " << static_cast<char>(boardSize + 65) << "): ";
		std::cin >> input;

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
	
	// If user selected a bomb, return -1
	if (bombsNear == -1) {
		shownBoard.setCell(x, y, 'X');
		return -1;
	}
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
