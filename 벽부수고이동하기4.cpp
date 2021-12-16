#include <iostream>
#include <vector>

using namespace std;

int n, m, idx = 1, nx, ny, cnt, point;
vector<vector<int>> map(1000, vector<int>(1000)), ans(1000, vector<int>(1000)), dir = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }, visited(1000, vector<int>(1000));
vector<int> zerocnt(100000), checkcnt(1000000), checklist;

void calcnt(int x, int y, int idx)
{
	visited[y][x] = idx;

	for (int k = 0; k < 4; k++)
	{
		nx = x + dir[k][1];
		ny = y + dir[k][0];

		if (nx >= 0 && nx < m && ny >= 0 && ny < n && !map[ny][nx] && visited[ny][nx] != idx)
		{
			cnt++;
			calcnt(nx, ny, idx);
		}
	}
}

int makeans(int x, int y)
{
	int answer = 1;
	
	for (int k = 0; k < 4; k++)
	{
		nx = x + dir[k][1];
		ny = y + dir[k][0];

		if (nx >= 0 && nx < m && ny >= 0 && ny < n && !map[ny][nx])
		{
			point = visited[ny][nx];
			if (!checkcnt[point])
			{
				checkcnt[point] = 1;
				checklist.push_back(point);
			}
		}
	}
	while(!checklist.empty())
	{
		answer += zerocnt[checklist.back()];
		checkcnt[checklist.back()] = 0;
		checklist.pop_back();
	}
	return answer % 10;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string line;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = 0; j < m; j++)
			map[i][j] = line[j] - '0';
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!map[i][j] && !visited[i][j])
			{
				cnt = 1;
				calcnt(j, i, idx);
				zerocnt[idx++] = cnt;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j])
				ans[i][j] = makeans(j, i);
			cout << ans[i][j];
		}
		cout << '\n';
	}
	return 0;
}