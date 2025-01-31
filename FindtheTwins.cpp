#include <iostream>

using namespace std;

int n, arr[10];

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int z = 0, m = 0;

		for (int i = 0; i < 10; i++)
		{
			cin >> arr[i];

			if (arr[i] == 17) z = 1;
			if (arr[i] == 18) m = 1;
		}

		for (int i = 0; i < 10; i++) cout << arr[i] << ' ';

		if (m && z) cout << "\nboth\n\n";
		else if (m) cout << "\nmack\n\n";
		else if (z) cout << "\nzack\n\n";
		else cout << "\nnone\n\n";
	}
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