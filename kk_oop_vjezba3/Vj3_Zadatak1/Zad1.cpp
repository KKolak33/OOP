#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using std::vector;

/*Napisati funkciju koja æe sumirati prvi i zadnji element vektora, drugi i predzadnji, treæi i predpredzadnji itd. Izraèunate sume spremiti u novi
vektor te izraèunati najveæu i najmanju meðu sumama*/


vector<int> funSum(vector<int> &v, vector<int>::iterator& min, vector<int>::iterator& max)
{
	int sum = 0;
	vector<int> v2;
	vector<int>::iterator it;  // iterator od pocetka vektora
	vector<int>::reverse_iterator rit;  // od kraja vektora
	vector<int>::iterator middle = v.begin() + v.size() / 2;  // kod neparne velicine vektora (srednji element)
	for (it = v.begin(), rit = v.rbegin(); it != v.begin() + v.size() / 2; ++it, ++rit)
	{
		sum = *it + *rit;
		v2.push_back(sum);
	}
	if (v.size() % 2 != 0)   // za neparnu velicinu elementa srednji element dodamo jer ga nemamo s cim zbrojiti
		v2.push_back(*middle);

	max = max_element(v2.begin(), v2.end());
	min = min_element(v2.begin(), v2.end());
	return v2;
}

int main()
{
	vector<int> v1 = { 11,22,73,84,95,6,7,8,39, 10 };
	int k = 0;
	vector<int>::iterator it, mn, mx;
	vector<int> v2 = funSum(v1, mn, mx);
	for (it = v2.begin(); it != v2.end(); ++it)
		cout << *it << " ";
	cout << endl << "Max sum: " << *mx << "\nMin sum " << *mn << endl;
	return 0;
}