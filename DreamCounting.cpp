#include <iostream>

using namespace std;

int n, m, arr[10];

void input()
{
	cin >> n >> m;
}

void solution()
{
	for (int i = n; i <= m; i++)
	{
		int k = i;

		while (k)
		{
			arr[k % 10]++;
			k /= 10;
		}
	}

	for (auto i : arr)
		cout << i << ' ';
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