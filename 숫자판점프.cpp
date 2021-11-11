#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
vector<vector<int>> v(5, vector<int>(5));
vector<vector<int>> dir = { {-1,0},{0,1},{1,0},{0,-1} };
map<int, int> m;

void makenum(int x, int y, int sum, int num)
{
	if (num == 6)
	{
		if (!m[sum])
			m[sum] = 1;
		return;
	}

	for (int k = 0; k < 4; k++)
	{
		int nx = x + dir[k][1];
		int ny = y + dir[k][0];

		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
			makenum(nx, ny, sum * 10 + v[ny][nx], num + 1);
	}
}

int main(void)
{
	int num;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> num;
			v[i][j] = num;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			makenum(j, i, v[i][j], 1);
	}
	cout << m.size();
	return 0;
}