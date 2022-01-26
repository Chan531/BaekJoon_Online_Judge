#include <iostream>
#include <cmath>

using namespace std;

int n, kx, ky, sx, sy;
string king, stone, order;

void input()
{
	cin >> king >> stone >> n;
	ky = abs(king[1] - '8');
	kx = king[0] - 'A';
	sy = abs(stone[1] - '8');
	sx = stone[0] - 'A';
}

void move(string order)
{
	if (order == "R" && kx + 1 < 8)
	{
		if (kx + 1 == sx && ky == sy)
		{
			if (sx + 1 < 8)
			{
				sx++;
				kx++;
			}
		}
		else
			kx++;
	}
	else if (order == "L" && kx - 1 >= 0)
	{
		if (kx - 1 == sx && ky == sy)
		{
			if (sx - 1 >= 0)
			{
				sx--;
				kx--;
			}
		}
		else
			kx--;
	}
	else if (order == "B" && ky + 1 < 8)
	{
		if (ky + 1 == sy && kx == sx)
		{
			if (sy + 1 < 8)
			{
				sy++;
				ky++;
			}
		}
		else
			ky++;
	}
	else if (order == "T" && ky - 1 >= 0)
	{
		if (ky - 1 == sy && kx == sx)
		{
			if (sy - 1 >= 0)
			{
				sy--;
				ky--;
			}
		}
		else
			ky--;
	}
	else if (order == "RT" && kx + 1 < 8 && ky - 1 >= 0)
	{
		if (kx + 1 == sx && ky - 1 == sy)
		{
			if (sx + 1 < 8 && sy - 1 >= 0)
			{
				sx++;
				kx++;
				sy--;
				ky--;
			}
		}
		else
		{
			kx++;
			ky--;
		}
	}
	else if (order == "LT" && kx - 1 >= 0 && ky - 1 >= 0)
	{
		if (kx - 1 == sx && ky - 1 == sy)
		{
			if (sx - 1 >= 0 && sy - 1 >= 0)
			{
				sx--;
				kx--;
				sy--;
				ky--;
			}
		}
		else
		{
			kx--;
			ky--;
		}
	}
	else if (order == "RB" && kx + 1 < 8 && ky + 1 < 8)
	{
		if (kx + 1 == sx && ky + 1 == sy)
		{
			if (sx + 1 < 8 && sy + 1 < 8)
			{
				sx++;
				kx++;
				sy++;
				ky++;
			}
		}
		else
		{
			kx++;
			ky++;
		}
	}
	else if (order == "LB" && kx - 1 >= 0 && ky + 1 < 8)
	{
		if (kx - 1 == sx && ky + 1 == sy)
		{
			if (sx - 1 >= 0 && sy + 1 < 8)
			{
				sx--;
				kx--;
				sy++;
				ky++;
			}
		}
		else
		{
			kx--;
			ky++;
		}
	}
}

void solution()
{
	while (n--)
	{
		cin >> order;
		move(order);
	}
	cout << char('A' + kx) << abs(ky - 8) << '\n' << char('A' + sx) << abs(sy - 8);
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