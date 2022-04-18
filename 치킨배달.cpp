#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct node {
	int y, x;
};

int n, m, ans = 1e9;
int map[51][51], visited[13];
vector<node> home, chicken, backtrack;              // 집, 치킨집, 치킨집 m개 모음

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 1)                    // 집 좌표 저장
				home.push_back({ i, j });

			else if (map[i][j] == 2)               // 치킨집 좌표 저장
				chicken.push_back({ i, j });
		}
	}
}

void chickendistance()
{
	int chickendis = 0;

	for (int i = 0; i < home.size(); i++)
	{
		int y = home[i].y;
		int x = home[i].x;
		int dis = 1e9;

		for (int j = 0; j < backtrack.size(); j++)
			dis = min(dis, abs(y - backtrack[j].y) + abs(x - backtrack[j].x));

		chickendis += dis;
	}

	ans = min(ans, chickendis);
}

void selectchicken(int idx, int cnt)
{
	if (cnt == m)
	{
		chickendistance();
		return;
	}

	for (int i = idx; i < chicken.size(); i++)
	{
		if (visited[i])
			continue;

		backtrack.push_back(chicken[i]);
		visited[i] = 1;
		selectchicken(i + 1, cnt + 1);
		visited[i] = 0;
		backtrack.pop_back();
	}
}

void solution()
{
	selectchicken(0, 0);
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