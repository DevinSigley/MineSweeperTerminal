#include <iostream>
#include "GameBoard.h"
#include "Menus.h"

using namespace std;

const int DIFF_EASY = 2;
const int DIFF_MEDIUM = 4;
const int DIFF_HARD = 6;

int main() {
	int difficulty, boardSize;
	Menus menus;
	difficulty = menus.intQuery("Choose your difficulty (1-Easy, 2-Medium, 3-Hard): ", 1, 3);
	boardSize = menus.intQuery("Choose a board size between 4 and 10: ", 4, 10);
	GameBoard bombBoard(boardSize), shownBoard(boardSize);

	shownBoard.initializeBoard(0);
	shownBoard.printBoard();

	cin >> boardSize;
	return 0;
}