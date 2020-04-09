#pragma once
#ifndef CARD_H
#define CARD_H

using namespace std;
#include<string>

class card {
public:
	string num;   // broj karte
	string zog;   // zog karte
	card(string mynum, string myzog);    // kreiranje karte brojem i zogom
	string print() const;    // ispis karte
};

#endif
