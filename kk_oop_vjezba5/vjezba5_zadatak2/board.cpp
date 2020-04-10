#include<iostream>
#include "board.h"
#include "point.h"
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;


// alocira matricu i definira znak za rub okvira
board::board(int c, int r) {
	n = c;  // columns
	m = r;  // rows
	array = new char*[m];
	this->b = 'o';   // rub okvira
	for (int i = 0; i < n; i++) {
		array[i] = new char[n];
	}
	this->setboard();
}

board::board(const board& other) : m(other.m), n(other.n) {}

char board::get(int i, int j) {
	return array[i][j];
}

int board::getrow(board* b) {
	return b->m;
}

int board::getcol(board* b) {
	return b->n;
}

char board::getb(board* myboard) {
	return myboard->b;
}

void board::setboard() {
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			if ((i == 0 || j == 0) || (i == m - 1 || j == n - 1)) {
				this->array[i][j] = this->b;
			}
			else
				this->array[i][j] = ' ';
		}
		cout << endl;
	}
}

bool board::compare(double h, double w) {
	if (round(h) >= this->n || round(w) >= this->m || h == 0 || w == 0 || h == n - 1 || w == m - 1)
		return false;
	return true;
}
void board::set(int i, int j, int e) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			array[i][j] = e;
		}
		cout << endl;
	}

}

void board::draw_char(point p, const char& ch) {
	int x = round(p.x);
	int y = round(p.y);
	for (int i = 1; i < m - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (i == p.x && j == p.y)
				array[i][j] = ch;
		}
		cout << endl;
	}
}


void board::draw_up_line(point p, char ch) {
	int y = round(p.y);
	for (int i = p.x; i > 0; i--) {
		array[i][y] = ch;
	}
}

bool setValue(double x, double x2) {
	if (x < x2)
		return true;
	return false;
}

void board::draw_line(point p1, point p2, char ch) {
	int x1 = min(p1.x, p2.x);
	int x2= max(p1.x, p2.x);
	int y1 = min(p1.y, p2.y);
	int y2 = max(p1.y, p2.y);

	cout << x1 << "  " << x2 << "   " << y1 << "  " << y2 << endl;
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			if (y1 == y2)
				array[y1][j] = ch;
			else if (x1 == x2)
				array[i][x1];
			else
				if (i == j)
					array[j][i] = ch;
		}
	}

}

void board::display() {
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			cout << this->get(i, j);
		}
		cout << endl;
	}
}

board::~board() {
	for (int i = 0; i < m; i++)
		delete[] array[i];
	delete[] array;
}