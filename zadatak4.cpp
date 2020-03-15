#include<iostream>
using namespace std;

/* Napisati funkciju koja vraæa niz int vrijednosti velièine n u kojem je svaki element zbroj svoja dva prethodnika. Prvi i drugi element u nizu su
jedinice. U main funkciji ispisati dobiveni niz i osloboditi memoriju.
*/

int& sum(int arr[], int n)
{
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}

int main4()
{
	int n;
	cout << "Unesite duljinu niza" << endl;
	cin >> n;
	int *arr = new int[n];
	sum(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i];
	delete[] arr;
	return 0;
}