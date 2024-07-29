#include <iostream>
#include <cstring>
#define N 111

using namespace std;

int n, q;
bool arr[N];

void input()
{
	cin >> n >> q;
}

void solution()
{
	while (q--)
	{
		char c;
		int a;

		cin >> c >> a;

		int idx = 1;

		if (c == '?')
		{
			while (a)
				if (!arr[idx++])
					a--;

			cout << idx - 1 << '\n';
		}

		else
		{
			arr[a] = 1;
		    arr[n - a + 1] = 1;
		}
	}

	memset(arr, 0, sizeof(arr));
}

void solve()
{
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