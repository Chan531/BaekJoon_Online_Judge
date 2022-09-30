#include <iostream>
#include <unordered_map>

using namespace std;

int n, m, ans;
unordered_map<int, int> cd;
unordered_map<int, int>::iterator it;

void input()
{
	int num;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		cd[num]++;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		cd[num]++;
	}
}

void solution()
{
	for (it = cd.begin(); it != cd.end(); it++)
		if (it->second == 2)
			ans++;

	cout << ans << '\n';
}

void reset()
{
	ans = 0;
	cd.clear();
}

void solve()
{
	while (1)
	{
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		input();
		solution();
		reset();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}