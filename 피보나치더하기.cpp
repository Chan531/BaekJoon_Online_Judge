#include <iostream>
#define N 79

using namespace std;

int k;
long long n, fibo[N];
string ans;

void input()
{
	cin >> k >> n;
}

void init()
{
	fibo[1] = 1;
	fibo[2] = 1;

	for (int i = 3; i < N; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
}

void backtrack(int idx, int cnt, long long val)
{
	if (ans == "YES" || val > n) return;

	if (cnt == k)
	{
		if (val == n) ans = "YES";
		return;
	}

	for (int i = idx; i < N; i++)
		backtrack(i, cnt + 1, val + fibo[i]);
}

void solution()
{
	ans = "NO";
	backtrack(1, 0, 0);
	cout << ans << '\n';
}

void solve()
{
	init();
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}