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

void Field::drawing(int  _snakex, int _snakey, int _fruitx, int _fruity) {
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

	dwCursorPosition.X = _fruitx;
	dwCursorPosition.Y = _fruity;
	SetConsoleCursorPosition(hStdout, dwCursorPosition);
	cout << '*';


	dwCursorPosition.X = _snakex;
	dwCursorPosition.Y = _snakey;
	SetConsoleCursorPosition(hStdout, dwCursorPosition);
	cout << '0';

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

 void Field::DynamicDrawing(int  _snakex, int _snakey, int _fruitx, int _fruity, int tailX[], int tailY[], int nTail, int  deleteX, int deleteY, bool _startGame) {
	 if(_startGame) {
		 HANDLE hStdout;
		 COORD  dwCursorPosition;
		 hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

		 dwCursorPosition.X = _fruitx;
		 dwCursorPosition.Y = _fruity;
		 SetConsoleCursorPosition(hStdout, dwCursorPosition);
		 cout << '*';


		 dwCursorPosition.X = _snakex;
		 dwCursorPosition.Y = _snakey;
		 SetConsoleCursorPosition(hStdout, dwCursorPosition);
		 cout << '0';

		 for(int k = 1; k <= nTail; k++) {
			 dwCursorPosition.X = tailX[k];
			 dwCursorPosition.Y = tailY[k];										//надо подтирать хвост за собой
			 SetConsoleCursorPosition(hStdout, dwCursorPosition);
			 cout << "o";

		 }
		 if(deleteX != 0 && deleteY != 0) {
			 dwCursorPosition.X = deleteX;
			 dwCursorPosition.Y = deleteY;
			 SetConsoleCursorPosition(hStdout, dwCursorPosition);
			 cout << ' ';
		 }
		 
		 }
	 }
	

 
	

