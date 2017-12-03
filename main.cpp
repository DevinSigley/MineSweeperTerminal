#include <iostream>
#include "GameBoard.h"
#include "Menus.h"

using namespace std;

int main() {
	int difficulty, boardSize, turn = 0, winCondition = 0;
	Menus menus;
	cout << "Welcome to Minesweeper!\n\n";
	difficulty = menus.intQuery("Choose your difficulty (1-Easy, 2-Medium, 3-Hard): ", 1, 3);
	boardSize = menus.intQuery("Choose a board size between 4 and 10: ", 4, 10);
	GameBoard bombBoard(boardSize), shownBoard(boardSize);

	bombBoard.generateBombs(difficulty * 2);
	bombBoard.printBoard();
	shownBoard.initializeBoard('?');
	
	while (winCondition == 0){
		// Have user pick space, if it's a bomb then change winCondition
		if (menus.pickSpace(shownBoard, bombBoard, turn) == -1) {
			winCondition = -1;
		}
		// If it wasn't a bomb, check to see if all non-bombs were cleared.
		else {
			winCondition = menus.checkWin(shownBoard, bombBoard);
		}
		turn++;
	}
	shownBoard.printBoard();
	if (winCondition == 1) {
		cout << "Congratulations! You have won in " << turn << " turns!\n";
	}
	else {
		cout << "Aww. You blew up a bomb and lost.\n";
	}

	cin >> boardSize;
	return 0;
}