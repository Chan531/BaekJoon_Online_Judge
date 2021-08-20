#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	string s, bomb;
	vector<char> c(1000001);
	cin >> s >> bomb;
	int index = 0;
	for (int i = 0; i < s.length(); i++)
	{
		c[index++] = s[i];
		int l = (int)bomb.length() - 1;
		if (c[index - 1] == bomb[l])
		{
			if (index - l < 1)
				continue;

			for (int j = index - 1; j >= index - (int)bomb.length(); j--)
			{
				if (c[j] != bomb[l])
					break;
				l--;
			}
			if (l == -1)
				index -= (int)bomb.length();
		}
	}
	if (index == 0)
		cout << "FRULA";
	else
	{
		for (int i = 0; i < index; i++)
			cout << c[i];
	}
	return 0;
}