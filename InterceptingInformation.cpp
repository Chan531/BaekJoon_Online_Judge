#include <iostream>

using namespace std;

int n = 8;

void input()
{

}

void solution()
{
	while (n--)
	{
		int a;
		cin >> a;

		if (a == 9)
		{
			cout << 'F';
			return;
		}
	}

	cout << 'S';
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