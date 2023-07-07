#include <iostream>

using namespace std;

int n, arr[4];

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			arr[3]++;

		else if (b <= 2)
			arr[0]++;

		else if (b == 3)
			arr[1]++;

		else if (b == 4)
			arr[2]++;
	}

	for (auto i : arr)
		cout << i << '\n';
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