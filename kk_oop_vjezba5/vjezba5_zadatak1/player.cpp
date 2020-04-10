#include<iostream>
#include "player.h"
#include "mac.h"
#include "card.h"

player::player() {
	cout << "Pozvan player konstruktor!" << endl;
	playerCards.reserve(10);
	points = 0;
}

player::player(string name) {
	cout << "Pozvan player konstruktor s argumentima" << endl;
	playerCards.reserve(10);
	points = 0;
	this->name = name;
}

void player::setPlayerName() {
	cout << "Unesite ime igraca:" << endl;
	cin >> this->name;
	this->points = 0;
}

void player::setPlayerPoints( int point) {
	this->points = point;
}

void player::setPlayerCards(card c) {
	playerCards.push_back(c);
}

string player::getPlayerName() {
	return this->name;
}

int player::getPlayerPoints(player p) {
	return p.points;
}

vector<card> player::getPlayerCards(player p) {
	return p.playerCards;
}

void player::setPlayer() {
	cout << "Unesite ime igraca " << endl;
	cin >> name;
	points = 0;
}

int player::compareCards(const card& p1) {
	int count = 0;
	for (int i = 0; i < playerCards.size(); i++) {
		if (playerCards.at(i).getNum(playerCards.at(i)) == p1.getNum(p1) && playerCards.at(i).getZog(playerCards.at(i)) == p1.getZog(p1))
			return 1;
	}
	return 0;
}

// 1,2,3 istog zoga ili 3 / 4 jedinice, 3 / 4 dvice, 3 / 4 trice
int player::akuza()
{
	int count1 = 0, count2 = 0, count3 = 0;
	string z[4] = { "C", "S", "D", "B" };
	for (int i = 0; i < 4; i++) {   // provjera karata po zogu
		int napolitana = 0;
		for (int j = 1; j < 4; j++)  // provjera 1, 2, 3 istog zoga
			napolitana += compareCards(card(to_string(j), z[i]));

		if (napolitana == 3)
			points += 3;

		count1 += compareCards(card("1", z[i]));
		count2 += compareCards(card("2", z[i]));
		count3 += compareCards(card("3", z[i]));
	}
	points = count1 == 3 ? points + 3 : count1 == 4 ? points + 4 : points + 0;
	points = count2 == 3 ? points + 3 : count2 == 4 ? points + 4 : points + 0;
	points = count3 == 3 ? points + 3 : count3 == 4 ? points + 4 : points + 0;
	return points;
}

void player::print() const {
	for (int i = 0; i < playerCards.size(); i++) {
		cout << playerCards.at(i).print() << "  ";
	}
	cout << endl;
}

player::~player() {
	cout << "Pozvan player destruktor!" << endl;
	playerCards.clear();
	vector<card>().swap(playerCards);
}