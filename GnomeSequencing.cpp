#include <iostream>
#include <algorithm>

using namespace std;

int arr[3], temp[3];

void input()
{
	for (int i = 0; i < 3; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < 3; i++)
		temp[i] = arr[i];

	sort(temp, temp + 3);

	for (int i = 0; i < 3; i++)
	{
		if (temp[i] != arr[i])
			break;

		if (i == 2)
		{
			cout << "Ordered\n";
			return;
		}
	}

	sort(temp, temp + 3, greater<>());

	for (int i = 0; i < 3; i++)
	{
		if (temp[i] != arr[i])
			break;

		if (i == 2)
		{
			cout << "Ordered\n";
			return;
		}
	}

	cout << "Unordered\n";
}

void solve()
{
	int tc;
	cin >> tc;
	cout << "Gnomes:\n";

	while (tc--)
	{
		input();
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