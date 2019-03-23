#pragma once
class Snake {
public:
	Snake(bool *_game_over, int _width, int _height, int *_score);
	~Snake();
	void direction(char kb_char, int *x, int *y);
	void border_control(int *x, int *y);
	void eating(int *f_x, int *f_y, int *x, int *y, int *_score);
private:
	bool *game_over;
	int width;
	int	height;
	int *score_num;
};

