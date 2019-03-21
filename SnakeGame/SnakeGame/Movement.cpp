#include "Movement.h"



Movement::Movement(bool *_game_over, int _width, int _height) {
	game_over = _game_over;
	width = _width;
	height = _height;
}


Movement::~Movement() {}

void Movement::direction(char kb_char, int * x, int * y) {
	if (kb_char == 'w' || kb_char == 'W' || kb_char == 'Ö' || kb_char == 'ö') {
		*y -= 1;
	} else if (kb_char == 's' || kb_char == 'S' || kb_char == 'Û' || kb_char == 'û') {
		*y += 1;
	} else if (kb_char == 'a' || kb_char == 'A' || kb_char == 'Ô' || kb_char == 'ô') {
		*x -= 1;
	} else if (kb_char == 'd' || kb_char == 'D' || kb_char == 'Â' || kb_char == 'â') {
		*x += 1;
	} else if (kb_char == 'x' || kb_char == 'X' || kb_char == '×' || kb_char == '×') {
		*game_over = true;
	}
}

void Movement::border_control(int * x, int * y) {
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
