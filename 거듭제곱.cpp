#include <iostream>
#define N 39
#define ll long long

using namespace std;

ll n, ans, cnt = 1, val = 1;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < N; i++)
	{
		cnt *= 2; val *= 3;
		if (n & cnt) ans += val;
	}
	n & 1 ? cout << ans + 1 : cout << ans;
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