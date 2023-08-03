#include <iostream>

using namespace std;

int a, b, arr[1001], ans;

void input()
{
	cin >> a >> b;
}

void solution()
{
	int idx = 1, val = 1;

	while (idx <= 1000)
	{
		for (int i = 0; i < val; i++)
			if (idx <= 1000)
				arr[idx++] = val;

		val++;
	}

	for (int i = a; i <= b; i++)
		ans += arr[i];

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