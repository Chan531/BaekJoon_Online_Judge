#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k, start, end, time, pos;
	cin >> n >> m >> k;
	priority_queue<int> course[1001];                                                               // k번 째 최단경로까지 저장
	vector<vector<vector<int>>> usetime(n + 1, vector<vector<int>>(n + 1));                         // 경로간의 소요시간 저장
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> routesearch;
	while (m--)
	{
		cin >> start >> end >> time;
		usetime[start][end].push_back(time);
	}
	routesearch.push(make_pair(0, 1));
	course[1].push(0);
	while (!routesearch.empty())
	{
		time = routesearch.top().first;
		pos = routesearch.top().second;

		routesearch.pop();

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < usetime[pos][i].size(); j++)
			{
				if (course[i].size() < k)
				{
					course[i].push(time + usetime[pos][i][j]);
					routesearch.push(make_pair(time + usetime[pos][i][j], i));
				}
				else if (course[i].top() > time + usetime[pos][i][j])
				{
					course[i].pop();
					course[i].push(time + usetime[pos][i][j]);
					routesearch.push(make_pair(time + usetime[pos][i][j], i));
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (course[i].size() == k)
			cout << course[i].top() << '\n';
		else
			cout << -1 << '\n';
	}
	return 0;
}