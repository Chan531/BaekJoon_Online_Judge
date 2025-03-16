#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int n, ans = -1;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = n + 1; i < 10000; i++)
	{
		int a = stoi(to_string(i).substr(0, 2));
		int b = stoi(to_string(i).substr(2, 2));

		if (pow(a + b, 2) == i)
		{
			ans = i;
			break;
		}
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