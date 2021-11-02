#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v(50, vector<int>(50)), w(50, vector<int>(50, 101));
vector<vector<int>> dir = { {-1,0},{0,1},{1,0},{0,-1} };
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int main(void)
{
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
			v[i][j] = s[j] - '0';
	}
	if (v[0][0] == 1)
	{
		pq.push({ 0, make_pair(0, 0) });
		w[0][0] = 0;
	}
	else
	{
		pq.push({ 1, make_pair(0, 0) });
		w[0][0] = 1;
	}
	while (!pq.empty())
	{
		int ch = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;

		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][1];
			int ny = y + dir[i][0];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (!v[ny][nx] && w[ny][nx] > ch + 1)
				{
					w[ny][nx] = ch + 1;
					pq.push(make_pair(ch + 1, make_pair(nx, ny)));
				}
				if (v[ny][nx] && w[ny][nx] > ch)
				{
					w[ny][nx] = ch;
					pq.push(make_pair(ch, make_pair(nx, ny)));
				}
			}
		}
	}
	cout << w[n - 1][n - 1];
	return 0;
}