#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard(int s) : size(s) {
	board = new int*[size];
	for (int i = 0; i < size; i++) {
		board[i] = new int[size];
	}
}

GameBoard::~GameBoard()
{
	for (int j = size - 1; j >= 0; j--) {
		delete board[j];
	}
	delete board;
}

int GameBoard::getCell(int x, int y) {
	return board[x][y];
}

int GameBoard::setCell(int x, int y, int value) {
	std::cout << "board at " << x << y << "is " << board[x][y] << std::endl;
	board[x][y] = value;
	std::cout << "now board is " << board[x][y] << std::endl;
	return 1;
}

// Print board with alphabetic legend
void GameBoard::printBoard() {
	std::cout << "   ";
	for (int letter = 0; letter < size; letter++) {
		std::cout << static_cast<char>(letter + 65) << "  ";
	}
	std::cout << std::endl;

	for (int i = 0; i < size; i++) {
		std::cout << static_cast<char>(i + 65) << "  ";
		for (int j = 0; j < size; j++) {
			std::cout << board[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

// Set all board positions to argument
void GameBoard::initializeBoard(int default) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = default;
		}
	}
}

// Checks how many bombs are nearby; returns it as an int.
int GameBoard::checkSurrounding(int x, int y) {
	int bombSum = 0;

	// Checking topleft and bottomleft corners
	if (x == 0) {
		if (y == 0) {
			if (board[x][y+1] == BOMB) {
				bombSum++;
			}
			if (board[x+1][y] == BOMB) {
				bombSum++;
			}
			if (board[x+1][y+1] == BOMB) {
				bombSum++;
			}
		}
		else if (y == size) {

		}
	}
	return bombSum;
}