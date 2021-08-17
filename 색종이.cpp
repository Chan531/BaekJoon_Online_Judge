#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v(101, vector<int>(101));
int black = 0;

void changeblack(int x, int y)
{
	for (int ny = y; ny < y + 10; ny++)
	{
		for (int nx = x; nx < x + 10; nx++)
		{
			if (v[ny][nx] == 0)
			{
				black++;
				v[ny][nx] = 1;
			}
		}
	}
}

int main(void)
{
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		changeblack(x, y);
	}
	cout << black;
	return 0;
}