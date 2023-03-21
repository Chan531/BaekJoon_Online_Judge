#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	while (1)
	{
		int m = n + 1;
		int cnt = 0;

		while (m != 0)
		{
			if (m % 10 == 0)
				cnt++;

			m /= 10;
		}

		if (cnt == 0)
		{
			cout << n + 1 << '\n';
			break;
		}
		
		n++;
	}
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
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