#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n = 0;
	string s;
	cin >> s;
	vector<int> v(1041);
	for (int i = 2; i <= 1040; i++)
	{
		if (!v[i])
		{
			for (int j = 2 * i; j <= 1040; j += i)
				v[j] = 1;
		}
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
			n += s[i] - 38;
		else
			n += s[i] - 96;
	}
	v[n] ? cout << "It is not a prime word." : cout << "It is a prime word.";
}