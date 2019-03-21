
#include <iostream>
#include <conio.h>
#include "windows.h"
using namespace std;


bool game_over;
int snakex, snakey, fruitx, fruity;
const int width = 20;
const int height = 20;
char dir;
int speed = 75;



/*class movement {
public:*/
	void direction(char kb_char, int *x, int *y) {
		if (kb_char == 'w' || kb_char == 'W' || kb_char == 'Ö' || kb_char == 'ö') {
			*y -= 1;
		}
		else if (kb_char == 's' || kb_char == 'S' || kb_char == 'Û' || kb_char == 'û') {
			*y += 1;
		}
		else if (kb_char == 'a' || kb_char == 'A' || kb_char == 'Ô' || kb_char == 'ô') {
			*x -= 1;
		}
		else if (kb_char == 'd' || kb_char == 'D' || kb_char == 'Â' || kb_char == 'â') {
			*x += 1;
		}
		else if (kb_char == 'x' || kb_char == 'X' || kb_char == '×' || kb_char == '×') {
			game_over = true;
		}

	};

	void border_control(int *x, int *y) {
		switch (*x){
		case (width+1): {
			*x = 1;
			break;
		}
		case 0: {
			*x = width;
			break;
		}
		}
		switch (*y){
		case (height+1): {
			*y = 1;
			break;
		}
		case 0: {
			*y = height;
			break;
		}
		}
	}
//};

void setup() {
	game_over = false;
	snakex = width / 2;
	snakey = height / 2;
	fruitx = rand() % width;
	fruity = rand() % height;
}


void field() {
	system("cls");
	for (int i = 0; i <= (width + 1); i++) {
		cout << "#";
	}
	cout << "\n";
	for (int i = 1; i <= (height); i++) {
		for (int j = 0; j <= (width + 1); j++) {
			if (j == 0 || j == (width + 1)) {
				cout << "#";
			}
			else if (i == snakey && j == snakex) {
				cout << '0';
			}
			else if (i == fruity && j == fruitx) {
				cout << '*';
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	for (int i = 0; i <= (width + 1); i++) {
		cout << "#";
	}
}


void input() {
	if (_kbhit()) {
		dir = _getch();
	}
}


void logic() {
	direction(dir, &snakex, &snakey);
	border_control(&snakex, &snakey);
}


int main()
{
	setup();
	while (!game_over) {
		field();
		input();
		logic();
		Sleep(speed);
	}
	return 0;
}

