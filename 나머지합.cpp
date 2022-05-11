#include <iostream>

using namespace std;

int n, m;
long long num, sum, restcnt[1001], ans;      // restcnt -> 나머지 개수 저장

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		sum += num;
		restcnt[sum % m]++;
	}
}

void solution()
{
	ans += restcnt[0];

	for (int i = 0; i < m; i++)
	{
		long long cnt = restcnt[i];
		ans += cnt * (cnt - 1) / 2;
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