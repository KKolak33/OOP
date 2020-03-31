#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctype.h>
using std::vector;
using namespace std;

/* Napisati funkciju koji prevodi engleske re�enice na pig latin jezik. Pravila su sljede�a:
(a) ako rije� po�inje samoglasnikom dopisuje se hay na kraj rije�i, (b) ina�e, svi suglasnici s po�etka rije�i prebacuju se na kraj te se na kraju 
rije�i dopisuje ay.
Re�enice treba spremiti u vector, a zatim prevesti slu�ajno odabranu re�enicu iz vektora. Primjer: �What time is it?� prevodi se kao �atwhay imetay 
ishay ithay?�*/

// provjerit prvo slovo rijeci
bool checkFirstLetter(char f)
{
	return (f == 'a' || f == 'e' || f == 'i' || f == 'o'  || f == 'u');
}


string add(string word)
{
	string::iterator itw;
	string sub;
	if (checkFirstLetter(tolower(word.at(0))))
		word.insert(word.length(), "hay");
	else {
		itw = word.begin();
		while (itw != word.end()) {
			if ((checkFirstLetter(tolower(*itw))))
				break;
			else {
				sub += *itw;
				++itw;
				itw = word.erase(--itw);
			}
		}
		word.insert(word.length(), sub + "ay");
	}
	return word;
}


string pigLatin(string sentence)
{
	string word;
	string::iterator it = sentence.begin();
	string s, w;
	while (it != sentence.end())
	{
		if (isspace(*it)) {
			w = add(word);
			s += w + " ";
			word.erase();
			w.erase();
		}
		else
			word += *it;
		++it;
	}
	w = add(word);
	s += w;
	return s;
}

int main()
{
	string s, ar;
	vector<string> v;
	int num, r;
	cout << "Koliko recenica zelite napisati? " << endl;
	cin >> num;
	for (int i = 0; i <= num; i++) {
		cout << "Unesite recenice " << endl;
		getline(cin, s);
		v.push_back(s);
	}
	r = rand() % v.size();
	string sen = pigLatin(v.at(r));
	cout << sen << endl;
	return 0;
}