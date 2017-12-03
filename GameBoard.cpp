#include "GameBoard.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameBoard::GameBoard(int s) : size(s) {
	board = new char*[size];
	for (int i = 0; i < size; i++) {
		board[i] = new char[size];
	}
}

GameBoard::~GameBoard()
{
	for (int j = size - 1; j >= 0; j--) {
		delete board[j];
	}
	delete board;
}

char GameBoard::getCell(int x, int y) {
	return board[x][y];
}

void GameBoard::setCell(int x, int y, char value) {
	board[x][y] = value;
}

int GameBoard::getSize() {
	return size;
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
void GameBoard::initializeBoard(char default) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = default;
		}
	}
}

void GameBoard::generateBombs(int difficulty) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (rand() % 11 <= difficulty) {
				board[i][j] = '1';
			}
			else {
				board[i][j] = '0';
			}
		}
	}
}


// Checks how many bombs are nearby; returns it as an int. Returns -1 if selected is bomb.
int GameBoard::checkSurrounding(int x, int y) {
	int bombSum = 0;

	// Return -1 if selected space is a bomb.
	if (this->getCell(x, y) == BOMB) {
		return -1;
	}

	// Checking left side
	if (x == 0) {
		if (y == 0) {
			if (board[x][y + 1] == BOMB) {
				bombSum++;
			}
			if (board[x + 1][y] == BOMB) {
				bombSum++;
			}
			if (board[x + 1][y + 1] == BOMB) {
				bombSum++;
			}
		}
		else if (y == size) {
			if (board[x][y - 1] == BOMB) {
				bombSum++;
			}
			if (board[x + 1][y] == BOMB) {
				bombSum++;
			}
			if (board[x + 1][y - 1] == BOMB) {
				bombSum++;
			}
		}
		else {
			if (board[x][y - 1] == BOMB) {
				bombSum++;
			}
			if (board[x][y + 1] == BOMB) {
				bombSum++;
			}
			if (board[x + 1][y - 1] == BOMB) {
				bombSum++;
			}
			if (board[x + 1][y] == BOMB) {
				bombSum++;
			}
			if (board[x + 1][y + 1] == BOMB) {
				bombSum++;
			}
		}
	}

	// Checking right side
	else if (x == size - 1) {
		if (y == 0) {
			if (board[x][y + 1] == BOMB) {
				bombSum++;
			}
			if (board[x - 1][y] == BOMB) {
				bombSum++;
			}
			if (board[x - 1][y + 1] == BOMB) {
				bombSum++;
			}
		}
		else if (y == size) {
			if (board[x][y - 1] == BOMB) {
				bombSum++;
			}
			if (board[x - 1][y] == BOMB) {
				bombSum++;
			}
			if (board[x - 1][y - 1] == BOMB) {
				bombSum++;
			}
		}
		else {
			if (board[x][y - 1] == BOMB) {
				bombSum++;
			}
			if (board[x][y + 1] == BOMB) {
				bombSum++;
			}
			if (board[x - 1][y - 1] == BOMB) {
				bombSum++;
			}
			if (board[x - 1][y] == BOMB) {
				bombSum++;
			}
			if (board[x - 1][y + 1] == BOMB) {
				bombSum++;
			}
		}
	}

	// Checking top
	else if (y == 0) {
		// Top corners already checked by preceding x checks, so excluded.
		if (board[x - 1][y] == BOMB) {
			bombSum++;
		}
		if (board[x + 1][y] == BOMB) {
			bombSum++;
		}
		if (board[x][y + 1] == BOMB) {
			bombSum++;
		}
		if (board[x - 1][y + 1] == BOMB) {
			bombSum++;
		}
		if (board[x + 1][y + 1] == BOMB) {
			bombSum++;
		}
	}

	// Checking bottom
	else if (y == size - 1) {
		if (board[x - 1][y] == BOMB) {
			bombSum++;
		}
		if (board[x + 1][y] == BOMB) {
			bombSum++;
		}
		if (board[x][y - 1] == BOMB) {
			bombSum++;
		}
		if (board[x - 1][y - 1] == BOMB) {
			bombSum++;
		}
		if (board[x + 1][y - 1] == BOMB) {
			bombSum++;
		}
	}
	
	// Checking space not on an edge
	else {
		if (board[x - 1][y] == BOMB) {
			bombSum++;
		}
		if (board[x + 1][y] == BOMB) {
			bombSum++;
		}
		if (board[x][y - 1] == BOMB) {
			bombSum++;
		}
		if (board[x][y + 1] == BOMB) {
			bombSum++;
		}
		if (board[x - 1][y - 1] == BOMB) {
			bombSum++;
		}
		if (board[x - 1][y + 1] == BOMB) {
			bombSum++;
		}
		if (board[x + 1][y - 1] == BOMB) {
			bombSum++;
		}
		if (board[x + 1][y + 1] == BOMB) {
			bombSum++;
		}
	}
	return bombSum;
}
