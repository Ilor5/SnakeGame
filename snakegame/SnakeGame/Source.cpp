
#include <iostream>
using namespace std;


bool game_over;
int snakex, snakey, fruitx, fruity;
const int width = 20;
const int height = 20;



void setup() {
	game_over = false;
}


void field() {
	system("cls");
	for (int i = 0; i <= (width + 1); i++) {
		cout << "#";
	}
	cout << "\n";
	for (int i = 0; i < (height); i++) {
		for (int j = 0; j <= (width + 1); j++) {
			if (j == 0 || j == (width + 1)) {
				cout << "#";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	for (int i = 0; i <= (width + 1); i++) {
		cout << "#";
	}
}


void input() {

}


void logic() {

}


int main()
{
	setup();
	while (!game_over) {
		field();
		input();
		logic();
	}
	return 0;
}

