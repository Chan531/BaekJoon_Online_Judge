#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, i;
	string s, w = "";
	cin >> n;
	cin.ignore();
	for (int j = 0; j < n; j++)
	{
		getline(cin, s);
		i = 0;
		while (i < s.length())
		{
			if (s[i] != ' ')
				w += s[i];
			else
			{
				reverse(w.begin(), w.end());
				cout << w << ' ';
				w = "";
			}
			i++;
		}
		reverse(w.begin(), w.end());
		cout << w << '\n';
		w = "";
	}
	return 0;
}