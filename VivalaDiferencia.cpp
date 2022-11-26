#include <iostream>
#include <cmath>

using namespace std;

int arr[4];

void input()
{
	for (int i = 0; i < 4; i++)
		cin >> arr[i];
}

bool check()
{
	if (arr[0] == arr[1])
		if (arr[1] == arr[2])
			if (arr[2] == arr[3])
				return false;

	return true;
}

void solution()
{
	int cnt = 0;

	while (check())
	{
		int a = abs(arr[0] - arr[1]);
		int b = abs(arr[1] - arr[2]);
		int c = abs(arr[2] - arr[3]);
		int d = abs(arr[3] - arr[0]);

		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		arr[3] = d;
		cnt++;
	}

	cout << cnt << '\n';
}

void solve()
{
	while (1)
	{
		input();

		if (arr[0] == 0)
			break;

		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}