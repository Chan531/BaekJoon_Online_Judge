#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	string s = "";
	int n = 0;
	int m = 0;
	int count = 0;
	vector<string> v;
	for (int i = 0; i < 8; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	while (n!= 8)
	{
		string t = v[n];
		if (n % 2 == 0)
		{
			if (m % 2 == 0 && t[m] == 'F')
				count++;
		}
		else
		{
			if (m % 2 == 1 && t[m] == 'F')
				count++;
		}
		m++;
		if (m == 8)
		{
			n++;
			m = 0;
		}
	}
	cout << count;
	return 0;
}