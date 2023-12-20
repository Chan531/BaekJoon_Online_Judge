#include <iostream>

using namespace std;

int n, m, sum;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		sum += num;
		m += num / 2;
	}

	(sum % 3 || sum / 3 > m) ? cout << "NO" : cout << "YES";
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