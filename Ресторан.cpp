#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	string str;
	map<char, string> rus;
	rus['A'] = "a";
	rus['B'] = "v";
	rus['E'] = "ye";
	rus['K'] = "k";
	rus['M'] = "m";
	rus['H'] = "n";
	rus['O'] = "o";
	rus['P'] = "r";
	rus['C'] = "s";
	rus['T'] = "t";
	rus['Y'] = "u";
	rus['X'] = "h";
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		cout << rus[str[i]];
	return 0;
}