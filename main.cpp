#include <iostream>
#include "GameBoard.h"

using namespace std;

int main() {
	cout << "Board size (square): ";
	int foo;
	cin >> foo;
	GameBoard bar(foo);
	bar.initializeBoard(0);
	bar.setCell(0, 0, 2);
	bar.printBoard();
	cin >> foo;
	return 0;
}