#include<iostream>
using namespace std;

/* Definirati strukturu koja opisuje vektor. Struktura se sastoji od niza int elemenata, logièke i fizièke velièine niza. Fizièka velièina je
inicijalno init, a kada se ta velièina napuni vrijednostima, alocira se duplo. Napisati funkcije vector_new, vector_delete, vector_push_back,
vector_pop_back, vector_front, vector_back i vector_size.*/

// struktura vektor
typedef struct
{
	int *arr;
	int size;  // broj elemenata
	int capacity;   // alocirana memorija
}vector;

// konstruktor 
void vector_new(vector& v, int c)
{
	v.capacity = c;
	v.arr = new int[v.capacity];
	v.size = 0;
}

// destrukcija 
void vector_delete(vector& v)
{
	delete[] v.arr;
	v.arr = 0;
	v.size = 0;
	v.capacity = 0;
}

// dodavanje na kraj  vektora
void vector_push_back(vector& v)
{
	if (v.size == v.capacity)  // provjerit kapacitet niza 
	{
		int *buf = new int[2 * v.capacity];  // udvostruci se kapacitet ako je popunjen
		for (int i = 0; i <= v.capacity; i++)
		{
			buf[i] = v.arr[i]; // kopiramo niz 
		}
		delete[] v.arr;  //zamijenimo nizove i povecamo kapacitet
		v.capacity *= 2;
		v.arr = buf;
	}
	int el;
	cout << "Unesite element koji zelite dodati na kraj vektora" << endl;
	cin >> el;
	v.arr[v.size] = el;  // dodajemo element na kraj niza 
	v.size++;   // uvecamo broj elemenata
}

// skidanje sa zadnjeg mjesta
void vector_pop_back(vector& v)
{
	/*int *temp = new int [v.capacity];
	for (int i = 0; i < v.size - 1; i++)
		temp[i] = v.arr[i];
	v.arr = temp;*/
	v.arr[v.size - 1] = 0;
	v.size--;
}

// vraca referencu na prvi element 
int& vector_front(vector& v)
{
	return v.arr[0];   // vrati referencu na prvi element 
}

// vraca referencu na zadnji element 
int& vector_back(vector& v)
{
	return v.arr[v.size - 1];  // vrati referencu na zadnji element 
}

int vector_size(vector& v)
{
	return v.size;
}

void vector_print(vector& v)
{
	for (int i = 0; i < v.size; i++)
		cout << v.arr[i] << " ";
	cout << endl;
}

int main()
{
	vector ve;
	int capacity;
	cout << "Unesite zeljeni kapacitet vektora " << endl;
	cin >> capacity;
	if (capacity == 0)
	{
		cout << "Kapacitet ne moze biti 0! " << endl;
		cin >> capacity;
	}
	vector_new(ve, capacity);
	int el;
	cout << "Koliko elemenata zelite dodati" << endl;
	cin >> el;
	for (int i = 0; i < el; i++)
		vector_push_back(ve);
	vector_print(ve);
	vector_pop_back(ve);
	cout << ve.arr[ve.size - 1] << endl;
	cout << "Vector front " << vector_front(ve) << endl;
	cout << "Vector back " << vector_back(ve) << endl;
	cout << "Vector size " << vector_size(ve) << endl;
	vector_delete(ve);
	return 0;
}