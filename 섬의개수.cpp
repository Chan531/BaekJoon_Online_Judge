#include <iostream>
#include <vector>

using namespace std;
int islands = 0;
vector<vector<int>> island;
vector<vector<int>> check;
int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };

void searchisland(int x, int y)
{
	check[y][x] = 1;

	for (int i = 0; i < 8; i++)
	{
		int nx = x + dir[i][1];
		int ny = y + dir[i][0];
		if (nx >= 0 && nx < island[0].size() && ny >= 0 && ny < island.size())
		{
			if (island[ny][nx] == 1 && check[ny][nx] == 0)
				searchisland(nx, ny);
		}
	}
	return;
}

void search(int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			if (check[i][j] == 0 && island[i][j] == 1)
			{
				islands++;
				searchisland(j, i);
			}
	}
}

int main(void)
{
	int w, h, num;
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++)
		{
			vector<int> line, checklist;
			for (int j = 0; j < w; j++)
			{
				cin >> num;
				line.push_back(num);
				checklist.push_back(0);
			}
			island.push_back(line);
			check.push_back(checklist);
		}
		search(w, h);
		cout << islands << '\n';
		islands = 0;
		check.clear();
		island.clear();
	}
	return 0;
}