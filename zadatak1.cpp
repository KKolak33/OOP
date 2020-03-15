#include<iostream>
using namespace std;

/* Napisati funkciju koja raèuna najveæi i najmanji broj u nizu od n prirodnih brojeva. Funkcija vraæa tražene brojeve pomoæu referenci.
*/

void minmax(int arr[], int n, int& max, int& min)
{
	max = arr[0];
	min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
}
int main1()
{
	int n, max, min;
	cout << "Unesite duzinu niza" << endl;
	cin >> n;
	int *arr = new int[n];
	cout << "Unesite elemente niza " << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	minmax(arr, n, max, min);
	cout << "Maximum: " << max << "\nMinimum: " << min << endl;
	delete[] arr;
	return 0;

}