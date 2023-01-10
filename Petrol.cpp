#include <iostream>

using namespace std;

int n, k, ans;

void input()
{
	cin >> n >> k;
}

void solution()
{
	// 이번달 살 수 있는 연료부터 해결
	if (n >= k)
	{
		n -= k;
		ans += k * 1500;
	}

	else
	{
		ans += n * 1500;
		n = 0;
	}

	if (n > 60)
	{
		ans += 60 * 1500;
		n -= 60;
	}

	else
	{
		ans += n * 1500;
		n = 0;
	}

	if (n > 0)
	{
		ans += n * 3000;
		n = 0;
	}

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
	cout.tie(NULL);

	solve();
	return 0;
}