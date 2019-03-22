#pragma once
class Field {
public:
	Field(int _height, int _width, int *_snakex, int *_snakey, int *_fruitx, int *_fruity);  
	~Field();
	void drawing();		
private:
	int height;
	int width;
	int *snakex;
	int *snakey;
	int *fruitx;
	int *fruity;
};

