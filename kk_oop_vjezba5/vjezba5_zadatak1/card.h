#pragma once
#ifndef CARD_H
#define CARD_H

using namespace std;
#include<string>

class card {
	string num;   // broj karte
	string zog;   // zog karte
public:
	card();  
	card(string number, string czog);
	string print() const;    // ispis karte
	string getNum(card c) const;
	void setNum(card c) const;
	string getZog(card c) const;
	void setZog(card c) const;
	~card();
};

#endif

