#pragma once

#include "windows.h"

class Snake {

public:
	Snake(bool *_game_over, int _width, int _height, int *_score, int *_speed);
	~Snake();
	void direction(int * x, int * y, int *_tailx, int *_taily);
	void border_control(int *x, int *y);
	void eating(int *f_x, int *f_y, int *x, int *y, int *_score, int *_speed, bool *_GrowUp);

private:
	bool *game_over;
	int width;
	int	height;
	int *score_num;
	int *speed;
	int lastKeyCode;
	HANDLE hInput;
	int getPressedKey();
};

