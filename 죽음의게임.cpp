#include <iostream>

using namespace std;

int n, k, point[150], ans = -1;
bool check[150];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> point[i];
}

void solution()
{
	int idx = 0, cur = 0;

	while (1)
	{
		if (check[cur])
			break;

		if (cur == k)
		{
			ans = idx;
			break;
		}

		check[cur] = 1;
		cur = point[cur];
		idx++;
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