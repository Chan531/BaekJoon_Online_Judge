#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[101], e[101], ans;

void input()
{
	cin >> n >> m;
}

void solution()
{
	for (int i = 1; i <= n; i++)
		arr[i] = i, e[i] = i;

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		for (int i = a; i <= b; i++)
		{
			e[i] = max(e[i], b);
			b = max(b, e[i]);
			arr[i] = arr[a];
		}
	}

	int idx = 0;

	for (int i = 1; i <= n; i++)
		if (idx < arr[i])
			idx = arr[i], ans++;

	cout << ans;
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