#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, charge[1001];
vector<int> task[1001];
bool check[1001];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int q;
		cin >> q;

		while (q--)
		{
			int num;
			cin >> num;

			task[i].push_back(num);
		}
	}
}

bool dfs(int n)
{
	for (int i = 0; i < task[n].size(); i++)
	{
		int work = task[n][i];

		if (check[work])
			continue;

		check[work] = 1;

		if (!charge[work] || dfs(charge[work]))
		{
			charge[work] = n;
			return true;
		}
	}
	return false;
}

void solution()
{
	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		memset(check, 0, sizeof(check));

		if (dfs(i))
			cnt++;
	}

	cout << cnt;
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