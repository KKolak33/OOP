#include<iostream>
#include<string>
using namespace std;

/* Napisati funkciju koja iz stringa izbaci svako pojavljivanje podstringa koristeæi funkcije standardne biblioteke.*/

void substring(string& s, string subs)
{
	int pos = s.find(subs);  // vrati poziciju podudaranja prvog karaktera ako nema podudaranja vrati npos
	while (pos != string::npos)
	{
		s.erase(pos, subs.length());   // brise substring iz stringa
		pos = s.find(subs, pos);   // trazimo sljedece pojavljivanje podstringa
	}
}
int main()
{
	string str("izbaci iz ovog izvornog stringa sve podstringove na iz");
	string sub("iz");
	substring(str, sub);
	cout << str << endl;
	return 0;
}