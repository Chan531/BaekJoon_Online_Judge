#include <iostream>

using namespace std;

int n, arr[101], map[1010][1010];

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		for (int j = a; j < a + c; j++)
			for (int k = b; k < b + d; k++)
				map[j][k] = i;
	}

	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			arr[map[i][j]]++;

	for (int i = 1; i <= n; i++)
		cout << arr[i] << '\n';
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