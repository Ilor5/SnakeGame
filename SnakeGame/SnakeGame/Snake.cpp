#include <time.h>
#include "Snake.h"


Snake::Snake(bool *_game_over, int _width, int _height) {
	game_over = _game_over;
	width = _width;
	height = _height;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	lastKeyCode = 0;
}

Snake::~Snake() {}

int Snake::getPressedKey() {
	DWORD cc;
	INPUT_RECORD irec;

	if (!GetNumberOfConsoleInputEvents(hInput, &cc) || cc == 0) {
		return 0;
	}
	ReadConsoleInput(hInput, &irec, 1, &cc);
	if (irec.EventType == KEY_EVENT && ((KEY_EVENT_RECORD&)irec.Event).bKeyDown) {
		return ((KEY_EVENT_RECORD&)irec.Event).wVirtualKeyCode;
	}
	return 0; 
}

void Snake::direction(int * x, int * y, bool *_startGame) {
	//bool foo = true;

	int keyCode = getPressedKey();
	lastKeyCode = keyCode != 0 ? keyCode : lastKeyCode;
	if (lastKeyCode == VK_UP) {
		*y -= 1;
		*_startGame = true;
	}
	else if (lastKeyCode == VK_DOWN) {
		*y += 1;
		*_startGame = true;
	}
	else if (lastKeyCode == VK_LEFT) {
		*x -= 1;
		*_startGame = true;
	}
	else if (lastKeyCode == VK_RIGHT) {
		*x += 1;
		*_startGame = true;
	}
	else if (lastKeyCode == 'X') {
		*game_over = true;
	}
}

void Snake::border_control(int *x, int *y) {
	if (*x == width + 1) {
		*x = 1;
	}
	else if (*x == 0) {
		*x = width;
	}
	if (*y == height + 1) {
		*y = 1;
	}
	else if (*y == 0) {
		*y = height;
	}
}

void Snake::eating(int *f_x, int *f_y, int *x, int *y, int *_score, int *_speed, int *_nTail) {			
	if (*x == *f_x && *y == *f_y) {
		srand((unsigned)time(NULL));
		*f_x = rand() % width + 1;
		*f_y = rand() % height + 1;
		(*_score) += 10;
		(*_speed)--;
		(*_nTail)++;
	}
}

void Snake::tail(int tailX[], int tailY[], int _nTail, int _snakex, int _snakey, int *_deleteX, int *_deleteY) {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2x, prev2y;
	tailX[0] = _snakex;
	tailY[0] = _snakey;
	for(int i = 1; i < _nTail; i++) {
		prev2x = tailX[i];
		prev2y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2x;
		prevY = prev2y;
	}
	*_deleteX = prevX;
	*_deleteY = prevY;
}