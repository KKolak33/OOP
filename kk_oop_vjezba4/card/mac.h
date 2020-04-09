#pragma once
#ifndef MAC_H
#define MAC_H

using namespace std;
#include "card.h"
#include<iostream>
#include<vector>
#include<string>
using std::vector;

class mac {
	vector<card>* deck;  // 40 karata u macu 
public:
	vector<card>* generateMac();
	void shuffle();   // mijesanje karata 
	card dealDeck();    // dijeljenje karata
	void printdeck() const;   // ispis maca
};

#endif
