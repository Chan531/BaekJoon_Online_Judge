#include <iostream>
#include <algorithm>

using namespace std;

int n, ans = 101010;

void input()
{
	cin >> n;
}

void solution()
{
	// 7
	int idx = n / 7;

	while (idx != 0)
	{
		int temp = n;
		int cnt = 0;
		temp -= idx * 7;
		cnt += idx;
		cnt += (temp / 5);
		temp -= (temp / 5) * 5;
		cnt += (temp / 2);
		temp -= (temp / 2) * 2;
		cnt += temp;

		ans = min(ans, cnt);
		idx--;
	}

	// 5
	idx = n / 5;

	while (idx != 0)
	{
		int temp = n;
		int cnt = 0;
		temp -= idx * 5;
		cnt += idx;
		cnt += (temp / 2);
		temp -= (temp / 2) * 2;
		cnt += temp;

		ans = min(ans, cnt);
		idx--;
	}

	// 2
	idx = n / 2;

	while (idx != 0)
	{
		int temp = n;
		int cnt = 0;
		temp -= idx * 2;
		cnt += idx;
		cnt += temp;

		ans = min(ans, cnt);
		idx--;
	}

	// 1
	ans = min(ans, n);

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