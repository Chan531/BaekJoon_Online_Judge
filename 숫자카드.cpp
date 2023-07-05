#include <iostream>

using namespace std;

int n, m, arr[20000001];

void input()
{
	cin >> n;

	while (n--)
	{
		int num;
		cin >> num;
		arr[num + 10000000] = 1;
	}

	cin >> m;
}

void solution()
{
	while (m--)
	{
		int num;
		cin >> num;

		if (arr[num + 10000000])
			cout << 1 << ' ';

		else
			cout << 0 << ' ';
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

	solve();
	return 0;
}