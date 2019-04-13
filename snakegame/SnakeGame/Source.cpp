
#include <iostream>
#include <conio.h>
#include "windows.h"
#include <time.h>
#include "Snake.h"
#include "Field.h"
using namespace std;


bool gameOver;
int snakex, snakey, fruitx, fruity;
const int width = 20;
const int height = 20;
char dir;
int speed = 150;
int score_num = 0;
int tailX[100], tailY[100];
int nTail = 0;
int deleteX, deleteY;
bool startGame = false;

HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
COORD bufferSize;

Snake *snake;
Field *field;



void setup() {
	snake = new Snake(&gameOver, width, height);
	field = new Field(height, width);
	srand((unsigned)time(NULL));
	gameOver = false;
	snakex = width / 2;
	snakey = height / 2;
	fruitx = rand() % width + 1;
	fruity = rand() % height + 1;

	bufferSize = { 90, 30 };
	SetConsoleScreenBufferSize(hWnd, bufferSize);
	field->drawing(snakex, snakey, fruitx, fruity);
	//gameOver = true;
}



int main()
{	
	setup();
	while (!gameOver) {
		
		snake->direction(&snakex, &snakey, &startGame, tailX, tailY, nTail);
		snake->border_control(&snakex, &snakey);
		snake->eating(&fruitx, &fruity, &snakex, &snakey, &score_num, &speed, &nTail);
		snake->tail(tailX, tailY, nTail, snakex, snakey, &deleteX, &deleteY);
		
		field->DynamicDrawing(snakex, snakey, fruitx, fruity, tailX, tailY, nTail, deleteX, deleteY, startGame);
		field->score(score_num);
		Sleep(speed);
	}
	delete snake;
	delete field;
	bufferSize = { 90, 30 };
	SetConsoleScreenBufferSize(hWnd, bufferSize);
	system("cls");
	cout << "  ######      ###    ##     ## ########     #######  ##     ## ######## ########     ####" << endl;
	cout << " ##    ##    ## ##   ###   ### ##          ##     ## ##     ## ##       ##     ##    ####" << endl;
	cout << " ##         ##   ##  #### #### ##          ##     ## ##     ## ##       ##     ##    ####" << endl;
	cout << " ##   #### ##     ## ## ### ## ######      ##     ## ##     ## ######   ########      ## " << endl;
	cout << " ##    ##  ######### ##     ## ##          ##     ##  ##   ##  ##       ##   ##         " << endl;
	cout << " ##    ##  ##     ## ##     ## ##          ##     ##   ## ##   ##       ##    ##     ####" << endl;
	cout << "  ######   ##     ## ##     ## ########     #######     ###    ######## ##     ##    ####" << endl;
                                                                                                                                                                                 






	Sleep(100000);
	return 0;
}

