#include"board.h"
#include<iostream>
using namespace std;

/*Definirajte klasu Board koja æe služiti kao okvir za iscrtavanje znakova.
Board je matrica èije se dimenzije zadaju u konstruktoru, a za koju se memorija alocira na heapu. Board ima rub koji se sastoji od nekog znaka koji je
odreðen u konstruktoru.
· Napišite defaultni konstruktor, copy konstruktor, konstruktor s argumentima i destruktor.
· Definirajte strukturu Point koja ima dva èlana x i y tipa double, gdje
su x i y vrijednosti manje od dimenzije matrice.
· Napišite member funkciju draw_char koja za toèku p i znak ch postavlja znak ch na odgovarajuæem mjestu u matrici (x-koordinata odgovara
retku matrice, a y-koordinata stupcu). Ako koordinate toèke p nisu
cjelobrojne, zaokružite ih na najbližu cjelobrojnu vrijednost.
· Napišite member funkciju draw_up_line koja poèevši od toèke p postavlja znak ch na svim poljima koja predstavljaju okomitu liniju prema
gore.
· Napišite member funkciju draw_line koja za dvije toèke p1 i p2 postavlja
znak ch na svim poljima koje predstavljaju liniju izmeðu te dvije toèke.
· Napišite member funkciju koja iscrtava trenutno stanje Boarda.*/


int main() {

	int m, n;
	double x, y, x2, y2;
	board* b;

	cout << "n: ";
	cin >> n;
	cout << "m: ";
	cin >> m;

	b = new board(n, m);

	cout << "Unesite kordinate tocke 1: " << endl;
	cin >> x;
	cin >> y;

	cout << "Unesite koordinate tocke 2: " << endl;
	cin >> x2;
	cin >> y2;

	if (b->compare(x, y) && b->compare(x2, y2)) {

		b->draw_char(point(x, y), 'x');
		b->draw_up_line(point(x, y), 'x');
		b->draw_line(point(x, y), point(x2, y2), 'x');

		b->display();
	}
	else
		cout << "Koordinate nisu valjane, pokusajte ponovno: " << endl;

}