/*
 * Board.h
 *
 *  Created on: Mar 7, 2020
 *      Author: Minh Tran
 */

#ifndef BOARD_H_
#define BOARD_H_

#include<iostream>
#include "Ship.h"
#include "Coordinate.h"
#include "Functions.h"

using namespace std;

const int WATER = 0;
const int SHIP = 1;
const int HIT = 2;

class Board {
private:
	int boardSize;
	int **board;
public:
	Board();
	void setBoard(int bSize);
	void printBoard();
	void markShip(Ship ship);
	void markHits(vector<Coordinate> hit_vect);
	int getVal(int x, int y);
	~Board();
};

Board::Board()  {
	boardSize = 0;

	// Initiate 2D array
	board = new int *[boardSize];
	for (int i = 0; i < boardSize; i++) {
		board[i] = new int[boardSize];
	}
}

void Board::setBoard(int bSize) {
	boardSize = bSize;

	// Initiate 2D array
	board = new int *[boardSize];
	for (int i = 0; i < boardSize; i++) {
		board[i] = new int[boardSize];
	}
	// Fill array with 0
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			board[i][j] = WATER;
		}

	}
}

void Board::printBoard() {
	cout << "\n----------------------------------\n";
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void Board::markShip(Ship ship) {
	vector<Coordinate> coordinate_vect;
	int x, y;
	coordinate_vect = ship.getCoordinatesVector();
	for (Coordinate coordinate : coordinate_vect) {
		x = int_to_index(coordinate.x);
		y = char_to_index(coordinate.y);
		board[x][y] = SHIP;
	}
}

void Board::markHits(vector<Coordinate> hit_vect) {
	int x, y;
	Coordinate co;
	for (unsigned int i = 0; i < hit_vect.size(); i++) {
		co = hit_vect[i];
		x = int_to_index(co.x);
		y = char_to_index(co.y);
		board[x][y] = HIT;
	}
}

int Board::getVal(int x, int y) {
	return board[x][y];
}

Board::~Board() {
	for (int i = 0; i < boardSize; i++) {
		delete[] board[i];
	}
	delete[] board;
}

#endif /* BOARD_H_ */
