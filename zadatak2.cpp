#include<iostream>
using namespace std;

/* Definirati strukturu kruznica. Napisati funkciju koja prima niz kruznica i jednu kruznicu i vraæa broj kruznica koji sijeku
kružnicu. Niz kruznica i kružnica šalju se u funkciju pomoæu const referenci.
*/

// struktura tocka 
typedef struct
{
	double x, y;
}point;

// struktura kruznica
typedef struct
{
	point p; // centar kruznice
	double r;   // radijus kruznice 
}circle;

int intersect(const circle(&arr)[3], int n, const circle& cref)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		double x = arr[i].p.x - cref.p.x;   // udaljenost na x-osi
		double y = arr[i].p.y - cref.p.y;   // udaljenost na y-osi
		double rsum = arr[i].r + cref.r;    // zbroj radijusa 2 kruznice 

		// ako je zbroj kvadrata x i y manji ili jednak rsum onda se sigurno preklapaju 
		if ((x * x + y * y) <= rsum * rsum)
			count++;
	}
	return count;
}

int main2()
{
	const circle rectArr[3] = { {2, 2, 1}, {5, 5, 0.5}, {4, 2, 1} };
	const circle c = { 3, 1, 1 };
	int num = intersect(rectArr, sizeof(rectArr) / sizeof(rectArr[0]), c);
	cout << "Number of intersect: " << num << endl;
	return 0;
}