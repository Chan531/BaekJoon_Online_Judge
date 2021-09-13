#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, st;
	cin >> n;
	vector<int> v, g(n + 1), r(n + 1), answer;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		st = v[i];
		for (int j = 0; j < i; j++)
		{
			if (v[j] < v[i])
				g[i] = max(g[i], g[j] + 1);
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		st = v[i];
		for (int j = n - 1; j > i; j--)
		{
			if (v[j] < v[i])
				r[i] = max(r[i], r[j] + 1);
		}
	}
	for (int i = 0; i < n; i++)
		answer.push_back(g[i] + r[i]);
	cout << *max_element(answer.begin(), answer.end()) + 1;
	return 0;
}