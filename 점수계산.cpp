#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
	int n, sum = 0;
	vector<int> v, o;
	map<int, int> m;
	for (int i = 0; i < 8; i++)
	{
		cin >> n;
		v.push_back(n);
		m[n] = i + 1;
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < 5; i++)
	{
		sum += v[i];
		o.push_back(m[v[i]]);
	}
	sort(o.begin(), o.end());
	cout << sum << '\n';
	for (auto i : o)
		cout << i << ' ';
	return 0;
}