#include <iostream>

using namespace std;

int arr[3];

void input()
{
	for (int i = 0; i < 3; i++)
	{
		int n;
		cin >> n;
		arr[n]++;
	}
}

void solution()
{
	if (arr[1] > arr[2]) cout << 1;
	else cout << 2;
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