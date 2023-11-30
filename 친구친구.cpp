#include <iostream>

using namespace std;

int n, m, arr[101010];

void input()
{
	cin >> n >> m;
}

void solution()
{
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		arr[a]++;
		arr[b]++;
	}

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