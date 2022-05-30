#include <iostream>
#include <map>

using namespace std;

int n, m, num, ans;
map<int, int> a, b;
map<int, int>::iterator it;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		a[num] = 1;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		b[num] = 1;
	}
}

void solution()
{
	for (it = a.begin(); it != a.end(); it++)
		if (!b[it->first])
			ans++;

	for (it = b.begin(); it != b.end(); it++)
		if (!a[it->first])
			ans++;

	cout << ans;
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
	cout.tie(NULL);

	solve();
	return 0;
}