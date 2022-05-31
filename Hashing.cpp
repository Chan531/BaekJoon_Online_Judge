#include <iostream>
#define M 1234567891

using namespace std;

int n;
string str;
long long ans;

void input()
{
	cin >> n >> str;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		long long num = str[i] - '`';

		for (int j = 0; j < i; j++)
		{
			num *= 31;
			num %= M;
		}

		ans += num;
		ans %= M;
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