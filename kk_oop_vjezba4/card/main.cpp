#include "card.h"
#include "mac.h"
#include "player.h"
#include<iostream>
using namespace std;

/*Definirajte klase za kartašku igru Trešeta. Modelirajte klase za kartu, igraèa i mac (deck). Karta se sastoji od broja i zoga. Mac ima 40 karata koji se moraju moæi 
promiješati i podijeliti igraèima (po 10 karata). Igraè ima ime, kombinaciju karata, broj bodova i može akužati ako ima odgovarajuæu kombinaciju karata (napolitana tj.
1, 2, 3 iste boje nose 3 boda, a po (barem) tri jedinice, dvojke ili trojke nose tri ili èetiri boda). Napisati program u kojem korisnik odreðuje broj igraèa (2 ili 4)
i imena igraèa, potom se promiješane karte podijele igraèima, te se ispisuje koliko bodova iz akuže ima koji igraè.*/

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