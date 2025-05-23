#include <iostream>

using namespace std;

int n;
long long m;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		cin >> m;
		cout << m * m << '\n';
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