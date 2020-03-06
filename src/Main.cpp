#include <iostream>
#include <vector>
#include "Game.h"
#include "Ship.h"
#include "Functions.h"
#include "Coordinate.h"
#include "Board.h"

using namespace std;

int main() {
	string S = "1B 2C,2D 4D,3A 4B";
	string H = "1B 2C 2B 1C 2D 3A";
	int boardSize = 8;
	Game g(boardSize, S, H);
	g.run();
	return 0;
}
