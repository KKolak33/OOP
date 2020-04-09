#include"board.h"
#include<iostream>
using namespace std;

int main() {

	int m, n;
	board* b;

	cout << "n: ";
	cin >> n;
	cout << "m: ";
	cin >> m;

	b = new board(n,m);
	b->draw_char(point(1, 1), 'x');
	b->draw_up_line(point(4, 4), 'x');
	b->draw_line(point(16, 8), point(2, 8), 'x');
	
	b->display();
}