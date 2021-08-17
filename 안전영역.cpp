#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> map;
int dir[4][2] = { {-1,0}, {0,1},{1,0},{0,-1} };
int n, area;

void searcharea(vector<vector<int>> &ch, int x, int y, int h)
{
	if (x < 0 || x >= n || y < 0 || y >= n)
		return;

	ch[y][x] = 1;

	for (int d = 0; d < 4; d++)
	{
		int nx = x + dir[d][1];
		int ny = y + dir[d][0];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && ch[ny][nx] == 0 && map[ny][nx] > h)
			searcharea(ch, nx, ny, h);
	}
}

void search(int n, int h)
{
	area = 0;
	vector<vector<int>> ch(n, vector<int>(n, 0));
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (ch[y][x] == 0 && map[y][x] > h)
			{
				area++;
				searcharea(ch, x, y, h);
			}
		}
	}
}

int main(void)
{
	int num;
	vector<int> m, ar;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> line;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			line.push_back(num);
		}
		m.push_back(*max_element(line.begin(), line.end()));
		map.push_back(line);
	}
	int ma = *max_element(m.begin(), m.end());
	ar.push_back(1);
	for (int i = 1; i < ma; i++)
	{
		search(n, i);
		ar.push_back(area);
	}
	cout << *max_element(ar.begin(), ar.end());
	return 0;
}