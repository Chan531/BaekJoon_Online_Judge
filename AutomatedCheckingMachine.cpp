#include <iostream>

using namespace std;

int n, arr[5];

void input()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		arr[i % 5] += n;
	}
}

void solution()
{
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] != 1)
		{
			cout << 'N';
			return;
		}
	}

	cout << 'Y';
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