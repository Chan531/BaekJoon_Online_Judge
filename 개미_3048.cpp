#include <iostream>
#include <algorithm>
#define p pair<char, int>

using namespace std;

int n, m, t;
p seq[55];
bool dir[2][26];

void input()
{
	cin >> n >> m;
	
	for (int i = n - 1; i >= 0; i--)
	{
		char c;
		cin >> c;
		seq[i] = { c, 1 };
		dir[1][c - 'A'] = 1;
	}

	for (int i = n; i < n + m; i++)
	{
		char c;
		cin >> c;
		seq[i] = { c, 0 };
		dir[0][c - 'A'] = 0;
	}

	cin >> t;
}

void solution()
{
	while (t--)
	{
		for (int i = 0; i < n + m - 1; i++)
		{
			if (dir[seq[i].second][seq[i].first - 'A'] == dir[seq[i].second][seq[i + 1].first - 'A']) continue;
			swap(seq[i], seq[i + 1]);
			i++;
		}
	}

	for (int i = 0; i < n + m; i++)
		cout << seq[i].first;
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