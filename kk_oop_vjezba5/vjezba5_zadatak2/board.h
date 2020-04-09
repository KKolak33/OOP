#pragma once
#ifndef BOARD_H
#define BOARD_H

using namespace std;
#include"point.h"

class board {
	char** array; //niz
	char b;
public:
	board() {};  // default constructor
	int n, m;  // rows and cols
	board(int c, int r);  // constructor with arguments
	board(const board& other);  // copy constructor
	char get(int i, int j);  // get matrix
	int getrow(board* b);
	int getcol(board* b);
	char getb(board* myboard);  // get char b
	void setboard();
	bool compare(double h, double w);
	void set(int i, int j, int e);  // set matrix
	void draw_char(point p, const char& ch);
	void draw_up_line(point p, char ch);
	void draw_line(point p1, point p2, char ch);
	void display();
	~board();  // destructor
};

#endif



