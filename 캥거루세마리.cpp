	#include <iostream>
	#include <algorithm>

	using namespace std;

	int a, b, c, ans;

	void input()
	{
		cin >> a >> b >> c;
	}

	bool check()
	{
		if (a + 1 == b && b + 1 == c)
			return 0;

		return 1;
	}

	void solution()
	{
		while (check())
		{
			if (b - a > c - b)
				swap(b, c);

			else
				swap(a, b);

			b = c - 1;
			ans++;
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

		solve();
		return 0;
	}