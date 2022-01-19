#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b, ans, maxkb = 1000000001, pos, cnt, npos;
vector<int> friendlist[101], check(101, -1);

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		friendlist[a].push_back(b);
		friendlist[b].push_back(a);
	}
}

void reset()
{
	for (int i = 1; i <= 100; i++)
		check[i] = -1;
}

int checkcnt()
{
	cnt = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (check[i] != -1)
			cnt += check[i];
	}
	return cnt;
}

void solve()
{
	for (int i = 1; i <= n; i++)
	{
		reset();
		queue<pair<int, int>> q;
		q.push({ 0, i });
		check[i] = 0;
		while (!q.empty())
		{
			cnt = q.front().first;
			pos = q.front().second;
			q.pop();

			for (int j = 0; j < friendlist[pos].size(); j++)
			{
				npos = friendlist[pos][j];
				if (check[npos] == -1)
				{
					check[npos] = cnt + 1;
					q.push({ cnt + 1, npos });
				}
			}
		}
		cnt = checkcnt();
		if (maxkb > cnt)
		{
			maxkb = cnt;
			ans = i;
		}
	}
	cout << ans;
}

int main(void)
{
	input();
	solve();
	return 0;
}