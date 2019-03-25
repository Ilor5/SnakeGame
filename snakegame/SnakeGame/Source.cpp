
#include <iostream>
#include <conio.h>
#include "windows.h"
#include <time.h>
#include "Snake.h"
#include "Field.h"
using namespace std;


bool game_over;
int snakex, snakey, tailx, taily, fruitx, fruity;
const int width = 20;
const int height = 20;
char dir;
int speed = 150;
int score_num = 0;
bool GrowUp = true;



Snake *snake;
Field *field;



void setup() {
	snake = new Snake(&game_over, width, height, &score_num, &speed);
	field = new Field(height, width);
	srand((unsigned)time(NULL));
	game_over = false;
	snakex = width / 2;
	snakey = height / 2;
	tailx = snakex;
	taily = snakey;
	fruitx = rand() % width + 1;
	fruity = rand() % height + 1;
	field->drawing();
}



int main()
{	
	setup();
	while (!game_over) {
		snake->eating(&fruitx, &fruity, &snakex, &snakey, &score_num, &speed, &GrowUp);
		snake->direction(&snakex, &snakey, &tailx, &taily, GrowUp);
		field->DynamicDrawing(snakex, snakey, tailx, taily, fruitx, fruity, &GrowUp);
		snake->border_control(&snakex, &snakey);
		
		field->score(score_num);
		Sleep(speed);
	}
	delete snake;
	delete field;
	return 0;
}

