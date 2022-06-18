#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, pen[1000];

void input()
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> pen[i];
}

void solution()
{
	int sum = m * k;
	int idx = 0;
	sort(pen, pen + n, greater<int>());

	while (sum > 0)
	{
		if (idx > n)
			break;

		sum -= pen[idx++];
	}

	idx == n + 1 ? cout << "STRESS" : cout << idx;
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