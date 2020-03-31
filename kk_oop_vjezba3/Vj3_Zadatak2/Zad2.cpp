#include<iostream>
#include<string>
#include<cctype>
using namespace std;

/*Napisati funkciju koja izmije�a rije�i u re�enici u inverznom poredku. To�ka mora ostati na kraju re�enice, prva rije� mora biti napisana velikim
po�etnim slovom, a zadnja malim. Koristiti reverse funkciju.
*/

string strreverse(string& s)
{
	reverse(s.begin(), s.end() - 1);
	string word;
	string sentence;
	string::iterator it = s.begin();
	while (it != s.end())
	{
		if (isspace(*it)) {
			reverse(word.begin(), word.end());
			sentence += word + " ";
			word.erase();
		}
		else
			word += *it;
		++it;
	}
	word[word.length() - 2] = tolower(word[word.length() - 2]);
	reverse(word.begin(), word.end() - 1);
	sentence += word;
	sentence[0] = toupper(sentence[0]);
	return sentence;
}

int main()
{
	string str("Napravi inverznu recenicu.");
	string rstr = strreverse(str);
	cout << rstr << endl;
	return 0;
}