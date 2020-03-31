#include "card.h"
#include "mac.h"
#include "player.h"
#include "function.cpp"
#include<iostream>
using namespace std;

int main()
{
	mac m; int playerNum;
	player p1, p2, p3, p4;

	// unos broja igraca
	cout << "Sudjeluju li 2 ili 4 igraca u igri ? " << endl;
	cin >> playerNum;
	
	// generiranje decka 
	cout << "My deck\n";
	m.generateMac();
	m.printdeck();

	// mijesanje karata
	cout << endl << "------------------------------------------------------------------------------" << endl;
	cout << "Shuffled deck\n";
	for (int i = 0; i < 5; i++)
		m.shuffle();
	//m.shuffle();
	m.printdeck();

	// podijela karata 
	cout << endl << "Karte igraca igraca" << endl;
	if (playerNum == 4){

		p1.setPlayer();
		p2.setPlayer();
		p3.setPlayer();
		p4.setPlayer();

		for (int i = 0; i < 10; i++) {

			p1.comb.push_back(m.dealDeck());
			p2.comb.push_back(m.dealDeck());
			p3.comb.push_back(m.dealDeck());
			p4.comb.push_back(m.dealDeck());
		}

		p1.points = p1.akuza();
		p2.points = p2.akuza();
		p3.points = p3.akuza();
		p4.points = p4.akuza();

		cout << "Punti igraca jedan  : " << p1.points << endl;
		cout << "Punti igraca dva  : " << p2.points << endl;
		cout << "Punti igraca tri  : " << p3.points << endl;
		cout << "Punti igraca cetiri  : " << p4.points << endl;
	}

	else if (playerNum == 2) {

		p1.setPlayer();
		p2.setPlayer();

		for (int i = 0; i < 10; i++) {

			p1.comb.push_back(m.dealDeck());
			p2.comb.push_back(m.dealDeck());
		}

		p1.points = p1.akuza();
		p2.points = p2.akuza();

		cout << "Punti igraca jedan  : " << p1.points << endl;
		cout << "Punti igraca dva  : " << p2.points << endl;
	}
	else
		cout << "Broj igraca moze biti samo 2 ili 4 !" << endl;
}