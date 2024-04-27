#include <iostream>
#define ll long long

using namespace std;

ll s, k, ans = 1;

void input()
{
	cin >> s >> k;
}

void solution()
{
	int cnt = s % k;

	for (int i = 0; i < k; i++)
	{
		ll temp = s / k;

		if (cnt)
		{
			temp++;
			cnt--;
		}

		ans *= temp;
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

	solve();
	return 0;
}