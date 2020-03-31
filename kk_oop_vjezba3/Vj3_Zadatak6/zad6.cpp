#include<iostream>
#include<list>
using std::list;
using namespace std;

/* Napisati funkciju koja u listu prirodnih brojeva ispred svakog parnog broja umetne nulu, a iza svakog neparnog broja osim jedinice umetne jedinicu. 
Funkcija vraæa broj elemenata izmeğu prve nule u listi i zadnje jedinice. U main funkciji generirati listu, pozvati funkciju, ispisati listu i povratnu
vrijednost funkcije*/

int insert(list<int>& mylist)
{
	list<int>::iterator it = mylist.begin();
	while (it != mylist.end())
	{
		if (*it % 2 == 0) {
			it = mylist.insert(it, 0);
			++it;++it;
		}
		if (*it % 2 != 0 && *it != 1) {
			++it;
			it = mylist.insert(it, 1);
			++it;
		}
		else
			++it;
	}
	int c = 0;
	list<int>::iterator it0 = find(mylist.begin(), mylist.end(), 0);
	list<int>::reverse_iterator it1 = find(mylist.rbegin(), mylist.rend(), 1);
	list<int>n(++it0, (++it1).base());
	return n.size();
	
}
int main()
{
	list<int> num, rlist;
	int size, el;
	list<int>::iterator it;
	// generiranje liste
	cout << "Koliko elementa zelite u listi ?" << endl;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cout << "Unesite element" << endl;
		cin >> el;
		num.push_back(el);
	}
	int n = insert(num);
	cout << "Broj elemenata izmedu prve 0 i zadnje jedinice je " << n << endl;
	// ispis liste
	for (it = num.begin(); it != num.end(); ++it)
		cout << *it << endl;
}