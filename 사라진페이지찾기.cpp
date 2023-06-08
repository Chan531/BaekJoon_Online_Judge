#include <iostream>
#include <algorithm>

using namespace std;

int a, b, arr[3];

void input()
{
	cin >> a;

	if (a == 0)
	{
		b = -1;
		return;
	}

	cin >> b;
}

void solution()
{
	if (b % 2)
	{
		arr[0] = b + 1;
		arr[1] = a - b;
		arr[2] = arr[1] + 1;
	}

	else
	{
		arr[0] = b - 1;
		arr[1] = a - b + 1;
		arr[2] = arr[1] + 1;
	}

	sort(arr, arr + 3);

	for (auto i : arr)
		cout << i << ' ';

	cout << '\n';
}

void solve()
{
	while (1)
	{
		input();
		
		if (b == -1)
			break;

		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}