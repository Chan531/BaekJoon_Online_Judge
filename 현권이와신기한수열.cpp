#include <iostream>
#include <unordered_map>

using namespace std;

int n, arr[101010];
unordered_map<int, bool> m;

void input()
{
	cin >> n;
}

void solution()
{
	m[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (arr[i - 1] - i < 0 || m[arr[i - 1] - i])
		{
			arr[i] = arr[i - 1] + i;
			m[arr[i - 1] + i] = 1;
		}

		else
		{
			arr[i] = arr[i - 1] - i;
			m[arr[i - 1] - i] = 1;
		}
	}

	cout << arr[n];
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