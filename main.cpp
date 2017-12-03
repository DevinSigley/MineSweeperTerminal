#include <iostream>
#include "GameBoard.h"
#include "Menus.h"

using namespace std;

int main() {
	int difficulty, boardSize, turn = 1, winCondition = 0;
	Menus menus;
	difficulty = menus.intQuery("Choose your difficulty (1-Easy, 2-Medium, 3-Hard): ", 1, 3);
	boardSize = menus.intQuery("Choose a board size between 4 and 10: ", 4, 10);
	GameBoard bombBoard(boardSize), shownBoard(boardSize);

	bombBoard.generateBombs(difficulty * 2);
	bombBoard.printBoard();

	shownBoard.initializeBoard('?');
	while (winCondition == 0){
		// Have user pick space, if it's a bomb then change winCondition
		if (menus.pickSpace(shownBoard, bombBoard) == -1) {
			winCondition = -1;
		}
		else {
			winCondition = menus.checkWin(shownBoard, bombBoard);
		}
	}
	shownBoard.printBoard();
	cout << "The win condition is: " << winCondition;

	cin >> boardSize;
	return 0;
}