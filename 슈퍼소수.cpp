#include <iostream>
#include <vector>
#define K 333333

using namespace std;

int n, cnt = 1;
vector<int> v;
bool prime[K];

void input()
{
	cin >> n;
}

void init()
{
	prime[1] = 1;

	for (int i = 2; i < K; i++)
	{
		if (prime[i])
			continue;

		if (!prime[cnt++])
			v.push_back(i);

		for (int j = i * 2; j < K; j += i)
			prime[j] = 1;
	}
}

void solution()
{
	init();

	while (n--)
	{
		int m;
		cin >> m;
		cout << v[m - 1] << '\n';
	}
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