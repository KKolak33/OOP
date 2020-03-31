#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using namespace std;

/*Napisati program u kojem korisnik unosi binarne znamenke (0 i 1) i sprema ih u container. Unosu je kraj kad korisnik unese vrijednost koja ne 
predstavlja binarnu znamenku. Nakon toga napisati funkciju stuffing_bit koja primjeni bit stuffing algoritam na container. Bit stuffing je tehnika
koja se koristi u HDLC protokolima za prijenos podataka u kojima je poèetak i završetak paketa odreðen sa nizom bitova 01111110. Da se ne bi sadržaj
paketa brkao sa stop-bitovima, potrebno je nakon svakog niza od pet jedinica umetnuti jednu nulu. Primjer: za uneseni niz bitova
00111011111110001111111011 rezultat je 0011101111101100011111011011*/

vector<int> stuffingBit(vector<int> v)
{
	vector<int>::iterator it = v.begin(); 
	int num = 0;
	vector<int>::iterator pos;
	for (it = v.begin(); it != v.end(); ++it) {
		if (num == 5) {
			it = v.insert(it, 0);
			++it; 
			num = 0;
		}
		if ((*it == 1) && (num < 5))
			num++;
		else
			num = 0;
	}
	return v;
}

int main()
{
	vector<int> v,vr;
	int el;
	cout << "Unesite element " << endl;
	cin >> el;
	while ((el == 0) || (el == 1)) {
		v.push_back(el);
		cout << "Unesite element " << endl;
		cin >> el;
	}
	vr = stuffingBit(v);
	vector<int>::iterator itr;
	for (itr = vr.begin(); itr != vr.end(); ++itr)
		cout << *itr << endl;
	return 0;
}