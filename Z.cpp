#include <iostream>
#include <cmath>

using namespace std;

int n, r, c;

void input()
{
	cin >> n >> r >> c;
}

void search(int start, int end)
{
	if (n == 1)
	{
		cout << start + r * 2 + c;
		return;
	}

	int idx = pow(2, n);
	int mid = idx / 2;
	// int num = pow(2, n - 1) * pow(2, n - 1);
	int num = pow(4, n) / 4;

	n--;

	if (r < mid && c < mid)
		search(start, start + num);

	else if (r < mid && c >= mid)
	{
		c -= mid;
		search(start + num, start + num * 2);
	}

	else if (r >= mid && c < mid)
	{
		r -= mid;
		search(start + num * 2, end - num);
	}

	else if (r >= mid && c >= mid)
	{
		c -= mid;
		r -= mid;
		search(end - num, end);
	}
}

void solution()
{
	search(0, pow(4, n));
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