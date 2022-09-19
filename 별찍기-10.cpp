#include <iostream>
#define E 6561          // 3^8

using namespace std;

int n;
bool map[E][E];

void input()
{
	cin >> n;
}

void star(int y, int x, int l)
{
	// 빈 칸 처리
	// ex. 길이가 9일 때 나머지가 3이어야 함.
	// ex. 길이가 3일 때 나머지가 1이어야 함.
	if (y % (l * 3) == l && x % (l * 3) == l)
	{
		for (int i = y; i < y + l; i++)
			for (int j = x; j < x + l; j++)
				map[i][j] = 1;

		return;
	}

	if (l == 1)
		return;

	for (int i = y; i < y + l; i += l / 3)
	{
		for (int j = x; j < x + l; j += l / 3)
		{
			star(i, j, l / 3);
		}
	}
}

void solution()
{
	star(0, 0, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j])
				cout << ' ';

			else
				cout << '*';
		}
		
		cout << '\n';
	}
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}