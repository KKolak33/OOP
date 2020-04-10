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
	vector<card> playerCards;  // kombinacija od 10 karata
	int points;   // broj bodova 
	string name;   // ime igraca
public:
	player();
	player(string name);
	void setPlayerName();
	void setPlayerPoints(int point);
	void setPlayerCards(card c);
	string getPlayerName();
	int getPlayerPoints(player p);
	vector<card> getPlayerCards(player p);
	void setPlayer();
	int akuza();    //  (napolitana 1,2,3 iste boje -> 3 boda, 3 / 4 jedinice / duje / trice nose 3 / 4 boda
	int compareCards(const card& p1);
	void print() const;
	~player();
};

#endif
