#include <iostream>

using namespace std;

int n, arr[1010];

void input()
{
	cin >> n;
}

void solution()
{
	cout << n << " => " <<  arr[n] << '\n';
}

void solve()
{
	int cnt = 2;
	arr[1] = 1;
	for (int i = 2; i < 1000; i++)
	{
		arr[i] += arr[i - 1] + cnt;
		cnt += 2;
	}

	while (1)
	{
		input();
		if (!n) break;
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