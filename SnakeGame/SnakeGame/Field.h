#pragma once
class Field {
public:
	Field(int _height, int _width, int _snakex, int _snakey, int _fruitx, int _fruity);   //add used variables
	~Field();
	void drawing(int _height, int _width, int _snakex, int _snakey, int _fruitx, int _fruity);			//add methods
private: 
	int height;
	int width;
	int snakex;
	int snakey;
	int fruitx; 
	int fruity;
		//add used global variables
};

