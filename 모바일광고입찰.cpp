#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<int> v;

void input()
{
	cin >> n >> k;
}

void solution()
{
	while (n--)
	{
		int a, b;
		cin >> a >> b;

		if (a < b) v.push_back(b - a);
		else k--;
	}

	sort(v.begin(), v.end());

	(k > 0) ? cout << v[k - 1] : cout << 0;
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}