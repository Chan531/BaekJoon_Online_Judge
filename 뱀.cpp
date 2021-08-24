#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, d = 0;
queue<pair<int, int>> dir;
queue<pair<int, int>> movement;
int di[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int dum(vector<vector<int>> &v, int y, int x, int t)
{
	if (x < 0 || x >= n || y < 0 || y >= n || v[y][x] == 1)
		return t;

	if (v[y][x] != 2)
	{
		v[movement.front().first][movement.front().second] = 0;
		movement.pop();
	}
	movement.push(make_pair(y, x));

	v[y][x] = 1;                                                    // 현재 꼬리가 있음을 표시

	if (!dir.empty() && dir.front().first == t)
	{
		dir.front().second == 'D' ? d += 1 : d -= 1;
		if (d == -1)
			d = 3;
		if (d == 4)
			d = 0;
		dir.pop();
	}

	if (x + di[d][1] >= 0 && x + di[d][1] < n && y + di[d][0] >= 0 && y + di[d][0] < n)
	{
		return dum(v, y + di[d][0], x + di[d][1], ++t);
	}

	else
		return t + 1;
}

int main(void)
{
	int k, l, x, num1, num2;
	char c;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> num1 >> num2;
		v[num1 - 1][num2 - 1] = 2;				   // 사과는 2
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> x >> c;
		dir.push(make_pair(x, c));
	}
	movement.push(make_pair(0, 0));
	cout << dum(v, 0, 1, 1);
	return 0;
}