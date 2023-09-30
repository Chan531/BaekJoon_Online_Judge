#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1010], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	int seq = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i])
		{
			seq++;
			continue;
		}

		ans = max(ans, seq);
		seq = 0;
	}

	cout << max(ans, seq);
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