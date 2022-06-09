#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>
#define p pair<int, int>

using namespace std;

string cogwheel[4];
int k, idx, com, ans;
bool check[4];

void input()
{
	for (int i = 0; i < 4; i++)
		cin >> cogwheel[i];
}

void rotate(int idx, int com)
{
	queue<p> q;
	q.push({ idx, com });

	while (!q.empty())
	{
		int pos = q.front().first;
		int dir = q.front().second;
		q.pop();

		if (check[pos])
			continue;

		check[pos] = 1;

		if (pos != 3 && cogwheel[pos][2] != cogwheel[pos + 1][6])
			q.push({ pos + 1, dir * -1 });

		if (pos != 0 && cogwheel[pos][6] != cogwheel[pos - 1][2])
			q.push({ pos - 1, dir * -1 });

		if (dir == 1)           // 시계 방향으로 돌려줌
		{
			string wheel = "";

			wheel.push_back(cogwheel[pos][7]);

			for (int i = 0; i < 7; i++)
				wheel.push_back(cogwheel[pos][i]);

			cogwheel[pos] = wheel;
		}

		else                    // 반시계 방향으로 돌려줌
		{
			string wheel = "";

			for (int i = 1; i < 8; i++)
				wheel.push_back(cogwheel[pos][i]);

			wheel.push_back(cogwheel[pos][0]);

			cogwheel[pos] = wheel;
		}
	}
}

void solution()
{
	cin >> k;

	while (k--)
	{
		cin >> idx >> com;
		rotate(idx - 1, com);
		memset(check, 0, sizeof(check));
	}

	for (int i = 0; i < 4; i++)
		if (cogwheel[i][0] == '1')
			ans += pow(2, i);

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