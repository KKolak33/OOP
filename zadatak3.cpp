#include<iostream>
using namespace std;

/*Napisati funkciju koja vraæa referencu na neki element niza. Koristeæi povratnu vrijednost funkcije kao lvalue uveæajte i-ti element niza za jedan.
*/

int& increment(int arr[], int& i)
{
	return arr[i];
}
int main3()
{
	int n, p;
	cout << "Unesite duzinu niza " << endl;
	cin >> n;
	int *arr = new int[n];
	cout << "Unesite elemente niza " << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Unesite poziciju elementa kojeg zelite uvecati za 1 (od 0 do  " << n << ")" << endl;
	cin >> p;
	increment(arr, p)++;
	cout << "Uveceni element sada je " << arr[p] << endl;
	delete[] arr;
	return 0;
}