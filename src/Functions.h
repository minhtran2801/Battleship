/*
 * Functions.h
 *
 *  Created on: Mar 7, 2020
 *      Author: Minh Tran
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <vector>
#include <string>
using namespace std;

const int ASCII_1 = 49;
const int ASCII_A = 65;

vector<string> split_str(char delimeter, string str) {
	vector<string> vector_str;
	string token;
	size_t pos;

	while ((pos = str.find(delimeter)) != string::npos) {
		token = str.substr(0, pos);
		vector_str.push_back(token);
		str.erase(0, pos + 1);
	}
	vector_str.push_back(str);
	return vector_str;
}

int int_to_index(char c) {
	return c - ASCII_1;
}

int char_to_index(char c) {
	return c - ASCII_A;
}




#endif /* FUNCTIONS_H_ */
