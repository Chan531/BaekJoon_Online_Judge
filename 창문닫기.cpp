#include <iostream>
#include <cmath>

using namespace std;

int n, ans;

void input()
{
	cin >> n;
}

void solution()
{
	int idx = 1;
	int m = sqrt(n);

	while (1)
	{
		if (idx > m)
			break;

		idx++;
	}

	cout << idx - 1;
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