
#include <iostream>
#include <conio.h>
#include "windows.h"
#include <time.h>
#include "Snake.h"
#include "Field.h"
using namespace std;


bool game_over;
int snakex, snakey, fruitx, fruity;
const int width = 20;
const int height = 20;
char dir;
int speed = 100;


Snake *snake;
Field *field;

void setup() {
	srand((unsigned)time(NULL));
	game_over = false;
	snakex = width / 2;
	snakey = height / 2;
	fruitx = rand() % (width + 1) + 1;
	fruity = rand() % (height + 1) + 1;
}


/*void field() {
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
}*/


void input() {
	if (_kbhit()) {
		dir = _getch();
	}
}


void logic() {
	snake->direction(dir, &snakex, &snakey);
	snake->border_control(&snakex, &snakey);
	snake->eating(&fruitx, &fruity, &snakex, &snakey);
}

int main()
{
	snake = new Snake(&game_over, width, height);
	field = new Field(height, width, &snakex, &snakey, &fruitx, &fruity);
	setup();
	while (!game_over) {
		field->drawing();
		//field();
		input();
		logic();
		Sleep(speed);
	}
	delete snake;
	delete field;
	return 0;
}

