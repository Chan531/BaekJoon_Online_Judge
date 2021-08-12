#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(1003002);
	v[1]++;
	for (int i = 2; i < n; i++)
	{
		if (v[i] != 1)
		{
			for (int j = i * 2; j <= 1003001; j += i)
				v[j] = 1;
		}
	}
	int i = n;
	while (1)
	{
		if (v[i] != 1)
		{
			string s = to_string(i);
			reverse(s.begin(), s.end());
			if (s == to_string(i))
			{
				cout << s;
				break;
			}
			for (int j = i * 2; j <= 1003001; j += i)
				v[j] = 1;
		}
		i++;
	}
	return 0;
}