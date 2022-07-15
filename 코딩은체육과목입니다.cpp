#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	while (n != 0)
	{
		cout << "long ";
		n -= 4;
	}

	cout << "int";
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