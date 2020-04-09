#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include "player.h"
#include "mac.h"
#include "card.h"

using namespace std;
using std::vector;

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


// dijeljenje karata
card mac::dealDeck()
{
	if (deck->size() <= 0)   // je li mac prazan ?
		cout << "Mac je prazan!";  
	card c = deck->at(deck->size() - 1);   
	cout << c.print() << endl;   
	deck->pop_back();     // uzima se karata s vrha
	return c;
}


// ispis decka
void mac::printdeck() const {
	for (int i = 0; i < deck->size(); i++) {
		cout << deck->at(i).print() << "  ";
	}
	cout << endl;
}



