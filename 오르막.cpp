#include <iostream>

using namespace std;

int pre = -1e9;

void input()
{

}

void solution()
{
	while (!cin.eof())
	{
		int a;
		cin >> a;

		if (a >= pre)
		{
			pre = a;
			continue;
		}

		cout << "Bad";
		return;
	}

	cout << "Good";
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