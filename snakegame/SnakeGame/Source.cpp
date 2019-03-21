
#include <iostream>
#include <conio.h>
#include "windows.h"
#include <time.h>
#include "Movement.h"
using namespace std;


bool game_over;
int snakex, snakey, fruitx, fruity;
const int width = 20;
const int height = 20;
char dir;
int speed = 75;


Movement *movement;

void setup() {
	srand((unsigned)time(NULL));
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
	movement->direction(dir, &snakex, &snakey);
	movement->border_control(&snakex, &snakey);
}


int main()
{
	movement = new Movement(&game_over, width, height);

	setup();
	while (!game_over) {
		field();
		input();
		logic();
		Sleep(speed);
	}
	delete movement;
	return 0;
}

