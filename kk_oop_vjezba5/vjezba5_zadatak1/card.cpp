#include<iostream>
#include "card.h"

card::card() {
	cout << "Pozvan card konstruktor" << endl;
}

// kreiranje karte sa zadanim brojem i zogom
card::card(string number, string czog) {
	cout << "Pozvan card konstruktor s argumentima!" << endl;
	num = number;
	zog = czog;
}

// printanje karte
string card::print() const {
	return num + "" + zog;
}


// vrati broj karte
string card::getNum(card c) const {
	return c.num;
}

void card::setNum(card c) const {
	c.num;
}

// vrati zog karte
string card::getZog(card c) const {
	return c.zog;
}

void card::setZog(card c) const {
	c.zog;
}

card::~card() {
	cout << "Pozvan je card destruktor!" << endl;
}