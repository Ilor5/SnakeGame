#include "Field.h"
#include <iostream>
using namespace std;



Field::Field(int _height, int _width, int *_snakex, int *_snakey, int *_fruitx, int *_fruity) {
	height = _height;
	width = _width;
	snakex = _snakex;
	snakey = _snakey;
	fruitx = _fruitx;
	fruity = _fruity;
}


Field::~Field() {}

void Field::drawing() {
	system("cls");
	for (int i = 0; i <= (width + 1); i++) {
		cout << "#";
	}
	cout << "\n";
	for (int i = 1; i <= (height); i++) {
		for (int j = 0; j <= (width + 1); j++) {
			if (j == 0 || j == (width + 1)) {
				cout << "#";
			} else if (i == *snakey && j == *snakex) {
				cout << '0';
			} else if (i == *fruity && j == *fruitx) {
				cout << '*';
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	for (int i = 0; i <= (width + 1); i++) {
		cout << "#";
	}
}
