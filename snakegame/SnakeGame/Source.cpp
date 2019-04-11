
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
int tailX[100], tailY[100];
int nTail = 0;
int deleteX, deleteY;
bool startGame = false;



Snake *snake;
Field *field;



void setup() {
	snake = new Snake(&game_over, width, height);
	field = new Field(height, width);
	srand((unsigned)time(NULL));
	game_over = false;
	snakex = width / 2;
	snakey = height / 2;
	tailx = snakex;
	taily = snakey;
	//fruitx = rand() % width + 1;
	//fruity = rand() % height + 1;
	fruitx = 13;
	fruity = 10;
	field->drawing(snakex, snakey, fruitx, fruity);
}



int main()
{	
	setup();
	while (!game_over) {
		
		snake->direction(&snakex, &snakey, &startGame);
		snake->border_control(&snakex, &snakey);
		snake->eating(&fruitx, &fruity, &snakex, &snakey, &score_num, &speed, &nTail);
		snake->tail(tailX, tailY, nTail, snakex, snakey, &deleteX, &deleteY);
		
		field->DynamicDrawing(snakex, snakey, fruitx, fruity, tailX, tailY, nTail, deleteX, deleteY, startGame);
		field->score(score_num);
		Sleep(speed);
	}
	delete snake;
	delete field;
	return 0;
}

