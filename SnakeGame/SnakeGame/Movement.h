#pragma once
class Movement
{
public:
	Movement(bool *_game_over, int _width, int _height);
	~Movement();
	void direction(char kb_char, int *x, int *y);
	void border_control(int *x, int *y);

private:
	bool *game_over;
	int width;
	int	height;
};

