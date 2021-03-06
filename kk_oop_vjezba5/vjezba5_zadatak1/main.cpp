#include "card.h"
#include "mac.h"
#include "player.h"
#include<iostream>
using namespace std;

/*U klasama igra�a i karte iz prethodne vje�be dodajte konstruktore s argumentima i destruktore.� Napravite odvojene hpp i cpp datoteke za svaku klasu. U hpp datotekama
su definicije klase (zaglavlja), a u cpp datotekama implementacija. � Sve podatkovne �lanove (data members) napravite privatne. Napi�ite
public get i set funkcije za pristup i promjenu podataka (za svaki data member posebno).
� U konstruktorima i destruktorima ispi�ite poruke kako bi vidjeli u kojem poredku se pozivaju.*/

int main()
{
	mac* m; int playerNum = 0;
	m = new mac[40];
	vector<player> playerArr[4];
	string name;
	player p;
	// unos broja igraca
	while (playerNum != 2 && playerNum != 4) {
		cout << "Sudjeluju li 2 ili 4 igraca u igri ? " << endl;
		cin >> playerNum;
	}

	for (int i = 0; i < playerNum; i++) {
		p.setPlayerName();
		playerArr->push_back(p);
	}

	m->generateMac();

	// mijesanje karata
	for (int i = 0; i < 2; i++)
		m->shuffle();

	for (int i = 0; i < playerNum; i++) {
		for (int j = 0; j < 10; j++)
			playerArr->at(i).setPlayerCards(m->dealDeck());
		playerArr->at(i).setPlayerPoints(playerArr->at(i).akuza());
		cout << "Punti igraca  " << playerArr->at(i).getPlayerName() << " : " << playerArr->at(i).getPlayerPoints(playerArr->at(i)) << endl;
	}

	delete[] m;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          