/*
 * Coordinate.h
 *
 *  Created on: Mar 7, 2020
 *      Author: Minh Tran
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

struct Coordinate {
	int x;
	int y;
	void setCoordinate(int x1, int y1) {
		x = x1;
		y = y1;
	}
};

#endif /* COORDINATE_H_ */
