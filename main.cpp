#include <iostream>
#include "GameBoard.h"
#include "Menus.h"

using namespace std;

int main() {
	int difficulty, boardSize;
	bool play = true;
	char playAgain;
	Menus menus;

	while (play) {
		cout << "Welcome to Minesweeper!\n\n";
		difficulty = menus.intQuery("Choose your difficulty (1-Easy, 2-Medium, 3-Hard): ", 1, 3);
		boardSize = menus.intQuery("Choose a board size between 3 and 15: ", 3, 15);
		GameBoard bombBoard(boardSize), shownBoard(boardSize);

		bombBoard.generateBombs(difficulty * 2);
		shownBoard.initializeBoard('?');

		int turn = 0, winCondition = 0;

		while (winCondition == 0) {
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
		cout << "Would you like to play again? (y/n): ";
		playAgain = menus.charQuery("Please enter either 'y' or 'n' : ");
		if (playAgain == 'y' || playAgain == 'Y') {
			play = true;
			cout << endl;
		}
		else {
			play = false;
		}
	}
	
	return 0;
}