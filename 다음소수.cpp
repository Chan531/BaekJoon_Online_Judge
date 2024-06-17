#include <iostream>
#include <vector>
#define N 63245

using namespace std;

long long n;
bool check[N + 1];
vector<int> v;

void init()
{
	check[0] = 1;
	check[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		if (check[i]) continue;

		v.push_back(i);

		for (int j = i * 2; j <= N; j += i)
			check[j] = 1;
	}
}

void input()
{
	cin >> n;
}

void solution()
{
	long long ans = 0;

	for (long long i = n; ; i++)
	{
		if (i <= N && !check[i])
		{
			ans = i;
			break;
		}

		for (int j = 0; j < v.size(); j++)
		{
			if (i % v[j] == 0 || v[j] > i) break;
			if (j == v.size() - 1) ans = i;
		}

		if (ans) break;
	}

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