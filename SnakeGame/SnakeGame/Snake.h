#pragma once
class Snake
{
public:
	Snake(bool *_game_over, int _width, int _height);
	~Snake();
	void direction(char kb_char, int *x, int *y);
	void border_control(int *x, int *y);
	void eating(int *f_x, int *f_y, int *x, int *y);
private:
	bool *game_over;
	int width;
	int	height;
};

