#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	string s;
	int count, mcount;
	vector<string> v;
	for (int i = 0; i < 3; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < 3; i++)
	{
		s = v[i];
		count = 1;
		mcount = 1;
		for (int j = 0; j < 7; j++)
		{
			if (s[j] == s[j + 1])
				count++;
			else
			{
				if (count > mcount)
					mcount = count;
				count = 1;
			}
		}
		count > mcount ? cout << count << '\n' : cout << mcount << '\n';
	}
	return 0;
}