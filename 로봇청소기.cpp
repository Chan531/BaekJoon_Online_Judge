#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> room;
int cl = 0;

void clean(int r, int c, int d)
{
	if (r < 0 || r >= room.size() || c < 0 || c >= room[0].size() || room[r][c] == 1)               // room을 벗어낫거나 벽인 경우
		return;
	if (room[r][c] != 2)                                                                            // 청소 상태로 만들기
	{
		room[r][c] = 2;
		cl++;
	}
	int rt = 0;
	while (1)
	{
		if (d == 0)
			d = 4;
		d--;
		rt++;
		if (d == 0 && room[r - 1][c] != 1 && room[r - 1][c] != 2)
			clean(r - 1, c, d);
		else if (d == 1 && room[r][c + 1] != 1 && room[r][c + 1] != 2)
			clean(r, c + 1, d);
		else if (d == 2 && room[r + 1][c] != 1 && room[r + 1][c] != 2)
			clean(r + 1, c, d);
		else if (d == 3 && room[r][c - 1] != 1 && room[r][c - 1] != 2)
			clean(r, c - 1, d);
		if (rt == 4)
			break;
	}
	if (d == 0)
	{
		if (room[r + 1][c] == 1)
		{
			cout << cl;
			exit(0);
		}
		else
			clean(r + 1, c, d);
	}
	else if (d == 1)
	{
		if (room[r][c - 1] == 1)
		{
			cout << cl;
			exit(0);
		}
		else
			clean(r, c - 1, d);
	}
	else if (d == 2)
	{
		if (room[r - 1][c] == 1)
		{
			cout << cl;
			exit(0);
		}
		else
			clean(r - 1, c, d);
	}
	else
	{
		if (room[r][c + 1] == 1)
		{
			cout << cl;
			exit(0);
		}
		else
			clean(r, c + 1, d);
	}
}

int main(void)
{
	int n, m, r, c, d, num;
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
	{
		vector<int> line;
		for (int j = 0; j < m; j++)
		{
			cin >> num;
			line.push_back(num);
		}
		room.push_back(line);
	}
	clean(r, c, d);
	return 0;
}