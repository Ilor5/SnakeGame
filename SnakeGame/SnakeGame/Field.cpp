#include <conio.h>
#include "Field.h"
#include <iostream>
#include "windows.h"
using namespace std;



Field::Field(int _height, int _width) {
	height = _height;
	width = _width;
}


Field::~Field() {}

void Field::drawing() {
	HANDLE hStdout;
	COORD  dwCursorPosition;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	dwCursorPosition.X = 0;
	dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hStdout, dwCursorPosition);
	for (int i = 0; i <= (width + 1); i++) {
		cout << "#";
	}
	cout << "\n";
	for (int i = 1; i <= (height); i++) {
		for (int j = 0; j <= (width + 1); j++) {
			if (j == 0 || j == (width + 1)) {
				cout << "#";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	for (int i = 0; i <= (width + 1); i++) {
		cout << "#";
	}
	cout << '\n';
	cout << "Score";
}

void Field::score(int _score) {
	HANDLE hStdout;
	COORD  dwCursorPosition;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	dwCursorPosition.X = width - 5;
	dwCursorPosition.Y = height + 2;
	SetConsoleCursorPosition(hStdout, dwCursorPosition);
	cout << _score;
}

void Field::DynamicDrawing(int _snakex, int _snakey, int _tailx, int _taily, int _fruitx, int _fruity, bool *_GrowUp) {
	HANDLE hStdout;
	COORD  dwCursorPosition;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	dwCursorPosition.X = _fruitx;
	dwCursorPosition.Y = _fruity;											//сделать сначала вывод фруктов
	SetConsoleCursorPosition(hStdout, dwCursorPosition);
	cout << '*';
	if (*_GrowUp == true) {
		dwCursorPosition.X = _snakex;
		dwCursorPosition.Y = _snakey;
		SetConsoleCursorPosition(hStdout, dwCursorPosition);
		cout << '0';
		*_GrowUp = false;
	}
	else {
		dwCursorPosition.X = _tailx;
		dwCursorPosition.Y = _taily;
		SetConsoleCursorPosition(hStdout, dwCursorPosition);
		cout << ' ';

		dwCursorPosition.X = _snakex;
		dwCursorPosition.Y = _snakey;
		SetConsoleCursorPosition(hStdout, dwCursorPosition);
		cout << '0';
	}
	
	
	

}
