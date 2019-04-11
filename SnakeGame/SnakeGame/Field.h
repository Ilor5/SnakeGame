#pragma once
class Field {
public:
	Field(int _height, int _width);
	~Field();
	void drawing(int  _snakex, int _snakey, int _fruitx, int _fruity);
	void score(int _score);
	void DynamicDrawing(int  _snakex, int _snakey, int _fruitx, int _fruity, int tailX[], int tailY[], int nTail, int  deleteX, int deleteY, bool _startGame);
private:
	int height, width;
	int snakex, snakey;
};

