#include <iostream>

using namespace std;

int n;

void solution()
{
	int idx = 0;

	for (int i = 0; ; i++)
	{
		idx = idx * 10 + 1;
		idx %= n;

		if (idx == 0)
		{
			cout << i + 1 << '\n';
			break;
		}
	}
}

void solve()
{
	while (cin >> n)
	{
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}