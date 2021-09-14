#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, num, t = 4611686018427389999;
	int k = 0;
	map<long long, int> m;
	map<long long, int>::iterator it;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		m[num]++;
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second > k)
		{
			k = it->second;
			t = it->first;
		}
		else if (it->second == k)
		{
			if (t > it->first)
				t = it->first;
		}
	}
	cout << t;
	return 0;
}