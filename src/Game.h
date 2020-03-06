/*
 * Game.h
 *
 *  Created on: Mar 7, 2020
 *      Author: Minh Tran
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include "Coordinate.h"
#include "Board.h"
#include "Ship.h"
#include "Functions.h"

using namespace std;

const char SPACE_DELIMETER = ' ';
const char COMMA_DELIMETER = ',';

class Game {
private:
	Board board;
	Ship ship;
	vector<Ship> ships;
	vector<Coordinate> hits;
	int hitCount, sunkCount;
public:
	Game(int boardSize, string shipStr, string hitStr);
	void markShipsOnBoard();
	void markHitsOnBoard();
	void checkHit();
	void printResult();
	void printBoard();
	void run();
};

Game::Game(int boardSize, string shipStr, string hitStr) {
	vector<string> vector_ship_str, vector_hit_str;
	Coordinate c1, c2;
	string str1, str2;

	// Initiate hit and sunk count;
	hitCount = 0;
	sunkCount = 0;

	// Initiate board
	board.setBoard(boardSize);

	// Replace commas by spaces in shipStr
	replace(shipStr.begin(), shipStr.end(), COMMA_DELIMETER, SPACE_DELIMETER);
	// Initiate vector_str with ships coordinates
	vector_ship_str = split_str(SPACE_DELIMETER, shipStr);
	for (unsigned int i = 0; i < vector_ship_str.size(); i = i + 2) {
		str1 = vector_ship_str[i];
		str2 = vector_ship_str[i + 1];

		c1.setCoordinate(str1[0], str1[1]);
		c2.setCoordinate(str2[0], str2[1]);

		ship.setCoordinate(c1, c2);
		ships.push_back(ship);
	}

	// Initiate hits string and vector
	vector_hit_str = split_str(SPACE_DELIMETER, hitStr);
	for (unsigned int i = 0; i < vector_hit_str.size(); i++) {
		str1 = vector_hit_str[i];
		c1.setCoordinate(str1[0], str1[1]);
		hits.push_back(c1);
	}
}

void Game::markShipsOnBoard() {
	for (unsigned int i = 0; i < ships.size(); i++) {
		board.markShip(ships[i]);
	}
}

void Game::markHitsOnBoard() {
	board.markHits(hits);
}

void Game::checkHit() {
	int sum = 0;
	int x, y, nodeNum;
	vector<Coordinate> co_vect;
	for (Ship ship : ships) {
		co_vect = ship.getCoordinatesVector();
		for (Coordinate co : co_vect) {
			x = int_to_index(co.x);
			y = char_to_index(co.y);
			sum += board.getVal(x, y);
		}
		nodeNum = ship.getNodeNum();
		if (sum == nodeNum * 2) {
			sunkCount++;
		} else if (sum > nodeNum) {
			hitCount++;
		}
	}
}

void Game::printResult() {
	cout << "\n--------------------------------------\n";
	cout << "Number of hit ships: " << hitCount << endl;
	cout << "number of sunken ships: " << sunkCount << endl;
}

void Game::printBoard() {
	board.printBoard();
}

void Game::run() {
	markShipsOnBoard();
	printBoard();
	markHitsOnBoard();
	printBoard();
	checkHit();
	printResult();
}

#endif /* GAME_H_ */
