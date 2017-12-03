#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class GameBoard{
private:
	const char BOMB = '1';
	int size;
	char** board;
	
public:
	GameBoard(int s);
	~GameBoard();
	char getCell(int x, int y);
	void setCell(int x, int y, char value);
	int getSize();
	void printBoard();
	void initializeBoard(char default);
	void generateBombs(int difficulty);
	int checkSurrounding(int x, int y);
};
#endif