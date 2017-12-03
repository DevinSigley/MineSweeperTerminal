#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class GameBoard{
private:
	const int BOMB = 1;
	int size;
	int** board;
	
public:
	GameBoard(int s);
	~GameBoard();
	int getCell(int x, int y);
	int setCell(int x, int y, int value);
	void printBoard();
	void initializeBoard(int default);
	void generateBombs(int difficulty);
	int checkSurrounding(int x, int y);
};
#endif