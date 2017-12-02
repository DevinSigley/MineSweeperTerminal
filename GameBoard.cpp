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

void GameBoard::printBoard() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << board[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

void GameBoard::initializeBoard(int default) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = default;
		}
	}
}