/*
 * Ship.h
 *
 *  Created on: Mar 7, 2020
 *      Author: Minh Tran
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "Coordinate.h"
#include <vector>
#include <iostream>
using namespace std;

class Ship {
private:
	vector<Coordinate> coordinate_vector;
	Coordinate coordinate1;
	Coordinate coordinate2;
	int node_num;
public:
	Ship();
	void setCoordinate(Coordinate c1, Coordinate c2);
	Coordinate getCo1();
	Coordinate getCo2();
	vector<Coordinate> getCoordinatesVector();
	int getNodeNum();
};

Ship::Ship() {
	node_num = 0;
}

void Ship::setCoordinate(Coordinate c1, Coordinate c2) {
	coordinate1 = c1;
	coordinate2 = c2;
	Coordinate temp_coordinate;
	for (int i = coordinate1.x; i <= coordinate2.x; i++) {
		for (int j = coordinate1.y; j <= coordinate2.y; j++) {
			temp_coordinate.setCoordinate(i, j);
			coordinate_vector.push_back(temp_coordinate);
			node_num++;
		}
	}
}

Coordinate Ship::getCo1() {
	return coordinate1;
}
Coordinate Ship::getCo2() {
	return coordinate2;
}
vector<Coordinate> Ship::getCoordinatesVector() {
	return coordinate_vector;
}
int Ship::getNodeNum() {
	return node_num;
}

#endif /* SHIP_H_ */
