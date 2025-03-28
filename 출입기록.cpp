#include <iostream>
#define N 202020

using namespace std;

int n, ans;
bool check[N];

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int a, b;
		cin >> a >> b;

		if (b)
		{
			if (check[a] == 1) ans++;
			check[a] = 1;
		}

		else
		{
			if (check[a] == 0) ans++;
			check[a] = 0;
		}
	}

	for (int i = 1; i < N; i++)
		if (check[i] == 1) ans++;

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