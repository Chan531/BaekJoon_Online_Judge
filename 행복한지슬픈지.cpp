#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int h = 0, s = 0;
	string t;
	getline(cin, t);
	for (int i = 0; i < t.length(); i++)
	{
		if (t[i] == ':')
		{
			if (t.substr(i, 3) == ":-)")
				h++;
			else if (t.substr(i, 3) == ":-(")
				s++;
		}
	}
	if (h > s)
		cout << "happy";
	else if (s > h)
		cout << "sad";
	else if (s == h && s)
		cout << "unsure";
	else
		cout << "none";
	return 0;
}