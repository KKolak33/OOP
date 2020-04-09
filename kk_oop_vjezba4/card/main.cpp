#include "card.h"
#include "mac.h"
#include "player.h"
#include<iostream>
using namespace std;

/*Definirajte klase za karta�ku igru Tre�eta. Modelirajte klase za kartu, igra�a i mac (deck). Karta se sastoji od broja i zoga. Mac ima 40 karata koji se moraju mo�i 
promije�ati i podijeliti igra�ima (po 10 karata). Igra� ima ime, kombinaciju karata, broj bodova i mo�e aku�ati ako ima odgovaraju�u kombinaciju karata (napolitana tj.
1, 2, 3 iste boje nose 3 boda, a po (barem) tri jedinice, dvojke ili trojke nose tri ili �etiri boda). Napisati program u kojem korisnik odre�uje broj igra�a (2 ili 4)
i imena igra�a, potom se promije�ane karte podijele igra�ima, te se ispisuje koliko bodova iz aku�e ima koji igra�.*/

int main()
{
	mac m; int playerNum = 0;
	vector<player> playerArr;
	player p;

	// unos broja igraca
	while (playerNum != 2 && playerNum != 4) {
		cout << "Sudjeluju li 2 ili 4 igraca u igri ? " << endl;
		cin >> playerNum;
	}

	for (int i = 0; i < playerNum; i++) {
		p.setPlayer();
		playerArr.push_back(p);
	}

	m.generateMac();
	m.printdeck();

	// mijesanje karata
	for (int i = 0; i < 2; i++)
		m.shuffle();

	// podijela karata
	for (int i = 0; i < playerNum; i++) {
		for (int j = 0; j < 10; j++)
			playerArr[i].playerCards.push_back(m.dealDeck());
		playerArr[i].akuza();
		cout << "Punti igraca  " << playerArr[i].name << " : " << playerArr[i].points << endl;
	}
}