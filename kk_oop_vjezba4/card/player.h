#pragma once
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
#include "card.h"
#include<iostream>
#include<vector>
using std::vector;
#include<string>

class player {
public:
	string name;   // ime igraca
	int points;   // broj bodova 
	void setPlayer();
	vector<card> comb;  // kombinacija od 10 karata
	int akuza();    //  (napolitana 1,2,3 iste boje -> 3 boda, 3 / 4 jedinice / duje / trice nose 3 / 4 boda
};

#endif