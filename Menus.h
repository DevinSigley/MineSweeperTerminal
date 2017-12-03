#ifndef MENUS_H
#define MENUS_H
#include <string>
#include "GameBoard.h"

class Menus
{
public:
	int intQuery(std::string prompt, int lowerBound, int upperBound);
	char charQuery(std::string prompt);
	int pickSpace(GameBoard& shownBoard, GameBoard& bombBoard, int turn);
	int checkWin(GameBoard& shownBoard, GameBoard& bombBoard);
	Menus();
	~Menus();
};

#endif