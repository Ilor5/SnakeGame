
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
int score_num = 0;



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


//void input() {
//	if (_kbhit()) {
//		dir = _getch();
//	}
//}


void logic() {
	snake->direction(&snakex, &snakey);
	snake->border_control(&snakex, &snakey);
	snake->eating(&fruitx, &fruity, &snakex, &snakey, &score_num, &speed);
}

int main()
{	snake = new Snake(&game_over, width, height, &score_num, &speed);
	field = new Field(height, width, &snakex, &snakey, &fruitx, &fruity, &score_num);
	setup();
	while (!game_over) {
		field->drawing();
		field->score();
		//input();
		logic();
		Sleep(speed);
	}
	delete snake;
	delete field;
	return 0;
}

