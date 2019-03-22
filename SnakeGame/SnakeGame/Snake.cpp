#include "Snake.h"
#include <time.h>
#include "windows.h"


Snake::Snake(bool *_game_over, int _width, int _height) {
	game_over = _game_over;
	width = _width;
	height = _height;
}


Snake::~Snake() {}

void Snake::direction(char kb_char, int * x, int * y) {
	if (kb_char == 'w' || kb_char == 'W' || kb_char == 'Ц' || kb_char == 'ц') {
		*y -= 1;
	} else if (kb_char == 's' || kb_char == 'S' || kb_char == 'Ы' || kb_char == 'ы') {
		*y += 1;
	} else if (kb_char == 'a' || kb_char == 'A' || kb_char == 'Ф' || kb_char == 'ф') {
		*x -= 1;
	} else if (kb_char == 'd' || kb_char == 'D' || kb_char == 'В' || kb_char == 'в') {
		*x += 1;
	} else if (kb_char == 'x' || kb_char == 'X' || kb_char == 'Ч' || kb_char == 'Ч') {
		*game_over = true;
	}
}

void Snake::border_control(int *x, int *y) {
	if (*x == width + 1) {
		*x = 1;
	} else if (*x == 0) {
		*x = width;
	}
	if (*y == height + 1) {
		*y = 1;
	} else if (*y == 0) {
		*y = height;
	}
}

void Snake::eating(int *f_x, int *f_y, int *x, int *y) {			//дописать рост змеи
	if (*x == *f_x && *y == *f_y) {
		srand((unsigned)time(NULL));
		*f_x = rand() % width + 1;
		*f_y = rand() % height + 1;
	}
}
