#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> farm;
int earthworm = 0;

void makefarm(int width, int height)
{
	earthworm = 0;
	for (int i = 0; i < height; i++)
	{
		vector<int> line;
		for (int j = 0; j < width; j++)
		{
			line.push_back(0);
		}
		farm.push_back(line);
	}
}

void plant(int x, int y)
{
	farm[y][x]++;
}

void investigate(int x, int y, int earthworm)
{
	if (x < 0 || y < 0 || x >= farm.size() || y >= farm[0].size())
		return;

	if (farm[x][y] == 0 || farm[x][y] == -1) return;

	else
	{
		farm[x][y] = -1;
		investigate(x - 1, y, earthworm);
		investigate(x, y - 1, earthworm);
		investigate(x + 1, y, earthworm);
		investigate(x, y + 1, earthworm);
	}
}

void search(int x, int y)
{
	for (int a = 0; a < y; a++)
	{
		for (int b = 0; b < x; b++)
		{
			if (farm[a][b] == 1)
			{
				investigate(a, b, earthworm++);
			}
		}
	}
}

int main(void)
{
	int n = 0;
	int width, height, num = 0;
	int x, y = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> width >> height >> num;
		makefarm(width, height);
		for (int s = 0; s < num; s++)
		{
			cin >> x >> y;
			plant(x, y);
		}
		search(width, height);
		cout << earthworm << '\n';
		farm.clear();
	}
}