#include<iostream>
#include<vector>
using std::vector;
using namespace std;

/*Napisati funkciju unstuffing_bit koja je inverzna funkciji stuffin_bit iz predhodnog zadatka. Funkcija prima modificirani container i izbacuje 
umetnute nule kako bi se dobila originalna sekvenca.*/

vector<int> unstuffingBit(vector<int> v)
{
	vector<int>::iterator it = v.begin();
	int num = 0;
	vector<int>::iterator pos;
	for (it = v.begin(); it != v.end(); ++it) {
		if ((num == 5) && (*it == 0) && (*(++it) == 1)) {
			it = v.erase(--it); 
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
	vector<int> v1, vret;
	int el;
	cout << "Unesite element " << endl;
	cin >> el;
	while ((el == 0) || (el == 1)) {
		v1.push_back(el);
		cout << "Unesite element " << endl;
		cin >> el;
	}
	vret = unstuffingBit(v1);
	vector<int>::iterator itr;
	for (itr = vret.begin(); itr != vret.end(); ++itr)
		cout << *itr << endl;
	return 0;
}