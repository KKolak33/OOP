#include<iostream>
#include<string>
using namespace std;

/*Napisati funkciju koja vraæa najduži zajednièki podstring u dva stringa.*/


string maxsubstr(string str1, string str2)
{
	string sub, nsub;
	string max;
	for (int i = 0; i <= str1.length(); i++)
	{
		for (int j = 1; j <= str1.length() - i; j++)
		{
			sub = str1.substr(i, j);
		}
		if (str2.find(sub) != string::npos)
			nsub = sub;
		if (nsub.length() > max.length())
			max = nsub;
		sub.erase();
		nsub.erase();

	}
	return max;
}

int main()
{
	string str1("Prvi string je podstringovo");
	string str2("podstringovo od string je ");
	string maxsub = maxsubstr(str1, str2);
	cout << maxsub;
	return 0;
}