#include "Menus.h"
#include <iostream>


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