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
	int x = 0, y = 0;
	std::string input;
	do {
		shownBoard.printBoard();
		std::cout << "Select a location by inputting a row then a column on the same line: ";
		
		std::cin >> input;
		for (unsigned int i = 0; i < input.length() - 1 || y == 0; i++) {
			if (isalpha(static_cast<int>(input[i]))) {
				if (x == 0) {
					x = static_cast<int>(input[i]);
				}
				else {
					y = static_cast<int>(input[i]);
				}
			}
		}

	} while (x == 0 && y == 0);
	return x;
	// TODO: Check if space has been picked before
}
