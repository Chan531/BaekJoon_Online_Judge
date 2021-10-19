#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;          // 우선순위 큐
vector<vector<int>> v(125, vector<int>(125));                                                                  // 맵
vector<vector<int>> le(125, vector<int>(125, 6250));                                                           // 최소비용 저장
vector<int> dir[4] = { {-1, 0},{0, 1},{1, 0},{0, -1} };                                                        // 방향

void searchle(int n)
{
	pq.push(make_tuple(v[0][0], 0, 0));
	while (!pq.empty())
	{
		int cost = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());

		pq.pop();

		for (int j = 0; j < 4; j++)
		{
			int nx = x + dir[j][1];
			int ny = y + dir[j][0];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n && le[ny][nx] > cost + v[ny][nx])
			{
				le[ny][nx] = v[ny][nx] + cost;
				pq.push(make_tuple(le[ny][nx], nx, ny));
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	for (int i = 1; ; i++)
	{
		cin >> n;
		if (!n)
			break;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> num;
				v[j][k] = num;
			}
		}
		le[0][0] = v[0][0];
		searchle(n);
		cout << "Problem " << i << ": " << le[n - 1][n - 1] << '\n';
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				le[j][k] = 6250;
		}
	}
	return 0;
}