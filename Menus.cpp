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

// TODO: Picking spaces 
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

	std::cout << "x and y:" << x << " " << y << std::endl;
	std::cout << "board size: " << bombBoard.getSize() << std::endl;
	int bombsNear = bombBoard.checkSurrounding(x, y);
	std::cout << "Current bombs near: " << bombsNear << std::endl;
	
	// If user selected a bomb, return -1
	if (bombsNear == -1) {
		shownBoard.setCell(x, y, 9);
		return -1;
	}
	else {
		shownBoard.setCell(x, y, bombsNear);
		return bombsNear;
	}
}
