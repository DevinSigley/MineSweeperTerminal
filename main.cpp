#include <iostream>
#include "GameBoard.h"
#include "Menus.h"

using namespace std;

int main() {
	int difficulty, boardSize;
	Menus menus;
	difficulty = menus.intQuery("Choose your difficulty (1-Easy, 2-Medium, 3-Hard): ", 1, 3);
	boardSize = menus.intQuery("Choose a board size between 4 and 10: ", 4, 10);
	GameBoard bombBoard(boardSize), shownBoard(boardSize);

	bombBoard.generateBombs(difficulty * 2);
	bombBoard.printBoard();

	shownBoard.initializeBoard(0);
	for (int i = 0; i < 5; i++) {
		menus.pickSpace(shownBoard, bombBoard);
	}
	shownBoard.printBoard();

	cin >> boardSize;
	return 0;
}