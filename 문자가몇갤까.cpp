#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int count;
	string s;
	while (1)
	{
		count = 0;
		vector<int> v(26);
		getline(cin, s);
		if (s == "#")
			break;
		for (int i = 0; i < s.length(); i++)
		{
			if (isalpha(s[i]))
			{
				if (!v[tolower(s[i]) - 'a'])
				{
					v[tolower(s[i]) - 'a'] = 1;
					count++;
				}
			}
		}
		cout << count << '\n';
	}
	return 0;
}