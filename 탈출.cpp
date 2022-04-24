#include <iostream>
#include <queue>
#include <string>
#define p pair<int, int>

using namespace std;

int n, t, g, visited[100000];
string ans = "ANG";

void input()
{
	cin >> n >> t >> g;
}

void solution()
{
	queue<p> q;
	q.push({ n, 0 });
	visited[n] = 1;

	while (!q.empty())
	{
		int pos = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt > t)
			continue;

		if (pos == g)
		{
			ans = to_string(cnt);
			break;
		}

		if (pos < 99999 && !visited[pos + 1])
		{
			visited[pos + 1] = 1;
			q.push({ pos + 1, cnt + 1 });
		}

		if (pos * 2 < 99999)
		{
			pos *= 2;

			int sub = 1;

			while (sub)
			{
				if (sub == pos)             // 1000 -> 0
				{
					pos = 0;
					sub = 0;
					continue;
				}

				if (sub > pos)              // 246 -> 146
				{
					pos -= sub / 10;
					sub = 0;
					continue;
				}

				sub *= 10;
			}

			if (visited[pos])
				continue;

			visited[pos] = 1;
			q.push({ pos, cnt + 1 });
		}
	}

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