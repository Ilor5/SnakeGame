#pragma once
class Field {
public:
	Field(int _height, int _width);
	~Field();
	void drawing();		
	void score(int _score);
	void DynamicDrawing(int _snakex, int _snakey, int _tailx, int _taily, int _fruitx, int _fruity, bool *_GrowUp);
private:
	int height;
	int width;
};

