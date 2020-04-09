#include<iostream>
#include "card.h"

// kreiranje karte sa zadanim brojem i zogom
card::card(string number, string czog) {
	num = number;
	zog = czog;
}

// printanje karte
string card::print() const {
	return num + "" + zog;
}

