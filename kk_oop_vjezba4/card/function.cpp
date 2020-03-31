#include<iostream>
#include<string>
#include<algorithm>
#include<time.h>
#include<vector>
#include <cstdlib>
#include <iomanip>
#include "player.h"
#include "mac.h"
#include "card.h"

using namespace std;
using std::vector;

void player::setPlayer() {
	cout << "Unesite ime igraca " << endl;
	cin >> name;
	points = 0;
}

card::card(){
	num = rand() % 10;
	zog = rand() % 4;
}

// kreiranje karte sa zadanim brojem i zogom
card::card(string number, string czog) {
	num = number;
	zog = czog;
}

// generiranje decka 
vector<card>* mac::generateMac() {
	string n[] = { "1","2","3","4","5","6","7","11","12","13" };
	string z[] = { "D","C","S","B" };
	deck = new vector<card>[40];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++)
			deck->push_back(card(n[i], z[j]));
	}
	return deck;
}

// mijesanje decka
void mac::shuffle() {
	//srand(time(0));
	for (int normal = 0; normal < 40; normal++) {
		int shuffle = rand() % 40;
		card temp = deck->at(normal);
		deck->at(normal) = deck->at(shuffle);
		deck->at(shuffle) = temp;
	}
}

// printanje karte
string card::print() const {
	return num + "" + zog;
}

// dijeljenje karata
card mac::dealDeck()
{
	if (deck->size() <= 0)   // je li deck prazan ?
		cout << "Mac je prazan!";  
	card c = deck->at(deck->size() - 1);   
	cout << c.print() << endl;   
	deck->pop_back();     // uzima se karata s vrha
	return c;
}

// usporedba karata 
bool operator ==(const card& p1, const card& p2) {
	return p1.num == p2.num && p1.zog == p2.zog;
}

// ispis decka
void mac::printdeck() const {
	cout << left;//print everything to the left
	for (int i = 0; i < deck->size(); i++) {
		cout << deck->at(i).print() << "      ";
	}
}

// provjerit karte sa istim zogom 
int player::akuza()
{
	card c;
	string z[4] = { "C", "S", "D", "B" };
	int count1 = 0, count2 = 0, count3 = 0;
	for (int i = 0; i < 4; i++) {
		if ((find(comb.begin(), comb.end(), card("1", z[i]))) != comb.end() && (find(comb.begin(), comb.end(), card("2", z[i]))) != comb.end() && (find(comb.begin(), comb.end(), card("3", z[i]))) != comb.end()) {
			points += 3;
		} 
		count1 += count(comb.begin(), comb.end(), (card("1", z[i])));
		count2 += count(comb.begin(), comb.end(), (card("2", z[i])));
		count3 += count(comb.begin(), comb.end(), (card("3", z[i])));
	}
	points = count1 == 3 ? points + 3 : count1 == 4 ? points + 4 : points + 0;
	points = count2 == 3 ? points + 3 : count2 == 4 ? points + 4 : points + 0;
	points = count3 == 3 ? points + 3 : count3 == 4 ? points + 4 : points + 0;
	return points;
}

