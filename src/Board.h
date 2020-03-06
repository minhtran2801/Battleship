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
using namespace std;

const int WATER = 0;
const int SHIP = 1;
const int HIT = 2;

class Board {
private:
	int boardSize;
	int **board;
public:
	Board() {
		boardSize = 0;

		// Initiate 2D array
		board = new int *[boardSize];
		for (int i = 0; i < boardSize; i++) {
			board[i] = new int[boardSize];
		}
	}
	~Board() {
		for (int i = 0; i < boardSize; i++) {
			delete[] board[i];
		}
		delete[] board;
	}
	void setBoard(int bSize) {
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
	void printBoard() {
		cout << "\n----------------------------------\n";
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
	void markShip(Ship ship) {
		vector<Coordinate> coordinate_vect;
		int x, y;
		coordinate_vect = ship.getCoordinatesVector();
		for (Coordinate coordinate : coordinate_vect) {
			x = int_to_index(coordinate.x);
			y = char_to_index(coordinate.y);
			board[x][y] = SHIP;
		}
	}
	void markHits(vector<Coordinate> hit_vect) {
		int x, y;
		for (unsigned int i = 0; i < hit_vect.size(); i++) {
			x = int_to_index(hit_vect[i].x);
			y = char_to_index(hit_vect[i].y);
			board[x][y] = HIT;
		}
	}
	int getVal(int x, int y) {
		return board[x][y];
	}
};



#endif /* BOARD_H_ */
