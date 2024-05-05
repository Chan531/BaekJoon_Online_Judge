#include <iostream>

using namespace std;

int arr[10];

void input()
{
	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;
		arr[n]++;
	}
}

void solution()
{
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] % 2)
		{
			cout << i;
			break;
		}
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