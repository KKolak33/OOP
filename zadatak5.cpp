#include<iostream>
using namespace std;

/* Napisati funkciju za unos pozitivnih cijelih brojeva. Korisnik unosi brojeve sve dok ne unese nulu. Funkcija inicijalno alocira memoriju za
10 elemenata. Svaki put kad velièina niza dosegne alociranu velièinu, alocira se duplo. U main funkciji ispisati dobiveni niz i osloboditi memoriju.
*/

int* inputfun(int& n)
{
	int *arr = new int[n];
	int el;
	int *temp;
	for (int i = 0; i < n; i++)
	{
		cout << "Unesite element niza" << "\n";
		cin >> el;
		if (el == 0)
			return arr;
		arr[i] = el;
		if (i == n - 1) {
			temp = new int[2 * n];
			for (int j = 0; j < n; j++)
				temp[j] = arr[j];
			delete[] arr;
			//arr = 0;
			n *= 2;
			arr = temp;
		}
	}
}

int main5()
{
	int len = 10;
	int *arr = inputfun(len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << endl;
	delete[] arr;
	return 0;
}